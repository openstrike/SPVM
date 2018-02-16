use strict;
use warnings;
use File::Copy 'copy';
use File::Basename 'basename';

my @old_jit_test_files = glob 't/jit/*';
for my $old_jit_test_file (@old_jit_test_files) {
  unlink $old_jit_test_file
    or die "Can't delete $old_jit_test_file";
}

my @default_test_files = glob 't/default/*';
for my $default_test_file (@default_test_files) {
  my $new_jit_test_file = 't/jit/' . basename $default_test_file;
  copy $default_test_file, $new_jit_test_file
    or die "Can't copy $default_test_file to $new_jit_test_file";
}