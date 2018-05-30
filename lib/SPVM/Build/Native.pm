package SPVM::Build::Native;

# SPVM::Build::PPtUtil is used from Makefile.PL
# so this module must be wrote as pure per script, not contain XS and don't use any other SPVM modules.

use strict;
use warnings;
use Carp 'croak', 'confess';

use ExtUtils::CBuilder;
use Config;
use File::Copy 'move';
use File::Path 'mkpath';
use DynaLoader;

use File::Basename 'dirname', 'basename';

sub new {
  my $class = shift;
  
  my $self = {};
  
  $self->{extra_compiler_flags} = SPVM::Build::Util::default_extra_compiler_flags();
  $self->{optimize} = SPVM::Build::Util::default_optimize();
  $self->{category} = 'native';
  
  return bless $self, $class;
}

sub category {
  my $self = shift;
  
  $self->{category};
}

sub extra_compiler_flags {
  my $self = shift;
  
  return $self->{extra_compiler_flags};
}

sub optimize {
  my $self = shift;
  
  return $self->{optimize};
}

sub create_build_shared_lib_make_rule {
  my ($self, $module_name) = @_;
  
  my $make_rule;
  
  # dynamic section
  $make_rule
  = "dynamic :: ";

  my $module_name_under_score = $module_name;
  $module_name_under_score =~ s/:/_/g;
  
  $make_rule
    .= "shared_lib_$module_name_under_score ";
  $make_rule .= "\n\n";
  
  my $module_base_name = $module_name;
  $module_base_name =~ s/^.+:://;
  
  my $src_dir = $module_name;
  $src_dir =~ s/::/\//g;
  $src_dir = "lib/$src_dir.native";
  
  # Dependency
  my @deps = grep { $_ ne '.' && $_ ne '..' } glob "$src_dir/*";
  
  # Shared library file
  my $shared_lib_bilb_file = SPVM::Build::Util::convert_module_name_to_shared_lib_bilb_file($module_name, $self->category);
  
  # Get native source files
  $make_rule
    .= "shared_lib_$module_name_under_score :: $shared_lib_bilb_file\n\n";
  $make_rule
    .= "$shared_lib_bilb_file :: @deps\n\n";
  $make_rule
    .= "\tperl -Ilib -MSPVM::Build::Native -e \"SPVM::Build::Native->new->build_shared_lib_blib('$module_name')\"\n\n";
  
  return $make_rule;
}

sub move_shared_lib_to_blib {
  my ($self, $shared_lib_file, $module_name) = @_;
  
  # Create shared lib blib directory
  my $shared_lib_blib_dir = SPVM::Build::Util::convert_module_name_to_shared_lib_blib_dir($module_name, $self->category);
  mkpath $shared_lib_blib_dir;
  
  # shared lib blib file
  my $shared_lib_blib_file = SPVM::Build::Util::convert_module_name_to_shared_lib_bilb_file($module_name, $self->category);
  
  # Move shared library file to blib directory
  move($shared_lib_file, $shared_lib_blib_file)
    or die "Can't move $shared_lib_file to $shared_lib_blib_file";
}

sub build_shared_lib_blib {
  my ($self, $module_name) = @_;

  # Build shared library
  my $shared_lib_file = $self->build_shared_lib(
    module_name => $module_name,
    module_dir => 'lib',
    source_dir => 'lib',
    build_dir => '.'
  );
  
  $self->move_shared_lib_to_blib($shared_lib_file, $module_name);
}

sub build_shared_lib {
  my ($self, %opt) = @_;
  
  # Module name
  my $module_name = $opt{module_name};
  
  # Module directory
  my $module_dir = $opt{module_dir};

  # Source directory
  my $source_dir = $opt{source_dir};
  unless (defined $source_dir) {
    $source_dir = $module_dir;
  }
  
  # Object created directory
  my $build_dir = $opt{build_dir};
  
  my $quiet = defined $opt{quiet} ? $opt{quiet} : 0;
 
  my $module_base_name = $module_name;
  $module_base_name =~ s/^.+:://;
  
  my $native_dir = $module_name;
  $native_dir =~ s/::/\//g;
  $native_dir .= '.native';
  $native_dir = "$source_dir/$native_dir";
  
  unless (defined $build_dir && -d $build_dir) {
    confess "SPVM build directory must be specified for native compile";
  }
  
  # Correct source files
  my $src_files = [];
  my @valid_exts = ('c', 'C', 'cpp', 'i', 's', 'cxx', 'cc');
  for my $src_file (glob "$native_dir/*") {
    if (grep { $src_file =~ /\.$_$/ } @valid_exts) {
      push @$src_files, $src_file;
    }
  }
  
  # Config
  my $config_file = "$native_dir/$module_base_name.config";
  my $config;
  if (-f $config_file) {
    $config = do $config_file
      or confess "Can't parser $config_file: $!$@";
  }
  
  # Include directory
  my $include_dirs = [];
  
  # Default include path
  my $env_header_include_dir = $INC{"SPVM/Build/Native.pm"};
  $env_header_include_dir =~ s/\/Build\/Native\.pm$//;
  push @$include_dirs, $env_header_include_dir;
  
  push @$include_dirs, $native_dir;
  
  # CBuilder config
  my $cbuilder_config = {};
  
  # Convert ExtUitls::MakeMaker config to ExtUtils::CBuilder config
  if ($config) {
    # CBuilder config name which compatible with ExtUtils::MakeMaker
    my @cbuilder_config_names_compatible = qw(
      optimize
      cc
      ccflags
      ld
      lddlflags
    );
    for my $cbuilder_name (@cbuilder_config_names_compatible) {
      my $makemaker_name = uc $cbuilder_name;
      
      if (defined $config->{$makemaker_name}) {
        $cbuilder_config->{$cbuilder_name} = delete $config->{$makemaker_name};
      }
    }
  }
  
  # Include directory
  if (defined $config->{INC}) {
    my $inc = delete $config->{INC};
    
    my @include_dirs_tmp = split /\s+/, $inc;
    for my $include_dir_tmp (reverse @include_dirs_tmp) {
      if ($include_dir_tmp =~ s/^-I//) {
        unshift @$include_dirs, $include_dir_tmp;
      }
      else {
        confess "Invalid include option \"$inc\"";
      }
    }
  }
  
  # Shared library
  my $extra_linker_flags = '';
  if (defined $config->{LIBS}) {
    my $libs = delete $config->{LIBS};
    
    if (ref $libs eq 'ARRAY') {
      $libs = join(' ', @$libs);
    }
    
    $extra_linker_flags .= $libs;
  }
  
  my @keys = keys %$config;
  if (@keys) {
    confess "$keys[0] is not supported option";
  }
  
  # OPTIMIZE
  $cbuilder_config->{optimize} ||= $self->optimize;
  
  # Compile source files
  my $cbuilder = ExtUtils::CBuilder->new(quiet => $quiet, config => $cbuilder_config);
  my $object_files = [];
  for my $src_file (@$src_files) {
    # Object file
    my $object_file = $module_name;
    $object_file =~ s/:/_/g;
    my $src_file_under_score = $src_file;
    $src_file_under_score =~ s/^.+\///;
    $src_file_under_score =~ s/[^a-zA-Z0-9]/_/g;
    $object_file = "$build_dir/${object_file}____$src_file_under_score.o";
    
    # Compile source file
    $cbuilder->compile(
      source => $src_file,
      object_file => $object_file,
      include_dirs => $include_dirs,
      extra_compiler_flags => $self->extra_compiler_flags
    );
    push @$object_files, $object_file;
  }
  
  my $dlext = $Config{dlext};
  
  # Module file
  my $module_file = $module_name;
  $module_file =~ s/::/\//g;
  $module_file = "$module_dir/$module_file.spvm";
  
  my $native_sub_names = SPVM::Build::Util::get_native_sub_names_from_module_file($module_file);

  my $native_func_names = [];
  for my $native_sub_name (@$native_sub_names) {
    my $native_func_name = "${module_name}::$native_sub_name";
    $native_func_name =~ s/:/_/g;
    push @$native_func_names, $native_func_name;
  }
  
  # This is dummy to suppress boot strap function
  # This is bad hack
  unless (@$native_func_names) {
    push @$native_func_names, '';
  }
  
  my $shared_lib_file = $cbuilder->link(
    objects => $object_files,
    module_name => $module_name,
    dl_func_list => $native_func_names,
    extra_linker_flags => $extra_linker_flags
  );
  
  return $shared_lib_file;
}

my $compiled_native_shared_lib_file_h = {};

sub get_sub_native_address {
  my ($self, $sub_abs_name) = @_;
  
  my $package_name;
  my $sub_name;
  if ($sub_abs_name =~ /^(?:(.+)::)(.+)$/) {
    $package_name = $1;
    $sub_name = $2;
  }
  
  my $dll_package_name = $package_name;
  my $shared_lib_file = $self->get_shared_lib_file($dll_package_name);
  
  my $shared_lib_func_name = $sub_abs_name;
  $shared_lib_func_name =~ s/:/_/g;
  my $native_address = SPVM::Build::Util::get_shared_lib_func_address($shared_lib_file, $shared_lib_func_name);
  
  # Try inline compile
  unless ($native_address) {
    my $module_name = $package_name;
    $module_name =~ s/^SPVM:://;
    
    unless ($compiled_native_shared_lib_file_h->{$module_name}) {
      my $module_dir = SPVM::Build::SPVMInfo::get_package_load_path($module_name);
      $module_dir =~ s/\.spvm$//;
      
      my $module_name_slash = $package_name;
      $module_name_slash =~ s/::/\//g;
      
      $module_dir =~ s/$module_name_slash$//;
      $module_dir =~ s/\/$//;
      
      # Build native code
      my $build_dir = $SPVM::BUILD_DIR;
      unless (defined $build_dir && -d $build_dir) {
        confess "SPVM build directory must be specified for native compile";
      }
      
      my $native_shared_lib_file = $self->build_shared_lib(
        module_dir => $module_dir,
        module_name => "SPVM::$module_name",
        build_dir => $build_dir,
        native => 1,
        quiet => 1,
      );
      
      $compiled_native_shared_lib_file_h->{$module_name} = $native_shared_lib_file;
    }
    
    $native_address = SPVM::Build::Util::get_shared_lib_func_address($compiled_native_shared_lib_file_h->{$module_name}, $shared_lib_func_name);
  }
  
  return $native_address;
}

sub get_shared_lib_file {
  my ($self, $module_name) = @_;
  
  my $module_name2 = $module_name;
  $module_name2 =~ s/SPVM:://;
  my @module_name_parts = split(/::/, $module_name2);
  my $module_load_path = SPVM::Build::SPVMInfo::get_package_load_path($module_name2);
  
  my $shared_lib_path = SPVM::Build::Util::convert_module_path_to_shared_lib_path($module_load_path, $self->category);
  
  return $shared_lib_path;
}

1;