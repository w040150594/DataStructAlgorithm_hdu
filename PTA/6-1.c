// 删除单链表偶数节点
#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int data;
    struct ListNode* next;
};

struct ListNode* createlist();
struct ListNode* deleteeven(struct ListNode* head);
void printlist(struct ListNode* head){
    struct ListNode* p = head;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    struct ListNode* head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */
//尾插法
struct ListNode* createlist(){
    struct ListNode* s, * r;//s为新结点，r为尾指针
    int e;
    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
    r = L;
    scanf("%d", &e);
    while(e != -1){
        s = (struct ListNode*)malloc(sizeof(struct ListNode));//申请新结点内存
        s->data = e;//新结点数据域赋值

        s->next = NULL;//新结点指针域置空
        r->next = s;//插入链表尾部
        r = s;//r指向新的尾结点
        scanf("%d", &e);
    }
    r->next = NULL;//表示当前链表结束
    return L;
}
//删除偶数结点
struct ListNode* deleteeven(struct ListNode* head){
    struct ListNode* p, * tail;
    //先处理链表从头就需要删除的情况
    while(head != NULL && head->data % 2 == 0){
        p = head;    //用p标记head方便释放空间
        head = head->next;
        free(p);     //释放内存空间
    }
    //如果删空直接返回NULL
    if(head == NULL)
        return NULL;
    //处理正常情况，head%2 !=0
    p = head;
    tail = p->next;
    while(tail != NULL){
        if(tail->data % 2 == 0){
            p->next = tail->next;    //tail前节点连接tail后节点
            free(tail);              //释放内存
        }
        else
            p = tail;
        tail = p->next;
    }
    return head;
}
