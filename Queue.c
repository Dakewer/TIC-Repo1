/*
 * Queue.c
 *
 *  Created on: 14 oct. 2024
 *      Author: hpiza
 */

#include <stdio.h>
#include "Queue.h"
#include <stdlib.h>

struct strNode {
	Type data;
	struct strNode* next;
};

typedef struct strNode* Node;

struct strQueue {
	Node first, last;
	int size;
};

Queue queue_create() {
	Queue q = (Queue) malloc(sizeof(struct strQueue));
	q->first = NULL;
	q->last = NULL;
	q->size = 0;
	return q;
}

int queue_size(Queue q) {
	return q->size;
}

Bool queue_isEmpty(Queue q) {
	return q->first == NULL;
}

Type queue_peek(Queue q) {
	if(queue_isEmpty(q)) return NULL;
	return q->first->data;
}

void queue_offer(Queue q, Type t) {
	Node n = (Node) malloc(sizeof(struct strNode));
	n->data = t;
	n->next = NULL;
	if(queue_isEmpty(q))
		q->first = n;
	else
		q->last->next = n;
	q->last = n;
	q->size ++;
}

Type queue_poll(Queue q) {
	if(queue_isEmpty(q)) return NULL;
	Type data = q->first->data;
	Node second = q->first->next;
	if(second == NULL) q->last = NULL;
	free(q->first);
	q->first = second;
	q->size --;
	return data;
}

void queue_print(Queue q, PrintFunc print) {
	Node tmp=q->first;
	printf("[");
	while(tmp!=NULL) {
		print(tmp->data);
		if(tmp->next!=NULL) printf(", ");
		tmp=tmp->next;
	}
	printf("]\n");
}

void queue_destroy(Queue q) {
	Node n = q->first;
	Node tmp;
	while(n != NULL) {
		tmp = n->next;
		free(n);
		n = tmp;
	}
	free(q);
}

