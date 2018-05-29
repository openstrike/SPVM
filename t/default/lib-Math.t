use lib "t/lib";
use JITTestAuto;

use strict;
use warnings;

use Test::More 'no_plan';

use SPVM 'TestCase::Math';

my $BYTE_MAX = 127;
my $BYTE_MIN = -128;
my $SHORT_MAX = 32767;
my $SHORT_MIN = -32768;
my $INT_MAX = 2147483647;
my $INT_MIN = -2147483648;
my $LONG_MAX = 9223372036854775807;
my $LONG_MIN = -9223372036854775808;
my $FLOAT_PRECICE = 16384.5;
my $DOUBLE_PRECICE = 65536.5;

# Positive infinity(unix like system : inf, Windows : 1.#INF)
my $POSITIVE_INFINITY = 9**9**9;

my $NaN = 9**9**9 / 9**9**9;

my $nan_re = qr/(nan|ind)/i;

# Start objects count
my $start_objects_count = SPVM::get_objects_count();

# Call subroutine
{
  ok(SPVM::TestCase::Math->sin());
  ok(SPVM::TestCase::Math->cos());
  ok(SPVM::TestCase::Math->tan());
}

# float
{
  ok(SPVM::TestCase::Math->float_pass_positive_infinity($POSITIVE_INFINITY));
  ok(SPVM::TestCase::Math->float_pass_nan($NaN));
  
  ok(SPVM::TestCase::Math->isinff());
  ok(SPVM::TestCase::Math->isfinitef());
  ok(SPVM::TestCase::Math->isnanf());
  
  is(SPVM::Math->INFINITYF(), $POSITIVE_INFINITY);
  
  like(SPVM::Math->NANF(), $nan_re);
}

# SPVM::Double
{
  ok(SPVM::TestCase::Math->double_pass_positive_infinity($POSITIVE_INFINITY));
  ok(SPVM::TestCase::Math->double_pass_nan($NaN));
  
  ok(SPVM::TestCase::Math->isinf());
  ok(SPVM::TestCase::Math->isfinite());
  ok(SPVM::TestCase::Math->isnan());
  
  is(SPVM::Math->INFINITY(), $POSITIVE_INFINITY);
  
  like(SPVM::Math->NAN(), $nan_re);
}

# All object is freed
my $end_objects_count = SPVM::get_objects_count();
is($end_objects_count, $start_objects_count);