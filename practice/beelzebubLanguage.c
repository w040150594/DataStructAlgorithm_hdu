#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../queue/queue.c"
#include"../stack/sqStack.c"

//翻译转换魔王语言
void transFormation(char* language, int* length, sqStack* s, sqQueue* q){
  //遍历输入的魔王语言
  for(int i = 0; i < *length; i++){
    //没找到第一个右括号前，从左至右依次入栈
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
      //按照规则出队入栈
      while(getLength(q) != 1){
        push(s, getTail(q));
        //入栈一个就出队一个
        push(s, deQueue(q));
      }
      //剩下的最后一个元素直接入栈
      push(s, deQueue(q));
    }
  }
}

int isError(char* language, int length){
  sqStack* temp = initStack();
  int flag = 1;
  for(int i = 0; i < length; i++){
    if(language[i] == '('){
      //如果是左括号直接入栈
      push(temp, language[i]);
    }
    //如果是右括号判断与栈顶元素是否匹配
    else if(language[i] == ')'){
      //如果匹配就出栈
      if(getTop(temp) == '('){
        pop(temp);
      }
      else{
        flag = 0;
      }
    }
    else if((language[i] < 'A' || language[i] > 'z') || (language[i] > 'Z' && language[i] < 'a')){
      flag = 0;
    }
  }

  if(flag == 0 || !isEmptyStack(temp)){
    printf("输入的魔王语言有误!\n");
    printf("-----------------------\n");
    return 0;
  }
  return 1;
}

int main(){
  printf("-----------------------\n");
  printf(" 魔王语言解释\n");
  printf("-----------------------\n");
  sqQueue* q = initQueue();
  sqStack* s = initStack();
  char language[MAXSIZE];
  int flag = 1, length = 0;
  do{
    printf("请输入魔王语言：\n");
    scanf("%s", language);
    length = strlen(language);
    //判断输入的魔王语言是否合法
    flag = isError(language, length);
  } while(flag == 0);
  //翻译转换魔王语言
  transFormation(language, &length, s, q);
  printf("-----------------------\n");
  printf("解释后的语言为：\n");
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
  printf("\n-----------------------\n");
  return 0;
}