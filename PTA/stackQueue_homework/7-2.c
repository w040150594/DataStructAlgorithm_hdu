#include<stdio.h>
#include<stdlib.h>
#include"../../queue/queue.c"

int main(){
  int n;
  scanf("%d", &n);
  sqQueue* oddQueue = initQueue();
  sqQueue* evenQueue = initQueue();
  elemType* num;
  num = (elemType*)malloc(sizeof(elemType));
  for(int i = 0; i < n; i++){
    scanf("%d", num);
    if(*num % 2 == 0)
      enQueue(evenQueue, num);
    else
      enQueue(oddQueue, num);
  }
  int flag = 0;
  while(!isEmpty(oddQueue) || !isEmpty(evenQueue)){
    if(flag)
      printf(" ");
    if(!isEmpty(oddQueue)){
      printf("%d", deQueue(oddQueue));
      flag = 1;
      if(!isEmpty(oddQueue))
        printf(" %d", deQueue(oddQueue));
    }
    if(!isEmpty(evenQueue)){
      if(flag)
        printf(" ");
      printf("%d", deQueue(evenQueue));
      flag = 1;
    }
  }
}