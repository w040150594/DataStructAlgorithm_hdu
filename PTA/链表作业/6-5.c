#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node* PtrToNode;
struct Node{
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

void ReadInput(List L1, List L2); /* 裁判实现，细节不表 */
void PrintSublist(PtrToNode StartP); /* 裁判实现，细节不表 */
PtrToNode Suffix(List L1, List L2);

int main(){
    List L1, L2;
    PtrToNode P;

    L1 = (List)malloc(sizeof(struct Node));
    L2 = (List)malloc(sizeof(struct Node));
    L1->Next = L2->Next = NULL;
    ReadInput(L1, L2);
    P = Suffix(L1, L2);
    PrintSublist(P);

    return 0;
}

/* 你的代码将被嵌在这里 */
PtrToNode Suffix(List L1, List L2){
    PtrToNode p1, p2;
    p1 = L1->Next;
    p2 = L2->Next;
    int count1 = 0, count2 = 0;// 计数
    while(p1){
        count1++;
        p1 = p1->Next;
    }
    while(p2){
        count2++;
        p2 = p2->Next;
    }
    // 让两链表尾部对齐
    if(count1 > count2){
        p1 = L1->Next;
        p2 = L2->Next;
        for(int i = 0; i < count1 - count2; i++){
            p1 = p1->Next;
        }
    }
    else{
        p1 = L1->Next;
        p2 = L2->Next;
        for(int i = 0; i < count2 - count1; i++){
            p2 = p2->Next;
        }
    }
    // 从尾部对齐对应的前面起始结点开始比较
    while(p1 && p2){
        if(p1 == p2){
            return p1;
        }
        p1 = p1->Next;
        p2 = p2->Next;
    }
    return NULL;
}