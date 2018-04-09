//測資
//4 5
//1 4 9
//4 3 8
//1 2 5
//2 4 6
//1 3 7


#include <stdio.h>

int main(){
    int n, m, i, k;

    //u,v,w的陣列大小要根據實際情況來設定，要比m2的最大值要大1
    int u[6], v[6], w[6];

    //first和next的陣列大小要根據實際情況來設定，要比n的最大值要大1
    int first[5], next[5];
    scanf("%d %d", &n, &m);

    //初始化first陣列的下標1~n的值為-1，表示1~n頂點暫時都沒有邊。
    for(i=1;i<=n;i=i+1){
        first[i]=-1;
    }

    for(i=1;i<=m;i=i+1){
        scanf("%d %d %d", &u[i], &v[i], &w[i]); //讀入每一條編

        //下面兩句是關鍵!!
        next[i]=first[u[i]];
        first[u[i]]=i;
    }


    printf("\n\n讀取每一個頂點的邊的陣列\n");
    //走訪每個頂點的邊
    for(i=1;i<=n;i=i+1){
        k=first[i];
        while(k!=-1){
            printf("%d %d %d\n", u[k], v[k], w[k]);
            k=next[k];
        }
    }


}




