#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Human
{
    char name[20];
    char gender[4];
    char birth[11];
    char marry[11];
} Human;

typedef struct FamilyNode
{
    Human data;
    struct FamilyNode *parent;
    struct FamilyNode *firstChild;
    struct FamilyNode *nextSibling;
} FamilyNode;

FamilyNode *root = NULL;

void printHuman(Human h)
{
    printf("������%s\n", h.name);
    printf("�Ա�%s\n", h.gender);
    printf("���գ�%s\n", h.birth);
}

void error(char *msg)
{
    printf("����%s\n", msg);
    exit(1);
}

void *alloc(size_t size)
{
    void *p = malloc(size);
    if (p == NULL)
    {
        error("�ڴ����ʧ��");
    }
    return p;
}

FamilyNode *findByName(char *name)
{

    FamilyNode *p = root;
    FamilyNode *stack[100];
    int top = -1;
    while (p != NULL || top != -1)
    {
        if (p != NULL)
        {
            if (strcmp(p->data.name, name) == 0)
            {
                return p;
            }
            stack[++top] = p;
            p = p->firstChild;
        }
        else
        {
            p = stack[top--];
            p = p->nextSibling;
        }
    }
    return NULL;
}

FamilyNode *createFamilyTree(char *name, char* gender, char *birth)
{

    FamilyNode *p = (FamilyNode *)alloc(sizeof(FamilyNode));

    strcpy(p->data.name, name);
    strcpy(p->data.gender, gender);
    strcpy(p->data.birth, birth);

    p->parent = NULL;
    p->firstChild = NULL;
    p->nextSibling = NULL;

    return p;
}

void addFamilyMember(char *father, char *child, char* gender, char *birth)
{

    FamilyNode *p = findByName(father);
    if (p == NULL)
    {
        error("û���ҵ����׵���Ϣ");
    }

    FamilyNode *q = (FamilyNode *)alloc(sizeof(FamilyNode));

    strcpy(q->data.name, child);
    strcpy(q->data.gender, gender);
    strcpy(q->data.birth, birth);

    q->parent = NULL;
    q->firstChild = NULL;
    q->nextSibling = NULL;

    if (p->firstChild == NULL)
    {
        p->firstChild = q;
    }
    else
    {
        FamilyNode *r = p->firstChild;
        while (r->nextSibling != NULL)
        {
            r = r->nextSibling;
        }
        r->nextSibling = q;
    }
    q->parent = p;
}

void deleteFamilyMember(char *name)
{

    FamilyNode *p = findByName(name);
    if (p == NULL)
    {
        error("û���ҵ�Ҫɾ�����˵���Ϣ");
    }
    if (p == root)
    {
        error("����ɾ��ʼ�����Ϣ");
    }
    if (p->firstChild != NULL)
    {
        error("����ɾ���к�����˵���Ϣ");
    }

    FamilyNode *q = p->parent;
    if (q->firstChild == p)
    {
        q->firstChild = p->nextSibling;
    }
    else
    {
        FamilyNode *r = q->firstChild;
        while (r->nextSibling != p)
        {
            r = r->nextSibling;
        }
        r->nextSibling = p->nextSibling;
    }

    free(p);
}

void queryFamilyMember(char *name)
{

    FamilyNode *p = findByName(name);
    if (p == NULL)
    {
        error("û���ҵ�Ҫ��ѯ���˵���Ϣ");
    }

    printHuman(p->data);

    if (p->parent != NULL)
    {
        printf("���ף�%s\n", p->parent->data.name);
    }

    if (p->firstChild != NULL)
    {
        printf("���ӣ�");
        FamilyNode *q = p->firstChild;
        while (q != NULL)
        {
            printf("%s ", q->data.name);
            q = q->nextSibling;
        }
        printf("\n");
    }
}

void queryAncestor(char *name)
{

    FamilyNode *p = findByName(name);
    if (p == NULL)
    {
        error("û���ҵ�Ҫ��ѯ���˵���Ϣ");
    }

    printf("���ȣ�");
    p = p->parent;
    while (p != NULL)
    {
        printf("%s ", p->data.name);
        p = p->parent;
    }
    printf("\n");
}

void queryDescendant(char *name)
{

    FamilyNode *p = findByName(name);
    if (p == NULL)
    {
        error("û���ҵ�Ҫ��ѯ���˵���Ϣ");
    }

    printf("������");

    FamilyNode *queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = p;
    while (front != rear)
    {
        p = queue[front++];
        FamilyNode *q = p->firstChild;
        while (q != NULL)
        {
            printf("%s ", q->data.name);
            queue[rear++] = q;
            q = q->nextSibling;
        }
    }
    printf("\n");
}

void queryCousin(char *name)
{

    FamilyNode *p = findByName(name);
    if (p == NULL)
    {
        error("û���ҵ�Ҫ��ѯ���˵���Ϣ");
    }

    printf("���ֵܣ�");
    if (p->parent != NULL && p->parent->parent != NULL)
    {
        FamilyNode *q = p->parent->parent->firstChild;
        while (q != NULL)
        {
            if (q != p->parent)
            {
                FamilyNode *r = q->firstChild;
                while (r != NULL)
                {
                    printf("%s ", r->data.name);
                    r = r->nextSibling;
                }
            }
            q = q->nextSibling;
        }
    }
    printf("\n");
}

void printFamilyTree()
{

    FamilyNode *queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while (front != rear)
    {
        FamilyNode *p = queue[front++];

        printf("��%d����", front);
        printHuman(p->data);
        FamilyNode *q = p->firstChild;
        while (q != NULL)
        {
            queue[rear++] = q;
            q = q->nextSibling;
        }
    }
}

void freeFamilyTree()
{

    FamilyNode *p = root;
    FamilyNode *stack[100];
    int top = -1;
    FamilyNode *pre = NULL;
    while (p != NULL || top != -1)
    {
        if (p != NULL)
        {
            stack[++top] = p;
            p = p->firstChild;
        }
        else
        {
            p = stack[top];
            if (p->nextSibling == NULL || p->nextSibling == pre)
            {
                p = stack[top--];
                free(p);
                pre = p;
                p = NULL;
            }
            else
            {
                p = p->nextSibling;
            }
        }
    }
}

void querySibling(char *name) 
{

    FamilyNode *p = findByName(name);
    if (p == NULL)
    {
        error("û���ҵ�Ҫ��ѯ���˵���Ϣ");
    }

    printf("�ֵܣ�");
    if (p->parent != NULL)
    {
        FamilyNode *q = p->parent->firstChild;
        while (q != NULL)
        {
            if (q != p)
            {
                printf("%s ", q->data.name);
            }
            q = q->nextSibling;
        }
    }
    printf("\n");
}

void queryParent(char *name)
{

    FamilyNode *p = findByName(name);
    if (p == NULL)
    {
        error("û���ҵ�Ҫ��ѯ���˵���Ϣ");
    }

    printf("���ף�");
    if (p->parent != NULL)
    {
        printf("%s ", p->parent->data.name);
        if (p->parent->data.gender == "��" && p->parent->parent != NULL)
        {
            FamilyNode *q = p->parent->parent->firstChild;
            while (q != NULL)
            {
                if (q != p->parent && q->data.gender == "Ů")
                {
                    printf("%s ", q->data.name);
                    break;
                }
                q = q->nextSibling;
            }
        }
    }
    printf("\n");
}

void queryChild(char *name)
{

    FamilyNode *p = findByName(name);
    if (p == NULL)
    {
        error("û���ҵ�Ҫ��ѯ���˵���Ϣ");
    }

    printf("���ӣ�");
    if (p->firstChild != NULL)
    {
        FamilyNode *q = p->firstChild;
        while (q != NULL)
        {
            printf("%s ", q->data.name);
            q = q->nextSibling;
        }
    }
    printf("\n");
}



int main()
{

    int choice;

    char name[20];

    char gender[4], birth[11], father[20], child[20];

    printf("��ӭʹ�ü���ͼ����ϵͳ��\n");
    printf("��ѡ����Ҫ���еĲ�����\n");
    printf("1. ��������ͼ\n");
    printf("2. ��Ӽ����Ա\n");
    printf("3. ɾ�������Ա\n");
    printf("4. ��ѯ�����Ա����Ϣ\n");
    printf("5. ��ѯ�����Ա������\n");
    printf("6. ��ѯ�����Ա�ĸ���\n");
    printf("7. ��ѯ�����Ա�ĺ���\n");
    printf("8. ��ӡ����ͼ\n");
    printf("0. �˳�ϵͳ\n");

    scanf("%d", &choice);

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:

            printf("���������ȵ�������");
            scanf("%s", name);
            printf("���������ȵ��Ա���/Ů����");
            scanf(" %s", &gender);
            printf("���������ȵĳ������ڣ���ʽΪyyyy.mm.dd����");
            scanf("%s", birth);

            root = createFamilyTree(name, gender, birth);

            printf("����ͼ�����ɹ���\n");
            break;
        case 2:

            printf("�����븸�׵�������");
            scanf("%s", father);
            printf("�������³�Ա��������");
            scanf("%s", child);
            printf("�������³�Ա���Ա���/Ů����");
            scanf(" %s", &gender);
            printf("�������³�Ա�ĳ������ڣ���ʽΪyyyy.mm.dd����");
            scanf("%s", birth);

            addFamilyMember(father, child, gender, birth);

            printf("�����Ա��ӳɹ���\n");
            break;

        case 3:

            printf("������Ҫɾ�����˵�������");
            scanf("%s", name);

            deleteFamilyMember(name);

            printf("�����Աɾ���ɹ���\n");
            break;
        case 4:

            printf("������Ҫ��ѯ���˵�������");
            scanf("%s", name);

            queryFamilyMember(name);
            break;
        case 5:

            printf("������Ҫ��ѯ���˵�������");
            scanf("%s", name);

            queryAncestor(name);
            break;

        case 6:

            printf("������Ҫ��ѯ���˵�������");
            scanf("%s", name);

            queryParent(name);
            break;
        case 7:

            printf("������Ҫ��ѯ���˵�������");
            scanf("%s", name);

            queryChild(name);
            break;
        case 8:

            printFamilyTree();
            break;
        default:

            printf("��Ч��ѡ�����������룡\n");
            break;
        }

        printf("��ѡ����Ҫ���еĲ�����");

        OUT:
        scanf("%d", &choice);
    }

    freeFamilyTree();

    printf("��лʹ�ü���ͼ����ϵͳ���ټ���\n");

    return 0;
}
