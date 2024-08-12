#include"SList.h";

void TestList1() {
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 6);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 7);
	SListPushBack(&plist, 8);
	SListPushBack(&plist, 2);
	SListPrint(plist);

	SListPushFront(&plist, 0);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPrint(plist); 

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 2);
	int i = 1;
	while (pos) {
		printf("第%d个pos节点：%p -> %d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	//查找->修改
	pos = SListFind(plist, 6);
	if (pos) {
		pos->data = 100;
	}
	SListPrint(plist);

	//插入
	SLTNode* pos2= SListFind(plist, 1);
	if (pos2) {
		SListInsert(&plist, pos2, 200);
	}
	SListPrint(plist);

}



int main() {
	TestList1();

	return 0;
}