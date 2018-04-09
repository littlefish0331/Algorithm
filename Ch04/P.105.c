//地圖
//10 10 6 8
//1 2 1 0 0 0 0 0 2 3
//3 0 2 0 1 2 1 0 1 2
//4 0 1 0 1 2 3 2 0 1
//3 2 0 0 0 1 2 4 0 0
//0 0 0 0 0 0 1 5 3 0
//0 1 2 1 0 1 5 4 3 0
//0 1 2 3 1 3 6 2 1 0
//0 0 3 4 8 9 7 5 0 0
//0 0 0 3 7 8 6 0 1 2
//0 0 0 0 0 0 0 0 1 0


#include <stdio.h>

struct note {
    int x;  //橫坐標
    int y;  //縱坐標
};

int main(){
    struct note que[2501];
    int head, tail;
    int a[51][51];
    int book[51][51]={0};
    int i, j, k, sum, max=0, mx, my, n, m, startx, starty, tx, ty;

    //定義一個方向陣列
    int next[4][2]={
        { 0, 1},
        { 1, 0},
        { 0,-1},
        {-1, 0}
    };

    //讀入n行m列以及小哼降落的座標
    scanf("%d %d %d %d", &n, &m, &startx, &starty);

    //讀入地圖
    for(i=1;i<=n;i=i+1){
        for(j=1;j<=m;j=j+1){
            scanf("%d", &a[i][j]);
        }
    }

    //佇列初始化
    head=1;
    tail=1;

    //往佇列插入降落的起始座標
    que[tail].x=startx;
    que[tail].y=starty;
    tail=tail+1;
    book[startx][starty]=1;
    sum=1;  //因為現在就站在一塊陸地上。

    //當佇列部為空的時候進行迴圈
    while(head<tail){
        //列舉四個方向
        for(k=0;k<=3;k=k+1){
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];

            //判斷是否越界
            //和之前的例子不同是因為以前的例子外圍是圍牆。
            if(tx<1 || tx>n || ty<1 || ty>m){
                continue;
            }

            //判斷是否為陸地或者是否曾經走過
            if(a[tx][ty]>0 && book[tx][ty]==0){
                sum=sum+1;

                //每個點只入佇列一次，標記這個點已經走過
                book[tx][ty]=1;

                //將新擴展的點加入佇列
                que[tail].x=tx;
                que[tail].y=ty;
                tail=tail+1;
            }

        }

        head=head+1;
        //注意這個地方千萬不能忘記。
        //當一個擴展結束後，head=head+1才能繼續往下擴展。

    }

    //最後輸出島嶼的大小。
    printf("\n%d\n", sum);

    getchar();
    getchar();
    return 0;

}


