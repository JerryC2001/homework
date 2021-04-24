#include "binary_sort_tree.h"


Status BST_init(NodePtr* BT) {
    *BT = NULL;
    printf("初始化成功！\n\n");
    return true;
}

Status BST_insert(NodePtr* BT, ElemType e) {
    NodePtr p = NULL;
    if(!(*BT)) {
        p = (NodePtr)malloc(sizeof(Node));
        p->value = e;
        p->left = p->right = NULL;
        *BT = p;
        printf("插入成功！\n\n");
        return true;
    }
    if(e == (*BT)->value) {
        printf("已经插入过该值！\n\n");
        return false;
    }
    if(e < (*BT)->value) BST_insert(&(*BT)->left, e);
    if(e > (*BT)->value) BST_insert(&(*BT)->right, e);
    return true;
}

Status BST_delete(NodePtr* BT, ElemType e) {
    NodePtr p = *BT, q, pPatient;
    if(!p) {
        printf("没有树根！\n\n");
        return false;
    }
    while(e != p->value) {
        if(!p) {
            printf("没有找到该值！\n\n");
            return false;
        }
        pPatient = p;
        if(e < p->value)    p = p->left;
        else                p = p->right;
    }
    if(!(p->left) && !(p->right)) {
        q = p;
        free(q);
    }
    else if(p->left && p->right) {
        q = p->left;
        NodePtr qPatient = q;
        while(q->right)     qPatient = q, q = q->right;
        p->value = q->value;
        free(q);
        qPatient->left = qPatient->right = NULL;
    }
    else {
        if(p->left)     q = p->left;
        if(p->right)    q = p->right;
        pPatient->left = q;
        free(p);
    }
    return true;
}

Status BST_search(NodePtr BT, ElemType e) {
    if(!BT) return false;
    if(e != BT->value) {
        BST_search(BT->left, e);
        BST_search(BT->right, e);
    }
    if(e == BT->value){
        printf("查询有此数！\n\n");
        return true;
    }
    return true;
}

Status BST_preorderR(NodePtr BT) {
    if(!BT) return false;
    printf("%d ",BT->value);
    BST_preorderR(BT->left);
    BST_preorderR(BT->right);
    return true;
}

Status BST_preorderI(NodePtr BT) {
    if(!BT) return false;
    NodePtr stk[20];
    int top = -1;
    NodePtr p = BT;
    while(p || top != -1) {
        if(p) {
            stk[++ top] = p;
            printf("%d ",p->value);
            p = p->left;
        }
        else {
            p = stk[top -- ];
            p = p->right;
        }
    }
    return true;
}

Status BST_inorderR(NodePtr BT) {
    if(!BT) return false;

    BST_inorderR(BT->left);
    printf("%d ",BT->value);
    BST_inorderR(BT->right);
    return true;
}

Status BST_inorderI(NodePtr BT) {
    if(!BT) return false;
    NodePtr stk[20];
    int top = -1;
    NodePtr p = BT;
    while(p || top != -1) {
        if(p) {
            stk[ ++ top] = p;
            p = p->left;
        }
        else {
            p = stk[top -- ];
            printf("%d ",p->value);
            p = p->right;
        }
    }
    return true;
}

Status BST_postorderR(NodePtr BT) {
    if(!BT) return false;

    BST_postorderR(BT->left);
    BST_postorderR(BT->right);
    printf("%d ",BT->value);
    return true;
}

Status BST_postorderI(NodePtr BT) {
    if(!BT) return false;
    NodePtr stk[20];
    int top = -1;
    int flagstk[20];
    NodePtr p = BT;
    while(p || top != -1) {
        if(p) {
            stk[ ++ top] = p;
            flagstk[top] = 1;
            p = p->left;
        }
        else {
            if(flagstk[top]) {
                p = stk[top];
                flagstk[top] = 0;
                p = p->right;
            }
            else {
                p = stk[top -- ];
                printf("%d ",p->value);
                p = NULL;
            }
        }
    }
    return true;
}

Status BST_levelOrder(NodePtr BT) {
    if(!BT) return false;
    NodePtr temp;
    NodePtr queue[QueueMaxSize];
    int front = 0;
    int rear = 0;
    if(BT) {
        queue[rear] = BT;
        rear = (rear + 1) % QueueMaxSize;
    }
    while(front != rear) {
        temp = queue[front];
        front = (front + 1) % QueueMaxSize;
        printf("%d ",temp->value);
        if(temp->left) {
            queue[rear] = temp->left;
            rear = (rear + 1) % QueueMaxSize;
        }
        if(temp->right) {
            queue[rear] = temp->right;
            rear = (rear + 1) % QueueMaxSize;
        }
    }
    return true;
}

void menu() {
    printf("\t\t\t\t二叉排列树\n");
    printf("\t\t\t\t1.插入数字\n");
    printf("\t\t\t\t2.查询数字\n");
    printf("\t\t\t\t3.删除数字\n");
    printf("\t\t\t\t4.递归前序遍历\n");
    printf("\t\t\t\t5.递归中序遍历\n");
    printf("\t\t\t\t6.递归后序遍历\n");
    printf("\t\t\t\t7.迭代前序遍历\n");
    printf("\t\t\t\t8.迭代中序遍历\n");
    printf("\t\t\t\t9.迭代后序遍历\n");
    printf("\t\t\t\t10.层序遍历\n");
    printf("\t\t\t\t11.退出程序\n");
    printf("请直接输入数字进行对应操作：");
}

int main() {
    int circle = 1;
    int choose;

    NodePtr root;
    BST_init(&root);
    

    while(circle) {

        system("pause");
        system("cls");
        menu();
        scanf("%d",&choose);
        
        if(choose == 1) {
            int e;
            printf("请输入您想插入的数据：");
            scanf("%d",&e);
            if(BST_insert(&root, e))   printf("插入成功！\n\n");
            else                    printf("插入失败！\n\n");
            
        }
        else if(choose == 2) {
            int e;
            printf("请输入您想查询的数：");
            scanf("%d",&e);
            BST_search(root, e);
        }
        else if(choose == 3) {
            int e;
            printf("请输入您想删除的数：");
            scanf("%d",&e);
            if(BST_delete(&root, e))    printf("操作成功！\n\n");
            else                        printf("操作失败！\n\n");
        }
        else if(choose == 4) {
            if(BST_preorderR(root))   printf("操作成功！\n\n");
            else                    printf("操作失败！\n\n");
        }
        else if(choose == 5) {
            if(BST_inorderR(root))    printf("操作成功！\n\n");
            else                    printf("操作失败！\n\n");
        }
        else if(choose == 6) {
            if(BST_postorderR(root))  printf("操作成功！\n\n");
            else                    printf("操作失败！\n\n");
        }
        else if(choose == 7) {
            if(BST_preorderI(root))    printf("操作成功！\n\n");
            else                        printf("操作失败！\n\n");
        }
        else if(choose == 8) {
            if(BST_inorderI(root))      printf("操作成功！\n\n");
            else                        printf("操作失败！\n\n");
        }
        else if(choose == 9) {
            if(BST_postorderI(root))    printf("操作成功！\n\n");
            else                        printf("操作失败！\n\n");
        }
        else if(choose == 10) {
            if(BST_levelOrder(root))  printf("操作成功！\n\n");
            else                    printf("操作失败！\n\n");
        }
        else if(choose == 11) {
            printf("\n退出程序成功！\n\n");
            system("pause");
            return 0;
        }
        else {
            printf("无效的输入请重试!");
        }
    }
}