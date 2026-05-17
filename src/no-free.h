#pragma once
#include <stdlib.h>
#include <string.h>

void* my_malloc(size_t size);
void* my_calloc(size_t num, size_t size);
void* my_realloc(void* ptr, size_t old_size, size_t new_size);
void free_heap();