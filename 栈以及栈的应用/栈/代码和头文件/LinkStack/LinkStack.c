#include "LinkStack.h"

Status initLStack(LinkStack *s) {
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!s->top)     return ERROR;
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s) {
    if(s->count == 0)   return SUCCESS;
    return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e) {
    if(!s->top) return ERROR;
    *e = s->top->data;
    return SUCCESS;
}

Status clearLStack(LinkStack *s) {
    LinkStackPtr p, q;
    p = s->top;
    while(p) {
        q = p;
        p = p->next;
        free(q);
    }
    s->count = 0;
    return SUCCESS;
}

Status destroyLStack(LinkStack *s) {
    LinkStackPtr p, q;
    p = s->top;
    while(p) {
        q = p;
        p = p->next;
        free(q);
    }
    s->count = 0;
    return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length) {
    LinkStackPtr p = s->top;
    length = 0;
    while(p) {
        length ++ ;
        p = p->next;
    }
    return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!p)  return ERROR;
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count ++ ;
    return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data) {
    LinkStackPtr p;
    if(isEmptyLStack(s))    return ERROR;
    data = s->top->data;
    p = s->top;
    s->top = s->top->next;
    free(p);
    s->count -- ;
    return SUCCESS;
}

void menu() {
    printf("\t\t\t\t**************************");
    printf("\t\t\t\t***  1.判断栈是否为空   ***");
    printf("\t\t\t\t***  2.得到栈顶元素     ***");
    printf("\t\t\t\t***  3.清空栈          ***");
    printf("\t\t\t\t***  4.销毁栈          ***");
    printf("\t\t\t\t***  5.检测栈长度       ***");
    printf("\t\t\t\t***  6.入栈             ***");
    printf("\t\t\t\t***  7.出栈             ***");
    printf("\t\t\t\t***************************");

    printf("请选择功能:");
}

int main() {
    int n,e;
    char judge = 'n';
    LinkStack s;
    initLStack(&s);

    while(judge == 'n') {
        printf("请输入您想插入多少个元素到栈：");
        scanf("%d",&n);
        printf("您想插入%d个栈您确定吗？请输入y 或 n ：");
        scanf("%s",&judge);
        while(judge != 'y' && judge != 'n') {
            printf("无效的输入请重试：");
            scanf("%s",&judge);
        }
    }
    judge = 'n';

    for(int i = 0 ; i < n ; i ++ ) {
        int num;
        while(judge == 'n') {
             printf("请输入您想在第%d个位置放的元素的数值：",i + 1);
            scanf("%d",&num);
            char judge = 'n';
            printf("您确定第%d个位置放的元素的数值是%d。您确定吗？请输入y 或 n：", i + 1, num);
            scanf("%s",&judge);
            while(judge != 'y' && judge != 'n') {
                printf("无效的输入请重试：");
                scanf("%s",&judge);
            }
        }
        if(pushLStack(&s, num))     printf("第%d个成功！\n\n",i + 1);
        else                        printf("第%d个失败!\n\n", i + 1);
    }
    printf("成功！\n\n");

    char choose;
    
    while(1) {
        int circle = 1;
        system("cls");
        menu();
        scanf("%s",&choose);

        while(circle) {
            
            if(choose == '1') {
                if(isEmptyLStack(&s))   printf("该栈为空！\n");
                else                    printf("该栈不为空！\n\n");
                circle = 0;
            }
            else if(choose == '2') {
                getTopLStack(&s, &e);
                printf("栈顶元素为：%lld\n\n",e);
                circle = 0;
            }
            else if(choose == '3') {
                clearLStack(&s);
                printf("清空栈成功！\n\n");

                while(judge == 'n') {
                    printf("请输入您想插入多少个元素到栈：");
                    scanf("%d",&n);
                    printf("您想插入%d个栈您确定吗？请输入y 或 n ：");
                    scanf("%s",&judge);
                    while(judge != 'y' && judge != 'n') {
                        printf("无效的输入请重试：");
                        scanf("%s",&judge);
                    }
                }
                judge = 'n';

                for(int i = 0 ; i < n ; i ++ ) {
                    int num;
                    while(judge == 'n') {
                        printf("请输入您想在第%d个位置放的元素的数值：",i + 1);
                        scanf("%d",&num);
                        char judge = 'n';
                        printf("您确定第%d个位置放的元素的数值是%d。您确定吗？请输入y 或 n：", i + 1, num);
                        scanf("%s",&judge);
                        while(judge != 'y' && judge != 'n') {
                            printf("无效的输入请重试：");
                            scanf("%s",&judge);
                        }
                    }
                    if(pushLStack(&s, num))     printf("第%d个成功！\n\n",i + 1);
                    else                        printf("第%d个失败!\n\n", i + 1);
                }

                circle = 0;
            }
            else if(choose == '4') {
                destroyLStack(&s);
                printf("销毁栈成功！\n\n感谢使用！\n\n");
                system("pause");
                return 0;
            }
            else if(choose == '5') {
                int length = 0;
                LStackLength(&s, &length);
                printf("该栈长度为: %d\n\n",length);
                circle = 0;
            }
            else if(choose == '6') {
                char judge = 'n';
                int num;
                printf("请输入您想添加的数据：");
                scanf("%d",&num);
                while(judge == 'n') {
                    printf("您想加入的数据为%d， 你确定吗？请输入y 或 n：");
                    scanf("%s",&judge);
                    while(judge != 'y' && judge != 'n') {
                        printf("无效的输入请重试：");
                        scanf("%s",&judge);
                    }
                }
                if(pushLStack(&s, num))    printf("成功入栈！\n\n");
                else                        printf("入栈失败！\n\n");
                circle = 0;
            }
            else if(choose == '7') {
                if(popLStack(&s, &e))       printf("出栈成功！值为%d\n\n", &e);
                else                        printf("出栈失败!\n\n");
                circle = 0;
            }
            else {
                printf("无效的输入请重试：");
                scanf("%s",&choose);
            }
        }
    }
}