//測資
//5 7 1 5
//邊的資訊
//1 2
//1 3
//2 3
//2 4
//3 4
//3 5
//4 5

#include <stdio.h>

struct node {
    int p;
}point[51];
int top=0;

int min=99999999, book[51]={0}, n, e[51][51], end, sol_num=0, final_sol;


void dfs(int cur, int dis){

    int i;

    //但對是否已經到達目標城市
    if(cur==end){

        sol_num=sol_num+1;
        printf("可行解方案%d：", sol_num);
        for(i=1;i<=top;i=i+1){
            printf("%d ", point[i]);
        }
        printf("\n");

        if(dis<min){
            min=dis;
            final_sol=sol_num;
        }
        return;
    }



    //從1號城市到n號城市依次嘗試。
    for(i=1;i<=n;i=i+1){
        if(e[cur][i]!=99999999 && book[i]==0){

            book[i]=1;
            //如果book的判斷想放在for迴圈的外面
            //那一開始主程式就不能book[start]=1

            //將目前嘗試的點進入堆疊
            top=top+1;
            point[top].p=cur;

            dfs(i, dis+1);
            book[i]=0;
            top=top-1;
        }
    }

    return;
}



int main(){
    int i, j, m, a, b, start;
    scanf("%d %d %d %d", &n, &m, &start, &end);

    //初始化二維陣列
    for(i=1;i<=n;i=i+1){
        for(j=1;j<=n;j=j+1){
            if(i==j){
                e[i][j]=0;
            }else{
                e[i][j]=99999999;
            }
        }
    }

    //讀入城市間的航班
    for(i=1;i<=m;i=i+1){
        scanf("%d %d", &a, &b);

        //此為無向圖
        e[a][b]=1;
        e[b][a]=1;
    }

    sol_num=0;
    book[start]=1;
    dfs(start, 0);  //表示start出發的城市編號，0表示已經走過的路程。
    printf("\n選擇方案%d\n", sol_num);
    printf("城市[%d]到城市[%d]的最少轉機次數=%d", start, end, min);

    getchar();
    getchar();
    return 0;
}
