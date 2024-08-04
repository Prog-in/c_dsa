#ifndef RESIZEABLE_ARRAY_H
#define RESIZEABLE_ARRAY_H

// type of the data in ResizableArray
#define T_DATA int

typedef struct ResizableArray {
    unsigned capacity;
    unsigned size;
    T_DATA *arr;
} ResizableArray;

/*  */
ResizableArray* initResizableArray(unsigned capacity);

/*  */
ResizableArray* initResizableArrayWithDefaultValue(unsigned capacity, T_DATA defaultValue);

/*  */
void resize(ResizableArray *rArr, unsigned newCapacity);

/*  */
void pushBack(ResizableArray* rArr, T_DATA data);

/*  */
T_DATA* get(ResizableArray* rArr, unsigned i);

/*  */
void set(ResizableArray* rArr, unsigned i, T_DATA data);

#endif // RESIZEABLE_ARRAY_H