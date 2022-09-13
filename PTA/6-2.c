//求链表的倒数第m个元素
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

ElementType Find(List L, int m);

int main(){
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L, m));
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Read(){
    int n;
    scanf("%d", &n);
    if(n == 0){
        return NULL;
    }
    List L = (List)malloc(sizeof(struct Node));
    List p = L;
    for(int i = 0; i < n; i++){
        List q = (List)malloc(sizeof(struct Node));
        scanf("%d ", &q->Data);

        p->Next = q;
        p = q;
    }
    p->Next = NULL;
    return L;
}

void Print(List head){
    PtrToNode p = head->Next;
    while(p){
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}

ElementType Find(List L, int m){
    int count = 0;
    PtrToNode p = L, q = L;//p用于计数，q寻找用于返回
    while(p->Next){
        count++;
        p = p->Next;
    }
    int n = count - m + 1;//倒数第m个元素的正数序号
    if(n > 0){
        for(int i = 0; i < n; i++){
            q = q->Next;
        }
        return q->Data;
    }
    else{
        return ERROR;
    }
}