#define MAXSIZE 100


// typedef struct{
//     char name[50];
// }people;

typedef int elemType;

typedef struct{
    elemType* base;
    int front, rear;
}sqQueue;

sqQueue* initQueue();
int isEmpty(sqQueue* q);
void enQueue(sqQueue* q, elemType* e);
elemType deQueue(sqQueue* q);
elemType getHead(sqQueue* q);
elemType getTail(sqQueue* q);
int getLength(sqQueue* q);
void traverseQueue(sqQueue* q);

