#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>

#include "spvm_api.h"

void SPVM__CORE__print(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  SPVM_API_OBJECT* object = args[0].object_value;
  
  char* chars = api->get_string_chars(api, object);
  
  printf("%s", (char*)chars);
}

void SPVM__CORE__warn(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  SPVM_API_OBJECT* object = args[0].object_value;
  
  char* chars = api->get_string_chars(api, object);
  
  fprintf(stderr, "%s", chars);
}

int64_t SPVM__CORE__time(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  (void)args;

  int64_t timer_value = (int64_t)time(NULL);
  
  
  return timer_value;
}

int32_t SPVM__CORE__sum_int(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  SPVM_API_OBJECT* array = args[0].object_value;
  
  int32_t length = api->get_array_length(api, array);
  
  int32_t* values = api->get_int_array_elements(api, array);
  
  int64_t total = 0;
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      total += values[i];
    }
  }
  
  return total;
}

int32_t SPVM__CORE__test1(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int32_t num1 = args[0].int_value;
  int32_t num2 = args[1].int_value;
  
  int32_t sub_id = api->get_sub_id(api, "CORE::test2");
  
  SPVM_API_VALUE new_args[2];
  new_args[0].int_value = 5;
  new_args[1].int_value = 3;
  
  int32_t ret = api->call_int_sub(api, sub_id, new_args);
  
  int32_t num3 = num1 + num2 + ret;
  
  return num3;
}

int32_t SPVM__CORE__test2(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int32_t num1 = args[0].int_value;
  int32_t num2 = args[1].int_value;
  
  int32_t num3 = num1 * num2;
  
  return num3;
}