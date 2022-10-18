#define MAXSIZE 100
// typedef struct{
//     char name[50];
// }people;

// typedef people elemType;
typedef char elemType;

typedef struct{
    elemType* base;
    int front, rear;
}sqQueue;

//构造空队列
sqQueue* initQueue(){
    sqQueue* q;
    q = (sqQueue*)malloc(sizeof(sqQueue));
    q->base = (elemType*)malloc(sizeof(elemType) * MAXSIZE);
    if(!q->base){
        printf("内存分配失败");
        exit(0);
    }
    q->front = q->rear = 0;
    return q;
}

//判断队列是否为空
int isEmptySqueue(sqQueue* q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}

//入队
void enQueue(sqQueue* q, elemType e){
    //牺牲最后一个空间来判断队列是否已满
    if((q->rear + 1) % MAXSIZE == q->front){
        printf("队列已满");
        exit(0);
    }
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
}

//出队
elemType deQueue(sqQueue* q){
    if(q->front == q->rear){
        printf("队列为空");
        exit(0);
    }
    elemType e = q->base[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return e;
}

//取队头元素
elemType getHead(sqQueue* q){
    if(q->front == q->rear){
        printf("队列为空");
        exit(0);
    }
    return q->base[q->front];
}

//取队尾元素
elemType getTail(sqQueue* q){
    if(q->front == q->rear){
        printf("队列为空");
        exit(0);
    }
    return q->base[q->rear - 1];
}

//求队列长度
int getLength(sqQueue* q){
    //循环队列的长度算法
    return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

//遍历队列
void traverseQueue(sqQueue* q){
    int i = q->front;
    if(i == q->rear){
        printf("队列为空");
        exit(0);
    }
    while(i != q->rear){
        printf("%c ", q->base[i]);
        i = (i + 1) % MAXSIZE;
    }
}
