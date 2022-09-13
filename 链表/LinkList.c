#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

// 初始化链表(带头结点)
void InitList(LinkList L){
    L = (Lnode*)malloc(sizeof(Lnode));// 申请头结点内存
    if(L = NULL)// 如果申请失败
        return;
    L->next = NULL;// 头结点指针域置空
}

//判断链表是否为空
int IsEmpty(LinkList L){
    if(L->next == NULL)// 如果头结点指针域为空
        return 1;
    else
        return 0;
}

//清空链表
void ClearList(LinkList L){
    Lnode* p, * q;//p是要删除的结点
    p = L->next;//p指向第一个结点
    while(p){
        q = p->next;//q用来保存p的下一个结点
        free(p);
        p = q;
    }
    L->next = NULL;// 头结点指针域置空
}

//摧毁单链表
void DestroyList(LinkList L){
    LinkList p;//或者Lnode* p，指向当前要销毁的头结点
    //遍历链表，销毁每一个结点
    while(L){
        p = L;
        L = L->next;
        p = NULL;//先将p置空，再释放p，防止野指针
        free(p);
    }
}

//遍历打印单链表
void PrintList(LinkList L){
    if(L == NULL)
        return;
    LinkList p = L->next;//p指向首元结点
    while(p){
        if(p->next == NULL)
            printf("%d", p->data);
        else
            printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
}

//后插操作：在p结点后插入元素e
void InsertNextNode(Lnode* p, ElemType e){
    if(p == NULL)
        return;
    Lnode* s = (Lnode*)malloc(sizeof(Lnode));//申请新结点内存
    if(s == NULL)
        return;
    s->data = e;//新结点数据域赋值
    s->next = p->next;//新结点指针域指向p的后继结点
    p->next = s;//p的指针域指向新结点
}

//在第i个位置插入元素e
void InsertList(LinkList L, int i, ElemType e){
    Lnode* p = GetElem(L, i - 1);//找到第i-1个结点
    InsertNextNode(p, e);
    // InsertPriorNode(p, e);
}

//前插操作：在p结点前插入元素e
void InsertPriorNode(Lnode* p, ElemType e){
    if(p == NULL)
        return;
    Lnode* s = (Lnode*)malloc(sizeof(Lnode));//申请新结点内存
    if(s == NULL)
        return;
    s->next = p->next;//新结点指针域指向p的后继结点
    p->next = s;//p的指针域指向新结点
    //交换p和s的数据域
    s->data = p->data;
    p->data = e;
}

//按位序删除（带头结点）
void DeleteList(LinkList L, int i){
    Lnode* p = GetElem(L, i - 1);//找到第i-1个结点
    if(p == NULL)
        return;
    Lnode* q = p->next;//q指向第i个结点（以备释放）
    if(q == NULL)
        return;
    // e= q->data;//保存删除节点的数据域
    p->next = q->next;//断开q
    free(q);
}

//删除指定结点p
void DeleteNode(Lnode* p){
    if(p == NULL)
        return;
    Lnode* q = p->next;//q指向p的后继结点
    p->data = p->next->data;//交换p和p后续结点的数据域
    p->next = q->next;//断开q
    free(q);
}

//按位查找，返回第i个元素
Lnode* GetElem(LinkList L, int i){
    if(i < 0)
        return NULL;
    Lnode* p = L;//p指向头结点
    int j = 0;
    //遍历链表，找到第i个结点
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    if(!p || j > i)//i值不合法
        return NULL;
    return p;
}

//按值查找，找到数据域为e的结点
Lnode* LocateElem(LinkList L, ElemType e){
    Lnode* p = L->next;//p指向首元结点
    while(p != NULL && p->data != e)
        p = p->next;
    if(!p || p->data != e)
        return NULL;
    return p;
}

//求表长
int Length(LinkList L){
    Lnode* p = L->next;//p指向首元结点
    int count = 0;
    while(p != NULL){
        p = p->next;
        count++;
    }
    return count;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList L){
    ElemType e;
    Lnode* s, * r;//s为新结点，r为尾指针
    L = (Lnode*)malloc(sizeof(Lnode));
    r = L;
    scanf("%d", &e);
    while(e != 9999){
        s = (Lnode*)malloc(sizeof(Lnode));//申请新结点内存
        s->data = e;//新结点数据域赋值
        s->next = NULL;//新结点指针域置空

        r->next = s;//插入链表尾部
        r = s;//r指向新的尾结点
        scanf("%d", &e);
    }
    r->next = NULL;//表示当前链表结束
    return L;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList L){
    ElemType e;
    Lnode* s;
    L = (Lnode*)malloc(sizeof(Lnode));
    L->next = NULL;//初始化为空表
    scanf("%d", &e);
    while(e != 9999){
        s = (Lnode*)malloc(sizeof(Lnode));//申请新结点内存
        s->data = e;//新结点数据域赋值

        s->next = L->next;//新结点指针域指向首元结点
        L->next = s;//头指针指向新结点
        scanf("%d", &e);
    }
    return L;
}

int main(){
    LinkList L;
    L = List_HeadInsert(L);
    PrintList(L);
    printf("------------------------\n");
    InsertList(L, 2, 100);
    PrintList(L);
    printf("------------------------\n");
    DeleteList(L, 3);
    PrintList(L);
    printf("------------------------\n");
    LocateElem(L, 100);
    PrintList(L);
    printf("------------------------\n");
    printf("%d\n", Length(L));
    printf("------------------------\n");
    // ClearList(L);
    DestroyList(L);
    PrintList(L);
    return 0;
}