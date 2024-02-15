#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct {
    int *array;
    int size;
} Array;

Array array_create( int init_size);             //  ��������
void array_free( Array *a);                     //  �ͷ������ڴ�
int array_size( const Array *a);                //  �鿴�����С
int* array_at( Array *a, int index);            //  �������鵥Ԫ
void array_inflate(Array *a, int more_size);    //  ��������

#endif