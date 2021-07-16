// montyhallsimulationC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

using namespace::std;

bool* getRandomDoorArray()
{
	bool *doors = new bool[3];
	doors[0] = false; doors[1] = false; doors[2] = false;
	int randDoor = rand() % 3;
	cout << randDoor;
	doors[randDoor] = true;
	return doors;
}


void simulate() {
	//get random door to have car
	bool* doors = getRandomDoorArray();
	//choose door

	//open goat door
	
	//return picked doors
	delete [] doors;
}

int main()
{
	const int TIMESTOSIMULATE = 100000;
	int sumFirstChoice = 0;
	int sumSwitchChoice = 0;
	for (int i = 0; i < TIMESTOSIMULATE; i++) {
		simulate();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
