#ifndef SPVM_BLOCK_H
#define SPVM_BLOCK_H

#include "spvm_base.h"

struct SPVM_block {
  int32_t id;
  int32_t need_leave_scope;
};

SPVM_BLOCK* SPVM_BLOCK_new(SPVM_COMPILER* compiler);

enum {
  // Block flag
  SPVM_BLOCK_C_ID_NORMAL,
  SPVM_BLOCK_C_ID_IF,
  SPVM_BLOCK_C_ID_ELSE,
  SPVM_BLOCK_C_ID_LOOP_STATEMENTS,
  SPVM_BLOCK_C_ID_SWITCH,
  SPVM_BLOCK_C_ID_SUB,
  SPVM_BLOCK_C_ID_EVAL,
  SPVM_BLOCK_C_ID_LOOP_INIT,
};

#endif