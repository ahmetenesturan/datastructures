#include <stdio.h>
#include <stdlib.h>

#define stacksize 10

typedef struct stk stack;
typedef struct node linkedlist;

struct node
{
	int data;
	struct node* next;
};

struct stk
{
	linkedlist* data[stacksize];
	int top;
};

linkedlist* create_list(int num)
{
	linkedlist* list = (linkedlist*)malloc(sizeof(linkedlist));
	list->data = num;
	list->next = NULL;
	return list;
}

void add_to_list(linkedlist* a, int num)
{
	linkedlist* list = create_list(num);
	a->next = list;
}


stack* create_stack(linkedlist* list)
{
	stack* out = (stack*)malloc(sizeof(stack));
	out->data[0] = list;
	out->top = 0;
	return out;
}


void push(stack* n_stk, linkedlist* list)
{
	if (n_stk->top == stacksize - 1) printf("stack is full");
	else
	{
		n_stk->top++;
		n_stk->data[n_stk->top] = list;
	}
}



int main(void)
{
	linkedlist* lst = create_list(5);
	add_to_list(lst, 3);
	linkedlist* lt = create_list(7);
	stack* a = create_stack(lst);
	push(a, lt);
	return 0;
}