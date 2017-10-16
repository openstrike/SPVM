#ifndef SPVM_CALL_FIELD_H
#define SPVM_CALL_FIELD_H

#include "spvm_base.h"

enum {
  SPVM_CALL_FIELD_C_CODE_VARBASENAME,
  SPVM_CALL_FIELD_C_CODE_BASENAME,
  SPVM_CALL_FIELD_C_CODE_ABSNAME,
};

struct SPVM_call_field {
  SPVM_OP* op_var;
  SPVM_OP* op_name;
  const char* resolved_name;
  int32_t code;
  int32_t id;
};

SPVM_CALL_FIELD* SPVM_CALL_FIELD_new(SPVM_COMPILER* compiler);

#endif
