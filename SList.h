#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
} SLTNode;

void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
SLTNode* SListFind(SLTNode* pphead, SLTDataType x);
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListDestroy(SLTNode** pphead);

