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

//利用佇列來儲存可行解
struct note {
    int p;
}point[101];
int top=0;

//cur是目前所在的城市編號，dis是目前已經走過的路程
void dfs(int cur, int dis){
    int j;
    int i;


    //如果目前走過的路程已經大於之前找到的最短路徑，則沒有必要在繼續往下嘗試了，立即返回
    //這一步判斷節省了很多時間
    //但是這一步會導致後面可能無法顯示所有的可行解!!
    if(dis>min){
        return;
    }


    //入堆疊，必須注意
    //1.前面會不會有可行解因為條件而無法進入堆疊的情形。例如前面的dis>min
    //2.不是成功了才進入堆疊，這樣沒辦法儲存到路徑的。所以不是放在if(cur==n)
    top=top+1;
    point[top].p=cur;


    //判斷是否到達了目標城市
    if(cur==n){

        //輸出可行解!!
        printf("\n\n 這條路可以成功：");
        for(i=1;i<=top;i=i+1){
            printf("%d ", point[i].p);
        }

        if(dis<min){
            min=dis;
        }
        return;
    }

    //判斷城市cur到城市j是否有路，並判斷城市j是否在已走過的路徑上。
    for(j=1;j<=n;j=j+1){

        //這一行可以知道深度優先是怎麼嘗試的。
        printf("\n嘗試路線(%d %d) ", cur, j);


        if(e[cur][j]!=99999999 && book[j]==0){

            //這一行可以知道深度優先是如何疊代的。
            printf("\n進入DFS：(%d %d) ", cur, j);

            book[j]=1;  //標記城市已經在路徑中
            dfs(j, dis+e[cur][j]);  //從城市j再出發，繼續尋找目標城市

            book[j]=0;  //之前一步探索完畢之後，取消對城市j的標記
            top=top-1;  //將目前嘗試的座標出堆疊
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
    printf("\n\nmin=%d", min);  //列印1號城市到5號城市的最短路徑。

    getchar();
    getchar();
    return 0;

}


