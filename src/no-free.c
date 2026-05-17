#include "no-free.h"

#define MAGIC_NUMBER 4096 // adjust to your needs

static void* addresses[MAGIC_NUMBER];
static size_t addresses_counter = 0;

void* my_malloc(size_t size) {
    // do "fprintf(stderr, "Too many allocates!");" if you like
    if (addresses_counter == MAGIC_NUMBER) exit(-1);
    void* new_address = malloc(size);
    if (!new_address) return new_address;
    addresses[addresses_counter++] = new_address;
    return new_address;
}

void* my_calloc(size_t num, size_t size) {
    void* new_address = my_malloc(num * size);
    if (!new_address) return new_address;
    memset(new_address, 0, num * size);
    return new_address;    
}

// i don't use realloc() often anyways, so non-POSIX func signature
// WARNING: must use returned value as reallocated array. Not "void* ptr".
void* my_realloc(void* ptr, size_t old_size, size_t new_size) {
    void* new_address = my_malloc(new_size);
    if (!new_address) return new_address;
    size_t total_size = old_size > new_size ? new_size : old_size;
    memcpy(new_address, ptr, total_size);
    return new_address;
}

void free_heap() {
    for (int i = 0; i < addresses_counter; ++i) 
        free(addresses[i]);
    addresses_counter = 0;
}