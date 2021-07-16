// montyhallsimulationC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

using namespace::std;

int chooseDoor();

/**
*	Method gotten from 3rd method here: https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
*/
float roundFloat(float var)
{
	// we use array of chars to store number
	// as a string.
	char str[40];

	// Print in string the value of var 
	// with two decimal point
	sprintf_s(str, "%.5f", var);

	// scan string value in var 
	sscanf_s(str, "%f", &var);

	return var;
}

/**
*	Creates a new door array on the heap, and passes the pointer to it back;
*/
bool* getRandomDoorArray()
{
	bool *doors = new bool[3];
	doors[0] = false; doors[1] = false; doors[2] = false;
	int randDoor = chooseDoor();
	doors[randDoor] = true;
	return doors;
}

/**
*	Chooses a random door (int between 1 and 3)
*/
int chooseDoor() {
	return rand() % 3;
}

/**
*	returns which door to "open", i.e, the one with the goat
*	also provides the door option that can be switched to
*/
int openGoatDoor(int choiceDoor, bool* doors, int* switchDoor) {
	int goat = -1;
	for (int i = 0; i < 3; i++) {
		if (doors[i] == false && i != choiceDoor) {
			goat = i;
		}
	}
	*switchDoor = (0 + 1 + 2) - (goat + choiceDoor);
	return goat;
}

/**
*	Run the simulation once and free memory
*	sets values of pointers for the main function
*/
void simulate(bool* pickedDoorVal, bool* switchedDoorVal) {
	//get random door to have car
	bool* doors = getRandomDoorArray();
	//choose door
	int pickedDoor = chooseDoor();
	//open goat door
	int* switchDoor = new int;
	int goatDoor = openGoatDoor(pickedDoor, doors, switchDoor);
	//return picked doors
	*pickedDoorVal = doors[pickedDoor];
	*switchedDoorVal = doors[*switchDoor];
	//free memory
	delete [] doors;
	delete switchDoor;
}

int main()
{
	const int TIMESTOSIMULATE = 100000;
	int sumFirstChoice = 0;
	int sumSwitchChoice = 0;
	for (int i = 0; i < TIMESTOSIMULATE; i++) {
		//run simulation
		bool pickedDoorValue = false;
		bool switchedDoorValue = false;
		simulate(&pickedDoorValue, &switchedDoorValue);
		//sum the results
		if (pickedDoorValue == true)
		{
			sumFirstChoice += 1;
		}
		if(switchedDoorValue == true)
		{
			sumSwitchChoice += 1;
		}
			
	}
	//get percentages
	float percentSwitchWon = (float)sumSwitchChoice / (float)TIMESTOSIMULATE;
	float percentChoiceWon = (float)sumFirstChoice / (float)TIMESTOSIMULATE;
	//round the floats
	percentSwitchWon = roundFloat(percentSwitchWon)*100;
	percentChoiceWon = roundFloat(percentChoiceWon)*100;
	//sumarise results
	printf("Keeping your first choice, you win %.3f%% of the time\n", percentChoiceWon);
	printf("Switching your choice, you win %.3f%% of the time\n", percentSwitchWon);


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
