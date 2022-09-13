//循环链表循环条件区别：p!=L;P->next!=L
//带尾指针循环链表合并
// void MergeList(LinkList La, LinkList Lb){
//     p = La->next;p存表头结点指针
//     La->next = Lb->next->next;//Lb表头连接Ta表尾
//     free(Lb->next);释放Lb的头结点
//     Lb->next = p;Lb表头连接La表头（实现循环）
// }
//----------------------------------------------------------------------------
//双向链表p之前插入某个元素
//s=malloc(sizeof(DLNode));
//s->data=e;新结点数据域赋值
//连接前驱
//s->prior=p->prior;新结点前驱指针域指向p的前驱结点
//p->prior->next=s;p的前驱结点的后继指针域指向新结点
//连接后继
// s->next=p;新结点后继指针域指向p
// p->prior=s;p的前驱指针域指向新结点
//----------------------------------------------------------------------------
//双向链表删除结点b
// b->prior->next=b->next;b的前驱结点的后继指针域指向b的后继结点
// b->next->prior=b->prior;b的后继结点的前驱指针域指向b的前驱结点
// free(b);释放b结点
//----------------------------------------------------------------------------
//链表合并
// void MergeList(LinkList La, LinkList Lb, LinkList Lc){
//     Lnode* pa = La->next;
//     Lnode* pb = Lb->next;
//     Lnode* pc = Lc = La;用La的头结点作为Lc的头结点
//     while(pa && pb){
//         if(pa->data <= pb->data){
//             pc->next = pa;将pa所指结点插入到pc所指结点之后
//             pc=pa;pc指向新的尾结点
//             pa = pa->next;//pa指向下一个结点
//         }
//      if(pa)
//          pc->next = pa;
//      else
//          pc->next = pb;
//      free(Lb);
// }
//----------------------------------------------------------------------------
//链表逆置（头插法）
// void Reverse(LinkList L){
//     Lnode* p = L->next;//p为工作指针（指向首元结点）
//     L->next = NULL;//置空
//     while(p){
//         Lnode* r = p->next;//r为p的后继结点
//         p->next = L->next;//将p插入到头结点的后面
//         L->next = p;
//         p = r;
//     }
// }

//----------------------------------------------------------------------------
//两个非递减有序链表合并为一个非递增有序链表
// void MergeList(LinkList La, LinkList Lb){
//     Lnode pa = La->next;
//     Lnode pb = Lb->next;
//     Lnode *r;
//     La->next = NULL;
//     while(pa && pb){
//         if(pa->data <= pb->data){
//             r=pa->next;//r暂存pa的后继结点
//             pa->next = La->next;
//             La->next = pa;
//             pa = r;
//         }
//         else{
//             r=pb->next;
//             pb->next = La->next;
//             La->next = pb;
//             pb = r;
//         }
//     }
//     if(pa)
//         pb = pa;
//     while(pb){
//         r=pb->next;
//         pb->next = La->next;
//         La->next = pb;
//         pb = r;
//     }
//     free(Lb);
// }