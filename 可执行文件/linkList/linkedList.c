#include "linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    *L = (LinkedList)malloc(sizeof(LNode));
    if(!(*L))
        return ERROR;
    (*L)->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList q;
    while(*L) {
        q = (*L)->next;
        free(*L);
        *L = q;
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if(!p)  return ERROR;
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if(!p || !p->next)
        return ERROR;
    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */

void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    while(L) {
        visit(L->data);
        L = L->next;
    }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    LNode *p = L;
    while(p) {
        if(p->data == e)    return SUCCESS;
        else    p = p->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    if(!(*L))     return ERROR;
    LinkedList p1, p2, p3;
    p1 = *L;
    p2 = p3 = p1->next;
    p1->next = NULL;
    while(p3) {
        p3 = p3->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    *L = p1;
    return SUCCESS;
}
/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LNode *fast, *slow;
    fast = slow = L;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return SUCCESS;
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    LinkedList p1, p2, head, t;
    int n = 0;
    head = p1 = *L;
    while(p1->next) {
    	p2 = p1->next;
    	p1->next = p2->next;
    	p2->next = p1;
    	if( ++ n == 1)	head = p2;
    	else	t->next = p2;
    	t = p1;
    	p1 = p1->next;
    	if(!p1)	break;
	}
	return head;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LinkedList p1, p2;
    p1 = p2 = *L;
    while(p2) {
    	p2 = p2->next->next;
    	p1 = p1->next;
    	if(p2->next->next == NULL) {
    		printf("中间结点数据为%d\n",p1->data);
    		break;
    	}
    	if(p2->next == NULL) {
    		printf("中间结点数据为%d, %d\n", p1->data, p1->next->data);
			break;
		}
	}
	return p1;
}

