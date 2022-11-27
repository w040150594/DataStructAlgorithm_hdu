#include<iostream>

#define MAX 100

typedef struct node{

  int adjvexpos;

  struct node* next;

}Rnode;

typedef struct{

  char data;

  Rnode* firstarc;

}Vnode;

typedef struct{

  Vnode* list;

  int length;

}Tree;

Tree* tree;

void CreatTree()

{

  printf("请输入节点的个数\n");

  char x; int i;

  scanf("%d", &tree->length);

  getchar();

  for(int j = 0; j < tree->length; j++)

  {

    printf("请输入第%d个节点\n", j);

    scanf("%c", &x);

    getchar();

    tree->list[j].data = x;

    tree->list[j].firstarc = NULL;

  }

  for(int j = 0; j < tree->length; j++)

  {

    printf("节点存储位置        节点值\n");

    printf("%d               %c\n", j, tree->list[j].data);

  }

  printf("参考以上列表，为以上节点建立关系\n");

  for(int j = 0; j < tree->length; j++)

  {

    printf("输入节点%c后继的存储位置，以-1结束\n", tree->list[j].data);

    scanf("%d", &i);

    getchar();

    while(i != -1)

    {

      Rnode* p = (Rnode*)malloc(sizeof(Rnode));

      p->adjvexpos = i;

      p->next = tree->list[j].firstarc;

      tree->list[j].firstarc = p;

      scanf("%d", &i);

      getchar();

    }

  }

}

void show()

{

  printf("您输入的树如下：\n");

  Rnode* p;

  for(int j = 0; j < tree->length; j++)

  {



    p = tree->list[j].firstarc;

    while(p)

    {

      printf("%c----->%c;", tree->list[j].data, tree->list[p->adjvexpos].data);

      p = p->next;

    }

  }

  printf("\n");

}

void poster()

{

  for(int j = 0; j < tree->length; j++)

  {

    printf("节点序号         节点值\n");

    printf("%d               %c\n", j, tree->list[j].data);

  }

  printf("请选择一个节点序号，我们将为您显示它的后继\n");

  int i;

  scanf("%d", &i);

  getchar();

  Rnode* p;

  p = tree->list[i].firstarc;

  printf("节点%c的后继如下：\n", tree->list[i].data);

  while(p)

  {

    printf("%c;", tree->list[p->adjvexpos].data);

    p = p->next;

  }

  printf("\n");

}

void Menu()

{

  printf("1.建立树；2.显示指定节点的后继；其他：退出\n");

  char input = getchar();

  getchar();

  if(input == '1')

  {

    CreatTree();

    show();

    Menu();

  }

  else if(input == '2')

  {

    poster();

    Menu();

  }

  else

    printf("bye!");

}

int main()

{

  tree = (Tree*)malloc(sizeof(Tree));

  tree->list = (Vnode*)malloc(MAX * sizeof(Vnode));

  Menu();

}
