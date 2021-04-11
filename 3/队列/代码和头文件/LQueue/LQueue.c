#include "LQueue.h"
	
void InitLQueue(LQueue *Q) {
    Q->length = 0;
    Q->front = Q->rear = NULL;
    if(Q->front || Q->rear) {
        printf("初始化失败！\n\n");
        exit(0);
    }
    printf("初始化成功！\n\n");
}

void DestoryLQueue(LQueue *Q) {
    Node *p, *q;
    p = Q->front;
    while(p) {
        q = p;
        p = p->next;
        free(q);
    }
}

Status IsEmptyLQueue(const LQueue *Q) {
    if(Q->front == Q->rear == NULL)
        return TRUE;
    return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e) {
    if(!Q->front) {
        printf("队列为空！\n\n");
        return FALSE;
    }
    e = Q->front->data;
    return TRUE;
}

int LengthLQueue(LQueue *Q) {
    return Q->length;
}

Status EnLQueue(LQueue *Q, void *data) {
    Node *p = (Node *)malloc(sizeof(Node));
    if(!p) {
        printf("开辟空间失败！\n\n");
        exit(0);
    }
    p->data = data;
    p->next = NULL;

    if(Q->rear) {
        Q->rear->next = p;
        Q->rear = p;
    }
    if(!Q->front) {
        Q->front = p;
        Q->rear = p;
    }
    Q->length ++ ;
    printf("插入成功！\n\n");
    return TRUE;
}

Status DeLQueue(LQueue *Q) {
    Node *q;
    if(IsEmptyLQueue(Q)) {
        printf("队列为空！\n\n");
        return FALSE;
    }
    else {
        if(Q->front->next == Q->rear) {
            free(Q->rear);
            Q->rear = Q->front;
            Q->front->next = NULL;
            Q->length -- ;
        }
        else {
            q = Q->front->next;
            Q->front->next = q->next;
            free(q);
            Q->length -- ;
        }
        printf("出队成功！\n\n");
        return TRUE;
    }
}

void ClearLQueue(LQueue *Q) {
    if(IsEmptyLQueue(&Q)) {
        printf("队列为空!\n\n");
        return ;
    }
    Node *p, *q;
    p = Q->front->next;
    while(p) {
        q = p;
        free(q);
        p = p->next;
    }
    Q->rear = Q->front = NULL;
}

Status TraverseLQueue(const LQueue *Q) {
    if(IsEmptyLQueue(&Q)) {
        printf("队列为空！\n\n");
        return FALSE;
    }
    Node *p = Q->front;
    while(p) {
        if(type == '1') printf("%d ",*(int *)p->data);
        if(type == '2') printf("%c ",*(char *)p->data);
        if(type == '3') printf("%f ",*(float *)p->data);
        if(type == '4') printf("%s ",*(char *)p->data);
        if(p->next) printf("->");
        p = p->next;
    }
    return TRUE;
}

void menu() {
    printf("\t\t\t\t******************************\n");
    printf("\t\t\t\t***     1.销毁队列          ***\n");
    printf("\t\t\t\t***     2.查看队列是否为空   ***\n");
    printf("\t\t\t\t***     3.查看队列头元素     ***\n");
    printf("\t\t\t\t***     4.查看队列长度       ***\n");
    printf("\t\t\t\t***     5.插入元素到队列      ***\n");
    printf("\t\t\t\t***     6.出队               ***\n");
    printf("\t\t\t\t***     7.清除队列           ***\n");
    printf("\t\t\t\t***     8.查看队列元素        ***\n");
    printf("\t\t\t\t********************************\n");

    printf("请输入您的选择：");
}

int main() {
    Node *Q = (Node *)malloc(sizeof(Node));
    InitLQueue(&Q);
    system("pause");
    int circle = 1;

    while(circle) {
        printf("\t\t\t\t1.整型    2.字符型    3.浮点型    4.字符串\n\n");
        printf("请选择您想入队的类型：");
        scanf("%s",&type);

        char judge;
        printf("\n\n您的选择是%c, 您确定吗?请输入y 或 n：", type);
        scanf("%s",&judge);
        while(judge != 'y' && judge != 'n') {
            printf("无效的输入请重试：");
            scanf("%s",&judge);
        }
        if(judge == 'y')    circle = 0;
    }
    circle = 1;

    while(1) {
        system("cls");
        char choose;
        circle = 1;

        while(circle) {
            menu();
            scanf("%s",&choose);
            if(choose == '1') {
                DestoryLQueue(&Q);
                printf("销毁成功！\n\n退出程序！\n\n");
                system("pause");
                return 0;
            }

            else if(choose == '2') {
                if(IsEmptyLQueue(&Q))       printf("队列为空！\n\n");
                else                       printf("队列不为空！\n\n");
                system("pause");
                circle = 0;
            }

            else if(choose == '3') {
                if(!IsEmptyLQueue(&Q)) {
                    if(type == '1') {
                        int a;
                        GetHeadLQueue(&Q, &a);
                        printf("头元素为%d\n\n", a);
                    }
                    else if(type == '2') {
                        char a;
                        GetHeadLQueue(&Q, &a);
                        printf("头元素为%c\n\n", a);
                    }
                    else if(type == '3') {
                        float a;
                        GetHeadLQueue(&Q, &a);
                        printf("头元素为%f\n\n", a);
                    }
                    else if(type == '4') {
                        char a[20];
                        GetHeadLQueue(&Q, a);
                        printf("头元素为%s\n\n", a);
                    }
                }
                else    printf("队列为空！\n\n");
                system("pause");
                circle = 0;
            }

            else if(choose == '4') {
                printf("队列长度为%d\n\n",LengthLQueue(&Q));
                system("pause");
                circle = 0;
            }

            else if(choose == '5') {
                if(type == '1') {
                    int a;
                    printf("请输入您想插入的整型元素：");
                    scanf("%d", &a);
                    printf("您确定您想输入数据是%d您确定吗？请输入y 或 n：", a);
                    char judge;
                    scanf("%s",&judge);
                    while(judge != 'y' && judge != 'n') {
                        printf("无效的输入请重试：");
                        scanf("%s",&judge);
                    }
                    if(judge == 'n')    printf("取消成功！\n\n");
                    if(judge == 'y') {
                        EnLQueue(&Q, &a);
                        printf("插入成功！\n\n");
                    }
                    circle = 0;
                }
                else if(type == '2') {
                    char a;
                    printf("请输入您想插入的字符元素：");
                    scanf("%c", &a);
                    printf("您确定您想输入数据是%c您确定吗？请输入y 或 n：", a);
                    char judge;
                    scanf("%s",&judge);
                    while(judge != 'y' && judge != 'n') {
                        printf("无效的输入请重试：");
                        scanf("%s",&judge);
                    }
                    if(judge == 'n')    printf("取消成功！\n\n");
                    if(judge == 'y') {
                        EnLQueue(&Q, &a);
                        printf("插入成功！\n\n");
                    }
                    circle = 0;
                }
                else if(type == '3') {
                    float a;
                    printf("请输入您想插入的浮点数元素：");
                    scanf("%f", &a);
                    printf("您确定您想输入数据是%f您确定吗？请输入y 或 n：", a);
                    char judge;
                    scanf("%s",&judge);
                    while(judge != 'y' && judge != 'n') {
                        printf("无效的输入请重试：");
                        scanf("%s",&judge);
                    }
                    if(judge == 'n')    printf("取消成功！\n\n");
                    if(judge == 'y') {
                        EnLQueue(&Q, &a);
                        printf("插入成功！\n\n");
                    }
                    circle = 0;
                }
                else if(type == '4') {
                    char a[20];
                    printf("请输入您想插入的整型元素：");
                    scanf("%s", a);
                    printf("您确定您想输入数据是%s您确定吗？请输入y 或 n：", a);
                    char judge;
                    scanf("%s",&judge);
                    while(judge != 'y' && judge != 'n') {
                        printf("无效的输入请重试：");
                        scanf("%s",&judge);
                    }
                    if(judge == 'n')    printf("取消成功！\n\n");
                    if(judge == 'y') {
                        EnLQueue(&Q, a);
                        printf("插入成功！\n\n");
                    }
                    circle = 0;
                }
                system("pause");
            }

            else if(choose == '6') {
                DeLQueue(&Q);
                system("pause");
                circle = 0;
            }

            else if(choose == '7') {
                ClearLQueue(&Q);
                system("pause");
                circle = 0;
            }

            else if(choose == '8') {
                TraverseLQueue(&Q);
                system("pause");
                circle = 0;
            }
            else {
                printf("无效的输入请重试:");
                scanf("%s",&choose);
            }
        }
    }
}