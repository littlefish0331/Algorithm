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

int a[51][51];
int book[51][51], n, m, sum;

void dfs(int x, int y, int color){
    //定義一個方向陣列
    int next[4][2]={
        { 0, 1},
        { 1, 0},
        { 0,-1},
        {-1, 0}
    };

    int k, tx, ty;
    a[x][y]=color;  //對a[x][y]這個格子進行染色。

    //列舉四個方向
    for(k=0;k<=3;k=k+1){
        tx=x+next[k][0];
        ty=y+next[k][1];

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

            dfs(tx, ty, color);
        }
    }

    return;
}

int main(){
    int i, j, startx, starty;
    scanf("%d %d %d %d", &n, &m, &startx, &starty);

    //讀入地圖
    for(i=1;i<=n;i=i+1){
        for(j=1;j<=m;j=j+1){
            scanf("%d", &a[i][j]);
        }
    }

    book[startx][starty]=1;
    sum=1;

    //從降落的點開始。
    dfs(startx,starty,-1);

    //最後輸出已經染色後的地圖。
    for(i=1;i<=n;i=i+1){
        printf("\n");
        for(j=1;j<=m;j=j+1){
            printf("%3d", a[i][j]); //%3d中的3是C語言中的場寬。
        }

    }

    getchar();
    getchar();
    return 0;

}


