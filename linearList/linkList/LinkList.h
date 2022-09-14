typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node* next;
}Lnode, * LinkList;
// *LinkList也可看成一个结点类型，即Lnode*，即指向结点的指针，强调是链表

//双向链表
// typedef struct DNode{
//     ElemType data;
//     struct DNode* prior;//前驱指针域
//     struct DNode* next;//后驱指针域
// }Dnode, * DLinkList;

void InitList(LinkList L);
int IsEmpty(LinkList L);
void ClearList(LinkList L);
void DestroyList(LinkList L);
void PrintList(LinkList L);
void InsertList(LinkList L, int i, ElemType e);
void InsertNextNode(Lnode* p, ElemType e);
void InsertList(LinkList L, int i, ElemType e);
void DeleteList(LinkList L, int i);
void DeleteNode(Lnode* p);
Lnode* GetElem(LinkList L, int i);
Lnode* LocateElem(LinkList L, ElemType e);
int Length(LinkList L);
LinkList List_TailInsert(LinkList L);
LinkList List_HeadInsert(LinkList L);

