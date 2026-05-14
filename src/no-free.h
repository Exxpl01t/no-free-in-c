#pragma once
#include <stdlib.h>

#define MAGIC_NUMBER 1024 // adjust to your needs

void* my_malloc(size_t size);
void free_heap();

static void* addresses[MAGIC_NUMBER];
static size_t addresses_counter = 0;

void* my_malloc(size_t size) {
    // do "fprintf(stderr, "Too many allocates!");" if you like
    if (addresses_counter == MAGIC_NUMBER) exit(-1);
    void* new_address = malloc(size);
    if (!new_address) return new_address;
    addresses[addresses_counter++] = new_address;
}

void free_heap() {
    for (int i = 0; i < addresses_counter; ++i) 
        free(addresses[i]);
}