#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define NUM_ALLOCS 1000

uint8_t* alloc_ptrs[NUM_ALLOCS];

void main()
{
    for (int i = 0; i < NUM_ALLOCS; ++i)
    {
        alloc_ptrs[i] = (uint8_t*)malloc(128);
        alloc_ptrs[i][0] = 13;
        alloc_ptrs[i][127] = 101;
    }

    for (int i = 0; i < NUM_ALLOCS; ++i)
    {
        assert(alloc_ptrs[i][0] == 13);
        assert(alloc_ptrs[i][127] == 101);
        free((void*)alloc_ptrs[i]);
    }

    // Regression: allocate unaligned data, then aligned data again
    uint8_t* ptr0 = (uint8_t*)malloc(3);
    uint32_t* ptr1 = (uint32_t*)malloc(4);
    *ptr1 = 333;
}
