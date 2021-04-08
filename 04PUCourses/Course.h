//***************************************************************************
// File name:		Course.h
// Author:			Cayden Wagner
// Date:				April 6 2021
// Class:				CS 250
// Assignment:	04PUCourse
// Purpose:			Declares a programmer-defined class for Course
//***************************************************************************

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Course {
	public:
		const string COMPUTER_SICENCE_PREFIX = "CS";
		const string MATH_PREFIX = "MATH";
		
		Course ();

		bool isFull () const;
		bool isMatch (string, string) const;
		bool isValidCourse () const;

		Course& operator++ ();

		friend istream& operator>> (istream&, Course&);
		friend ostream& operator<< (ostream&, Course&);

	private:
		string mPrefix;
		string mCourseNum;
		int mCapacity;
		int mCurrentEnrollment;
};
