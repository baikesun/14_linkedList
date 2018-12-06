#include <stdio.h>
#include <stdlib.h>

typedef struct linknd{
	int data;
	void *next;
	//struct linknd *next;
} linknd_t;

static /*struct linknd*/linknd_t *list;   //linkedList�� ��ü�� ���������� ���� 

linknd_t* create_node(int value)   //header node�� ����Ű�� �Լ�  
{
	linknd_t* ndPtr;
	
	//���� �޸� �Ҵ�
	ndPtr = (linknd_t*)malloc(sizeof(linknd_t)); //(malloc�� ����ü�� ��ȯ) //����ü�� ũ�⸸ŭ�� �޸𸮸� �Ҵ� 
	if(ndPtr == NULL)
	{
		printf("ERROR!\n");
		
		return NULL;
	}
	
	//������ ���� 
	ndPtr->data = value;
	ndPtr->next = NULL;   //linkedList �ʱ�ȭ�� �ٽ�. �� ����ų�� �𸥴�. 
	
	return ndPtr; 
}

void addTail(int value)
{
	linknd_t *ndPtr, *newPtr;   //node�� ����Ű�� ������ ���� 
	
	if(list == NULL)   //ù node�̸� 
	{
		return;
	}
	else   //������ node�� ���� ���� �ֵ��� 
	{
		ndPtr = list;
		
		while(ndPtr->next != NULL)
		{
			ndPtr = ndPtr->next;
		}
		
		newPtr = create_node(value);
		ndPtr->next = newPtr;   //���� ���� node�� ����Ű�� �� 
	}
}
