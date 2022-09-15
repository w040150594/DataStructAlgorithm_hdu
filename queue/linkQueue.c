#include<stdio.h>
#include<stdlib.h>

typedef int elemType;

typedef struct queueNode{
    elemType data;
    struct queueNode* next;
}queueNode, * queuePtr;

typedef struct{
    queuePtr front;
    queuePtr rear;
}* linkQueue;

//构造空链队列
linkQueue initQueue(){
    linkQueue q;
    q->front = q->rear = (queuePtr)malloc(sizeof(queueNode));
    q->front->next = NULL;
    return q;
}

//判断队列是否为空
int isEmpty(linkQueue q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}

//摧毁链队列
void destroyQueue(linkQueue q){
    while(q->front){
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
}

//入队
void enQueue(linkQueue q, elemType e){
    queuePtr p = (queuePtr)malloc(sizeof(queueNode));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

//出队(队头指针指向链表头结点)
elemType deQueue(linkQueue q){
    if(q->front == q->rear){
        printf("队列为空");
        exit(0);
    }
    queuePtr p = q->front->next;
    elemType e = p->data;
    q->front->next = p->next;
    //如果队列只有最后一个元素，出队后队列为空，需要修改队尾指针
    if(q->rear == p){
        q->rear = q->front;
    }
    free(p);
    return e;
}

//取队头元素
elemType getHead(linkQueue q){
    if(q->front == q->rear){
        printf("队列为空");
        exit(0);
    }
    return q->front->next->data;
}
