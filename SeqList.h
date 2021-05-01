#pragma once
#include <stdio.h>
#include <stdlib.h>
//顺序表，有效数组在数组中必须是连续的
//静态数据表
//typedef int SLDataType;
//#define NUM 10
//struct SeqList
//{
//	SLDataType _a[NUM];
//	int size;
//};
//
//void SeqListPushBack(struct SeqList* ps, SLDataType x);
//void SeqListPopBack(struct SeqList* ps);
//void SeqListPushFront(struct SeqList* ps, SLDataType x);
//void SeqListPopFront(struct SeqList* ps);

//动态顺序数据表
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *a;
	int size;	 //有效数据个数
	int capacity;//容量
}SL,SeqList;
//简写

//pop 删除
//push 写入
//front 从前面
//back  从后面
//初始化数据
void SeqListInit(SL* ps);
//尾插
void SeqListPushBack(SL* ps, SLDataType x);
//尾删
void SeqListPopBack(SL* ps);
//头插
void SeqListPushFront(SL* ps, SLDataType x);
//头删
void SeqListPopFront(SL* ps);
//中间插                   数据位置position
void SeqListInsert(SL* ps,int pos, SLDataType x);
//中间删                   数据位置position
void SeqListErase(SL* ps, int pos);
//打印
void SeqListPrint(SL* ps);
//检查容量（顺便扩容）
void SeqListCheckCapacity(SL* ps);
//查找一个值
int SeqListFind(SL* ps, SLDataType x);
//排序
int SeqListSort(SL* ps);
//二分查找
int SeqListBinaryFind(SL* ps, SLDataType x);