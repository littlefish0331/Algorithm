#include <stdio.h>
struct queue{
    int data[100];  //佇列主體，用來存放資料。
    int head;       //佇列首。
    int tail;       //佇列尾。
};

int main(){

    struct queue q;
    int i;

    //初始化佇列。
    q.head=1;
    q.tail=1;

    for(i=1;i<=9;i++){
        //依序向佇列插入九個數字
        scanf("%d", &q.data[i]);
        q.tail=q.tail+1;
    }

    while(q.head<q.tail){
        //佇列首將佇列移出
        printf("%d ", q.data[q.head]);
        q.head=q.head+1;

        //將新的佇列首的數字新增到佇列尾
        q.data[q.tail]=q.data[q.head];
        q.tail=q.tail+1;

        //再將佇列首移出。
        q.head=q.head+1;
    }

    getchar();
    getchar();
    return 0;
}
