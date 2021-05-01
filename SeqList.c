#define  _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <assert.h>

//ʵ�ֺ���


//��ʼ������
void SeqListInit(SL* ps)
{
	//�����ԵĿ��ռ䷽ʽ
	/*s.size = 0;
	s.a = NULL;
	s.capaity = 0;*/

	//���� ʹ��malloc  a���malloc���ٵĵ�ַ �ǡ�����С
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}

	ps->size = 0;
	ps->capacity = 4;
}


//β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);//���գ�NULL��ֱ�ӱ���

	//������ˣ���Ҫ����
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}


//βɾ
void SeqListPopBack(SL* ps) {
	assert(ps);
	ps->size--;
}


//ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//�ǲ�����Ҫ����
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


//ͷɾ
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


//�м��                   ����λ��position
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


//�м�ɾ                   ����λ��position
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


//��ӡ
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < (ps->size); i++)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n");
}


//���������˳�����ݣ�
void SeqListCheckCapacity(SL* ps) 
{
	if ((ps->size) >= (ps->capacity))
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)
			* ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
	}
}


//����һ��ֵ
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	//���ص�ַ
	for (int i = 0; i <(ps->size); i++)
	{
		if (ps->a[i] == x)
		{
			return i + 1;
		}
	}
	printf("�Ҳ���\n");
	return NULL;
}