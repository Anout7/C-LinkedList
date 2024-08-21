#include"DList.h";

void TestList2() {
	//哨兵头节点不存储有效数据
	LTNode* plist = DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPrint(plist);

	DListPopBack(plist);
	DListPopBack(plist);
	DListPrint(plist);

	DListPushFront(plist, 100);
	DListPushFront(plist, 200);
	DListPushFront(plist, 300);
	DListPrint(plist);

	DListPopFront(plist);
	DListPrint(plist);

	LTNode* pos = DListFind(plist, 2);
	if (pos) {
		DListErase(pos);
	}
	DListPrint(plist);

	DListDestroy(plist);
	plist = NULL;
}


int main() {
	TestList2();

	return 0;
}