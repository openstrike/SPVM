package SPVM::Build::Setting;

use strict;
use warnings;

sub new {
  my $class = shift;
  
  my $self = {};
  
  $self->{config} = {};

  $self->{extra_compiler_flags} = [];

  $self->{extra_linker_flags} = [];

  $self->{include_dirs} = [];
  
  return bless $self, $class;
}

sub set_include_dirs {
  my ($self, $include_dirs) = @_;
  
  $self->{include_dirs} = $include_dirs;
  
  return $self;
}

sub get_include_dirs {
  my $self = shift;
  
  return $self->{include_dirs};
}

sub add_include_dir {
  my ($self, $include_dir) = @_;
  
  push @{$self->{include_dirs}}, $include_dir;
  
  return $self;
}

sub set_extra_compiler_flags {
  my ($self, $extra_compiler_flags) = @_;
  
  $self->{extra_compiler_flags} = $extra_compiler_flags;
  
  return $self;
}

sub get_extra_compiler_flags {
  my $self = shift;
  
  return $self->{extra_compiler_flags};
}

sub add_extra_compiler_flag {
  my ($self, $extra_compiler_flag) = @_;
  
  push @{$self->{extra_compiler_flags}}, $extra_compiler_flag;
  
  return $self;
}

sub set_extra_linker_flags {
  my ($self, $extra_linker_flags) = @_;
  
  $self->{extra_linker_flags} = $extra_linker_flags;
  
  return $self;
}

sub get_extra_linker_flags {
  my $self = shift;
  
  return $self->{extra_linker_flags};
}

sub add_extra_linker_flag {
  my ($self, $extra_linker_flag) = @_;
  
  push @{$self->{extra_linker_flags}}, $extra_linker_flag;
  
  return $self;
}

sub set_config {
  my ($self, %key_values) = @_;
  
  my $config = $self->{config};
  
  for my $key (keys %key_values) {
    my $value = $key_values{$key};
    $config->{$key} = $value;
  }
  
  return $self;
}

sub add_config {
  my ($self, %key_values) = @_;
  
  my $config = $self->{config};

  for my $key (keys %key_values) {
    my $value = $key_values{$key};
    $config->{$key} .= " $value";
  }
  
  return $self;
}

sub get_config {
  my $self = shift;
  
  my $config = $self->{config};

  if (@_) {
    return $config->{$_[0]};
  }
  else {
    return $config;
  }
}

=head1 NAME

SPVM::Build::Setting;

=head1 DESCRIPTION

L<ExtUtils::CBuilder> setting of C<new>, C<compile>, C<link> methods.

=cut

1;