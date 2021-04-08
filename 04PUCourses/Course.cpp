//***************************************************************************
// File name:		Course.cpp
// Author:			Cayden Wagner
// Date:				April 6 2021
// Class:				CS 250
// Purpose:			Implements constructors & functions of class Courses
// **************************************************************************

#include "Course.h"
#include <iostream>
#include <string>

using namespace std;

/****************************************************************************
Constructor:		Course

Description:		Initializes the data members to default values

Parameters:			None

Returned:				None
****************************************************************************/

Course::Course () {
	mPrefix = "NULL";
	mCourseNum = "NULL";
	mCapacity = 0;
	mCurrentEnrollment = 0;
}

/****************************************************************************
Function:			isFull

Description:	Determines if the course has any remaining availability

Parameters:		None

Returned:			True if the class is full and false if the class has
							availability
****************************************************************************/

bool Course::isFull () const {
	return (mCurrentEnrollment >= mCapacity);
}

/****************************************************************************
Function:				isMatch

Description:		Accepts a class prefix and class index and determines if it
								matches with the class that the function was called on

Parameters:			prefix   - A string that corresponds to a course prefix
								classNum - An integer that corresponds to the course index

Returned:				True if the prefix and index passed in match with the course
								that the function was called on
****************************************************************************/

bool Course::isMatch (string prefix, string classNum) const {
	bool bIsMatch = false;
	if (prefix == mPrefix && classNum == mCourseNum) {
		bIsMatch = true;
	}
	return bIsMatch;
}

/****************************************************************************
Function:				isValidCourse

Description:		Determines if a course is valid by testing for certain 
								criteria
									
Parameters:			None
	
Returned:				True if the course is valid; False if the course is invalid. 
								An invalid course has a prefix that is not MATH or CS or has 
								an enrollment that is over the capacity
****************************************************************************/

bool Course::isValidCourse () const {
	bool bIsValid = true;

	if (!(mPrefix == COMPUTER_SICENCE_PREFIX || mPrefix == MATH_PREFIX)) {
		bIsValid = false;
	}
	if (mCurrentEnrollment > mCapacity) {
		bIsValid = false;
	}
	return bIsValid;
}

/****************************************************************************
Operator:				++

Description:		Increments the current enrollment if the course is not full

Parameters:			None

Returned:				The course that the operator was called on
****************************************************************************/

Course& Course::operator++ () {
	if (mCurrentEnrollment < mCapacity) {
		mCurrentEnrollment++;
	}
	return *this;
}

/****************************************************************************
Operator:				>>

Description:		Reads in a course from a stream

Parameters:			rcIn	 - istream object that determines which stream the 
												 course is read in from
								course - The course that is modified by the data read in

Returned:				The stream operator that was included in the operator call
****************************************************************************/

istream& operator>> (istream& rcIn, Course& course) {
	rcIn >> course.mPrefix >> course.mCourseNum >> course.mCapacity
			 >> course.mCurrentEnrollment;

	return rcIn;
}

/****************************************************************************
Operator:				>>

Description:		Prints the course to a stream

Parameters:			rcOut	 - ostream object that determines to which stream the
												 course is outputted
								course - The course that is printed to the stream

Returned:				The stream operator that was included in the operator call
****************************************************************************/

ostream& operator<< (ostream& rcOut, Course& course) {
	rcOut << course.mPrefix << " " << course.mCourseNum << " Cap: " 
				<< course.mCapacity << " Available: " 
				<< course.mCapacity - course.mCurrentEnrollment << endl;

	return rcOut;
}