#define  _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <assert.h>

//实现函数


//初始化数据
void SeqListInit(SL* ps)
{
	//最无脑的开空间方式
	/*s.size = 0;
	s.a = NULL;
	s.capaity = 0;*/

	//进阶 使用malloc  a存放malloc开辟的地址 是↓个大小
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}

	ps->size = 0;
	ps->capacity = 4;
}


//尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);//传空（NULL）直接报错

	//如果满了，需要增容
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}


//尾删
void SeqListPopBack(SL* ps) {
	assert(ps);
	ps->size--;
}


//头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//是不是需要扩容
	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}


//头删
void SeqListPopFront(SL* ps)
{
	assert(ps);
	int start = 0;
	while (start < (ps->size - 1))
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}


//中间插                   数据位置position
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end>=pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}


//中间删                   数据位置position
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	int start = pos - 1;
	while (start < (ps->size - 1))
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}


//打印
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < (ps->size); i++)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n");
}


//检查容量（顺便扩容）
void SeqListCheckCapacity(SL* ps) 
{
	if ((ps->size) >= (ps->capacity))
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)
			* ps->capacity);
		if (ps->a == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
}


//查找一个值
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	//返回地址
	for (int i = 0; i <(ps->size); i++)
	{
		if (ps->a[i] == x)
		{
			return i + 1;
		}
	}
	printf("找不到\n");
	return NULL;
}