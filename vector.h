#include <stdio.h>
#include <stdlib.h>

#define DEFINE_VECTOR_TYPE(type) \
    typedef struct { \
        type *array; \
        size_t length; \
        size_t capacity; \
    } type##Vector;

#define CreateVector(type, name, initial_capacity) \
    type##Vector* name = (type##Vector*) malloc(sizeof(type##Vector)); \
    if (!name) { \
        fprintf(stderr, "Memory allocation failed\n"); \
        exit(1); \
    } \
    name->length = 0; \
    name->capacity = initial_capacity; \
    name->array = (type*) calloc(initial_capacity, sizeof(type)); \
    if (!name->array) { \
        fprintf(stderr, "Memory allocation failed\n"); \
        exit(1); \
    }

#define DEFINE_VECTOR_FUNCTIONS(type) \
    void push_##type(type##Vector* vector, type value) { \
        if (vector->length >= vector->capacity) { \
            vector->capacity *= 2; \
            vector->array = (type*) realloc(vector->array, vector->capacity * sizeof(type)); \
            if (!vector->array) { \
                fprintf(stderr, "Memory reallocation failed\n"); \
                exit(1); \
            } \
        } \
        vector->array[vector->length++] = value; \
    } \
    \
    type at_##type(type##Vector* vector, size_t index) { \
        if (index >= vector->length) { \
            fprintf(stderr, "Index out of bounds: %zu\n", index); \
            exit(1); \
        } \
        return vector->array[index]; \
    } \
    \
    void pop_##type(type##Vector* vector) { \
        if (vector->length == 0) { \
            fprintf(stderr, "Pop from empty vector\n"); \
            exit(1); \
        } \
        vector->length--; \
    } \
    \
    type* begin_##type(type##Vector* vector) { \
        return vector->array; \
    } \
    \
    type* end_##type(type##Vector* vector) { \
        return vector->array + vector->length; \
    } \
    \
    void free_##type##_vector(type##Vector* vector) { \
        free(vector->array); \
        free(vector); \
    }

DEFINE_VECTOR_TYPE(int)
DEFINE_VECTOR_FUNCTIONS(int)

int main() {
    CreateVector(int, myVector, 10);
    
    push_int(myVector, 1);
    push_int(myVector, 2);
    push_int(myVector, 3);
    
    printf("Element at index 1: %d\n", at_int(myVector, 1));
    
    pop_int(myVector);
    
    for (int *it = begin_int(myVector); it != end_int(myVector); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
    
    free_int_vector(myVector);

    return 0;
}
