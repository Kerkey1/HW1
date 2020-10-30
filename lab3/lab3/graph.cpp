#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

typedef struct Node {
	int index;
	struct Node* next;
}LIST;

LIST* GM[50];

LIST* create_node(int name)
{
	LIST* tmp = (LIST*)malloc(sizeof(LIST));
	tmp->index = name;
	tmp->next = NULL;
	return(tmp);
}
void add_element_end(int data, LIST* head)
{
	
	LIST* tmp = (LIST*)malloc(sizeof(LIST));
	tmp->index = data;
	tmp->next = NULL;
	LIST* p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = tmp;
}
LIST* remove_all(LIST* head)
{
	while (head != NULL)
	{
		LIST* p = head;
		head = head->next;
		free(p);
	}
	return NULL;
}
LIST* remove_element(int data, LIST* head)
{
	LIST* tmp = head, * p = NULL;
	if (head == NULL)
		return NULL;
	while (tmp && tmp->index != data)
	{
		p = tmp;
		tmp = tmp->next;
	}
	if (tmp == head)
	{
		free(head);
		return tmp->next;
	}
	if (!tmp)
		return head;
	p->next = tmp->next;
	free(tmp);
	return head;
}
void print(LIST* head) {
	LIST* v = head;
	if (v != NULL) {
		printf("%d:  ", v->index + 1);
		v = v->next;
	}
	while (v != NULL)
	{
		printf("%d ", v->index + 1);
		v = v->next;
	}
}
void transfer(int**Array,int N) {
	printf("Список Смежности:\n");
	for (int i = 0; i < N; i++) {
		Node* tmp = create_node(i);
		for (int j = 0; j < N; j++) {
			if (Array[i][j] == 1)
				add_element_end(j, tmp);
		}
		GM[i] = tmp;
	}
	for (int i = 0; i < N; i++) {
		print(GM[i]);
		printf("\n");
	}
	printf("\n");
}
/*
void S_identification(LIST* (&p), int N, int x1, int x2) {
	for (int i = 0; i < N; i++) {
		LIST* v = &p[i];

		if (v->index != x2 && v->index != x1) {
			if (v != NULL)	v = v->next;
			while (v != NULL) {
				if (v->index == x2)
					v->index = x1;
				v = v->next;
			}
		}
		if (v->index == x2)
			remove_all(&p[i]);

	}
	for (int i = 0; i < N; i++) {
		if (i == x2) continue;
		print(GM[i]);
		printf("\n");
	}
	printf("\n");
}
*/