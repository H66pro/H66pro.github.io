#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

// typedef struct _node {
//     int value;
//     struct _node *next;
// } Node;

typedef struct _list{
    Node *head;
    Node *tail;
} List;

void List_add( int number, List *p_list);
void List_put( Node *p);
void List_del( List *p_list, int delData);
void List_cls( List *p_list);

int main( int argc, char const *argv[])
{
    int delData;
    List list;
    list.head = list.tail = NULL;
    int number;
    do{
        scanf("%d",&number);
        if( number != -1){
            List_add( number, &list);
        }
    }while( number != -1);
    
    List_put( list.head);
    printf("请输入您要删除的数据：\n");
    scanf("%d",&delData);
    List_del( &list, delData);
    List_put( list.head);

    List_cls( &list);
    printf("%p\n",list.head);
    return 0;   
}

void List_add( int number, List *p_list)        //  添加链表单元
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    p_list->tail = p_list->head;
    if( p_list->tail ){
        while( p_list->tail->next){
            p_list->tail = p_list->tail->next;
        }
        p_list->tail->next = p;
    }else{
        p_list->head = p;
    }
}

void List_put( Node *p)                          //  输出链表
{  
    for( ; p; p=p->next){
        printf("%d\t",p->value);
    }
    printf("\n");
}

void List_del( List *p_list, int delData)
{
    int ret = 0;
    do{
        ret = 0;
        Node *p = p_list->head, *q=NULL;
        for( ; p; q = p,p = p->next){
            if( p->value == delData){
                if( q){
                    q->next = p->next;
                } else {
                    p_list->head = p->next;
                }
                free(p);
                ret = 1;
                break;
            }
        }   
    }while( ret);
}

void List_cls( List *p_list){
    Node *p = p_list->head, *q = p->next;
    for( ; p; p = q){
        q = p->next;
        free(p);
    }
}