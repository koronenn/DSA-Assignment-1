//Arvin Akbari PROG72370
#include "queue.h"

//initQueue function that creates a new queue and returns its pointer
Queue* initQueue()
{
	//mallocing newQueue and checking if malloc was successful
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	if (newQueue == NULL)
	{
		printf("Cannot allocate memory for Queue");
		return NULL;
	}
	//setting head and tail to null and returning newQueue
	newQueue->head = NULL;
	newQueue->tail = NULL;
	return newQueue;
}

//isEmpty function that returns 0 if queue is not empty and 1 if queue is empty
int isEmpty(Queue* queue)
{
	return queue->head == NULL;
}

//enQueue function that creats new nodes in the queue
int enQueue(Queue* queue, PLAYER player)
{
	//creating a new node and checking if malloc was successful, if not return -1 (indicator of failure)
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("cannot allocate memory to queue");
		return -1;
	}

	//setting newNodes player to the passed player and next to NULL
	newNode->player = player;
	newNode->next = NULL;

	//if the queues tail is null, set the queue head and tail to null
	if (queue->tail == NULL)
	{
		queue->tail = newNode;
		queue->head = newNode;
	}
	//otherwise set the current tails next to newNode, and change the tail to become newNode
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
	}
	return 0;
}

//deQueue function that returns a player
PLAYER deQueue(Queue* queue)
{
	//setting the node to delete to the head node in the queue
	Node* nodeToDelete = queue->head;
	//setting the player to return to the player of the node that will be deleted
	PLAYER playerToReturn = nodeToDelete->player;

	//setting the head to be the next node in the list
	queue->head = queue->head->next;

	//checking if the head points to null, if so, set tail to null as well
	if (queue->head == NULL)
	{
		queue->tail = NULL;
	}

	//freeing the node to delete and returning the player
	free(nodeToDelete);

	return playerToReturn;
}

//addNewPlayerToQueue function that adds indicated amount of players to the queue
int addNewPlayerToQueue(Queue* queue, int numOfPlayers)
{

	//for loop that creates a new player and adds it to the queue 
	for (int i = 0; i < numOfPlayers; i++)
	{
		//creating a newplayer and calling the randomization functions and copying them over to the new player
		PLAYER newPlayer;
		strncpy(newPlayer.playerName, createRandomName(), MAXUSERNAME);
		newPlayer.level = randomizeLevel();
		newPlayer.faction = randomizeFaction();

		//adding the new player to queue, if enQueue returns -1, there was an issue with mallocing, return -1 as well (indication of failure)
		if (enQueue(queue, newPlayer) == -1)
		{
			return -1;
		}
	}

	return 0;

}