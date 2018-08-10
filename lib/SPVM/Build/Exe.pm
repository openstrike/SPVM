package SPVM::Build::Exe;

use strict;
use warnings;
use Carp 'croak', 'confess';
use Pod::Usage 'pod2usage';

use SPVM::Build;
use SPVM::Build::Util;

use Getopt::Long 'GetOptions';

use ExtUtils::CBuilder;
use File::Copy 'move';
use File::Path 'mkpath';
use DynaLoader;

use File::Basename 'dirname', 'basename';

sub create_exe_file {
  my $package_name = shift;
  
  # New SPVM::Build object
  my $build = SPVM::Build->new;
  
  # Add package informations
  my $package_info = {
    name => $package_name,
  };
  push @{$build->{package_infos}}, $package_info;
  
  # Compile
  my $compile_success = $self->compile_spvm();
  unless ($compile_success) {
    croak "Compile error";
  }

  # Build precompile all subs - Compile C source codes and link them to SPVM precompile subroutine
  $build->build_precompile({all_subs => 1});
  
  # Build native packages - Compile C source codes and link them to SPVM native subroutine
  $build->build_native;
  
  # Build exe file
  $self->build_exe;
}




1;