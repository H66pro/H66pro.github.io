#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct {
    int *array;
    int size;
} Array;

Array array_create( int init_size);             //  创建数组
void array_free( Array *a);                     //  释放数组内存
int array_size( const Array *a);                //  查看数组大小
int* array_at( Array *a, int index);            //  访问数组单元
void array_inflate(Array *a, int more_size);    //  数组增大

#endif