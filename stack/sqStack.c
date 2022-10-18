
#define MAXSIZE 100

typedef char elemType;
typedef struct{
    elemType* base;
    elemType* top;
    int stackSize;
}sqStack;

//初始化栈
sqStack* initStack(){
    sqStack* s;
    s = (sqStack*)malloc(sizeof(sqStack));
    s->base = (elemType*)malloc(MAXSIZE * sizeof(elemType));
    if(!s->base){
        printf("初始化栈失败");
        exit(0);
    }
    s->top = s->base;
    s->stackSize = MAXSIZE;
    return s;
}

//判断栈是否为空
int isEmptyStack(sqStack* s){
    return s->top == s->base;
}

//计算栈的长度
int stackLength(sqStack* s){
    return s->top - s->base;
}

//销毁栈
void destroyStack(sqStack* s){
    if(s->base){
        free(s->base);
        s->base = NULL;
        s->top = NULL;
        s->stackSize = 0;
    }
}

//把栈清空
void clearStack(sqStack* s){
    if(s->base){
        s->top = s->base;
    }
}

//进栈
void push(sqStack* s, elemType e){
    if(s->top - s->base == s->stackSize){
        printf("栈已满");
    }

    *s->top = e;
    s->top++;
}

//出栈
elemType pop(sqStack* s){
    if(s->top == s->base){
        printf("栈为空");
        exit(0);
    }
    s->top--;
    return *s->top;
}

//判断栈是否为满
int isFullStack(sqStack* s){
    return s->top - s->base == s->stackSize;
}

//取栈顶元素
elemType getTop(sqStack* s){
    if(s->top == s->base){
        printf("栈为空");
        exit(0);
    }
    return *(s->top - 1);
}

//遍历栈
void traverseStack(sqStack* s){
    while(!isEmptyStack(s)){
        printf("%c", pop(s));
    }
}
//栈的反转
sqStack* reverseStack(sqStack* s){
    sqStack* s1 = initStack();
    while(!isEmptyStack(s)){
        push(s1, pop(s));
    }
    return s1;
}