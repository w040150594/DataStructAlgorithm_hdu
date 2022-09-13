#include<stdio.h>
#include<stdlib.h>

typedef int elemType;

typedef struct stackNode{
    elemType data;
    struct stackNode* next;
}stackNode, * linkStack;

//构造空链栈
linkStack initStack(){
    linkStack s = (linkStack)malloc(sizeof(stackNode));
    s = NULL;
    return s;
}

//将一个元素压入链栈(头插法)
void push(linkStack s, elemType e){
    stackNode* p = (stackNode*)malloc(sizeof(stackNode));
    p->data = e;
    p->next = s;
    s = p;
}

//取栈顶元素
elemType getTop(linkStack s){
    if(s == NULL){
        printf("栈为空");
        exit(0);
    }
    return s->data;
}

//将一个元素从链栈中弹出(头删法)
elemType pop(linkStack s){
    if(s == NULL){
        printf("栈为空");
        exit(0);
    }
    stackNode* p = s;//p指向栈顶元素

    elemType e = p->data;//保存栈顶元素
    s = p->next;
    free(p);
    return e;
}