#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   char name[20];
   struct Node* parent;
   struct Node* children[100];
   int child_count;
} Node;

Node* find(Node* node, const char* name) {
   if (strcmp(node->name, name) == 0) {
       return node;
   }
   for (int i = 0; i < node->child_count; i++) {
       Node* result = find(node->children[i], name);
       if (result) {
           return result;
       }
   }
   return NULL;
}

int update(Node* node, const char* name, Node* new_parent) {
   if (strcmp(node->name, name) == 0) {
       if (new_parent) {
           node->parent = new_parent;
           return 1;
       }
       return 0;
   }
   for (int i = 0; i < node->child_count; i++) {
       if (update(node->children[i], name, new_parent)) {
           return 1;
       }
   }
   return 0;
}

void add_child(Node* parent, Node* child) {
   parent->children[parent->child_count++] = child;
}

int main() {
   Node* alice = malloc(sizeof(Node));
   strcpy(alice->name, "Alice");
   alice->parent = NULL;
   alice->child_count = 0;

   Node* bob = malloc(sizeof(Node));
   strcpy(bob->name, "Bob");
   bob->parent = alice;
   bob->child_count = 0;

   Node* charlie = malloc(sizeof(Node));
   strcpy(charlie->name, "Charlie");
   charlie->parent = alice;
   charlie->child_count = 0;

   Node* david = malloc(sizeof(Node));
   strcpy(david->name, "David");
   david->parent = bob;
   david->child_count = 0;

   Node* eve = malloc(sizeof(Node));
   strcpy(eve->name, "Eve");
   eve->parent = charlie;
   eve->child_count = 0;

   printf("欢迎使用家谱图管理系统！\n");
    // 打印菜单
    printf("请选择你要进行的操作：\n");
    printf("1. 建立家谱图\n");
    printf("2. 添加家族成员\n");
    printf("3. 添加家族成员的伴侣\n");
    printf("4. 删除家族成员\n");
    printf("5. 查询家族成员的信息\n");
    printf("6. 查询家族成员的祖先\n");
    printf("7. 查询家族成员的后代子孙\n");
    printf("8. 查询家族成员的堂兄弟\n");
    printf("9. 查询家族成员的兄弟\n");
    printf("10. 查询家族成员的双亲\n");
    printf("11. 查询家族成员的孩子\n");
    printf("12. 打印家谱图\n");
    printf("0. 退出系统\n");
    // 输入用户的选择
    scanf("%d", &choice);
    // 使用循环，根据用户的选择执行相应的操作，直到用户选择退出
    while (choice != 0)
    {
        switch (choice)
        {
        case 1: // 如果用户选择建立家谱图
            // 输入始祖的姓名、性别和出生日期
            printf("请输入始祖的姓名：");
            scanf("%s", name);
            printf("请输入始祖的性别（M表示男性，F表示女性）：");
            scanf(" %c", &gender);
            printf("请输入始祖的出生日期（格式为yyyy-mm-dd）：");
            scanf("%s", birth);
            // 调用函数，建立家谱图
            root = createFamilyTree(name, gender, birth);
            // 打印成功信息
            printf("家谱图建立成功！\n");
            break;
        case 2: // 如果用户选择添加家族成员
            // 输入父亲的姓名、孩子的姓名、性别、出生日期和（对于女性）出嫁日期
            printf("请输入父亲的姓名：");
            scanf("%s", father);
            printf("请输入孩子的姓名：");
            scanf("%s", child);
            printf("请输入孩子的性别（M表示男性，F表示女性）：");
            scanf(" %c", &gender);
            printf("请输入孩子的出生日期（格式为yyyy-mm-dd）：");
            scanf("%s", birth);
            if (gender == 'F')
            { // 如果孩子是女性
                printf("请输入孩子的出嫁日期（格式为yyyy-mm-dd）：");
                scanf("%s", marry);
            }
            // 调用函数，添加家族成员
            addFamilyMember(father, child, gender, birth, marry);
            // 打印成功信息
            printf("家族成员添加成功！\n");
            break;
        case 3: // 如果用户选择添加家族成员的伴侣
            // 输入要添加伴侣的人的姓名、伴侣的姓名、性别、出生日期和（对于女性）出嫁日期
            printf("请输入要添加伴侣的人的姓名：");
            scanf("%s", name);
            printf("请输入伴侣的姓名：");
            scanf("%s", spouse);
            printf("请输入伴侣的性别（M表示男性，F表示女性）：");
            scanf(" %c", &gender);
            printf("请输入伴侣的出生日期（格式为yyyy-mm-dd）：");
            scanf("%s", birth);
            if (gender == 'F')
            { // 如果伴侣是女性
                printf("请输入伴侣的出嫁日期（格式为yyyy-mm-dd）：");
                scanf("%s", marry);
            }
            // 调用函数，添加家族成员的伴侣
            addSpouse(name, spouse, gender, birth, marry);
            // 打印成功信息
            printf("家族成员的伴侣添加成功！\n");
            break;
        case 4: // 如果用户选择删除家族成员
            // 输入要删除的人的姓名
            printf("请输入要删除的人的姓名：");
            scanf("%s", name);
            // 调用函数，删除家族成员
            deleteFamilyMember(name);
            // 打印成功信息
            printf("家族成员删除成功！\n");
            break;
        case 5: // 如果用户选择查询家族成员的信息
            // 输入要查询的人的姓名
            printf("请输入要查询的人的姓名：");
            scanf("%s", name);
            // 调用函数，查询家族成员的信息
            queryFamilyMember(name);
            break;
        case 6: // 如果用户选择查询家族成员的祖先
            // 输入要查询的人的姓名
            printf("请输入要查询的人的姓名：");
            scanf("%s", name);
            // 调用函数，查询家族成员的祖先
            queryAncestor(name);
            break;
        case 7: // 如果用户选择查询家族成员的后代子孙
            // 输入要查询的人的姓名
            printf("请输入要查询的人的姓名：");
            scanf("%s", name);
            // 调用函数，查询家族成员的后代子孙
            queryDescendant(name);
            break;
        case 8: // 如果用户选择查询家族成员的堂兄弟
            // 输入要查询的人的姓名
            printf("请输入要查询的人的姓名：");
            scanf("%s", name);
            // 调用函数，查询家族成员的堂兄弟
            queryCousin(name);
            break;
        case 9: // 如果用户选择查询家族成员的兄弟
            // 输入要查询的人的姓名
            printf("请输入要查询的人的姓名：");
            scanf("%s", name);
            // 调用函数，查询家族成员的兄弟
            querySibling(name);
            break;
        case 10: // 如果用户选择查询家族成员的双亲
            // 输入要查询的人的姓名
            printf("请输入要查询的人的姓名：");
            scanf("%s", name);
            // 调用函数，查询家族成员的双亲
            queryParent(name);
            break;
        case 11: // 如果用户选择查询家族成员的孩子
            // 输入要查询的人的姓名
            printf("请输入要查询的人的姓名：");
            scanf("%s", name);
            // 调用函数，查询家族成员的孩子
            queryChild(name);
            break;
        case 12: // 如果用户选择打印家谱图
            // 调用函数，打印家谱图
            printFamilyTree();
            break;
        default: // 如果用户选择其他无效的选项
            // 打印错误信息
            printf("无效的选择，请重新输入！\n");
            break;
        }
        // 打印菜单
        printf("请选择你要进行的操作：\n");
        printf("1. 建立家谱图\n");
        printf("2. 添加家族成员\n");
        printf("3. 添加家族成员的伴侣\n");
        printf("4. 删除家族成员\n");
        printf("5. 查询家族成员的信息\n");
        printf("6. 查询家族成员的祖先\n");
        printf("7. 查询家族成员的后代子孙\n");
        printf("8. 查询家族成员的堂兄弟\n");
        printf("9. 查询家族成员的兄弟\n");
        printf("10. 查询家族成员的双亲\n");
        printf("11. 查询家族成员的孩子\n");
        printf("12. 打印家谱图\n");
        printf("0. 退出系统\n");
        // 输入用户的选择
        scanf("%d", &choice);
    }
    // 如果用户选择退出
    // 释放家谱图的内存空间
    freeFamilyTree();
    // 打印退出信息
    printf("感谢使用家谱图管理系统，再见！\n");

   Node* updated_charlie = find(alice, "Charlie");
   update(alice, "Charlie", alice);
   printf("Updated Charlie's parent: %s\n", updated_charlie->parent ? updated_charlie->parent->name : "NULL");

   return 0;
}
