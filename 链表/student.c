#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXSIZE 100
#define NUM 3
typedef struct{
    int num;
    char name[20];
    int score;
} Student;

//顺序表的结构体定义
typedef struct{
    Student* data;
    int size;
    int capacity;
} SqList;

//顺序表的初始化
SqList* newSqList(){
    SqList* L = (SqList*)malloc(sizeof(SqList));
    L->data = (Student*)malloc(sizeof(Student) * MAXSIZE);
    L->size = 0;
    L->capacity = MAXSIZE;
    return L;
}

// 根据指定学生个数，逐个输入学生信息
void input(SqList* L){
    int i;
    for(i = 0; i < NUM; i++){
        printf("请输入第%d个学生的信息\n", i + 1);
        printf("请输入学号：");
        scanf("%d", &L->data[i].num);
        printf("请输入姓名：");
        scanf("%s", L->data[i].name);
        printf("请输入成绩：");
        scanf("%d", &L->data[i].score);
        L->size++;
    }
}

// 逐个显示学生表中所有学生的相关信息;
void display(SqList* L){
    for(int i = 0; i < L->size; i++){
        printf("第%d个学生的信息为：\n", i + 1);
        printf("学号：%d\n", L->data[i].num);
        printf("姓名：%s\n", L->data[i].name);
        printf("成绩：%d\n", L->data[i].score);
    }
}

// 根据姓名进行查找，返回此学生的学号和成绩
void search(SqList* L, Student* e, char* name){
    for(int i = 0; i < L->size; i++){
        if(strcmp(L->data[i].name, name) == 0){
            e->num = L->data[i].num;
            e->score = L->data[i].score;
            printf("学号：%d\n", e->num);
            printf("成绩：%d\n", e->score);
            return;
        }
    }
    printf("查无此人！\n");
}

//根据指定的位置可返回相应的学生信息（学号，姓名，成绩）
void locate(SqList* L, Student* e, int index){
    if(index < 1 || index > L->size){
        printf("查无此人！\n");
        return;
    }
    e = &L->data[index - 1];
    printf("第%d个学生的信息为：\n", index);
    printf("学号：%d\n", e->num);
    printf("姓名：%s\n", e->name);
    printf("成绩：%d\n", e->score);
}

// 给定一个学生信息，插入到表中指定的位置
void insert(SqList* L, Student* e, int index){
    if(index < 1 || index > L->size + 1){
        printf("插入位置不合法！\n");
        return;
    }
    for(int i = L->size; i >= index; i--){
        L->data[i] = L->data[i - 1];
    }
    L->data[index - 1] = *e;
    L->size++;
    printf("插入成功！\n");
}

// 删除指定位置的学生信息
void delete(SqList* L, int index){
    if(index < 1 || index > L->size){
        printf("删除失败!\n");
        return;
    }
    for(int i = index - 1; i < L->size - 1; i++){
        L->data[i] = L->data[i + 1];
    }
    L->size--;
    printf("删除成功!\n");
}

// 统计表中学生个数
int count(SqList* L){
    return L->size;
}

int main(){
    system("chcp 65001");
    SqList* L = newSqList();
    Student* e = (Student*)malloc(sizeof(Student));
    int index;
    char name[20];
    input(L);
    printf("---------------------------------\n");
    display(L);
    printf("---------------------------------\n");


    printf("请输入要查找的学生姓名：");
    scanf("%s", name);
    search(L, e, name);
    printf("---------------------------------\n");
    printf("请输入要查找的学生位置：");
    scanf("%d", &index);
    locate(L, e, index);
    printf("---------------------------------\n");

    Student* e1 = (Student*)malloc(sizeof(Student));

    printf("请输入要插入的学生信息：\n");
    printf("请输入学号：");
    scanf("%d", &e1->num);
    printf("请输入姓名：");
    scanf("%s", e1->name);
    printf("请输入成绩：");
    scanf("%d", &e1->score);
    printf("请输入要插入的位置：");
    scanf("%d", &index);
    insert(L, e1, index);
    printf("---------------------------------\n");

    printf("请输入要删除学生的位置：\n");
    scanf("%d", &index);
    delete(L, index);
    printf("---------------------------------\n");
    display(L);
    printf("---------------------------------\n");

    printf("表中学生个数为：%d\n", count(L));
    system("pause");
    return 0;
}
