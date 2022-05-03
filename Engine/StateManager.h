#pragma once
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	bool isState;
}stateManager;

stateManager* initState(bool* state)
{
	stateManager->isState = state;
	return state;
}