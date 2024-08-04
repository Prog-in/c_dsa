#include "../src/ResizableArray.h"
#include "./utils/utils.h"
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

void freeResizableArray(ResizableArray *rArr) {
    if (rArr != NULL)
    {
        free(rArr->arr);
    }
    free(rArr);
}

void populateResizableArray(ResizableArray *rArr)
{
    for (unsigned i = 0; i < rArr->capacity; i++)
    {
        set(rArr, i, genRandNum()); 
    }
}

void assertInitialization(unsigned capacity)
{
    ResizableArray *rArr = initResizableArray(capacity);

    if (capacity == 0)
    {
        assert(rArr == NULL);
        return;
    }
    assert(rArr->capacity == capacity);

    // checking bounds
    populateResizableArray(rArr);

    freeResizableArray(rArr);
}

void assertInitializationWithDefaultValue(unsigned capacity, int defaultValue)
{
    ResizableArray *rArr = initResizableArrayWithDefaultValue(capacity, defaultValue);

    if (capacity == 0)
    {
        assert(rArr == NULL);
        return;
    }

    assert(rArr->capacity == capacity);

    // checking bounds and array values
    for (unsigned i = 0; i < capacity; i++)
    {
        assert(get(rArr, i) != NULL);
        assert(*get(rArr, i) == defaultValue);
    }

    freeResizableArray(rArr);
}

void assertSetting(unsigned capacity)
{
    ResizableArray *rArr = initResizableArray(capacity);

    int *data = genRandArr(capacity);
    
    for (unsigned i = 0; i < capacity; i++)
    {
        set(rArr, i, data[i]);
    }

    for (unsigned i = 0; i < capacity; i++)
    {
        assert(get(rArr, i) != NULL);
        assert(*get(rArr, i) == data[i]);
    }
    
    freeResizableArray(rArr);
    free(data);
}

void assertGetting(unsigned capacity, unsigned size)
{
    ResizableArray *rArr = initResizableArray(capacity);
    
    int *data = genRandArr(size);

    for (unsigned i = 0; i < size; i++)
    {
        set(rArr, i, data[i]);
    }

    assert(get(rArr, -1) == NULL);

    assert(get(rArr, size+1) == NULL);

    for (unsigned i = 0; i < size; i++)
    {
        assert(get(rArr, i) != NULL);
        assert(*get(rArr, i) == rArr->arr[i]);
    }

    freeResizableArray(rArr);
    free(data);
}

void assertResizing(unsigned capacity, unsigned newCapacity)
{
    ResizableArray *rArr = initResizableArray(capacity);
    populateResizableArray(rArr);
    if (capacity == 0)
    {
        assert(rArr == NULL);
        return;
    }

    int *old = malloc(capacity * sizeof(T_DATA));
    for (unsigned i = 0; i < capacity; i++)
    {
        assert(get(rArr, i) != NULL);
        old[i] = *get(rArr, i);
    }

    int *oldArr = rArr->arr;

    resize(rArr, newCapacity);

    if (newCapacity == 0)
    {
        assert(rArr->arr == oldArr);
        free(old);
        freeResizableArray(rArr);
        return;
    }

    unsigned expectedSize = rArr->size < newCapacity ? rArr->size : newCapacity;

    assert(rArr->size == expectedSize);

    for (unsigned i = 0; i < rArr->size; i++)
    {
        assert(get(rArr, i) != NULL);
        assert(*get(rArr, i) == old[i]);
    }

    free(old);
    freeResizableArray(rArr);
}

void assertPushBack(unsigned capacity)
{
    ResizableArray *rArr = initResizableArray(capacity);

    if (capacity == 0)
    {
        assert(rArr == NULL);
        return;
    }

    int *data = genRandArr(capacity + 1);

    for (unsigned i = 0; i < capacity; i++)
    {
        pushBack(rArr, data[i]);
    }

    assert(rArr->size == capacity);

    assert(rArr->capacity == capacity);

    pushBack(rArr, data[capacity]);

    assert(rArr->size == capacity + 1);

    assert(rArr->capacity == capacity * 2);

    for (unsigned i = 0; i < capacity + 1; i++)
    {
        assert(get(rArr, i) != NULL);
        assert(*get(rArr, i) == data[i]);
    }

    free(data);
    freeResizableArray(rArr);

    //testing with NULL
    pushBack(NULL, data[0]);
}

int main()
{
    srand(time(NULL));

    unsigned n = genRandNum() + 1; // positive value
    int defaultValue = genRandNum();

    // ============ initialization test ============ 
    printf("Testing ResizableArray initialization...\n");

    for (unsigned i = 0; i < n; i++)
    {
        assertInitialization(i);
        assertInitializationWithDefaultValue(i, defaultValue);
    }

    printf("ResizableArray initialization OK!\n");

    // ============ setting data test ============
    printf("Testing setting data in the ResizableArray...\n");
    
    assertSetting(n);

    printf("Setting data OK!\n");

    // ============ getting data test ============
    printf("Testing getting data from the ResizableArray...\n");

    assertGetting(n, n/2);

    printf("Getting data OK!\n");

    // ============ resizing test ============
    printf("Testing resizing the ResizableArray...\n");

    assertResizing(n, 0);

    assertResizing(n, n/2);

    assertResizing(n, n*2);

    printf("Resizing OK!\n");

    // ============ push back test ============ 
    printf("Testing pushing back data into the ResizableArray...\n");
    
    assertPushBack(n);

    printf("Push back OK!");

    return 0;
}