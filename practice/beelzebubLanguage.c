#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../queue/queue.c"
#include"../stack/sqStack.c"

//翻译转换魔王语言
void transFormation(char* language, int* length, sqStack* s, sqQueue* q){
  //遍历输入的魔王语言
  for(int i = 0; i < *length; i++){
    //没找到第一个右括号前，依次入栈
    if(language[i] != ')'){
      push(s, language[i]);
    }
    //找到第一个右括号
    else if(language[i] == ')'){
      //依次入队，直到遇到配套的左括号
      while(getTop(s) != '('){
        enQueue(q, pop(s));
      }
      //出栈左括号
      pop(s);

      while(getLength(q) != 1){
        push(s, getTail(q));
        push(s, getHead(q));
        deQueue(q);
      }
      push(s, getTail(q));
      deQueue(q);
    }
  }
}

void isError(char* language, int length){
  int left = 0;
  int right = 0;
  for(int i = 0; i < length; i++){
    if(language[i] == '('){
      left++;
    }
    else if(language[i] == ')'){
      right++;
    }
  }
  if(left != right){
    printf("输入的魔王语言有误");
    exit(0);
  }
}

int main(){
  printf("-----------------------\n");
  printf(" 魔王语言解释\n");
  printf("-----------------------\n");
  sqQueue* q = initQueue();
  sqStack* s = initStack();
  char language[MAXSIZE];
  printf("请输入魔王语言：\n");
  scanf("%s", language);
  int length = strlen(language);
  //判断输入的魔王语言是否合法
  isError(language, length);
  //翻译转换魔王语言
  transFormation(language, &length, s, q);
  printf("解释后的语言为：");
  //反转栈
  sqStack* s1 = reverseStack(s);
  //转换AB并输出
  while(!isEmptyStack(s1)){
    switch(getTop(s1)){
    case 'A':
      printf("sae");
      pop(s1);
      break;
    case 'B':
      printf("tsaedsae");
      pop(s1);
      break;
    default:
      printf("%c", pop(s1));
      break;
    }
  }
  return 0;
}