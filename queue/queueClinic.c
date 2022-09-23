//循环队列
#include<stdio.h>
#include<stdlib.h>
#include"queue.c"
int main(){
    int result;
    sqQueue* q = initQueue();
    sqQueue* q1 = initQueue();
    int* e = (int*)malloc(sizeof(int));
    int* e1 = (int*)malloc(sizeof(int));
    *e = 1;
    *e1 = 2;
    enQueue(q, e);
    enQueue(q, e1);
    while(1){
        printf("----------------\n");
        printf("1.给候诊病人编号\n");
        printf("2.提示病人就诊\n");
        printf("3.退出\n");
        printf("----------------\n");
        printf("请选择：");
        scanf("%d", &result);
        switch(result){
        case 1:
            printf("请%d号病人就诊,根据屏幕显示编号就诊\n", getHead(q));
            int* e2 = (int*)malloc(sizeof(int));
            *e2 = deQueue(q);
            enQueue(q1, e2);
            break;
        case 2:
            printf("请%d号病人就诊\n", deQueue(q1));
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}