//5 8
//圖的邊資訊
//1 2 2
//1 5 10
//2 3 3
//2 5 7
//3 1 4
//3 4 4
//4 5 5
//5 3 3


#include <stdio.h>

int min=99999999, book[101], n, e[101][101];    //我們這裡假設99999999為正無窮

//cur是目前所在的城市編號，dis是目前已經走過的路程
void dfs(int cur, int dis){
    int j;

    //如果目前走過的路程已經大於之前找到的最短路徑，則沒有必要在繼續往下嘗試了，立即返回
    //這一步判斷節省了很多時間
    if(dis>min){
        return;
    }

    //判斷是否到達了目標城市
    if(cur==n){
        if(dis<min){
            min=dis;
        }
        return;
    }

    //判斷城市cur到城市j是否有路，並判斷城市j是否在已走過的路徑上。
    for(j=1;j<=n;j=j+1){
        if(e[cur][j]!=99999999 && book[j]==0){

            //這一行可以知道深度優先是如何疊代的。
            printf("\n進入DFS：(%d %d) ", cur, j);

            book[j]=1;  //標記城市已經在路徑中
            dfs(j, dis+e[cur][j]);  //從城市j再出發，繼續尋找目標城市
            book[j]=0;  //之前一步探索完畢之後，取消對城市j的標記
        }
    }

    return;
}


int main(){
    int i, j, m, a, b, c;
    scanf("%d %d", &n, &m);

    //初始化二維陣列
    for(i=1;i<=n;i=i+1){
        for(j=1;j<=m;j=j+1){
            if(i==j){
                e[i][j]=0;
            }else{
                e[i][j]=99999999;
            }
        }
    }

    //讀入城市之間的道路
    for(i=1;i<=m;i=i+1){
        scanf("%d %d %d", &a, &b, &c);
        e[a][b]=c;
    }

    //從1號城市出發
    book[1]=1;  //標記1號城市已經在路徑中
    dfs(1,0);   //1表示目前所在的城市標號，0表示目前已經走過的路程
    printf("\nmin=%d", min);  //列印1號城市到5號城市的最短路徑。

    getchar();
    getchar();
    return 0;

}


