#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <windows.h>
#define N 6      //定义顶点集合个数，可以根据需要更改。 
#define Max_num N*N
#define inf 99     //inf代替为无穷大，可以更改值 

int  s[N] = { 0 }, G[N][N] = { 0 }; //s存放路径经过的顶点集合，G为图邻接矩阵 
static char u[N] = { '0' };    //顶点v的集合全集u 

int main() {
    int i, j, vs, vd;
    char start, end;
    void dijkstra(int vs, int vd);   //vs对应start，vd对应end 
    void input_graph(int a[N][N]); //输入无向图关系 
    void display_matrix(int a[N][N]); //显示无向图邻结矩阵 
    void copyright();
    copyright();
    //初始化图G，对角线为0，其余为无穷大inf  
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (i != j)
                G[i][j] = inf;

    //输入并显示G的矩阵
    input_graph(G);  display_matrix(G);
    putchar(getchar());
    // 输入起点和终点start,end 
    printf("\n请输入起点和终点(两者空格隔开，回车结束，格式为a d或0 3等)：\n");
    scanf("%c %c", &start, &end);
    printf("\n您输入起点和终点start-->end为：%c-->%c，", start, end);
    //找到起点和重点在标号数组中相对位置如a对应0，b对应1 
    for (j = 0; j < N; j++) {
        if (start == u[j]) vs = j; //扫描集合A，对比找到在二维数组中位置i,j 
        if (end == u[j])   vd = j; //如start=a,end=d,则找到i=0,j=3,从而a[0][1]=1 
    }
    printf("即：第%d号结点（vs）-->第%d号结点（vd）\n", vs, vd);

    dijkstra(vs, vd);    //程序的核心部分 

    printf("\n");
    system("pause");
    printf("学号 :202205280140 姓名:谭振宇");
    return 0;
}

//下面是函数实现部分 

void dijkstra(int vs, int vd) {    //声明起点vs到终点vd的dijkstra函数 
    int path[N], dist[N];
    int i, p, min;
    void display(int p, int s[N], int path[N], int dist[N]);
    void output(int path[N], int vs, int vd);
    s[vs] = 1; p = vs;       //p是指s中当前结点，开始为起点VS，状态为1
    for (i = 0; i < N; i++)
    {
        dist[i] = G[vs][i];
        if (dist[i] == inf)  //inf代表无穷大 
            path[i] = -1;   //初始化，其他与vs相连的前驱结点为vs， 否则为-1
        else
            path[i] = vs;
    }
    putchar(10);
    display(p, s, path, dist);

    while (s[vd] != 1) {
        min = inf;
        for (i = 0; i < N; i++)
            if (s[i] == 0 && dist[i] < min) {
                p = i;
                min = dist[i];
            }
        s[p] = 1;       //找出一号新的入S结点，标记为1，下次不再找 

        for (i = 0; i < N; i++) {          //扫描S，找0值，寻找下一最短路径
            if (s[i] == 0)            //比较各路径长度，找出下一入S结点 
                if (G[p][i] < inf && G[p][i] + dist[p] < dist[i])                  //min(所有与p相邻结点的路径长度)
                {
                    dist[i] = G[p][i] + dist[p];
                    path[i] = p;
                }
        }

        display(p, s, path, dist);
    }
    printf("%c已经进入S，结束！最短路径长度就是dist中第%d号结点的值：%d\n", u[vd], vd, dist[vd]);
    output(path, vs, vd);
}

void display(int p, int s[N], int path[N], int dist[N]) {
    int i;
    static int count = 1;
    printf("第%d步:当前处理结点p值指向第%d号结点%c\n", count, p, u[p]);
    printf("当前u集合中结点全集为:");
    for (i = 0; i < N; i++) { printf("%5c", u[i]); }
    putchar(10);     //putchar(10)为换行符，相当于printf("\n") 
    printf("当前s集合中结点状态为:");
    for (i = 0; i < N; i++) { printf("%5d", s[i]); }
    putchar(10);
    printf("当前path中结点状态为：");
    for (i = 0; i < N; i++) { printf("%5d", path[i]); }
    putchar(10);
    printf("当前dist中结点状态为：");
    for (i = 0; i < N; i++) { printf("%5d", dist[i]); }
    putchar(10);
    putchar(10);
    count++;
    system("pause");
}

void input_graph(int a[N][N]) {
    int i = 0, j = 0, m, k, w;
    int choise;    //无向图还是有向图选择 
    char c1, c2;
    printf("请按顺序输入图G的%d个顶点集合v:(不空格回车结束)\n", N);
    for (m = 0; m < N; m++)
        scanf("%c", &u[m]);
    putchar(getchar());    //把回车符给输出，即换行，否则回车符会影响后面的字符读取 
    printf("请问是无向图还是有向图:(无向图输入0，有向图输入1)：\n");
    scanf("%d", &choise);
    putchar(getchar());
    printf("\n请输入图的两点关系及距离构成的边集E:（如ab 5,或01 5,以##0结束）\n");
    for (k = 0; k < Max_num - 1; k++) {
        scanf("%c%c %d,", &c1, &c2, &w);
        if (c1 == '#') break;
        for (m = 0; m < N; m++) {
            if (c1 == u[m])  	i = m; //扫描集合A，对比找到在二维数组中位置i,j 
            if (c2 == u[m])   j = m; //如c1=a,c2=b,则找到i=0,j=1,从而a[0][1]=1 
        }
        a[i][j] = w;      //有向图，单向向为1 
        choise == 0 ? (a[j][i] = w) : (choise = 1);     //无向图，双向为1 
    }
    printf("\n");
}

void display_matrix(int c[N][N]) {
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%4d", c[i][j]);
        printf("\n");
    }
    system("pause");
}

void output(int path[N], int vs, int vd) {
    int i, j, p, num = 0, temp[N] = { 0 };
    temp[0] = vd; p = vd;
    printf("\n");

    printf("从最后的path数组倒溯可得：");
    printf("%d号点   ", vd);
    while (p != vs) {
        p = path[p];
        num++;
        temp[num] = p;
        printf("%d号点  ", p);
    }
    printf("\n因此起点到终点最短路径为：");
    for (i = num; i >= 0; i--) {
        j = temp[i];
        printf("%3c    ", u[j]);
    }
    printf("\n\n");
    system("pause");
    printf("\n");
    printf("\n总结：1、Dijkstra算法，步骤最少2步，最多等于结点个数，时间复杂度为O(n平方)；");
    printf("\n      2、不断扫描dist，找未进入s的最短路径，终点进入s即可，无需每个结点都入；");
    printf("\n      3、每个未进s的结点i，与当前p的距离+dist[p]，再与dist[i]比较取最小值;");
    printf("\n      4、Dijkstra算法的最短路径长度，只要看dist数值中终点对应值；");
    printf("\n      5、Dijkstra算法最短路径由path数值中倒溯得到，非常简单 ");
}
void copyright() {
    int i;
    for (i = 0; i < 6; i++)
        printf("\n");
    system("color 0C");
    printf("本Dijkstra算法教学程序版权属于谷老师和计科系全体同学。\n");
    printf("      欢迎计科系同学们学习交流，共同进步！\n");
    for (i = 0; i < 6; i++)
        printf("\n");
    system("pause");
    system("cls");
    system("color 0f");
}
