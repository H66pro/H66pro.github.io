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
    printf("姓名：%s\n", h.name);
    printf("性别：%s\n", h.gender);
    printf("生日：%s\n", h.birth);
}

void error(char *msg)
{
    printf("错误：%s\n", msg);
    exit(1);
}

void *alloc(size_t size)
{
    void *p = malloc(size);
    if (p == NULL)
    {
        error("内存分配失败");
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
        error("没有找到父亲的信息");
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
        error("没有找到要删除的人的信息");
    }
    if (p == root)
    {
        error("不能删除始祖的信息");
    }
    if (p->firstChild != NULL)
    {
        error("不能删除有后代的人的信息");
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
        error("没有找到要查询的人的信息");
    }

    printHuman(p->data);

    if (p->parent != NULL)
    {
        printf("父亲：%s\n", p->parent->data.name);
    }

    if (p->firstChild != NULL)
    {
        printf("孩子：");
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
        error("没有找到要查询的人的信息");
    }

    printf("祖先：");
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
        error("没有找到要查询的人的信息");
    }

    printf("后代子孙：");

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
        error("没有找到要查询的人的信息");
    }

    printf("堂兄弟：");
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

        printf("第%d代：", front);
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
        error("没有找到要查询的人的信息");
    }

    printf("兄弟：");
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
        error("没有找到要查询的人的信息");
    }

    printf("父亲：");
    if (p->parent != NULL)
    {
        printf("%s ", p->parent->data.name);
        if (p->parent->data.gender == "男" && p->parent->parent != NULL)
        {
            FamilyNode *q = p->parent->parent->firstChild;
            while (q != NULL)
            {
                if (q != p->parent && q->data.gender == "女")
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
        error("没有找到要查询的人的信息");
    }

    printf("孩子：");
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

    printf("欢迎使用家谱图管理系统！\n");
    printf("请选择你要进行的操作：\n");
    printf("1. 建立家谱图\n");
    printf("2. 添加家族成员\n");
    printf("3. 删除家族成员\n");
    printf("4. 查询家族成员的信息\n");
    printf("5. 查询家族成员的祖先\n");
    printf("6. 查询家族成员的父亲\n");
    printf("7. 查询家族成员的孩子\n");
    printf("8. 打印家谱图\n");
    printf("0. 退出系统\n");

    scanf("%d", &choice);

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:

            printf("请输入祖先的姓名：");
            scanf("%s", name);
            printf("请输入祖先的性别（男/女）：");
            scanf(" %s", &gender);
            printf("请输入祖先的出生日期（格式为yyyy.mm.dd）：");
            scanf("%s", birth);

            root = createFamilyTree(name, gender, birth);

            printf("家谱图建立成功！\n");
            break;
        case 2:

            printf("请输入父亲的姓名：");
            scanf("%s", father);
            printf("请输入新成员的姓名：");
            scanf("%s", child);
            printf("请输入新成员的性别（男/女）：");
            scanf(" %s", &gender);
            printf("请输入新成员的出生日期（格式为yyyy.mm.dd）：");
            scanf("%s", birth);

            addFamilyMember(father, child, gender, birth);

            printf("家族成员添加成功！\n");
            break;

        case 3:

            printf("请输入要删除的人的姓名：");
            scanf("%s", name);

            deleteFamilyMember(name);

            printf("家族成员删除成功！\n");
            break;
        case 4:

            printf("请输入要查询的人的姓名：");
            scanf("%s", name);

            queryFamilyMember(name);
            break;
        case 5:

            printf("请输入要查询的人的姓名：");
            scanf("%s", name);

            queryAncestor(name);
            break;

        case 6:

            printf("请输入要查询的人的姓名：");
            scanf("%s", name);

            queryParent(name);
            break;
        case 7:

            printf("请输入要查询的人的姓名：");
            scanf("%s", name);

            queryChild(name);
            break;
        case 8:

            printFamilyTree();
            break;
        default:

            printf("无效的选择，请重新输入！\n");
            break;
        }

        printf("请选择你要进行的操作：");

        OUT:
        scanf("%d", &choice);
    }

    freeFamilyTree();

    printf("感谢使用家谱图管理系统，再见！\n");

    return 0;
}
