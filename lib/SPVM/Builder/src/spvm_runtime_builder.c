#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "spvm_runtime_builder.h"

#include "spvm_compiler.h"
#include "spvm_type.h"
#include "spvm_package.h"
#include "spvm_type.h"
#include "spvm_op.h"
#include "spvm_hash.h"
#include "spvm_list.h"
#include "spvm_util_allocator.h"
#include "spvm_compiler_allocator.h"
#include "spvm_yacc_util.h"
#include "spvm_list.h"
#include "spvm_opcode_array.h"
#include "spvm_sub.h"
#include "spvm_runtime.h"
#include "spvm_runtime_api.h"
#include "spvm_sub.h"
#include "spvm_field.h"
#include "spvm_package_var.h"
#include "spvm_native.h"
#include "spvm_opcode.h"
#include "spvm_basic_type.h"
#include "spvm_use.h"
#include "spvm_op_checker.h"
#include "spvm_opcode_builder.h"
#include "spvm_object.h"
#include "spvm_runtime_basic_type.h"
#include "spvm_runtime_package.h"
#include "spvm_runtime_field.h"
#include "spvm_runtime_package_var.h"
#include "spvm_runtime_sub.h"
#include "spvm_runtime_my.h"
#include "spvm_runtime_info_type.h"
#include "spvm_runtime_info_switch_info.h"
#include "spvm_runtime_info_case_info.h"
#include "spvm_my.h"
#include "spvm_portable.h"

#include "spvm_csource_builder_exe.h"
#include "spvm_string_buffer.h"




















































SPVM_ENV* SPVM_RUNTIME_BUILDER_create_env(SPVM_RUNTIME* runtime) {

  void* env_init[]  = {
    SPVM_RUNTIME_API_get_array_length,
    SPVM_RUNTIME_API_get_byte_array_elements,
    SPVM_RUNTIME_API_get_short_array_elements,
    SPVM_RUNTIME_API_get_int_array_elements,
    SPVM_RUNTIME_API_get_long_array_elements,
    SPVM_RUNTIME_API_get_float_array_elements,
    SPVM_RUNTIME_API_get_double_array_elements,
    SPVM_RUNTIME_API_get_object_array_element,
    SPVM_RUNTIME_API_set_object_array_element,
    SPVM_RUNTIME_API_get_field_index,
    SPVM_RUNTIME_API_get_byte_field,
    SPVM_RUNTIME_API_get_short_field,
    SPVM_RUNTIME_API_get_int_field,
    SPVM_RUNTIME_API_get_long_field,
    SPVM_RUNTIME_API_get_float_field,
    SPVM_RUNTIME_API_get_double_field,
    SPVM_RUNTIME_API_get_object_field,
    SPVM_RUNTIME_API_get_pointer,
    SPVM_RUNTIME_API_set_byte_field,
    SPVM_RUNTIME_API_set_short_field,
    SPVM_RUNTIME_API_set_int_field,
    SPVM_RUNTIME_API_set_long_field,
    SPVM_RUNTIME_API_set_float_field,
    SPVM_RUNTIME_API_set_double_field,
    SPVM_RUNTIME_API_set_object_field,
    SPVM_RUNTIME_API_get_sub_id,
    SPVM_RUNTIME_API_get_sub_id_method_call,
    SPVM_RUNTIME_API_get_basic_type_id,
    SPVM_RUNTIME_API_new_object_raw,
    SPVM_RUNTIME_API_new_byte_array_raw,
    SPVM_RUNTIME_API_new_short_array_raw,
    SPVM_RUNTIME_API_new_int_array_raw,
    SPVM_RUNTIME_API_new_long_array_raw,
    SPVM_RUNTIME_API_new_float_array_raw,
    SPVM_RUNTIME_API_new_double_array_raw,
    SPVM_RUNTIME_API_new_object_array_raw,
    SPVM_RUNTIME_API_new_multi_array_raw,
    SPVM_RUNTIME_API_new_value_t_array_raw,
    SPVM_RUNTIME_API_new_string_raw,
    SPVM_RUNTIME_API_new_pointer_raw,
    SPVM_RUNTIME_API_get_exception,
    SPVM_RUNTIME_API_set_exception,
    SPVM_RUNTIME_API_get_ref_count,
    SPVM_RUNTIME_API_inc_ref_count,
    SPVM_RUNTIME_API_dec_ref_count,
    SPVM_RUNTIME_API_inc_dec_ref_count,
    SPVM_RUNTIME_API_get_memory_blocks_count,
    SPVM_RUNTIME_API_dec_ref_count_only,
    SPVM_RUNTIME_API_weaken,
    SPVM_RUNTIME_API_isweak,
    SPVM_RUNTIME_API_unweaken,
    SPVM_RUNTIME_API_concat,
    SPVM_RUNTIME_API_create_exception_stack_trace,
    (void*)(intptr_t)sizeof(SPVM_OBJECT), // object_header_byte_size
    (void*)(intptr_t)offsetof(SPVM_OBJECT, ref_count), // object_ref_count_byte_offset
    (void*)(intptr_t)offsetof(SPVM_OBJECT, basic_type_id), // object_basic_type_id_byte_offset
    (void*)(intptr_t)offsetof(SPVM_OBJECT, type_dimension), // object_dimension_byte_offset
    (void*)(intptr_t)offsetof(SPVM_OBJECT, elements_length), // object_elements_length_byte_offset
    SPVM_RUNTIME_call_sub,
    SPVM_RUNTIME_API_enter_scope,
    SPVM_RUNTIME_API_push_mortal,
    SPVM_RUNTIME_API_leave_scope,
    SPVM_RUNTIME_API_new_object,
    SPVM_RUNTIME_API_new_byte_array,
    SPVM_RUNTIME_API_new_short_array,
    SPVM_RUNTIME_API_new_int_array,
    SPVM_RUNTIME_API_new_long_array,
    SPVM_RUNTIME_API_new_float_array,
    SPVM_RUNTIME_API_new_double_array,
    SPVM_RUNTIME_API_new_object_array,
    SPVM_RUNTIME_API_new_multi_array,
    SPVM_RUNTIME_API_new_value_t_array,
    SPVM_RUNTIME_API_new_string,
    SPVM_RUNTIME_API_new_pointer,
    SPVM_RUNTIME_API_get_package_var_id,
    (void*)(intptr_t)offsetof(SPVM_RUNTIME, package_vars_heap), // runtime_package_vars_heap_byte_offset
    runtime,
    SPVM_RUNTIME_API_has_interface,
    (void*)(intptr_t)SPVM_BASIC_TYPE_C_ID_BYTE_OBJECT,
    (void*)(intptr_t)SPVM_BASIC_TYPE_C_ID_SHORT_OBJECT,
    (void*)(intptr_t)SPVM_BASIC_TYPE_C_ID_INT_OBJECT,
    (void*)(intptr_t)SPVM_BASIC_TYPE_C_ID_LONG_OBJECT,
    (void*)(intptr_t)SPVM_BASIC_TYPE_C_ID_FLOAT_OBJECT,
    (void*)(intptr_t)SPVM_BASIC_TYPE_C_ID_DOUBLE_OBJECT,
  };
  
  int32_t env_length = 85;
  SPVM_ENV* env = SPVM_UTIL_ALLOCATOR_safe_malloc_zero(sizeof(void*) * env_length);
  memcpy(&env[0], &env_init[0], sizeof(void*) * env_length);
  
  return env;
}

SPVM_ENV* SPVM_RUNTIME_BUILDER_build_runtime_env(SPVM_PORTABLE* portable) {
  
  SPVM_RUNTIME* runtime = SPVM_UTIL_ALLOCATOR_safe_malloc_zero(sizeof(SPVM_RUNTIME));
  
  runtime->portable = portable;
  
  SPVM_ENV* env = SPVM_RUNTIME_BUILDER_create_env(runtime);
  
  // Share runtime information with portable
  runtime->symbols = portable->symbols;
  runtime->symbols_length = portable->symbols_length;
  runtime->basic_types = (SPVM_RUNTIME_BASIC_TYPE*)portable->basic_types;
  runtime->basic_types_length = portable->basic_types_length;
  runtime->fields = (SPVM_RUNTIME_FIELD*)portable->fields;
  runtime->fields_length = portable->fields_length;
  runtime->package_vars = (SPVM_RUNTIME_PACKAGE_VAR*)portable->package_vars;
  runtime->package_vars_length = portable->package_vars_length;
  runtime->args = (SPVM_RUNTIME_MY*)portable->args;
  runtime->mys = (SPVM_RUNTIME_MY*)portable->mys;
  runtime->info_types = (SPVM_RUNTIME_INFO_TYPE*)portable->info_types;
  runtime->info_field_ids = portable->info_field_ids;
  runtime->info_package_var_ids = portable->info_package_var_ids;
  runtime->info_sub_ids = portable->info_sub_ids;
  runtime->opcodes = (SPVM_OPCODE*)portable->opcodes;
  runtime->subs = (SPVM_RUNTIME_SUB*)portable->subs;
  runtime->subs_length = portable->subs_length;

  runtime->info_long_values = portable->info_long_values;
  runtime->info_double_values = portable->info_double_values;
  runtime->info_string_values = portable->info_string_values;
  runtime->info_string_values_length = portable->info_string_values_length;
  runtime->info_string_lengths = portable->info_string_lengths;

  // Native sub addresses
  runtime->sub_native_addresses = SPVM_UTIL_ALLOCATOR_safe_malloc_zero(sizeof(void*) * (runtime->subs_length + 1));
  
  // Precompile sub addresses
  runtime->sub_precompile_addresses = SPVM_UTIL_ALLOCATOR_safe_malloc_zero(sizeof(void*) * (runtime->subs_length + 1));
  
  // build runtime info_switch_info info_switch_infos
  int32_t info_switch_info_ints_index = 0;
  runtime->info_switch_infos = SPVM_LIST_new(0);
  for (int32_t i = 0; i < portable->info_switch_infos_length; i++) {
    int32_t* portable_info_switch_info_ints = (int32_t*)&portable->info_switch_info_ints[info_switch_info_ints_index];

    SPVM_RUNTIME_INFO_SWITCH_INFO* runtime_info_switch_info = SPVM_RUNTIME_INFO_SWITCH_INFO_new();
    runtime_info_switch_info->default_opcode_rel_index = portable_info_switch_info_ints[0];
    int32_t case_infos_length = portable_info_switch_info_ints[1];
    
    runtime_info_switch_info->case_infos = SPVM_LIST_new(0);
    for (int32_t case_info_index = 0; case_info_index < case_infos_length; case_info_index++) {
      SPVM_RUNTIME_INFO_CASE_INFO* info_case_info = SPVM_RUNTIME_INFO_CASE_INFO_new();
      
      info_case_info->match = portable_info_switch_info_ints[2 + (2 * case_info_index)];
      info_case_info->opcode_rel_index = portable_info_switch_info_ints[2 + (2 * case_info_index) + 1];
      
      SPVM_LIST_push(runtime_info_switch_info->case_infos, info_case_info);
    }
    
    info_switch_info_ints_index += 2 + case_infos_length * 2;
    
    SPVM_LIST_push(runtime->info_switch_infos, runtime_info_switch_info);
  }

  // build packages
  runtime->packages_length = portable->packages_length;
  runtime->packages = SPVM_UTIL_ALLOCATOR_safe_malloc_zero(sizeof(SPVM_RUNTIME_PACKAGE) * (runtime->packages_length + 1));
  for (int32_t i = 0; i < portable->packages_unit * portable->packages_length; i += portable->packages_unit) {
    int32_t* portable_package = (int32_t*)&portable->packages[i];
    
    SPVM_RUNTIME_PACKAGE* runtime_package = &runtime->packages[i / portable->packages_unit];
    runtime_package->id = portable_package[0];
    runtime_package->name_id = portable_package[1];
    runtime_package->destructor_sub_id = portable_package[2];
    runtime_package->category = portable_package[3];
    runtime_package->load_path_id = portable_package[4];
    runtime_package->flag = portable_package[5];
  }

  // build package symtable
  runtime->package_symtable = SPVM_HASH_new(0);
  for (int32_t package_id = 0; package_id < runtime->packages_length; package_id++) {
    
    SPVM_RUNTIME_PACKAGE* package = &runtime->packages[package_id];
    const char* package_name = runtime->symbols[package->name_id];
    SPVM_HASH_insert(runtime->package_symtable, package_name, strlen(package_name), package);
    
    package->fields = SPVM_LIST_new(0);
    package->field_symtable = SPVM_HASH_new(0);
    package->field_signatures = SPVM_LIST_new(0);
    package->field_signature_symtable = SPVM_HASH_new(0);
    package->object_field_indexes = SPVM_LIST_new(0);
    package->package_vars = SPVM_LIST_new(0);
    package->package_var_symtable = SPVM_HASH_new(0);
    package->package_var_signatures = SPVM_LIST_new(0);
    package->package_var_signature_symtable = SPVM_HASH_new(0);
    package->subs = SPVM_LIST_new(0);
    package->sub_symtable = SPVM_HASH_new(0);
    package->sub_signatures = SPVM_LIST_new(0);
    package->sub_signature_symtable = SPVM_HASH_new(0);
  }

  // Register field info to package
  for (int32_t field_id = 0; field_id < runtime->fields_length; field_id++) {
    SPVM_RUNTIME_FIELD* field = &runtime->fields[field_id];
    
    int32_t package_id = field->package_id;
    
    SPVM_RUNTIME_PACKAGE* package = &runtime->packages[package_id];
    
    SPVM_LIST_push(package->fields, field);
    const char* field_name = runtime->symbols[field->name_id];
    SPVM_HASH_insert(package->field_symtable, field_name, strlen(field_name), field);
    
    const char* field_signature = runtime->symbols[field->signature_id];
    SPVM_LIST_push(package->field_signatures, (char*)field_signature);
    SPVM_HASH_insert(package->field_signature_symtable, field_signature, strlen(field_signature), field);
    
    if (SPVM_RUNTIME_API_is_object_type(env, field->basic_type_id, field->type_dimension, field->type_flag)) {
      SPVM_LIST_push(package->object_field_indexes, (void*)(intptr_t)field->index);
    }
  }
  
  // Register package_var info to package
  for (int32_t package_var_id = 0; package_var_id < runtime->package_vars_length; package_var_id++) {
    SPVM_RUNTIME_PACKAGE_VAR* package_var = &runtime->package_vars[package_var_id];
    
    int32_t package_id = package_var->package_id;
    
    SPVM_RUNTIME_PACKAGE* package = &runtime->packages[package_id];
    
    SPVM_LIST_push(package->package_vars, package_var);
    const char* package_var_name = runtime->symbols[package_var->name_id];
    SPVM_HASH_insert(package->package_var_symtable, package_var_name, strlen(package_var_name), package_var);
    
    const char* package_var_signature = runtime->symbols[package_var->signature_id];
    SPVM_LIST_push(package->package_var_signatures, (char*)package_var_signature);
    SPVM_HASH_insert(package->package_var_signature_symtable, package_var_signature, strlen(package_var_signature), package_var);
  }

  // Register sub info to package
  for (int32_t sub_id = 0; sub_id < runtime->subs_length; sub_id++) {
    SPVM_RUNTIME_SUB* sub = &runtime->subs[sub_id];
    
    
    int32_t package_id = sub->package_id;
    
    SPVM_RUNTIME_PACKAGE* package = &runtime->packages[package_id];
    
    SPVM_LIST_push(package->subs, sub);
    const char* sub_name = runtime->symbols[sub->name_id];
    SPVM_HASH_insert(package->sub_symtable, sub_name, strlen(sub_name), sub);
    
    const char* sub_signature = runtime->symbols[sub->signature_id];
    SPVM_LIST_push(package->sub_signatures, (char*)sub_signature);
    SPVM_HASH_insert(package->sub_signature_symtable, sub_signature, strlen(sub_signature), sub);
  }

  // build runtime basic type symtable
  runtime->basic_type_symtable = SPVM_HASH_new(0);
  for (int32_t basic_type_id = 0; basic_type_id < runtime->basic_types_length; basic_type_id++) {
    SPVM_RUNTIME_BASIC_TYPE* runtime_basic_type = &runtime->basic_types[basic_type_id];
    const char* runtime_basic_type_name = runtime->symbols[runtime_basic_type->name_id];
    SPVM_HASH_insert(runtime->basic_type_symtable, runtime_basic_type_name, strlen(runtime_basic_type_name), runtime_basic_type);
  }
  
  // build runtime field symtable
  runtime->field_symtable = SPVM_HASH_new(0);
  for (int32_t field_id = 0; field_id < runtime->fields_length; field_id++) {
    SPVM_RUNTIME_FIELD* runtime_field = &runtime->fields[field_id];
    const char* runtime_field_name = runtime->symbols[runtime_field->name_id];
    SPVM_HASH_insert(runtime->field_symtable, runtime_field_name, strlen(runtime_field_name), runtime_field);
  }

  // build sub symtable
  runtime->sub_symtable = SPVM_HASH_new(0);
  for (int32_t sub_id = 0; sub_id < runtime->subs_length; sub_id++) {
    SPVM_RUNTIME_SUB* sub = &runtime->subs[sub_id];
    const char* sub_abs_name = runtime->symbols[sub->abs_name_id];
    SPVM_HASH_insert(runtime->sub_symtable, sub_abs_name, strlen(sub_abs_name), sub);
  }

  // Initialize Package Variables
  runtime->package_vars_heap = SPVM_UTIL_ALLOCATOR_safe_malloc_zero(sizeof(SPVM_VALUE) * (runtime->package_vars_length + 1));

  runtime->mortal_stack_capacity = 1;

  runtime->mortal_stack = SPVM_UTIL_ALLOCATOR_safe_malloc_zero(sizeof(SPVM_OBJECT*) * runtime->mortal_stack_capacity);
  
  return env;
}
