//Arvin Akbari PROG72370
#pragma once

//setting definitions and including necessary libraries
#define FACTIONS 3
#define MAXUSERNAME 11
#define MAXCHARSET 61
#define MINLEVEL 1
#define MAXLEVEL 60
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaring enum faction and struct player
typedef enum faction
{
	RED,
	BLUE,
	GREEN
}Faction;

typedef struct player
{
	int level;
	char playerName[MAXUSERNAME];
	Faction faction;
}PLAYER;

//creating prototypes for randomization functions
char* createRandomName();
int randomizeLevel();
int randomizeFaction();
