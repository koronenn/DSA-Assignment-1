//Arvin Akbari PROG72370
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "player.h"

//creating structs node and queue
typedef struct node
{
	PLAYER player;
	struct node* next;
}Node;

typedef struct queue
{
	Node* head;
	Node* tail;
}Queue;

//creating function prototypes
int addNewPlayerToQueue(Queue* queue, int numOfPlayers);
void displayAllPlayers(Queue* queue);
Queue* initQueue();
int isEmpty(Queue* queue);
int enQueue(Queue* queue, PLAYER player);
PLAYER deQueue(Queue* queue);