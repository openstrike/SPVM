#ifndef SPVM_RUNTIME_API_H
#define SPVM_RUNTIME_API_H

#include "spvm_base.h"
#include "spvm_api.h"

SPVM_OBJECT* SPVM_RUNTIME_API_create_exception_stack_trace(SPVM_ENV* api, SPVM_OBJECT* exception, int32_t sub_id, int32_t current_line);

SPVM_OBJECT* SPVM_RUNTIME_API_concat(SPVM_ENV* api, SPVM_OBJECT* string1, SPVM_OBJECT* string2);

int32_t SPVM_RUNTIME_API_is_debug(SPVM_ENV* api);

int32_t SPVM_RUNTIME_API_create_void_type_id(SPVM_ENV* api);
int32_t SPVM_RUNTIME_API_create_byte_type_id(SPVM_ENV* api);
int32_t SPVM_RUNTIME_API_create_short_type_id(SPVM_ENV* api);
int32_t SPVM_RUNTIME_API_create_int_type_id(SPVM_ENV* api);
int32_t SPVM_RUNTIME_API_create_long_type_id(SPVM_ENV* api);
int32_t SPVM_RUNTIME_API_create_float_type_id(SPVM_ENV* api);
int32_t SPVM_RUNTIME_API_create_double_type_id(SPVM_ENV* api);

SPVM_RUNTIME* SPVM_RUNTIME_API_new_runtime();
void SPVM_RUNTIME_API_dec_ref_count_only(SPVM_ENV* api, SPVM_OBJECT* object);
int32_t SPVM_RUNTIME_API_get_object_header_length_offset(SPVM_ENV* api);

// Array functions
int32_t SPVM_RUNTIME_API_get_object_header_byte_size(SPVM_ENV* api);
int32_t SPVM_RUNTIME_API_get_array_length(SPVM_ENV* api, SPVM_OBJECT* array);
int8_t* SPVM_RUNTIME_API_get_byte_array_elements(SPVM_ENV* api, SPVM_OBJECT* array);
int16_t* SPVM_RUNTIME_API_get_short_array_elements(SPVM_ENV* api, SPVM_OBJECT* array);
int32_t* SPVM_RUNTIME_API_get_int_array_elements(SPVM_ENV* api, SPVM_OBJECT* array);
int64_t* SPVM_RUNTIME_API_get_long_array_elements(SPVM_ENV* api, SPVM_OBJECT* array);
float* SPVM_RUNTIME_API_get_float_array_elements(SPVM_ENV* api, SPVM_OBJECT* array);
double* SPVM_RUNTIME_API_get_double_array_elements(SPVM_ENV* api, SPVM_OBJECT* array);
void SPVM_RUNTIME_API_set_object_array_accessent(SPVM_ENV* api, SPVM_OBJECT* array, int32_t index, SPVM_OBJECT* value);
SPVM_OBJECT* SPVM_RUNTIME_API_get_object_array_accessent(SPVM_ENV* api, SPVM_OBJECT* array, int32_t index);

// Object functions
int32_t SPVM_RUNTIME_API_get_field_id(SPVM_ENV* api, SPVM_OBJECT* object, const char* name);
int8_t SPVM_RUNTIME_API_get_byte_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id);
int16_t SPVM_RUNTIME_API_get_short_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id);
int32_t SPVM_RUNTIME_API_get_int_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id);
int64_t SPVM_RUNTIME_API_get_long_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id);
float SPVM_RUNTIME_API_get_float_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id);
double SPVM_RUNTIME_API_get_double_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id);
SPVM_OBJECT* SPVM_RUNTIME_API_get_object_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id);
void SPVM_RUNTIME_API_weaken_object_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id);
void SPVM_RUNTIME_API_set_byte_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id, int8_t value);
void SPVM_RUNTIME_API_set_short_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id, int16_t value);
void SPVM_RUNTIME_API_set_int_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id, int32_t value);
void SPVM_RUNTIME_API_set_long_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id, int64_t value);
void SPVM_RUNTIME_API_set_float_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id, float value);
void SPVM_RUNTIME_API_set_double_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id, double value);
void SPVM_RUNTIME_API_set_object_field(SPVM_ENV* api, SPVM_OBJECT* object, int32_t field_id, SPVM_OBJECT* value);
int32_t SPVM_RUNTIME_API_check_cast(SPVM_ENV* api, int32_t cast_basic_type_id, int32_t cast_type_dimension, SPVM_OBJECT* object);

// Call Subroutine
void SPVM_RUNTIME_API_call_void_sub(SPVM_ENV* api, int32_t sub_id, SPVM_VALUE* args);
int8_t SPVM_RUNTIME_API_call_byte_sub(SPVM_ENV* api, int32_t sub_id, SPVM_VALUE* args);
int16_t SPVM_RUNTIME_API_call_short_sub(SPVM_ENV* api, int32_t sub_id, SPVM_VALUE* args);
int32_t SPVM_RUNTIME_API_call_int_sub(SPVM_ENV* api, int32_t sub_id, SPVM_VALUE* args);
int64_t SPVM_RUNTIME_API_call_long_sub(SPVM_ENV* api, int32_t sub_id, SPVM_VALUE* args);
float SPVM_RUNTIME_API_call_float_sub(SPVM_ENV* api, int32_t sub_id, SPVM_VALUE* args);
double SPVM_RUNTIME_API_call_double_sub(SPVM_ENV* api, int32_t sub_id, SPVM_VALUE* args);
SPVM_OBJECT* SPVM_RUNTIME_API_call_object_sub(SPVM_ENV* api, int32_t sub_id, SPVM_VALUE* args);

// String
SPVM_OBJECT* SPVM_RUNTIME_API_new_string(SPVM_ENV* api, char* bytes, int32_t length);
int32_t SPVM_RUNTIME_API_get_string_length(SPVM_ENV* api, SPVM_OBJECT* object);
int8_t* SPVM_RUNTIME_API_get_string_bytes(SPVM_ENV* api, SPVM_OBJECT* object);
void SPVM_RUNTIME_API_print(SPVM_ENV* api, SPVM_OBJECT* string);

// Internal functions
int32_t SPVM_RUNTIME_API_get_fields_length(SPVM_ENV* api, SPVM_OBJECT* object);
int32_t SPVM_RUNTIME_API_dump_field_names(SPVM_ENV* api, SPVM_OBJECT* object);
int32_t SPVM_RUNTIME_API_get_ref_count(SPVM_ENV* api, SPVM_OBJECT* object);

int32_t SPVM_RUNTIME_API_get_sub_id(SPVM_ENV* api, const char* name);
int32_t SPVM_RUNTIME_API_get_sub_id_interface_method(SPVM_ENV* api, SPVM_OBJECT* object, int32_t decl_sub_id);
int32_t SPVM_RUNTIME_API_get_method_sub_id(SPVM_ENV* api, SPVM_OBJECT* object, const char* sub_name);
int32_t SPVM_RUNTIME_API_get_class_method_sub_id(SPVM_ENV* api, const char* package_name, const char* sub_name);
int32_t SPVM_RUNTIME_API_get_basic_type_id(SPVM_ENV* api, const char* name);

SPVM_OBJECT* SPVM_RUNTIME_API_new_object(SPVM_ENV* api, int32_t package_id);

SPVM_OBJECT* SPVM_RUNTIME_API_new_address_array(SPVM_ENV* api, int32_t length);

SPVM_OBJECT* SPVM_RUNTIME_API_new_byte_array(SPVM_ENV* api, int32_t length);
SPVM_OBJECT* SPVM_RUNTIME_API_new_short_array(SPVM_ENV* api, int32_t length);
SPVM_OBJECT* SPVM_RUNTIME_API_new_int_array(SPVM_ENV* api, int32_t length);
SPVM_OBJECT* SPVM_RUNTIME_API_new_long_array(SPVM_ENV* api, int32_t length);
SPVM_OBJECT* SPVM_RUNTIME_API_new_float_array(SPVM_ENV* api, int32_t length);
SPVM_OBJECT* SPVM_RUNTIME_API_new_double_array(SPVM_ENV* api, int32_t length);
SPVM_OBJECT* SPVM_RUNTIME_API_new_object_array(SPVM_ENV* api, int32_t basic_type_id, int32_t length);
SPVM_OBJECT* SPVM_RUNTIME_API_new_multi_array(SPVM_ENV* api, int32_t basic_type_id, int32_t dimension, int32_t length);

SPVM_OBJECT* SPVM_RUNTIME_API_new_call_stack_object(SPVM_ENV* api, int32_t length);

// Exception
void SPVM_RUNTIME_API_set_exception(SPVM_ENV* api, SPVM_OBJECT* exception);
SPVM_OBJECT* SPVM_RUNTIME_API_get_exception(SPVM_ENV* api);

// Reference count
int32_t SPVM_RUNTIME_API_get_ref_count(SPVM_ENV* api, SPVM_OBJECT* object);
void SPVM_RUNTIME_API_dec_ref_count(SPVM_ENV* api, SPVM_OBJECT* object);
void SPVM_RUNTIME_API_inc_ref_count(SPVM_ENV* api, SPVM_OBJECT* object);
void SPVM_RUNTIME_API_inc_dec_ref_count(SPVM_ENV* api, SPVM_OBJECT* object);
int32_t SPVM_RUNTIME_API_isweak(SPVM_ENV* api, SPVM_OBJECT* object);
void SPVM_RUNTIME_API_weaken(SPVM_ENV* api, SPVM_OBJECT** object_address);
void SPVM_RUNTIME_API_unweaken(SPVM_ENV* api, SPVM_OBJECT** object_address);

// Global information
int32_t SPVM_RUNTIME_API_get_objects_count(SPVM_ENV* api);
SPVM_RUNTIME* SPVM_RUNTIME_API_get_runtime();
void SPVM_RUNTIME_API_set_runtime(SPVM_ENV* api, SPVM_RUNTIME* runtime);
void SPVM_RUNTIME_API_free_runtime(SPVM_ENV* api, SPVM_RUNTIME* runtime);

int32_t print_error(SPVM_ENV* api, const char* message);
void exit(int32_t statue);
int32_t get_stderr();


#endif
