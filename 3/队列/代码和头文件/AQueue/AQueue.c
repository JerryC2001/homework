#include "AQueue.h"

void InitAQueue(AQueue *Q) {
    Q->length = MAXQUEUE;
    for(int i = 0 ; i < MAXQUEUE ; i ++ )
        Q->data[i] = (void *)malloc(31);
    Q->front = Q->rear = 0;
    printf("初始化成功！\n");
}

void DestoryAQueue(AQueue *Q) {
    if(!Q->data[0]) {
        printf("没有初始化！\n");
        return ;
    }
    for(int i = 0 ; i < MAXQUEUE ; i ++ )
        free(Q->data[i]);
    Q->data[0] = NULL;
}

Status IsFullAQueue(const AQueue *Q) {
    if(!Q->data[0]) {
        printf("没有初始化！\n\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q)) {
        printf("队列为空！\n\n");
        return FALSE;
    }
    if(LengthAQueue(Q) == MAXQUEUE - 1) {
        printf("队列已满！\n\n");
        return TRUE;
    }
    printf("队列没满！\n\n");
    return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q) {
    if(!Q->data[0]) {
        printf("队列没有初始化！\n\n");
        return TRUE;
    }
    if(!LengthAQueue(Q)) {
        printf("队列为空\n\n");
        return TRUE;
    }
    printf("不为空\n\n");
    return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void *e) {
    if(IsEmptyAQueue(Q)) {
        printf("队列为空！\n\n");
        return FALSE;
    }
    memcpy(e, Q->data[Q->front], 30);
    return TRUE;
}

int LengthAQueue(AQueue *Q) {
    int length;
    length=(Q->rear - Q->front + Q->length) % Q->length;
    printf("队列长度为：%d\n\n",length);
    return length;
}

Status EnAQueue(AQueue *Q, void *data) {
    if(IsFullAQueue(Q)) {
        printf("队列已满!\n\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q)) {
        memcpy(Q->data[Q->front], data, 30);
        Q->rear = (Q->rear + 1 ) % Q->length;
        return TRUE;
    }
    memcpy(Q->data[Q->rear], data, 30);
    Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}

Status DeAQueue(AQueue *Q) {
    if(IsEmptyAQueue(Q)) {
        printf("队列为空！\n\n");
        return FALSE;
    }
    Q->front = (Q->front + 1) % Q->length;
    printf("出队成功！\n\n");
    return TRUE;
}

void ClearAQueue(AQueue *Q) {
    if(IsEmptyAQueue(Q)) {
        printf("队列为空！\n\n");
        return ;
    }
    Q->front = Q->rear = 0;
    printf("清除成功！\n\n");
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)) {
    if(!Q->data[0]) {
        printf("没有初始化\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q)) {
        printf("队列为空！\n");
        return FALSE;
    }
    int i = 0;
    while(i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
        foo(Q->data[Q->front + i]);
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}


void menu() {
    printf("\t\t\t\t******************************\n");
    printf("\t\t\t\t***     1.销毁队列          ***\n");
    printf("\t\t\t\t***     2.判断队列是否为满   ***\n");
    printf("\t\t\t\t***     3.判断队列是否为空   ***\n");
    printf("\t\t\t\t***     4.查看队列头元素     ***\n");
    printf("\t\t\t\t***     5.查看队列长度       ***\n");
    printf("\t\t\t\t***     6.插入元素到队列中   ***\n");
    printf("\t\t\t\t***     7.删除队列元素       ***\n");
    printf("\t\t\t\t***     8.清空队列           ***\n");
    printf("\t\t\t\t***     9.遍历队列元素       ***\n");
    printf("\t\t\t\t***     0.退出程序           ***\n");
    printf("\t\t\t\t********************************\n\n");

    printf("请选择操作功能:");
}

int main() {
    AQueue *Q = (AQueue *)malloc(sizeof(AQueue)); 
    InitAQueue(Q);

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
        menu();
        circle = 1;

        char choose;
        scanf("%s",&choose);

        while(circle) {
            if(choose == '1') {
                DestoryAQueue(Q);
                system("pause");
                circle = 0;
            }

            else if(choose == '2') {
                IsFullAQueue(Q);
                system("pause");
                circle = 0;
            }

            else if(choose == '3') {
                IsEmptyAQueue(Q);
                system("pause");
                circle = 0;
            }

            else if(choose == '4') {
                if(!IsEmptyAQueue(Q)) {
                    if(type == '1') {
                        int a;
                        GetHeadAQueue(Q, &a);
                        printf("头元素为%d\n\n",a);
                    }
                    else if(type == '2') {
                        char a;
                        GetHeadAQueue(Q, &a);
                        printf("头元素为%c\n\n",a);
                    }
                    else if(type == '3') {
                        float a;
                        GetHeadAQueue(Q, &a);
                        printf("头元素为%f\n\n",a);
                    }
                    else if(type == '4') {
                        char a[20];
                        GetHeadAQueue(Q, a);
                        printf("头元素为%s",a);
                    }
                }
                system("pause");
                circle = 0;
            }

            else if(choose == '5') {
                LengthAQueue(Q);
                system("pause");
                circle = 0;
            }

            else if(choose == '6') {
                if(type == '1') {
                    int a;
                    printf("请输入您想插入的整型数据：");
                    scanf("%d",&a);
                    printf("您确定你想的插入数据是%d您确定吗？请输入y 或 n：",a);
                    char judge;
                    scanf("%s",&judge);
                    while(judge != 'y' && judge != 'n') {
                        printf("无效的输入请重试：");
                        scanf("%s",&judge);
                    }
                    if(judge == 'n')        printf("取消成功！\n\n");
                    if(judge == 'y') {
                        EnAQueue(Q, &a);
                        Q->type[Q->rear] = '1';
                        printf("插入成功！\n\n");
                    }
                    circle = 0;
                }
                else if(type == '2') {
                    char a;
                    printf("请输入您想插入的字符数据：");
                    scanf("%s",&a);
                    printf("您确定你想的插入数据是%c您确定吗？请输入y 或 n：", a);
                    char judge;
                    scanf("%s",&judge);
                    while(judge != 'y' && judge != 'n') {
                        printf("无效的输入请重试：");
                        scanf("%s",&judge);
                    }
                    if(judge == 'n')        printf("取消成功！\n\n");
                    if(judge == 'y') {
                        EnAQueue(Q, &a);
                        Q->type[Q->rear] = '2';
                        printf("插入成功！\n\n");
                    }
                    circle = 0;
                }
                else if(type == '3') {
                    float a;
                    printf("请输入您想插入的浮点数数据：");
                    scanf("%f",&a);
                    printf("您确定你想的插入数据是%f您确定吗？请输入y 或 n：",a);
                    char judge;
                    scanf("%s",&judge);
                    while(judge != 'y' && judge != 'n') {
                        printf("无效的输入请重试：");
                        scanf("%s",&judge);
                    }
                    if(judge == 'n')        printf("取消成功！\n\n");
                    if(judge == 'y') {
                        EnAQueue(Q, &a);
                        Q->type[Q->rear] = '3';
                        printf("插入成功！\n\n");
                    }
                    circle = 0;
                }
                else if(type == '4') {
                    char a[20];
                    printf("请输入您想插入的字符串数据：");
                    scanf("%s",a);
                    printf("您确定你想的插入数据是%s您确定吗？请输入y 或 n：", a);
                    char judge;
                    scanf("%s",&judge);
                    while(judge != 'y' && judge != 'n') {
                        printf("无效的输入请重试：");
                        scanf("%s",&judge);
                    }
                    if(judge == 'n')        printf("取消成功！\n\n");
                    if(judge == 'y') {
                        EnAQueue(Q, a);
                        Q->type[Q->rear] = '4';
                        printf("插入成功！\n\n");
                    }
                    circle = 0;
                }
                system("pause");
                circle = 0;
            }

            else if(choose == '7') {
                DeAQueue(Q);
                system("pause");
                circle = 0;
            }

            else if(choose == '8') {
                ClearAQueue(Q);
                system("pause");
                circle = 0;
            }

            else if(choose == '9') {
                
                system("pause");
                circle = 0;
            }

            else if(choose == '0') {
                printf("感谢使用！\n\n退出程序！\n\n");
                system("pause");
                return 0;
            }

            else{
                printf("无效的输入请重试：");
                scanf("%s",&choose);
            }
        }
    }
}