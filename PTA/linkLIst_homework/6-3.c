#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList(List L); /* 裁判实现，细节不表 */
List Delete(List L, ElementType minD, ElementType maxD);

int main(){
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete(L, minD, maxD);
    PrintList(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
List ReadInput(){
    int n;
    scanf("%d", &n);
    List L = (List)malloc(sizeof(struct LNode));
    L->Last = n - 1;
    for(int i = 0; i < n; i++){
        scanf("%d ", &L->Data[i]);
    }
    return L;
}

void PrintList(List L){
    for(int i = 0; i <= L->Last; i++){
        printf("%d ", L->Data[i]);
    }
    printf("\n");
}
//超时
List Delete(List L, ElementType minD, ElementType maxD){
    int i = 0;
    while(i <= L->Last){
        if(L->Data[i] > minD && L->Data[i] < maxD){
            // 删除
            for(int j = i; j < L->Last; j++){
                L->Data[j] = L->Data[j + 1];
            }
            L->Last--;
        }
        else{
            i++;
        }
    }
    return L;
}

List Delete(List L, ElementType minD, ElementType maxD){
    int i, count = 0;
    for(i = 0;i <= L->Last;i++){
        if(L->Data[i]<maxD && L->Data[i]>minD)//若当前元素在区间内，count+1
            count++;
        else
            L->Data[i - count] = L->Data[i];//若当前元素不在区间内，把当前元素向前移动count单位,并替换Data[i-count]
    }
    L->Last -= count;
    return L;
}