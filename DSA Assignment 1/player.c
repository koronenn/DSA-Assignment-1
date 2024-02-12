//Arvin Akbari PROG72370
#include "queue.h"

//function createRandomName
char* createRandomName()
{
	//declaring the charSet of all lower and capital letters in alphabet and all numbers from  1-9
	char charSet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
	char playerName[MAXUSERNAME];

	//for loop that calls rand to get a random int between 0 and 61 which indicates the random index in charSet
	//setting playerName at index I to the random character chosen by rand
	for (int i = 0; i < MAXUSERNAME; i++)
	{
		int charSetIndex = rand() % MAXCHARSET;
		playerName[i] = charSet[charSetIndex];
	}
	//setting the last character in playerName to null terminator
	playerName[MAXUSERNAME - 1] = '\0';
	return playerName;
}

//randomizeLevel function that calls rand function and returns a random number between 1 and 60
int randomizeLevel()
{
	return rand() % (MAXLEVEL)+MINLEVEL;
}

//randomizeFaction function that calls rand function and returns a random number between 0 and 3
int randomizeFaction()
{
	return rand() % FACTIONS;
}



