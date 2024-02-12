//Arvin Akbari PROG72370
#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
#define NUMOFARGSPASSED 2
#define ARGUEMENTINDEX 1
#include <time.h>

int main(int argc, char* argv[])
{
	//calling the srand function so that randomization is random every time program is run
	srand(time(NULL));

	//checking to see if the number of arguement is passed, if not print error message and exit program.
	if (argc != NUMOFARGSPASSED)
	{
		printf("Error: Incorrect number of arguements passed, expected %d arguements, recieved %d arguements", NUMOFARGSPASSED, argc);
		return 1;
	}

	//converting the argv to an int
	int numberOfPlayers = atoi(argv[ARGUEMENTINDEX]);

	//checking to see if the number of players is greater than 0
	if (numberOfPlayers <= 0)
	{
		printf("Error: A positive number of players is needed");
		return 1;
	}

	//initializing queue
	Queue* queue = initQueue();

	//adding new players, if function returns -1 print error message and exit program
	if (addNewPlayerToQueue(queue, numberOfPlayers) == -1)
	{
		printf("\n could not successfully add players to queue");
		return 1;
	}

	printf("Added %d players to queue\n", numberOfPlayers);

	//array of strings of all factions
	char* playerFactions[] = { "Red", "Blue", "Green" };

	//while loop that will call deQueue function and print player information so long as queue is not empty
	while (!isEmpty(queue))
	{
		PLAYER playerToDisplay = deQueue(queue);
		printf("Player Name: %s, Current Level: %d, Current Faction: %s\n",
			playerToDisplay.playerName, playerToDisplay.level,
			playerFactions[playerToDisplay.faction]);
	}

	return 0;
}