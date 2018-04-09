#include <stdio.h>
#include <stdlib.h>
//C 語言動態記憶體配置的相關函數位於 stdlib.h 這個 C 語言的標準函式庫中

//新建一個結構體用來表示鏈結串列的節點型別
struct node{
    int data;
    struct node *next;  //用來儲存下一個節點的位址，所以是指標。
};

int main(){
    struct node *head, *p, *q, *t;
    int i, n;

    scanf("%d", &n);
    head=NULL;      //頭指標初始為空。

    for(i=1;i<=n;i=i+1){
        //迴圈讀入n個數
        scanf("%d", &a);

        //動態申請一個空間，用來存放一個節點，並用臨時指標p指向這個節點。
        p=(struct node*)malloc(sizeof(struct node));
        p->data=a;      //將資料儲存到目前資料的data欄位中。
        p->next=NULL;   //設定目前節點的後繼指標指向空，也就是目前節點的下一個節點為空。

        if(head==NULL){
            head=p; //如果這是第一個新建的節點，則將頭指標指向這個節點。
        }else{
            q->next=p;  //如果不是第一個新建的節點，則將上一個節點的後繼指標指向目前節點。
        }

        q=p;
    }


    //輸出鏈結串列中的所有數字
    printf("\n\n");
    t=head;
    while(t!=NULL){
        printf("%d ", t->data);
        t=t->next;      //繼續下一個節點
    }
    //while的條件可以用(head!=NULL)，然後裡面的t就都改成head


    // 釋放記憶體空間
    free(head);head = NULL;
    free(p);p=NULL;
    free(q);q=NULL;
    free(t);t=NULL;

    getchar();
    getchar();
    return 0;
}

