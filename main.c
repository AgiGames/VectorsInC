#include "vector.h"

DEFINE_VECTOR_TYPE(int);
DEFINE_VECTOR_FUNCTIONS(int);

int main(){
    printf("VECTOR CLASS IN C IMPLEMENTATION!\n");
    CreateVector(int, myVector, 3);
    push(myVector, 3);
    pop(myVector);
    for(int i = 0; i < myVector->length; i++)
        printf("%d\t", at(myVector, i));
    printf("\n");
    printf("%d\t", at(myVector, 5));
    int* beginPtr = begin(myVector);
    printf("%d\n", *(beginPtr));
    int* endPtr = end(myVector);
    printf("%d\n", *(endPtr));
    return 0;
}