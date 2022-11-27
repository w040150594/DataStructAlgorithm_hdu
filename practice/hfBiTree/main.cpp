#include<bits/stdc++.h>
using namespace std;
int n = 0;
char word[10001];//
int wei[10001];//权重
typedef struct HuffmanTree{
    char pi;
    int weight;
    int parent,lchild,rchild;
}Tree;
string code[10000];
//初始化操作
Tree *hftree;
void crearteTree(int n){
    hftree= (Tree*) malloc(sizeof(Tree)*(2*n-1));
    for(int i = 0;i<n;i++){
        hftree[i].pi = word[i];
        hftree[i].weight = wei[i];
        hftree[i].parent = hftree[i].lchild = hftree[i].rchild = -1;
    }
    for(int i = n;i<2*n-1;i++){
        hftree[i].parent = -1;
        hftree[i].pi = '$';
        int min = 1000000;//最小
        int cmin = 1000000;//次小
        int mpi = -1;
        int cmpi = -1;
        for(int j = 0;j<i;j++){
            if(hftree[j].parent == -1) {
                if (hftree[j].weight < min) {
                    if(min < cmin){
                        cmin = min;
                        cmpi = mpi;
                    }
                    min = hftree[j].weight;
                    mpi = j;
                }
                else {
                    if (hftree[j].weight < cmin) {
                        cmin = hftree[j].weight;
                        cmpi = j;
                    }
                }
            }
        }
        hftree[i].weight = cmin+min;
        hftree[i].lchild = mpi;
        hftree[i].rchild = cmpi;
        hftree[mpi].parent = i;
        hftree[cmpi].parent = i;
    }
}
void Init(){
    cout<<"输入的是（1.权重）还是（2.字符出现频率）"<<endl;
    int is1;
    cin>>is1;
    if(is1 == 1){
        cout<<"输入字符集大小:";
        cin>>n;
        cout<<"输入"<<n<<"个字符集:（如果输入的是空格，请用'.'表示）";
        for(int i = 0;i<n;i++){
            cin>>word[i];
        }
        cout<<"输入"<<n<<"个字符集的权重:";
        for(int i = 0;i<n;i++){
            cin>>wei[i];
        }
    }
    else{
        cout<<"输入字符集大小:";
        cin>>n;
        cout<<"输入"<<n<<"个字符集:（如果输入的是空格，请用'.'表示）";
        for(int i = 0;i<n;i++){
            cin>>word[i];
        }
        cout<<"输入"<<n<<"个字符集的出现频率:";
        for(int i = 0;i<n;i++){
            double as;
            cin>>as;
            wei[i] = as * 100;
        }
    };
    cout<<"输入数据成功，正在创建哈夫曼树......."<<endl;
    crearteTree(n);
    cout<<"创建哈夫曼树成功，下面输出该哈夫曼树的参数。"<<endl;
    cout<<"结点i"<<"\t字符"<<"\t权值"<<"\t双亲"<<"\t左孩子"<<"\t右孩子"<<endl;
    for(int i = 0;i<2*n-1;i++){
        cout<<i<<"\t"<<hftree[i].pi<<"\t"<<hftree[i].weight<<"\t"<<hftree[i].parent<<"\t"<<hftree[i].lchild<<"\t"<<hftree[i].rchild<<endl;
    }
    FILE *fp;
    if((fp = fopen("hfmTree.txt","w")) == NULL){
        cout<<"打开文件失败"<<endl;
    }
    //数据存进hfmTree.txt文件
    for(int i = 0;i<2*n-1;i++){
        fprintf(fp,"%d ",i);
        fwrite(&word[i],1,1,fp);
        fprintf(fp," %d ",hftree[i].weight);
        fprintf(fp,"%d ",hftree[i].parent);
        fprintf(fp,"%d ",hftree[i].lchild);
        fprintf(fp,"%d ",hftree[i].rchild);
    }
    fclose(fp);
    cout<<"哈夫曼树创建成功并且存入文件hfmTree.txt中了！！！"<<endl;
}
//初始化操作


//E编码
void bianma(Tree *tree,int pi,string s){//递归编码
    code[tree[pi].pi] = s;
    if(tree[pi].lchild != -1)
        bianma(tree,tree[pi].lchild,s+"0");
    if(tree[pi].rchild != -1)
        bianma(tree,tree[pi].rchild,s+"1");
}
void E(){//编码
    bianma(hftree,2*n-2,"");
    cout<<"二进制码生成成功，编码结果为:"<<endl;
    cout<<"结点i"<<"\t字符"<<"\t权值"<<"\t编码"<<endl;
    for(int i = 0;i<n;i++){
        cout<<i<<"\t"<<hftree[i].pi<<"\t"<<hftree[i].weight<<"\t"<<code[hftree[i].pi]<<endl;
    }
    cout<<"接下来读取ToBetran文件的正文并且进行编码:"<<endl;
    FILE *fp = fopen("ToBetran.txt","r");
    char mp[1001];
    int po = 0;
    while(1){
        char di = fgetc(fp);
        if(di == EOF)
            break;
        mp[po++] = di;
    }
    fclose(fp);
    string s = mp;
    cout<<mp<<"的编码为: ";
    string ans = "";
    for(int i = 0;i<po;i++){
        if(mp[i]==' '){
            mp[i] = '.';
        }
        cout<<code[mp[i]];
        ans += code[mp[i]];
    }
    cout<<endl;
    cout<<"将编好的码存进CodeFile.txt中"<<endl;
    FILE *p = fopen("CodeFile.txt","w");
    char nnp[ans.length()];
    for(int i = 0;i<ans.length();i++){
        nnp[i] = ans[i];
    }
    fwrite(nnp,sizeof(nnp),1,p);
    fclose(p);
    cout<<"编好的码存进CodeFile.txt成功!!!"<<endl;
}
//E编码



void Menu(){
    cout<<"---------------哈夫曼编码器/译码器----------------"<<endl;
    cout<<"   I:初始化并创建哈夫曼树        E:编码           "<<endl;
    cout<<"   D:对二进制码进行译码         P:打印编码        "<<endl;
    cout<<"   T:哈夫曼树                  Q:退出            "<<endl;
    cout<<"-----------------------------------------------"<<endl;
}
void D(){
    cout<<"先将CodeFile文件中的二进制编码取出:"<<endl;
    FILE *p = fopen("CodeFile.txt","r");
    char ch[10001] ;
    int po = 0;
    while(true){
        char as = fgetc(p);
        if(as == EOF)
            break;
        ch[po++] = as;
    }
    cout<<"CodeFile文件中的二进制编码为:"<<ch<<endl;
    cout<<"接着对二进制编码进行翻译:"<<endl;
    cout<<ch<<"的翻译结果为:";
    int pi = 2*n-2;
    string ans = "";
    for(int i  =0;i < po;i++){
        if(ch[i] == '0'){
            pi = hftree[pi].lchild;
        }
        else{
            pi = hftree[pi].rchild;
        }
        if(hftree[pi].lchild == -1 && hftree[pi].rchild == -1){
            if(hftree[pi].pi == '.'){
                ans+=' ';
            }
            else
               ans+=hftree[pi].pi;
            pi = 2*n-2;
        }
    }
    cout<<ans<<endl;
    cout<<"将其存进TextFile文件中"<<endl;
    FILE *fp = fopen("TextFile.txt","w");
    for(int i = 0;i<ans.length();i++)
    fprintf(fp,"%c",ans[i]);
    fclose(fp);
    cout<<"数据存进TextFile文件成功！"<<endl;
}
//D

//PPPPPPP
void P(){
    cout<<"将CodeFile文件中的数据以50一行在终端进行显示，然后存储进CodePrin文件:"<<endl;
    FILE *cf = fopen("CodeFile.txt","r");
    FILE *cp = fopen("CodePrin.txt","w");
    char temp;
    fscanf(cf,"%c",&temp);
    for(int i = 1;!feof(cf);i++){
        cout<<temp;
        fputc(temp,cp);
        fscanf(cf,"%c",&temp);
        if(i%50 == 0) {
            cout << endl;
            fputc('\n',cp);
        }
    }
    cout<<endl;
    cout<<"存储进CodePrin文件成功！"<<endl;
}
//P

//T
char mp[151][151];
void prin(int l,int r,int num,int ceng){
    mp[l][r] = hftree[num].weight;
    if(hftree[num].lchild !=-1){
        prin(l+1,r - (ceng - l - 1),hftree[num].lchild,ceng);
    }
    if(hftree[num].rchild !=-1){
        prin(l+1,r + (ceng - l - 1),hftree[num].rchild,ceng);
    }
}
int findchenshu(int pi){//递归计算层数
    if(pi == -1){
        return 0;
    }
    int lnum = findchenshu(hftree[pi].lchild) + 1;
    int rnum = findchenshu(hftree[pi].rchild) + 1;
    return max(lnum,rnum);
}
void out(int pi){
    if(pi == -1){
        return ;
    }
    cout<<hftree[pi].pi<<"\t"<<hftree[pi].weight<<endl;
    out(hftree[pi].lchild);
    out(hftree[pi].rchild);
}
void T(){
    cout<<"打印哈夫曼树："<<endl;
    int num = 2*n-2;
    memset(mp,' ',sizeof(mp));//先都存为空格
    int cengshu = findchenshu(2*n-2);//计算层数
    cout<<"测试：层数为:"<<cengshu<<endl;
    int zhongjian = 1;
    for(int i = 1;i<=cengshu;i++){
        zhongjian *= 2;
    }
    zhongjian--;
    prin(0,zhongjian/2,num,cengshu);
    for(int i = 0;i<zhongjian;i++){
        bool is = true;
        for(int j = 0;j<zhongjian;j++){
            if(mp[i][j] == ' '){
                cout<<mp[i][j];
            }
            else{
                is = false;
                cout<<'o';
            }
        }
        cout<<endl;
        if(is){
            break;
        }
    }
    cout<<"输出成功,其中，该树的先序遍历为:"<<endl;
    cout<<"字符"<<"\t"<<"权重"<<endl;
    out(2*n-2);
    cout<<"哈夫曼树打印完毕"<<endl;
}
//T
int main(){
    while(true){
        char choose;//选择什么操作
        Menu();//显示菜单
        cout<<"请输入你想要进行的操作"<<endl;
        cin>>choose;
        switch (choose) {
            case 'I':
                Init();
                break;
            case 'E'://c创建二进制哈夫曼编码，并且从ToBetran文件中读取的正文进行编码，然后存放于CodeFile文件
                E();
                break;
            case 'D'://对CodeFile文件中的二进制编码进行译码。
                D();
                break;
            case 'P':
                P();//将CodeFile文件中的数据以50一行在终端进行显示，然后存储进CodePrin文件
                break;
            case 'T':
                T();//打印哈夫曼树
                break;
            case 'Q':
                exit(0);
            default:
                break;
        }
    }
    return 0;
}
