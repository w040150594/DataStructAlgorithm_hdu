#include <stdio.h>
#include <stdlib.h>

struct stud_node{
    int    num;
    char   name[20];
    int    score;
    struct stud_node* next;
};

struct stud_node* createlist();
struct stud_node* deletelist(struct stud_node* head, int min_score);

int main(){
    int min_score;
    struct stud_node* p, * head = NULL;

    head = createlist();

    for(p = head; p != NULL; p = p->next)
        printf("%d %s %d\n", p->num, p->name, p->score);

    scanf("%d", &min_score);

    head = deletelist(head, min_score);
    for(p = head; p != NULL; p = p->next)
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct stud_node* createlist(){
    struct stud_node* head, * tail, * newNode;    // 头节点、尾节点、临时节点
    // 为头节点分配内存，数据域不存信息
    head = (struct stud_node*)malloc(sizeof(struct stud_node));
    // 头节点指向空
    head->next = NULL;
    // 此时尾节点跟头节点是同一个节点
    tail = head;
    int num;
    scanf("%d", &num);
    while(num != 0){
        // 为临时节点分配内存
        newNode = (struct stud_node*)malloc(sizeof(struct stud_node));
        // 将信息存入临时节点数据域
        newNode->num = num;
        scanf("%s", &newNode->name);
        scanf("%d", &newNode->score);
        // newNode指向空
        newNode->next = NULL;

        // 将临时节点链接到链表尾
        tail->next = newNode;
        // 更新尾节点为临时节点
        tail = newNode;
        scanf("%d", &num);
    }
    tail->next = NULL;
    return head;
}
struct stud_node* deletelist(struct stud_node* head, int min_score){
    struct stud_node* pCurrent = head; // 当前节点
    // 链表为空
    if(!head){
        return NULL;
    }
    // 由于头节点不存信息，故从头节点的下一节点开始遍历链表
    // 当前节点实际为首元节点(pCurrent->next)
    while(pCurrent->next){
        // 节点分数小于给定分数，删除该节点
        if(pCurrent->next->score < min_score){
            // 临时节点，保存当前节点pCurrent->next
            struct stud_node* temp = pCurrent->next;
            // 将当前节点的下个节点的地址覆盖当前节点的地址
            pCurrent->next = temp->next;
            // 释放之前的节点
            free(temp);
        }
        else{
            pCurrent = pCurrent->next;
        }
    }
    // 头节点不存储值，返回下一节点的地址
    head = head->next;
    return head;
}


