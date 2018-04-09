#include <stdio.h>
#include <string.h>

int main(){
    char a[101], s[101];
    int i, len, mid, next, top;

    gets(a);         //讀入一串字串。會從a[0]開始存入。
    len=strlen(a);  //求字串的長度。
    mid=len/2-1;     //求字串的中點。
    //五個字中點為5/2=2.5，但因為整數型別則為2，但陣列的下標會需要1
    //四個字中點為4/2=2，但陣列的下標會需要1

    top=0;          //堆疊的初始化。top=0的時候不放東西

    //將mid以前的字元，依次入堆疊
    for(i=0;i<=mid;i=i+1){
        top=top+1;
        s[top]=a[i];
        //上面兩行，可以簡寫為s[++top]=a[i]
    }

    //判斷字串的長度是奇數還是偶數，並找出需要進行自員匹配的起始註標。
    if(len%2==0){
        next=mid+1;
    }else{
        next=mid+2;
    }

    //開始匹配
    for(i=next;i<=len-1;i=i+1){
        if(a[i]!=s[top]){
            break;
        }
        top=top-1;
    }

    //如果top的值為0，則說明推疊內所有的字元都被一一比對了
    if(top==0){
        printf("YES");
    }else{
        printf("NO");
    }

    getchar();
    getchar();
    return 0;
}
