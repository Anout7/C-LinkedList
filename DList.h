#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDateType;

typedef struct ListNode {
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* DListInit();
LTNode* BuyDListNode(LTDateType x);
void DListPrint(LTNode* phead);
void DListPushBack(LTNode* phead, LTDateType x);
void DListPopBack(LTNode* phead);
void DListPushFront(LTNode* phead, LTDateType x);
void DListPopFront(LTNode* phead);
LTNode* DListFind(LTNode* phead, LTDateType x);
void DListInsert(LTNode* pos, LTDateType x);
void DListErase(LTNode* pos);
void DListDestroy(LTNode* phead);

