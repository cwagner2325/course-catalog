//***************************************************************************
// File name:			PUDriver.cpp
// Author:				Cayden Wagner
// Date:					April 6 2021
// Class:					CS 250
// Assignment:		04PUCourses
// Purpose:				Create a class that represents a course at Pacific
//								University.
// Hours:					4
// Computer OS:   MacOS
//***************************************************************************

#include "Course.h"
#include <iostream>
#include <fstream>

using namespace std;

void printMenu ();
void drawHeading (string, char);

/****************************************************************************
Function:			main

Description:	Driver to test the functionality of class Course

Parameters:		None

Returned:			Exit status
****************************************************************************/

int main () {
	const string PROGRAM_TITLE = "PACIFIC UNIVERSITY COURSES";
	const string COMPUTER_SICENCE_PREFIX = "CS";
	const string MATH_PREFIX = "MATH";
	const string OPTION_ONE = "1", OPTION_TWO = "2", OPTION_THREE = "3";
	const string OPTION_FOUR = "4";
	const string INPUT_FILE = "courses.txt";
	const char BORDER_CHAR = '*';
	const int MAX_SIZE = 10;

	Course* apcCourses[MAX_SIZE] = { nullptr };
	int numCourses = 0;
	string userPrefix, userSelection = "0", userNumber;
	bool bIsValidCourse = true, bFoundCourse = false;
	ifstream cInputFile;

	drawHeading (PROGRAM_TITLE, BORDER_CHAR);

	cInputFile.open (INPUT_FILE);

	if (!(cInputFile.is_open ())) {
		cout << "The File Failed to Open" << endl;
		return EXIT_FAILURE;
	}

	while (!cInputFile.eof () && MAX_SIZE > numCourses) {
		apcCourses[numCourses] = new Course;
		cInputFile >> *apcCourses[numCourses];
		numCourses++;
	}

	for (int i = 0; i < numCourses && bIsValidCourse; i++) {
		bIsValidCourse = apcCourses[i]->isValidCourse ();
	}

	if (!cInputFile.eof () && numCourses >= MAX_SIZE) {
		cout << "The File Contained too many Courses" << endl;
	}
	else if (!(bIsValidCourse)) {
		cout << "The File Contained Invalid Courses" << endl;
	}
	else {
		do {
			do {
				printMenu ();
				cout << "Option: ";
				cin >> userSelection;
				cout << endl;
			} while (!(userSelection == OPTION_ONE ||
								 userSelection == OPTION_TWO ||
						 		 userSelection == OPTION_THREE || 
								 userSelection == OPTION_FOUR));

			if (OPTION_ONE == userSelection) {
				for (int i = 0; i < numCourses; i++) {
					cout << *apcCourses[i];
				}
				cout << endl;
			}
			else if (OPTION_TWO == userSelection) {
				do {
					cout << "Prefix: ";
					cin >> userPrefix;
				} while (!(userPrefix == MATH_PREFIX ||
					userPrefix == COMPUTER_SICENCE_PREFIX));
				cout << "Number: ";
				cin >> userNumber;
				cout << endl;

				for (int i = 0; i < numCourses && bFoundCourse == false; i++) {
					if (apcCourses[i]->isMatch (userPrefix, userNumber)) {
						bFoundCourse = true;
						cout << *apcCourses[i] << endl;
					}
				}
				if (!(bFoundCourse)) {
					cout << "The course does not exist.\n\n";
				}
				bFoundCourse = false;
			}

			else if (OPTION_THREE == userSelection) {
				do {
					cout << "Prefix: ";
					cin >> userPrefix;
				} while (!(userPrefix == MATH_PREFIX ||
					userPrefix == COMPUTER_SICENCE_PREFIX));
				cout << "Number: ";
				cin >> userNumber;
				cout << endl;

				for (int i = 0; i < numCourses && bFoundCourse == false; i++) {
					if (apcCourses[i]->isMatch (userPrefix, userNumber)) {
						bFoundCourse = true;
						cout << *apcCourses[i];
						if (!(apcCourses[i]->isFull ())) {
							++* apcCourses[i];
							cout << endl << "Student was added to the course.\n\n";
						}
						else {
							cout << endl << "The course is already full.\n\n";
						}
					}
				}
				if (!(bFoundCourse)) {
					cout << "The course does not exist.\n\n";
				}
				bFoundCourse = false;
			}
		} while (OPTION_FOUR != userSelection);
	}

	for (int i = 0; i < numCourses; i++) {
		delete apcCourses[i];
	}

	cInputFile.close ();

	return EXIT_SUCCESS;
}

/****************************************************************************
Function:			printMenu

Description:	Displays a menu to the screen

Parameters:		None

Returned:			None
****************************************************************************/

void printMenu () {
	cout << "----------------------------" << endl 
			 << "1. Print all courses" << endl << "2. Print one course" << endl
			 << "3. Add a student to a course" << endl << "4. Quit" << endl
			 << "----------------------------" << endl << endl;
}

//***************************************************************************
// Function:     drawHeading
//
// Description:  Displays a title encompassed by a border character
//
// Parameters:	 title		  - Title of the program
//							 borderChar - Character to encompass the title
//	
// Returned:		 None
//***************************************************************************

void drawHeading(string title, char borderChar) {
	for (int i = 0; i < title.length(); i++) {
		cout << borderChar;
	}

	cout << endl << title << endl;

	for (int i = 0; i < title.length(); i++) {
		cout << borderChar;
	}
	cout << endl << endl;
}
