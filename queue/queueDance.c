#include<stdio.h>
#include<stdlib.h>
#include"queue.c"
#define MAXSIZE 100

int main(){
    sqQueue* boyQueue = initQueue();
    sqQueue* girlQueue = initQueue();
    elemType* boyName;
    elemType* girlName;
    boyName = (elemType*)malloc(sizeof(elemType));
    girlName = (elemType*)malloc(sizeof(elemType));
    char result;
    int flag = 1;
    while(flag){
        printf("输入男生的名字：");
        scanf("%s", boyName->name);
        enQueue(boyQueue, boyName);
        printf("是否继续(y/n)");
        scanf("%s", &result);
        switch(result){
        case 'y':
            break;
        case 'n':
            flag = 0;
            break;
        default:
            printf("输入错误\n");
            continue;
        }
    }
    flag = 1;
    while(flag){
        printf("输入女生的名字：");
        scanf("%s", girlName->name);
        enQueue(girlQueue, girlName);
        printf("是否继续(y/n)");
        scanf("%s", &result);
        switch(result){
        case 'y':
            break;
        case 'n':
            flag = 0;
            break;
        default:
            printf("输入错误");
            continue;
        }
    }
    printf("下一支舞曲，舞伴配对如下：\n");
    while(!isEmpty(boyQueue) && !isEmpty(girlQueue)){

        printf("%s的舞伴是%s\n", deQueue(boyQueue).name, deQueue(girlQueue).name);
    }
}