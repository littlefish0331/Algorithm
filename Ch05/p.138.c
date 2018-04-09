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

struct note {
    int x;  //城市編號
    int s;  //轉機次數
};

int main(){
    struct note que[2501];
    int e[51][51]={0}, book[51]={0};
    int head, tail;
    int i, j, n, m, a, b, cur, start, end, flag=0;

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

    //讀入城市之間的航班
    for(i=1;i<=m;i=i+1){
        scanf("%d %d", &a, &b);
        //注意這裡是無向圖
        e[a][b]=1;
        e[b][a]=1;
    }

    //佇列初始化
    head=1;
    tail=1;

    //從start城市開始出發，將start號城市加入佇列
    que[tail].x=start;
    que[tail].s=0;
    tail=tail+1;
    book[start]=1;  //標記start城市已在佇列

    //當佇列不為空的時候迴圈
    while(head<tail){
        cur=que[head].x;  //目前佇列中首城市的編號

        //從1~n依次嘗試
        for(j=1;j<=n;j=j+1){

            //從城市cur到城市j是否有航班並且判斷城市j是否已經在佇列中
            if(e[cur][j]!=99999999 && book[j]==0){  //!!!!!!!!!這邊等等想一下!!!!!

                //如果城市cur到城市j有航班，並且城市j不在佇列中，則將j號城市入佇列
                que[tail].x=j;
                que[tail].s=que[head].s+1;
                tail=tail+1;

                //標記城市已經在佇列中
                book[j]=1;
            }

            //如果到達目標城市，停止擴展，任務結束，退出迴圈
            if(que[tail-1].x==end){
                //注意下面兩句話的位置千萬不要寫顛倒了!
                flag=1;
                break;  //這個作用為跳離for迴圈。
            }
        }

        if(flag==1){
            break;  //這個作用為跳離while迴圈。
        }

        //要記得當一個點擴展結束，要head=head+1，才能繼續擴展
        head=head+1;
    }

    //列印佇列中末尾最後一個(目標城市)的轉機次數
    //注意tail是指向佇列的佇列尾(即最後一位)的下一個位置，所以還需要-1
    printf("\nStart[%d]到End[%d]的最少轉機次數=%d\n\n", start, end, que[tail-1].s);

    //知道廣度優先搜尋是怎麼做的
    printf("BFS的'第幾步'和'搜尋的點'\n");
    for(i=1;i<=tail-1;i=i+1){
        printf("(%d %d)\n", que[i].s, que[i].x);
    }
    printf("佇列的tail=%d", tail);


    getchar();
    getchar();
    return 0;

}


