#include "linkedList.h"

LinkedList getNode(LinkedList head, int n);
LinkedList createNode();
void pri(ElemType e);
int sgets();

int main() {
    int n;
    LinkedList p, head, p1;
    InitList(&head);
    p = head;

    printf("创建一个新链表，请输入您向创建结点的个数：");
    n = sgets();

    for(int i = 1 ; i <= n ; i ++ ) {
        if(i == 1) {
            char judge = 'n';
            while(judge == 'n') {
                printf("请输入第%d个结点的数据:",i);
                scanf("%d", &p->data);
                printf("您是否创建第%d个数据为%d?请输入 n 或 y：", i, p->data);
                scanf("%s",&judge);
                while(judge != 'n' && judge != 'y') {
                    printf("无效的输入，请重试：");
                    scanf("%s", &judge);
                }
            }
            printf("成功！\n\n");
        } else {
            p1 = (LinkedList)malloc(sizeof(LinkedList));
            p->next = p1;
            p = p1;
            p1->next = NULL;

            char judge = 'n';
            while(judge == 'n') {
                printf("请输入第%d个结点的数据:",i);
                scanf("%d", &p->data);
                printf("您是否创建第%d个数据为%d?请输入 n 或 y：", i, p->data);
                scanf("%s",&judge);
                while(judge != 'n' && judge != 'y') {
                    printf("无效的输入，请重试：");
                    scanf("%s", &judge);
                }
            }
            printf("成功！\n\n");
        }
    }

    while(1) {
        printf("\t\t\t\t******************************\n");
        printf("\t\t\t\t****                      ****\n");
        printf("\t\t\t\t****  1.销毁链表并退出     ****\n");
        printf("\t\t\t\t****  2.插入一个结点到链表  ****\n");
        printf("\t\t\t\t****  3.删除一个结点到链表  ****\n");
        printf("\t\t\t\t****  4.遍历链表并输出数据  ****\n");
        printf("\t\t\t\t****  5.查询链表中的某数据  ****\n");
        printf("\t\t\t\t****  6.反转链表           ****\n");
        printf("\t\t\t\t****  7.判断链表是否有循环  ****\n");
        printf("\t\t\t\t****  8.链表的奇偶结点对换  ****\n");
        printf("\t\t\t\t****  9.查询中间的结点     ****\n");
        printf("\t\t\t\t****  0.退出              ****\n");
        printf("\t\t\t\t****                      ****\n");
        printf("\t\t\t\t******************************\n");

        char choose;
        ElemType a, *e;
        fflush(stdin);
        e = &a;

        printf("请输入您的选择：");
        scanf("%s",&choose);
        switch(choose) {
            case '1' :  DestroyList(&head);
                        printf("成功！\n\n");
                        system("pause");
                        return 0;

            case '2' :  printf("请输入您要在第几个结点后插入：");
                        a = sgets();
                        if(InsertList(getNode(head, a), createNode()))      printf("成功！\n\n");
                        else                                                printf("失败！\n\n");
                        break;

            case '3' :  printf("请输入您想删除第几个结点之后的结点：");
                        a = sgets();
                        if(DeleteList(getNode(head, a), e))        printf("成功！删除结点数据为%d\n\n", *e);
                        else                        printf("失败！\n\n");
                        break;

            case '4' :  TraverseList(head, pri);
                        break;

            case '5' :  printf("请输入您要查询的数字：");
                        a = sgets();
                        if(SearchList(head, a))     printf("成功！\n\n");
                        else                        printf("失败!\n\n");
                        break;

            case '6' :  if(ReverseList(&head))         printf("成功！\n\n");
                        else                        printf("失败！\n\n");
                        break;

            case '7' :  if(IsLoopList(head))           printf("成功！\n\n");
                        else                        printf("失败！\n\n");
                        break;

            case '8' :  ReverseEvenList(&head);        printf("成功！\n\n");
                        break;

            case '9' :  FindMidNode(&head);            printf("成功！\n\n");
                        break;

            case '0':    printf("感谢使用！\n");
                        system("pause");
                        return 0;

            default :   printf("无效的输入请重试：");
        }
    }
}

LinkedList getNode(LinkedList head, int n) {
    if(n < 1)   return NULL;
    LinkedList p = head;
    for(int i = 1 ; i < n ; i ++ ) {
        p = p->next;
        if(i < n - 1 && p->next ==  NULL)
            return NULL;
    }
    return p;
}

LinkedList createNode() {
    LinkedList q;
    q = (LinkedList)malloc(sizeof(LNode));
    printf("请输入要插入的数据：");
    char judge = 'n';
    while(judge == 'n') {
        printf("请输入新结点的数据:");
        scanf("%d", &q->data);
        printf("您是否创建数据为%d?请输入 n 或 y：", q->data);
        scanf("%s",&judge);
        while(judge != 'n' && judge != 'y') {
            printf("无效的输入，请重试：");
            scanf("%s", &judge);
        }
    }
    printf("成功!n");
    return 0;
}

void pri(ElemType e) {
    printf("%d->",e);
}

int sgets()
{
    char * ret_val;
    char * find;
    char  st[100];

    fflush(stdin);
    ret_val = fgets(st,100,stdin);
    if(ret_val){
        find = strchr(st,'\n');
        if(find)    *find = '\0';
        else while(getchar() != '\n')
                continue;
    }

   return atoi(ret_val);
}