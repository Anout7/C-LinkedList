#include"DList.h";


LTNode* DListInit() {
	//创建哨兵头节点
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead; 
}

LTNode* BuyDListNode(LTDateType x) {
	LTNode* tmp = (LTNode*)malloc(sizeof(LTNode));
	tmp->data = x;
	tmp->prev = NULL;
	tmp->next = NULL;

	return tmp;
}

void DListPrint(LTNode* phead) {
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void DListPushBack(LTNode* phead, LTDateType x) {
	assert(phead);

	//LTNode* tail = phead->prev;
	//LTNode* tmp = BuyDListNode(x);

	//tail->next = tmp;
	//tmp->prev = tail;
	//tmp->next = phead;
	//phead->prev = tmp;

	DListInsert(phead, x);
}

void DListPopBack(LTNode* phead) {
	//assert(phead);
	//assert(phead->next != phead);

	//LTNode* tail = phead->prev;
	//tail->prev->next = phead;
	//phead->prev = tail->prev;
	//free(tail);

	DListErase(phead->prev);
}

void DListPushFront(LTNode* phead, LTDateType x) {
	assert(phead);

	//LTNode* tmp = BuyDListNode(x);

	//LTNode* head = phead->next;
	//phead->next = tmp;
	//tmp->prev = phead;
	//tmp->next = head;
	//head->prev = tmp;

	DListInsert(phead->next, x);
}

void DListPopFront(LTNode* phead) {
	//assert(phead);
	//assert(phead->next != phead);

	//LTNode* head = phead->next;
	//phead->next = head->next;
	//head->next->prev = phead;

	//free(head);

	DListErase(phead->next);
}

LTNode* DListFind(LTNode* phead, LTDateType x) {
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

//pos位置之前插入 与DListFind一起用
void DListInsert(LTNode* pos, LTDateType x) {
	assert(pos);

	LTNode* tmp = BuyDListNode(x);
	LTNode* posPrev = pos->prev;

	posPrev->next = tmp;
	tmp->prev = posPrev;
	tmp->next = pos;
	pos->prev = tmp;
}

//删除pos位置 与DListFind一起用
void DListErase(LTNode* pos) {
	assert(pos);

	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
}

void DListDestroy(LTNode* phead) {
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead) {
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
}

