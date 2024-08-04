#include "ResizableArray.h"
#include <stdlib.h>

void resize(ResizableArray *rArr, unsigned newCapacity)
{
    if (rArr == NULL || newCapacity == 0)
    {
        return;
    }

    T_DATA *new_arr = realloc(rArr->arr, newCapacity * sizeof(T_DATA));

    if (new_arr != NULL)
    {
        // couldn't resize the same memory block
        if (new_arr != rArr->arr)
        {
            free(rArr->arr);
            rArr->arr = new_arr;
        }

        rArr->capacity = newCapacity;

        if (newCapacity < rArr->size)
        {
            rArr->size = newCapacity;
        }
    }
}

ResizableArray* initResizableArray(unsigned capacity)
{
    ResizableArray* rArr;

    if (capacity == 0)
    {
        rArr = NULL;
    }
    else
    {
        rArr = malloc(sizeof(ResizableArray));
    }

    if (rArr != NULL)
    {
        rArr->size = 0;
        rArr->capacity = capacity;
        rArr->arr = malloc(capacity * sizeof(T_DATA));

        if (rArr->arr == NULL)
        {
            return NULL;  
        } 
    }
    return rArr;
}

ResizableArray* initResizableArrayWithDefaultValue(unsigned capacity, T_DATA defaultValue)
{
    ResizableArray* rArr;
    if (capacity == 0)
    {
        rArr = NULL;
    }
    else
    {
        rArr = malloc(sizeof(ResizableArray));
    }

    if (rArr != NULL)
    {
        rArr->size = capacity;
        rArr->capacity = capacity;
        rArr->arr = malloc(capacity * sizeof(T_DATA));

        if (rArr->arr == NULL)
        {
            return NULL;  
        } 

        for (unsigned i = 0; i < rArr->capacity; i++)
        {
            rArr->arr[i] = defaultValue;
        }
    }
    return rArr;
}

void pushBack(ResizableArray* rArr, T_DATA data)
{
    if (rArr == NULL)
    {
        return;
    }
    
    if (rArr->size == rArr->capacity)
    {
        resize(rArr, rArr->capacity*2);
    }
    rArr->arr[rArr->size++] = data;
}

T_DATA* get(ResizableArray* rArr, unsigned i)
{
    if (rArr == NULL || i >= rArr->size)
    {
        return NULL;
    }

    return &rArr->arr[i];
}

void set(ResizableArray* rArr, unsigned i, T_DATA data)
{
    if (rArr == NULL || i >= rArr->capacity)
    {
        return;
    }

    if (i > rArr->size)
    {
        return;
    }
    if (i == rArr->size)
    {
        rArr->arr[rArr->size++] = data;
    }
    else
    {
        rArr->arr[i] = data;
    }
}