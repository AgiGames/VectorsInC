#include <stdio.h>
#include <stdlib.h>

#define DEFINE_VECTOR_TYPE(type) \
    typedef struct { \
        type *array; \
        int length; \
    } type##Vector; \

#define CreateVector(type, name, size) \
    type##Vector* name = (type##Vector*) malloc(sizeof(type##Vector)); \
    if (name == NULL) { \
        fprintf(stderr, "Memory allocation failed\n"); \
        exit(1); \
    } \
    name->length = size; \
    name->array = (type*) calloc(size, sizeof(type)); \
    if (name->array == NULL) { \
        fprintf(stderr, "Memory allocation failed\n"); \
        exit(1); \
    } \

#define DEFINE_VECTOR_FUNCTIONS(type) \
    void push(type##Vector* vector, type value) { \
        vector->length++; \
        vector->array = (type*) realloc(vector->array, vector->length * sizeof(type)); \
        if (vector->array == NULL) { \
            fprintf(stderr, "Memory reallocation failed\n"); \
            exit(1); \
        } \
        for(int i = 0; i < vector->length - 1; i++){ \
            vector->array[i+1] = vector->array[i]; \
        } \
        vector->array[0] = value; \
    } \
    \
    type at(type##Vector* vector, size_t index) { \
        if (index >= vector->length) { \
            fprintf(stderr, "Index out of bounds\n"); \
            exit(1); \
        } \
        return vector->array[index]; \
    } \
    \
    void pop(type##Vector* vector) { \
        vector->length--; \
    } \
