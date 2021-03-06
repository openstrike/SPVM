#include <stdio.h>

#include "spvm_runtime_allocator.h"
#include "spvm_util_allocator.h"
#include "spvm_runtime.h"

void* SPVM_RUNTIME_ALLOCATOR_alloc_memory_block_zero(SPVM_RUNTIME* runtime, size_t byte_size) {
  (void)runtime;
  
  void* block = SPVM_UTIL_ALLOCATOR_safe_malloc_zero(byte_size);
  runtime->memory_blocks_count++;
  
#ifdef SPVM_DEBUG_OBJECT_COUNT
  fprintf(stderr, "[INC_MEMORY_BLOCK_CNT] %d\n", runtime->memory_blocks_count);
#endif
  
  return block;
}

void SPVM_RUNTIME_ALLOCATOR_free_memory_block(SPVM_RUNTIME* runtime, void* block) {
  (void)runtime;
  
  if (block) {
    free(block);
    runtime->memory_blocks_count--;
    
#ifdef SPVM_DEBUG_OBJECT_COUNT
    fprintf(stderr, "[INC_MEMORY_BLOCK_CNT] %d\n", runtime->memory_blocks_count);
#endif
  }
}
