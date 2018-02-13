#include "spvm_opcode.h"
#include "spvm_compiler.h"
#include "spvm_compiler_allocator.h"































































































const char* const SPVM_OPCODE_C_CODE_NAMES[] = {
  "NOP",
  "ADD_INT",
  "ADD_LONG",
  "ADD_FLOAT",
  "ADD_DOUBLE",
  "SUBTRACT_INT",
  "SUBTRACT_LONG",
  "SUBTRACT_FLOAT",
  "SUBTRACT_DOUBLE",
  "MULTIPLY_INT",
  "MULTIPLY_LONG",
  "MULTIPLY_FLOAT",
  "MULTIPLY_DOUBLE",
  "DIVIDE_INT",
  "DIVIDE_LONG",
  "DIVIDE_FLOAT",
  "DIVIDE_DOUBLE",
  "REMAINDER_INT",
  "REMAINDER_LONG",
  "REMAINDER_FLOAT",
  "REMAINDER_DOUBLE",
  "LEFT_SHIFT_INT",
  "LEFT_SHIFT_LONG",
  "RIGHT_SHIFT_INT",
  "RIGHT_SHIFT_LONG",
  "RIGHT_SHIFT_UNSIGNED_INT",
  "RIGHT_SHIFT_UNSIGNED_LONG",
  "BIT_AND_INT",
  "BIT_AND_LONG",
  "BIT_OR_INT",
  "BIT_OR_LONG",
  "BIT_XOR_INT",
  "BIT_XOR_LONG",
  "COMPLEMENT_INT",
  "COMPLEMENT_LONG",
  "NEGATE_INT",
  "NEGATE_LONG",
  "NEGATE_FLOAT",
  "NEGATE_DOUBLE",
  "CONVERT_BYTE_TO_SHORT",
  "CONVERT_BYTE_TO_INT",
  "CONVERT_BYTE_TO_LONG",
  "CONVERT_BYTE_TO_FLOAT",
  "CONVERT_BYTE_TO_DOUBLE",
  "CONVERT_SHORT_TO_BYTE",
  "CONVERT_SHORT_TO_INT",
  "CONVERT_SHORT_TO_LONG",
  "CONVERT_SHORT_TO_FLOAT",
  "CONVERT_SHORT_TO_DOUBLE",
  "CONVERT_INT_TO_BYTE",
  "CONVERT_INT_TO_SHORT",
  "CONVERT_INT_TO_LONG",
  "CONVERT_INT_TO_FLOAT",
  "CONVERT_INT_TO_DOUBLE",
  "CONVERT_LONG_TO_BYTE",
  "CONVERT_LONG_TO_SHORT",
  "CONVERT_LONG_TO_INT",
  "CONVERT_LONG_TO_FLOAT",
  "CONVERT_LONG_TO_DOUBLE",
  "CONVERT_FLOAT_TO_BYTE",
  "CONVERT_FLOAT_TO_SHORT",
  "CONVERT_FLOAT_TO_INT",
  "CONVERT_FLOAT_TO_LONG",
  "CONVERT_FLOAT_TO_DOUBLE",
  "CONVERT_DOUBLE_TO_BYTE",
  "CONVERT_DOUBLE_TO_SHORT",
  "CONVERT_DOUBLE_TO_INT",
  "CONVERT_DOUBLE_TO_LONG",
  "CONVERT_DOUBLE_TO_FLOAT",
  "CONVERT_BYTE_TO_BYTE",
  "CONVERT_SHORT_TO_SHORT",
  "CONVERT_INT_TO_INT",
  "CONVERT_LONG_TO_LONG",
  "CONVERT_FLOAT_TO_FLOAT",
  "CONVERT_DOUBLE_TO_DOUBLE",
  "GT_BYTE",
  "GT_SHORT",
  "GT_INT",
  "GT_LONG",
  "GT_FLOAT",
  "GT_DOUBLE",
  "GE_BYTE",
  "GE_SHORT",
  "GE_INT",
  "GE_LONG",
  "GE_FLOAT",
  "GE_DOUBLE",
  "LT_BYTE",
  "LT_SHORT",
  "LT_INT",
  "LT_LONG",
  "LT_FLOAT",
  "LT_DOUBLE",
  "LE_BYTE",
  "LE_SHORT",
  "LE_INT",
  "LE_LONG",
  "LE_FLOAT",
  "LE_DOUBLE",
  "IS_UNDEF",
  "IS_NOT_UNDEF",
  "EQ_BYTE",
  "EQ_SHORT",
  "EQ_INT",
  "EQ_LONG",
  "EQ_FLOAT",
  "EQ_DOUBLE",
  "EQ_OBJECT",
  "NE_BYTE",
  "NE_SHORT",
  "NE_INT",
  "NE_LONG",
  "NE_FLOAT",
  "NE_DOUBLE",
  "NE_OBJECT",
  "INC_BYTE",
  "INC_SHORT",
  "INC_INT",
  "INC_LONG",
  "BOOL_BYTE",
  "BOOL_SHORT",
  "BOOL_INT",
  "BOOL_LONG",
  "BOOL_FLOAT",
  "BOOL_DOUBLE",
  "BOOL_OBJECT",
  "LOAD_UNDEF",
  "MOVE",
  "NEW_OBJECT",
  "NEW_STRING",
  "NEW_OBJECT_ARRAY",
  "ARRAY_LOAD_BYTE",
  "ARRAY_LOAD_SHORT",
  "ARRAY_LOAD_INT",
  "ARRAY_LOAD_LONG",
  "ARRAY_LOAD_FLOAT",
  "ARRAY_LOAD_DOUBLE",
  "ARRAY_LOAD_OBJECT",
  "ARRAY_STORE_BYTE",
  "ARRAY_STORE_SHORT",
  "ARRAY_STORE_INT",
  "ARRAY_STORE_LONG",
  "ARRAY_STORE_FLOAT",
  "ARRAY_STORE_DOUBLE",
  "ARRAY_STORE_OBJECT",
  "ARRAY_LENGTH",
  "GET_FIELD_BYTE",
  "GET_FIELD_SHORT",
  "GET_FIELD_INT",
  "GET_FIELD_LONG",
  "GET_FIELD_FLOAT",
  "GET_FIELD_DOUBLE",
  "GET_FIELD_OBJECT",
  "SET_FIELD_BYTE",
  "SET_FIELD_SHORT",
  "SET_FIELD_INT",
  "SET_FIELD_LONG",
  "SET_FIELD_FLOAT",
  "SET_FIELD_DOUBLE",
  "SET_FIELD_OBJECT",
  "IF_EQ_ZERO",
  "IF_NE_ZERO",
  "TABLE_SWITCH",
  "TABLE_SWITCH_RANGE",
  "LOOKUP_SWITCH",
  "GOTO",
  "CALL_SUB",
  "RETURN",
  "CROAK",
  "LOAD_EXCEPTION_VAR",
  "STORE_EXCEPTION_VAR",
  "CURRENT_LINE",
  "WEAKEN_FIELD",
  "NEW_BYTE_ARRAY",
  "NEW_SHORT_ARRAY",
  "NEW_INT_ARRAY",
  "NEW_LONG_ARRAY",
  "NEW_FLOAT_ARRAY",
  "NEW_DOUBLE_ARRAY",
  "CONCAT_STRING_STRING",
  "CONCAT_STRING_BYTE",
  "CONCAT_STRING_SHORT",
  "CONCAT_STRING_INT",
  "CONCAT_STRING_LONG",
  "CONCAT_STRING_FLOAT",
  "CONCAT_STRING_DOUBLE",
  "PUSH_EVAL",
  "POP_EVAL",
  "PUSH_ARG",
  "INC_REF_COUNT",
  "DEC_REF_COUNT",
  "LOAD_PACKAGE_VAR_BYTE",
  "LOAD_PACKAGE_VAR_SHORT",
  "LOAD_PACKAGE_VAR_INT",
  "LOAD_PACKAGE_VAR_LONG",
  "LOAD_PACKAGE_VAR_FLOAT",
  "LOAD_PACKAGE_VAR_DOUBLE",
  "LOAD_PACKAGE_VAR_OBJECT",
  "STORE_PACKAGE_VAR_BYTE",
  "STORE_PACKAGE_VAR_SHORT",
  "STORE_PACKAGE_VAR_INT",
  "STORE_PACKAGE_VAR_LONG",
  "STORE_PACKAGE_VAR_FLOAT",
  "STORE_PACKAGE_VAR_DOUBLE",
  "STORE_PACKAGE_VAR_OBJECT",
  "LOAD_CONSTANT_BYTE",
  "LOAD_CONSTANT_SHORT",
  "LOAD_CONSTANT_INT",
  "LOAD_CONSTANT_LONG",
  "LOAD_CONSTANT_FLOAT",
  "LOAD_CONSTANT_DOUBLE",
  "LOAD_CONSTANT_BYTE_0",
  "LOAD_CONSTANT_SHORT_0",
  "LOAD_CONSTANT_INT_0",
  "LOAD_CONSTANT_LONG_0",
  "LOAD_CONSTANT_FLOAT_0",
  "LOAD_CONSTANT_DOUBLE_0",
  "CASE",
  "IF_CROAK_CATCH",
  "IF_CROAK_RETURN",
  "SET_CROAK_FLAG_TRUE",
  "MOVE_BYTE",
  "MOVE_SHORT",
  "MOVE_INT",
  "MOVE_LONG",
  "MOVE_FLOAT",
  "MOVE_DOUBLE",
  "MOVE_OBJECT",
  "PUSH_AUTO_DEC_REF_COUNT",
  "LEAVE_SCOPE",
};

SPVM_OPCODE* SPVM_OPCODE_new(SPVM_COMPILER* compiler) {
  SPVM_OPCODE* opcode = SPVM_COMPILER_ALLOCATOR_alloc_memory_pool(compiler, compiler->allocator, sizeof(SPVM_OPCODE));
  
  return opcode;
}
