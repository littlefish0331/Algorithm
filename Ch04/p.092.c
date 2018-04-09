//地圖
//0 0 1 0
//0 0 0 0
//0 0 1 0
//0 1 0 0
//0 0 0 1

//測資
//1 1 4 3

#include <stdio.h>

struct note {
    int x;  //橫坐標
    int y;  //縱座標
    int f;  //父親在佇列中的編號，可以用來輸出路徑
            //可以知道這個點是由哪一個點延伸的分支來的。
    int s;  //步數
};

int main(){
    struct note que[2501];  //因為地圖大小不超過50*50，所以佇列擴展不會超過2500個。
    int a[51][51]={0}, book[51][51]={0};

    //定義一個用於表示走的方向的陣列
    int next[4][2]={
        { 0, 1},
        { 1, 0},
        { 0,-1},
        {-1, 0}
    };

    int head, tail;
    int i, j, k, n, m, startx, starty, p, q,tx, ty, flag;

    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i=i+1){
        for(j=1;j<=m;j=j+1){
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d %d %d %d", &startx, &starty, &p, &q);

    //佇列初始化
    head=1;
    tail=1;

    //往佇列插入迷宮入口座標
    que[tail].x=startx;
    que[tail].y=starty;
    que[tail].f=0;
    que[tail].s=0;
    tail=tail+1;
    book[startx][starty]=1;

    flag=0; //用來標記是否到達目標點，0表示暫時還沒有到達，1表示到達

    //當佇列不為空的時候進行迴圈
    while(head<tail){
        //列舉4個方向
        for(k=0;k<=3;k=k+1){
            //計算下一個點的座標
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];

            //判斷是否越界
            if(tx<1 || tx>n || ty<1 || ty>m){
                continue;
            }
            //在迴圈敘述中
            //我們可以使用 break 指令讓它強制離開迴圈
            //或是用 continue 指令來忽略下面的指令而繼續下一次的迴圈


            //判斷是否為障礙物，或已經在路徑中
            if(a[tx][ty]==0 && book[tx][ty]==0){
                //把這個點標示為已經走過
                //注意寬度搜尋每個點都只會入佇列一次，所以和深度搜尋不同，不需要將book陣列還原
                book[tx][ty]=1;

                //插入新的點到佇列中
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].f=head;   //這個是從head擴展出來的，所以它的父親是head
                                    //本題不需要求路徑，所以可省略。
                                    //由此就可以知道上一個分支的節點是哪一個。
                que[tail].s=que[head].s+1;  //步數是父親的步數+1。
                tail=tail+1;
            }

            //如果到了目標點，停止擴展，任務結束，退出迴圈。
            if(tx==p && ty==q){
                flag=1;
                break;
            }
        }

        if(flag==1){
            break;
        }
        head=head+1;    //這個地方一定要記得，當一個點擴展結束後
                        //head=head+1才能對後面的點再進行擴展
    }

    //輸出佇列中末尾中，最後一的點(目標)的步數
    //注意tail是指向佇列尾(及最後一位)的下一個位置，所以這需要-1
    printf("%d\n", que[tail-1].s);

    //找出路徑。注意因為選擇路徑的順序為右下左上，所以會先找到此條路徑
    //並不會輸出所有路徑!!
    printf("路徑為(%d,%d)", que[tail-1].x, que[tail-1].y);
    head=que[tail-1].f;
    i=0;//紀錄回頭找出原本路徑幾步。
    while(i!=que[tail-1].s){
        printf(" (%d,%d)", que[head].x, que[head].y);
        head=que[head].f;   //看自己的f，就知道來自哪個分支的點。
        i=i+1;
    }

    getchar();
    getchar();

    return 0;

}
