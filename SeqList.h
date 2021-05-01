#pragma once
#include <stdio.h>
#include <stdlib.h>
//˳�����Ч�����������б�����������
//��̬���ݱ�
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

//��̬˳�����ݱ�
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *a;
	int size;	 //��Ч���ݸ���
	int capacity;//����
}SL,SeqList;
//��д

//pop ɾ��
//push д��
//front ��ǰ��
//back  �Ӻ���
//��ʼ������
void SeqListInit(SL* ps);
//β��
void SeqListPushBack(SL* ps, SLDataType x);
//βɾ
void SeqListPopBack(SL* ps);
//ͷ��
void SeqListPushFront(SL* ps, SLDataType x);
//ͷɾ
void SeqListPopFront(SL* ps);
//�м��                   ����λ��position
void SeqListInsert(SL* ps,int pos, SLDataType x);
//�м�ɾ                   ����λ��position
void SeqListErase(SL* ps, int pos);
//��ӡ
void SeqListPrint(SL* ps);
//���������˳�����ݣ�
void SeqListCheckCapacity(SL* ps);
//����һ��ֵ
int SeqListFind(SL* ps, SLDataType x);
//����
int SeqListSort(SL* ps);
//���ֲ���
int SeqListBinaryFind(SL* ps, SLDataType x);