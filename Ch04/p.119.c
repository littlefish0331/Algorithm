//水管地圖
//5 4
//5 3 5 3
//1 5 3 0
//2 3 5 1
//6 1 1 5
//1 5 5 4

#include <stdio.h>

int a[51][51];  //假設土地大小不超過50*50
int book[51][51], n, m, flag=0;

struct note{
    int x;
    int y;
    int f;
}s[100];
int top=0;

void dfs(int x, int y, int front){

    //可以看到程式嘗試的方法
    //就會發現其實浪費蠻多時間的!!
    printf("\n-%d,%d,%d- ", x, y, front);

    int i;
    //判斷這裡是否到達終點，要注意這裡的y座標為m+1
    //注意判斷是否到達終點一定要放在越界判斷前面。
    if(x==n && y==m+1){
        flag=1;
        for(i=1;i<=top;i=i+1){
            printf("(%d,%d,%d) ", s[i].x, s[i].y, s[i].f);
            //程式碼改進，如此一來就可以確認進水口的方向了
        }

        return;
    }

    //判斷是否越界
    if(x<1 || x>n || y<1 ||y>m){
        return;
    }

    //判斷這個管道是否在路徑中已經使用過
    if(book[x][y]==1){
        return;
    }
    book[x][y]=1;   //標記目前使用這個管道。

    //將目前嘗試的座標入堆疊。
    top=top+1;
    s[top].x=x;
    s[top].y=y;
    s[top].f=front;

    //目前水管是直管的情形
    if( a[x][y]>=5 && a[x][y]<=6 ){
        if(front==1){   //進水口在左邊
            dfs(x, y+1, 1); //只能用5號這種擺放方式。
        }
        if(front==2){   //進水口在上邊
            dfs(x+1, y, 2); //只能用6號這種擺放方式。
        }
        if(front==3){   //進水口在右邊
            dfs(x, y-1, 3); //只能用5號這種擺放方式。
        }
        if(front==4){   //進水口在下邊
            dfs(x-1, y, 4); //只能用6號這種擺放方式。
        }
    }

    //目前水管是彎管的情形
    if( a[x][y]>=1 && a[x][y]<=4 ){
        if(front==1){   //進水口在左邊
            dfs(x+1, y, 2); //3號狀態。
            dfs(x-1, y, 4); //4號狀態。
        }
        if(front==2){   //進水口在上邊
            dfs(x, y+1, 1); //1號狀態。
            dfs(x, y-1, 3); //4號狀態。
        }
        if(front==3){   //進水口在右邊
            dfs(x-1, y, 4); //1號狀態。
            dfs(x+1, y, 2); //2號狀態。
        }
        if(front==4){   //進水口在下邊
            dfs(x, y+1, 1); //2號狀態。
            dfs(x, y-1, 3); //3號狀態。
        }
    }

    //取消標記
    book[x][y]=0;
    top=top-1;  //將目前嘗試的座標出堆疊。

    return;
}


int main(){
    int i, j, num=0;
    scanf("%d %d", &n, &m);

    //讀入遊戲地圖
    for(i=1;i<=n;i=i+1){
        for(j=1;j<=m;j=j+1){
            scanf("%d", &a[i][j]);
        }
    }

    //開始搜尋，從(1,1)開始，進水方向也是1。
    dfs(1,1,1);

    //判斷是否找到鋪設方案
    if(flag==0){
        printf("inpossible!\n");
    }else{
        printf("找到鋪設方案了!\n\n");
    }

    getchar();
    getchar();
    return 0;
}


