#include <stdio.h>
int main(){
    int q[102]={0,6,3,1,7,5,8,9,2,4}, head, tail;
    int i;

    //先初始化佇列。
    head=1;
    tail=10;    //佇列中已經有9個元素，tail指向佇列尾的一個位置。

    while(head<tail){

        //列印佇列首，並將佇列首出佇列。
        printf("%d ", q[head]);
        head=head+1;

        //將新的佇列首的數字新增到佇列尾。
        q[tail]=q[head];
        tail=tail+1;

        //再將佇列首出佇列。
        head=head+1;

    }

    getchar();
    getchar();
    return 0;

}


