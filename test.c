#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//测试头尾的插入删除
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListInsert(&s, 4,4);
	SeqListPushFront(&s,4);
	int a=SeqListFind(&s, 4);


	SeqListPrint(&s);
	printf("%d", a);
}

int main()
{
	TestSeqList1();

	return 0;
}