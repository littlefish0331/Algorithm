#include <stdio.h>

struct queue{
    int data[1000];
    int head;
    int tail;
};

struct stack{
    int data[10];
    int top;
};

int main(){
    struct queue q1, q2;
    struct stack s;
    int book[10];
    int i, t;

    //初始化佇列q1和佇列q2為空，此時兩人手中都還沒有牌
    q1.head=1;
    q1.tail=1;
    q2.head=1;
    q2.tail=1;

    //初始化堆疊為空。
    s.top=0;

    //初始化用來標記的陣列，標記那些牌已經在桌上了。
    for(i=1;i<=9;i=i+1){
        book[i]=0;
    }

    //先讀六張牌，放到小哼的手中
    for(i=1;i<=6;i=i+1){
        scanf("%d", &q1.data[q1.tail]); //讀入一個數字放到佇列尾
        q1.tail=q1.tail+1;              //佇列尾往後挪一位
    }
    //再讀六張牌，放到小哈的手中
    for(i=1;i<=6;i=i+1){
        scanf("%d", &q2.data[q2.tail]); //讀入一個數字放到佇列尾
        q2.tail=q2.tail+1;              //佇列尾往後挪一位
    }


    while(q1.head<q1.tail && q2.head<q2.tail){

        t=q1.data[q1.head]; //  小哼先亮出一張牌
        //判斷小哼目前打出的牌是否能贏牌
        if(book[t]==0){
            //表明桌面上沒有牌面為t的牌
            //小哼此輪沒有贏牌
            q1.head=q1.head+1;  //小哼已經打出一張牌，所以要把打出的排出佇列
            s.top=s.top+1;      //入堆疊是從下標1開始放唷!!
            s.data[s.top]=t;    //把打出的牌放到桌上，即入堆疊。
            book[t]=1;          //標記桌面上有機有牌面為t的牌了
        }else{
            //小哼此輪可以贏牌
            q1.head=q1.head+1;  //小哼已經打出一張牌，所以要把打出的排出佇列
            q1.data[q1.tail]=t; //把打出的牌，放到手中牌的末尾
            q1.tail=q1.tail+1;

            while(s.data[s.top]!=t){
                //把桌上可以贏得的牌一次放到手中牌的末尾
                book[s.data[s.top]]=0;  //取消標記
                q1.data[q1.tail]=s.data[s.top]; //依次放入佇列尾
                q1.tail=q1.tail+1;
                s.top=s.top-1;                  //堆疊中少一張牌，所以堆疊頂要減1。
            }
        }


        t=q2.data[q2.head]; //  小哈先亮出一張牌
        //判斷小哈目前打出的牌是否能贏牌
        if(book[t]==0){
            //表明桌面上沒有牌面為t的牌
            //小哈此輪沒有贏牌
            q2.head=q2.head+1;  //小哈已經打出一張牌，所以要把打出的排出佇列
            s.top=s.top+1;      //入堆疊是從下標1開始放唷!!
            s.data[s.top]=t;    //把打出的牌放到桌上，即入堆疊。
            book[t]=1;          //標記桌面上有機有牌面為t的牌了
        }else{
            //小哼此輪可以贏牌
            q2.head=q2.head+1;  //小哈已經打出一張牌，所以要把打出的排出佇列
            q2.data[q2.tail]=t; //把打出的牌，放到手中牌的末尾
            q2.tail=q2.tail+1;

            while(s.data[s.top]!=t){
                //把桌上可以贏得的牌一次放到手中牌的末尾
                book[s.data[s.top]]=0;  //取消標記
                q2.data[q2.tail]=s.data[s.top]; //依次放入佇列尾
                q2.tail=q2.tail+1;
                s.top=s.top-1;                  //堆疊中少一張牌，所以堆疊頂要減1。
            }
        }


        //如果要每一輪出完牌(小哼小哈各出牌ˊ一次)就輸出結果，就這這段code!!
        printf("\n\n小哼目前手中的牌是");
        for(i=q1.head;i<q1.tail;i=i+1){
            printf(" %d", q1.data[i]);
        }

        printf("\n小哈目前手中的牌是");
        for(i=q2.head;i<q2.tail;i=i+1){
            printf(" %d", q2.data[i]);
        }

        //如果桌上有牌則依次輸出桌上的牌
        if(s.top>0){
            //因為桌上的牌是從s.top=1開始
            printf("\n進行中，桌上的牌是");
            for(i=1;i<=s.top;i=i+1){
                printf(" %d", s.data[i]);
            }
        }else{
            printf("\n進行中，桌上已經沒有牌了");
        }


    }







    if(q2.head==q2.tail){
        printf("\n\n小哼win~~");
        printf("\n小哼目前手中的牌是");

        for(i=q1.head;i<q1.tail;i=i+1){
            printf(" %d", q1.data[i]);
        }

        //如果桌上有牌則依次輸出桌上的牌
        if(s.top>0){
            //因為桌上的牌是從s.top=1開始
            printf("\n\n桌上的牌是");
            for(i=1;i<=s.top;i=i+1){
                printf(" %d", s.data[i]);
            }
        }else{
            printf("\n\n桌上已經沒有牌了");
        }

    }else{
        printf("\n\n小哈win~~");
        printf("\n小哈目前手中的牌是");

        for(i=q2.head;i<q2.tail;i=i+1){
            printf(" %d", q2.data[i]);
        }

        //如果桌上有牌則依次輸出桌上的牌
        if(s.top>0){
            //因為桌上的牌是從s.top=1開始
            printf("\n桌上的牌是");
            for(i=1;i<=s.top;i=i+1){
                printf(" %d", s.data[i]);
            }
        }else{
            printf("\n\n桌上已經沒有牌了");
        }
    }

    getchar();
    getchar();
    return 0;
}

