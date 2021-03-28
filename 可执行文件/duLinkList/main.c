#include "duLinkedList.h"

void select(DuLinkedList head);
void pri(ElemType e);
DuLinkedList getNode(DuLinkedList head, int n);
DuLinkedList createNode();
int sgets();

int main() {
    int n = 0;
    DuLinkedList p1, p2, head;
    
    printf("创建一个新链表，请输入您向创建结点的个数：");
    n = sgets();

    for(int i = 1 ; i <= n ; i ++ ) {
        if(i == 1) {
            InitList_DuL(&head);
            printf("请输入第%d个数据：",i);
            head->data = sgets();
            char judge = 'n';
            while(judge == 'n') {
                printf("您确定第%d个数据为%d？请输入 n 或 y ：",i, head->data);
                scanf("%s",&judge);
                while(judge != 'n' && judge != 'y') {
                    printf("无效的输入请重试：");
                    scanf("%s", &judge);
                }
            }
            p1 = head;
        }
        else {
            p2 = (DuLinkedList)malloc(sizeof(DuLNode));
            printf("请输入第%d个数据：",i);
            p2->data = sgets();
            char judge = 'n';
            while(judge == 'n') {
                printf("您确定第%d个数据为%d？请输入 n 或 y ：",i, p2->data);
                scanf("%s",&judge);
                while(judge != 'n' && judge != 'y') {
                    printf("无效的输入请重试：");
                    scanf("%s", &judge);
                }
            }
            p2->next = NULL;
            p2->prior = p1;
            p1->next = p2;
            p1 = p2;
        }
    }
    select(head);
}

void pri(ElemType e) {
    printf("%d->",e);
}

DuLinkedList getNode(DuLinkedList head, int n) {
    if(n < 1)   return NULL;
    DuLinkedList p = head;
    for(int i = 1 ; i < n ; i ++ ) {
        p = p->next;
        if(i < n - 1 && p->next == NULL)
            return NULL;
    }
    return p;
}

DuLinkedList createNode() {
    DuLinkedList q;
    q = (DuLinkedList)malloc(sizeof(DuLNode));
    
    char judge = 'n';
    while(judge == 'n') {
        printf("请输入您要插入的数据：");
        q->data = sgets();
        printf("您确定数据为%d？", q->data);
        scanf("%s",&judge);
        while(judge != 'n' && judge != 'y') {
            printf("无效的输入请重试：");
            scanf("%s", &judge);
        }
    }
    q->next = q->prior  = NULL;
    return q;
}

int sgets() {
    char *ret_val;
    char *find;
    char st[100];
    fflush(stdin);
    ret_val = fgets(st, 100, stdin);
    if(ret_val) {
        find = strchr(st, '\n');
        if(find)    *find = '\0';
        else 
            while(getchar() != '\n')
                continue;
    }
    return atoi(ret_val);
}

void select(DuLinkedList head) {
    printf("\t\t\t\t*********************************\n");
    printf("\t\t\t\t***  1.销毁链表并退出程序      ***\n");
    printf("\t\t\t\t***  2.插入结点到指定节点前    ***\n");
    printf("\t\t\t\t***  3.插入节点到指定结点后    ***\n");
    printf("\t\t\t\t***  4.删除结点并输出结点      ***\n");
    printf("\t\t\t\t***  5.遍历链表并输出链表数据  ***\n");
    printf("\t\t\t\t*********************************\n");
        
    char choose;
    ElemType a, *e;
    fflush(stdin);
    e = &a;

    printf("请输入您的选择：");
    
    while(scanf("%s",&choose) == 1) {
        
        if(choose == '1') {
            DestroyList_DuL(&head);
            return 0;
        }
        else if(choose == '2') {
            printf("请输入您要在第几个结点前插入：");
            a = sgets();
            if(InsertBeforeList_DuL(getNode(head, a), createNode()))    printf("成功！\n\n");
            else                                                        printf("失败!\n\n");
        }
        else if(choose == '3') {
            printf("请输入您要在第几个结点后插入：");
            a = sgets();
            if(InsertAfterList_DuL(getNode(head, a), createNode()))     printf("成功!\n\n");
            else                                                        printf("失败！\n\n");
        }
        else if(choose == '4') {
            printf("请输入您要删除第几个结点之后的结点：");
            a = sgets();
            if(DeleteList_DuL(getNode(head, a), e)) printf("成功！删除结点数据为%d\n",*e);
            else                                    printf("失败！\n\n");
        }
        else if(choose == '5') {
            TraverseList_DuL(head, pri);
        }
        else {
            printf("无效的输入请重试：");
        }
        printf("\t\t\t\t*********************************\n");
        printf("\t\t\t\t***  1.销毁链表并退出程序      ***\n");
        printf("\t\t\t\t***  2.插入结点到指定节点前    ***\n");
        printf("\t\t\t\t***  3.插入节点到指定结点后    ***\n");
        printf("\t\t\t\t***  4.删除结点并输出结点      ***\n");
        printf("\t\t\t\t***  5.遍历链表并输出链表数据  ***\n");
        printf("\t\t\t\t*********************************\n\n");
        printf("请输入您的选择：");
    }
}