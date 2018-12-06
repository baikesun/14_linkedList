#include <stdio.h>
#include <stdlib.h>

typedef struct linknd{
	int data;
	void *next;
	//struct linknd *next;
} linknd_t;

static /*struct linknd*/linknd_t *list;   //linkedList의 실체를 전역변수로 선언 

linknd_t* create_node(int value)   //header node를 가리키는 함수  
{
	linknd_t* ndPtr;
	
	//동적 메모리 할당
	ndPtr = (linknd_t*)malloc(sizeof(linknd_t)); //(malloc이 구조체를 만환) //구조체의 크기만큼의 메모리를 할당 
	if(ndPtr == NULL)
	{
		printf("ERROR!\n");
		
		return NULL;
	}
	
	//정수를 저장 
	ndPtr->data = value;
	ndPtr->next = NULL;   //linkedList 초기화의 핵심. 뭘 가리킬지 모른다. 
	
	return ndPtr; 
}

void addTail(int value)   //다음 node 마지막을 가리키는 함수 
{
	linknd_t *ndPtr, *newPtr;   //node를 가리키는 포인터 변수 
	
	if(list == NULL)   //첫 node이면 
	{
		return;
	}
	else   //이전에 node를 만든 적이 있따면 
	{
		ndPtr = list;
		
		while(ndPtr->next != NULL)
		{
			ndPtr = ndPtr->next;
		}
		
		newPtr = create_node(value);
		ndPtr->next = newPtr;   //새로 만든 node를 가리키게 함 
	}
}

void genList(void)   //list의 실체 만들기(header node만들기) 
{
	list = create_node(0);
	
	return;
}

void print_list(void)   //유의미한 data가 있는 node의 값을 출력(2번째 node부터 출력) 
{
	linknd_t *ndPtr;
	
	ndPtr = list->next;
	
	while(ndPtr != NULL)
	{
		printf("%i ", ndPtr->data);
		
		ndPtr = ndPtr->next;
	}
}
