#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array.h"

const int BLOCK_SIZE = 10;
// typedef struct {
//     int *array;
//     int size;
// } Array;

Array array_create( int init_size)          //  创建数组
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size);
    return a;
}

void array_free( Array *a)                  //  释放数组内存
{
    free (a->array);
    a->array = NULL;
    a->size = 0;
}

int array_size( const Array *a)             //  查看数组大小
{
    return a->size;
}

int* array_at( Array *a, int index)         //  访问数组单元
{
    if ( index >= a->size){
        array_inflate( a, (index/BLOCK_SIZE+1)*BLOCK_SIZE - (a->size));
    }
    return &(a->array[index]);
}

void array_inflate(Array *a, int more_size) //  数组增大
{
    int *p = (int*) malloc(sizeof(int) * (a->size + more_size));
    int i=0;
    // for( i=0; i<a->size; i++){
    //     p[i] = a->array[i];
    // }
    memcpy( p, a->array, sizeof(int) * (a->size));
    free( a->array);
    a->array = p;
    a->size += more_size;
}

int main(int argc, char *argv[])
{
    Array a = array_create( 100);
    printf("%d\n",array_size(&a));
    *array_at(&a, 10) = 66;
    printf("%d\n",*array_at(&a, 10));

    for( int i=0; i<200; i++) {
        *array_at( &a,i) = i;
    }
    
    for( int i=0; i<200; i++) {
        printf("%d\t",*array_at( &a,i));
    }
    array_free( &a);

    return 0;
}