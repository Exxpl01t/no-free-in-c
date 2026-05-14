#include "no-free.h"

int main() {
    atexit(free_heap);

    // allocate memory and do not free it manually
    void* data_on_heap = my_malloc(1024);
    return 0;
}