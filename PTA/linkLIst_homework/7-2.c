//重排链表
#include<stdio.h>

#define MAXSIZE 100001
#define HEADNODE 100000

typedef struct Node{
    int data; //记录当前结点的数据
    int next; //记录下一个结点的地址
}Node;

int main(){
    Node a[MAXSIZE]; //存储链表，下标为结点地址
    int firstAddress, num; //记录第一个结点的地址和结点数量
    scanf("%d %d", &firstAddress, &num);
    int init[MAXSIZE];//init存储原来的结点地址顺序
    int reNew[MAXSIZE]; //reNew存储改变后的结点地址顺序。
    int address, data, next;

    //输入数据，创建链表
    int i = 0;
    for(i = 0; i < num; i++){
        //给地址为address的结点赋值
        scanf("%d %d %d", &address, &data, &next);
        a[address].data = data;
        a[address].next = next;
    }

    //把初始链表的结点地址按顺序存储到init数组里
    int count = 0; //计算一共有多少个有效结点（前面输入的结点可能是不在链表里的“废结点”）
    address = firstAddress;
    while(address != -1){
        init[count] = address;
        address = a[address].next;
        count++;
    }
    //这时，有效结点的总个数为count

    //把修改后的地址顺序存储到reNew里
    int initLeft = 0, initRight = count - 1; //相当于init的指针
    //initLeft指向init数组的左侧，initRight指向init的右侧开始，两者往中间靠
    int new_point = 0; //相当于reNew数组的指针
    while(initLeft <= initRight){
        if(initLeft < initRight){
            //把init数组中最后一个结点的地址，赋值给reNew数组的第一个元素
            reNew[new_point] = init[initRight];
            new_point++;//指向第二位
            initRight--;//指向倒数第二个结点地址

            //再把init数组中第一个结点的地址，赋值给reNew数组的第二个元素
            reNew[new_point] = init[initLeft];
            new_point++; //指向第三位
            initLeft++; //指向第二个结点的地址

            //一次循环相当于给reNew传了两个元素，一个是init的最后一位，一个是init的第一位
            //当initLeft与initRight相遇的时候，循环就退出了
        }
        else{
            //initLeft == initRight
            //这时候说明有效结点个数是整数
            reNew[new_point] = init[initLeft];
            new_point++;
            initLeft++;
            //这时reNew数组的元素就是题目要求的结点顺序
        }
    }

    //按照reNew数组的地址顺序打印每个结点的地址和数据
    for(i = 0; i < count - 1; i++){
        //输出的顺序为：当前结点的地址，结点数据，下一结点的地址
        //这里要注意的是：这里的“下一结点”已经不是存储在a数组里的a[i].next了（.next对应的是起始链表顺序）
        //所以这里输出第三位，应该是reNew数组里当前结点的下一个结点地址
        printf("%05d %d %05d\n", reNew[i], a[reNew[i]].data, reNew[i + 1]);
    }
    printf("%05d %d -1\n", reNew[i], a[reNew[i]].data);

    return 0;
}


