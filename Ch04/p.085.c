//地圖
//0 0 1 0
//0 0 0 0
//0 0 1 0
//0 1 0 0
//0 0 0 1

//測資
//1 1 4 3

#include <stdio.h>

int n, m, p, q, min=99999999;
int a[51][51], book[51][51];

void dfs(int x, int y, int step){
    //這個結構的格式以及後來要呼叫的方式要學一下!!
    int next[4][2]={
        { 0, 1},//向右走
        { 1, 0},//向下走
        { 0,-1},//向左走
        {-1, 0}//向上走
    };

    int tx, ty, k;

    //判斷是否到達小哈(目標)位置
    if(x==p && y==q){
        //更新最小值
        if(step<min){
            min=step;
        }

        //這條路徑找到人，所以要返回道上次呼叫函數的地方
        return;
    }

    //列舉四種方法
    for(k=0;k<3;k=k+1){
        //計算下一個點的位置
        tx=x+next[k][0];
        ty=y+next[k][1];

        //判斷是否越界
        if(tx<1 || tx>n || ty<1 || ty>m){
            continue;
        }
        //在迴圈敘述中
        //我們可以使用 break 指令讓它強制離開迴圈
        //或是用 continue 指令來忽略下面的指令而繼續下一次的迴圈

        //判斷該點是否為障礙物，或是已經在路徑中
        if(a[tx][ty]==0 && book[tx][ty]==0){
            book[tx][ty]=1;     //標記這個點已經走過
            dfs(tx, ty, step+1);//開始嘗試下一個點
            book[tx][ty]=0;     //嘗試結束，取消這個點的標記
        }
    }

    //全部的所有路徑可能都嘗試完，所以return
    return;
}



int main(){
    int i, j, startx, starty;

    //讀入n和m，n為行，m為列
    scanf("%d %d", &n, &m);

    //讀入迷宮
    for(i=1;i<=n;i=i+1){
        for(j=1;j<=m;j=j+1){
            scanf("%d", &a[i][j]);
        }
    }

    //讀入起點與終點
    scanf("%d %d %d %d", &startx, &starty, &p, &q);

    //從起點開始搜尋
    book[startx][starty]=1; //標記起點已經在路徑中，防止後面重複走

    //第一個參數是起點的x座標，第二個參數是起點的y座標，第三個參數是初始步數為0
    dfs(startx, starty, 0);

    //輸出最短步數
    printf("%d", min);

    getchar();
    getchar();

    return 0;
}


