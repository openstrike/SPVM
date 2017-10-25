#ifndef SPVM_BYTECODE_H
#define SPVM_BYTECODE_H

#include "spvm_base.h"






























































































enum {
  SPVM_BYTECODE_C_CODE_NOP,
  SPVM_BYTECODE_C_CODE_UNDEF,
  SPVM_BYTECODE_C_CODE_PUSH_BYTE,
  SPVM_BYTECODE_C_CODE_PUSH_BYTE_TO_SHORT,
  SPVM_BYTECODE_C_CODE_PUSH_SHORT,
  SPVM_BYTECODE_C_CODE_PUSH_BYTE_TO_INT,
  SPVM_BYTECODE_C_CODE_PUSH_SHORT_TO_INT,
  SPVM_BYTECODE_C_CODE_PUSH_BYTE_TO_LONG,
  SPVM_BYTECODE_C_CODE_PUSH_SHORT_TO_LONG,
  SPVM_BYTECODE_C_CODE_LOAD_CONSTANT,
  SPVM_BYTECODE_C_CODE_LOAD_CONSTANT2,
  SPVM_BYTECODE_C_CODE_ADD_BYTE,
  SPVM_BYTECODE_C_CODE_ADD_SHORT,
  SPVM_BYTECODE_C_CODE_ADD_INT,
  SPVM_BYTECODE_C_CODE_ADD_LONG,
  SPVM_BYTECODE_C_CODE_ADD_FLOAT,
  SPVM_BYTECODE_C_CODE_ADD_DOUBLE,
  SPVM_BYTECODE_C_CODE_SUBTRACT_BYTE,
  SPVM_BYTECODE_C_CODE_SUBTRACT_SHORT,
  SPVM_BYTECODE_C_CODE_SUBTRACT_INT,
  SPVM_BYTECODE_C_CODE_SUBTRACT_LONG,
  SPVM_BYTECODE_C_CODE_SUBTRACT_FLOAT,
  SPVM_BYTECODE_C_CODE_SUBTRACT_DOUBLE,
  SPVM_BYTECODE_C_CODE_MULTIPLY_BYTE,
  SPVM_BYTECODE_C_CODE_MULTIPLY_SHORT,
  SPVM_BYTECODE_C_CODE_MULTIPLY_INT,
  SPVM_BYTECODE_C_CODE_MULTIPLY_LONG,
  SPVM_BYTECODE_C_CODE_MULTIPLY_FLOAT,
  SPVM_BYTECODE_C_CODE_MULTIPLY_DOUBLE,
  SPVM_BYTECODE_C_CODE_DIVIDE_BYTE,
  SPVM_BYTECODE_C_CODE_DIVIDE_SHORT,
  SPVM_BYTECODE_C_CODE_DIVIDE_INT,
  SPVM_BYTECODE_C_CODE_DIVIDE_LONG,
  SPVM_BYTECODE_C_CODE_DIVIDE_FLOAT,
  SPVM_BYTECODE_C_CODE_DIVIDE_DOUBLE,
  SPVM_BYTECODE_C_CODE_REMAINDER_BYTE,
  SPVM_BYTECODE_C_CODE_REMAINDER_SHORT,
  SPVM_BYTECODE_C_CODE_REMAINDER_INT,
  SPVM_BYTECODE_C_CODE_REMAINDER_LONG,
  SPVM_BYTECODE_C_CODE_REMAINDER_FLOAT,
  SPVM_BYTECODE_C_CODE_REMAINDER_DOUBLE,
  SPVM_BYTECODE_C_CODE_NEGATE_BYTE,
  SPVM_BYTECODE_C_CODE_NEGATE_SHORT,
  SPVM_BYTECODE_C_CODE_NEGATE_INT,
  SPVM_BYTECODE_C_CODE_NEGATE_LONG,
  SPVM_BYTECODE_C_CODE_NEGATE_FLOAT,
  SPVM_BYTECODE_C_CODE_NEGATE_DOUBLE,
  SPVM_BYTECODE_C_CODE_LEFT_SHIFT_BYTE,
  SPVM_BYTECODE_C_CODE_LEFT_SHIFT_SHORT,
  SPVM_BYTECODE_C_CODE_LEFT_SHIFT_INT,
  SPVM_BYTECODE_C_CODE_LEFT_SHIFT_LONG,
  SPVM_BYTECODE_C_CODE_RIGHT_SHIFT_BYTE,
  SPVM_BYTECODE_C_CODE_RIGHT_SHIFT_SHORT,
  SPVM_BYTECODE_C_CODE_RIGHT_SHIFT_INT,
  SPVM_BYTECODE_C_CODE_RIGHT_SHIFT_LONG,
  SPVM_BYTECODE_C_CODE_RIGHT_SHIFT_UNSIGNED_BYTE,
  SPVM_BYTECODE_C_CODE_RIGHT_SHIFT_UNSIGNED_SHORT,
  SPVM_BYTECODE_C_CODE_RIGHT_SHIFT_UNSIGNED_INT,
  SPVM_BYTECODE_C_CODE_RIGHT_SHIFT_UNSIGNED_LONG,
  SPVM_BYTECODE_C_CODE_BIT_AND_BYTE,
  SPVM_BYTECODE_C_CODE_BIT_AND_SHORT,
  SPVM_BYTECODE_C_CODE_BIT_AND_INT,
  SPVM_BYTECODE_C_CODE_BIT_AND_LONG,
  SPVM_BYTECODE_C_CODE_BIT_OR_BYTE ,
  SPVM_BYTECODE_C_CODE_BIT_OR_SHORT ,
  SPVM_BYTECODE_C_CODE_BIT_OR_INT,
  SPVM_BYTECODE_C_CODE_BIT_OR_LONG,
  SPVM_BYTECODE_C_CODE_BIT_XOR_BYTE,
  SPVM_BYTECODE_C_CODE_BIT_XOR_SHORT,
  SPVM_BYTECODE_C_CODE_BIT_XOR_INT,
  SPVM_BYTECODE_C_CODE_BIT_XOR_LONG,
  SPVM_BYTECODE_C_CODE_CONVERT_BYTE_TO_SHORT,
  SPVM_BYTECODE_C_CODE_CONVERT_BYTE_TO_INT,
  SPVM_BYTECODE_C_CODE_CONVERT_BYTE_TO_LONG,
  SPVM_BYTECODE_C_CODE_CONVERT_BYTE_TO_FLOAT,
  SPVM_BYTECODE_C_CODE_CONVERT_BYTE_TO_DOUBLE,
  SPVM_BYTECODE_C_CODE_CONVERT_SHORT_TO_BYTE,
  SPVM_BYTECODE_C_CODE_CONVERT_SHORT_TO_INT,
  SPVM_BYTECODE_C_CODE_CONVERT_SHORT_TO_LONG,
  SPVM_BYTECODE_C_CODE_CONVERT_SHORT_TO_FLOAT,
  SPVM_BYTECODE_C_CODE_CONVERT_SHORT_TO_DOUBLE,
  SPVM_BYTECODE_C_CODE_CONVERT_INT_TO_BYTE,
  SPVM_BYTECODE_C_CODE_CONVERT_INT_TO_SHORT,
  SPVM_BYTECODE_C_CODE_CONVERT_INT_TO_LONG,
  SPVM_BYTECODE_C_CODE_CONVERT_INT_TO_FLOAT,
  SPVM_BYTECODE_C_CODE_CONVERT_INT_TO_DOUBLE,
  SPVM_BYTECODE_C_CODE_CONVERT_LONG_TO_BYTE,
  SPVM_BYTECODE_C_CODE_CONVERT_LONG_TO_SHORT,
  SPVM_BYTECODE_C_CODE_CONVERT_LONG_TO_INT,
  SPVM_BYTECODE_C_CODE_CONVERT_LONG_TO_FLOAT,
  SPVM_BYTECODE_C_CODE_CONVERT_LONG_TO_DOUBLE,
  SPVM_BYTECODE_C_CODE_CONVERT_FLOAT_TO_BYTE,
  SPVM_BYTECODE_C_CODE_CONVERT_FLOAT_TO_SHORT,
  SPVM_BYTECODE_C_CODE_CONVERT_FLOAT_TO_INT,
  SPVM_BYTECODE_C_CODE_CONVERT_FLOAT_TO_LONG,
  SPVM_BYTECODE_C_CODE_CONVERT_FLOAT_TO_DOUBLE,
  SPVM_BYTECODE_C_CODE_CONVERT_DOUBLE_TO_BYTE,
  SPVM_BYTECODE_C_CODE_CONVERT_DOUBLE_TO_SHORT,
  SPVM_BYTECODE_C_CODE_CONVERT_DOUBLE_TO_INT,
  SPVM_BYTECODE_C_CODE_CONVERT_DOUBLE_TO_LONG,
  SPVM_BYTECODE_C_CODE_CONVERT_DOUBLE_TO_FLOAT,
  SPVM_BYTECODE_C_CODE_INC_BYTE,
  SPVM_BYTECODE_C_CODE_INC_SHORT,
  SPVM_BYTECODE_C_CODE_INC_INT,
  SPVM_BYTECODE_C_CODE_INC_LONG,
  SPVM_BYTECODE_C_CODE_LOAD,
  SPVM_BYTECODE_C_CODE_STORE,
  SPVM_BYTECODE_C_CODE_STORE_OBJECT,
  SPVM_BYTECODE_C_CODE_POP,
  SPVM_BYTECODE_C_CODE_NEW_OBJECT,
  SPVM_BYTECODE_C_CODE_NEW_STRING,
  SPVM_BYTECODE_C_CODE_NEW_OBJECT_ARRAY,
  SPVM_BYTECODE_C_CODE_ARRAY_LOAD_BYTE,
  SPVM_BYTECODE_C_CODE_ARRAY_LOAD_SHORT,
  SPVM_BYTECODE_C_CODE_ARRAY_LOAD_INT,
  SPVM_BYTECODE_C_CODE_ARRAY_LOAD_LONG,
  SPVM_BYTECODE_C_CODE_ARRAY_LOAD_FLOAT,
  SPVM_BYTECODE_C_CODE_ARRAY_LOAD_DOUBLE,
  SPVM_BYTECODE_C_CODE_ARRAY_LOAD_OBJECT,
  SPVM_BYTECODE_C_CODE_ARRAY_STORE_BYTE,
  SPVM_BYTECODE_C_CODE_ARRAY_STORE_SHORT,
  SPVM_BYTECODE_C_CODE_ARRAY_STORE_INT,
  SPVM_BYTECODE_C_CODE_ARRAY_STORE_LONG,
  SPVM_BYTECODE_C_CODE_ARRAY_STORE_FLOAT,
  SPVM_BYTECODE_C_CODE_ARRAY_STORE_DOUBLE,
  SPVM_BYTECODE_C_CODE_ARRAY_STORE_OBJECT,
  SPVM_BYTECODE_C_CODE_ARRAY_LENGTH,
  SPVM_BYTECODE_C_CODE_GET_FIELD_BYTE,
  SPVM_BYTECODE_C_CODE_GET_FIELD_SHORT,
  SPVM_BYTECODE_C_CODE_GET_FIELD_INT,
  SPVM_BYTECODE_C_CODE_GET_FIELD_LONG,
  SPVM_BYTECODE_C_CODE_GET_FIELD_FLOAT,
  SPVM_BYTECODE_C_CODE_GET_FIELD_DOUBLE,
  SPVM_BYTECODE_C_CODE_GET_FIELD_OBJECT,
  SPVM_BYTECODE_C_CODE_SET_FIELD_BYTE,
  SPVM_BYTECODE_C_CODE_SET_FIELD_SHORT,
  SPVM_BYTECODE_C_CODE_SET_FIELD_INT,
  SPVM_BYTECODE_C_CODE_SET_FIELD_LONG,
  SPVM_BYTECODE_C_CODE_SET_FIELD_FLOAT,
  SPVM_BYTECODE_C_CODE_SET_FIELD_DOUBLE,
  SPVM_BYTECODE_C_CODE_SET_FIELD_OBJECT,
  SPVM_BYTECODE_C_CODE_CMP_BYTE,
  SPVM_BYTECODE_C_CODE_CMP_SHORT,
  SPVM_BYTECODE_C_CODE_CMP_LONG,
  SPVM_BYTECODE_C_CODE_CMP_FLOAT_L,
  SPVM_BYTECODE_C_CODE_CMP_FLOAT_G,
  SPVM_BYTECODE_C_CODE_CMP_DOUBLE_L,
  SPVM_BYTECODE_C_CODE_CMP_DOUBLE_G,
  SPVM_BYTECODE_C_CODE_IF_EQ_ZERO,
  SPVM_BYTECODE_C_CODE_IF_NE_ZERO,
  SPVM_BYTECODE_C_CODE_IF_LT_ZERO,
  SPVM_BYTECODE_C_CODE_IF_GE_ZERO,
  SPVM_BYTECODE_C_CODE_IF_GT_ZERO,
  SPVM_BYTECODE_C_CODE_IF_LE_ZERO,
  SPVM_BYTECODE_C_CODE_IF_EQ_CMP,
  SPVM_BYTECODE_C_CODE_IF_NE_CMP,
  SPVM_BYTECODE_C_CODE_IF_LT_CMP,
  SPVM_BYTECODE_C_CODE_IF_GE_CMP,
  SPVM_BYTECODE_C_CODE_IF_GT_CMP,
  SPVM_BYTECODE_C_CODE_IF_LE_CMP,
  SPVM_BYTECODE_C_CODE_IF_EQ_CMP_OBJECT,
  SPVM_BYTECODE_C_CODE_IF_NE_CMP_OBJECT,
  SPVM_BYTECODE_C_CODE_IF_NULL,
  SPVM_BYTECODE_C_CODE_IF_NON_NULL,
  SPVM_BYTECODE_C_CODE_TABLE_SWITCH,
  SPVM_BYTECODE_C_CODE_LOOKUP_SWITCH,
  SPVM_BYTECODE_C_CODE_GOTO,
  SPVM_BYTECODE_C_CODE_CALL_SUB,
  SPVM_BYTECODE_C_CODE_RETURN_VOID,
  SPVM_BYTECODE_C_CODE_RETURN_BYTE,
  SPVM_BYTECODE_C_CODE_RETURN_SHORT,
  SPVM_BYTECODE_C_CODE_RETURN_INT,
  SPVM_BYTECODE_C_CODE_RETURN_LONG,
  SPVM_BYTECODE_C_CODE_RETURN_FLOAT,
  SPVM_BYTECODE_C_CODE_RETURN_DOUBLE,
  SPVM_BYTECODE_C_CODE_RETURN_OBJECT,
  SPVM_BYTECODE_C_CODE_CROAK,
  SPVM_BYTECODE_C_CODE_LOAD_EXCEPTION,
  SPVM_BYTECODE_C_CODE_STORE_EXCEPTION,
  SPVM_BYTECODE_C_CODE_WIDE,
  SPVM_BYTECODE_C_CODE_CURRENT_LINE,
  SPVM_BYTECODE_C_CODE_WEAKEN_FIELD_OBJECT,
  SPVM_BYTECODE_C_CODE_NEW_BYTE_ARRAY,
  SPVM_BYTECODE_C_CODE_NEW_SHORT_ARRAY,
  SPVM_BYTECODE_C_CODE_NEW_INT_ARRAY,
  SPVM_BYTECODE_C_CODE_NEW_LONG_ARRAY,
  SPVM_BYTECODE_C_CODE_NEW_FLOAT_ARRAY,
  SPVM_BYTECODE_C_CODE_NEW_DOUBLE_ARRAY,
  SPVM_BYTECODE_C_CODE_CONCAT_STRING_STRING,
  SPVM_BYTECODE_C_CODE_CONCAT_STRING_BYTE,
  SPVM_BYTECODE_C_CODE_CONCAT_STRING_SHORT,
  SPVM_BYTECODE_C_CODE_CONCAT_STRING_INT,
  SPVM_BYTECODE_C_CODE_CONCAT_STRING_LONG,
  SPVM_BYTECODE_C_CODE_CONCAT_STRING_FLOAT,
  SPVM_BYTECODE_C_CODE_CONCAT_STRING_DOUBLE,
  SPVM_BYTECODE_C_CODE_PUSH_CATCH_EXCEPTION,
  SPVM_BYTECODE_C_CODE_POP_CATCH_EXCEPTION,
  SPVM_BYTECODE_C_CODE_LOAD_PACKAGE_VAR,
  SPVM_BYTECODE_C_CODE_STORE_PACKAGE_VAR,
  SPVM_BYTECODE_C_CODE_STORE_PACKAGE_VAR_OBJECT,
};

extern const char* const SPVM_BYTECODE_C_CODE_NAMES[];

#endif
