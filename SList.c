#include"SList.h";

SLTNode* BuyListNode(SLTDataType x){
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
	if (tmp == NULL) {
		printf("malloc fail\n");
		exit(-1);
	}
	tmp->data = x;
	tmp->next = NULL;

	return tmp;
}

void SListPrint(SLTNode* phead)  {
	SLTNode* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SLTNode** pphead, SLTDataType x) {
	SLTNode* tmp = BuyListNode(x);

	if (*pphead == NULL) {
		*pphead = tmp;
	}
	else {
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = tmp;
	}

}

void SListPushFront(SLTNode** pphead, SLTDataType x) {
	SLTNode* tmp = BuyListNode(x);
	
	tmp->next = *pphead;
	*pphead = tmp;
}

void SListPopBack(SLTNode** pphead) {
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SLTNode* tail = *pphead;
		while (tail->next->next) {
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead) {
	assert(*pphead);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
	SLTNode* cur = phead;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		else {
			cur = cur->next;
		}
	}

	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	SLTNode* tmp = BuyListNode(x);

	if (*pphead == pos) {
		*pphead = tmp; 
		tmp->next = pos;
	}
	else {
		SLTNode* prevPos = *pphead;
		while (prevPos->next != pos) {
			prevPos = prevPos->next;
		}

		prevPos->next = tmp;
		tmp->next = pos;
	}

}

void SListErase(SLTNode** pphead, SLTNode* pos) {
	if (*pphead == pos) {
		*pphead = (*pphead)->next;
		free(pos);
	}
	else{
		SLTNode* prev = *pphead;
		while (prev != pos) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(prev);
	}
}

void SListDestory(SLTNode** pphead) {
	SLTNode* cur = *pphead;
	while (cur){
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
}