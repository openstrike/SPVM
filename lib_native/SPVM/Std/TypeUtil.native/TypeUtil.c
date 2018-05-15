#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <float.h>

#include "spvm_api.h"

float SPVM__Std__TypeUtil__FLT_MAX(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  (void)args;
  
  return FLT_MAX;
}

float SPVM__Std__TypeUtil__FLT_MIN(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  (void)args;
  
  return FLT_MIN;
}

double SPVM__Std__TypeUtil__DBL_MAX(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  (void)args;
  
  return DBL_MAX;
}

double SPVM__Std__TypeUtil__DBL_MIN(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  (void)args;
  
  return DBL_MIN;
}
