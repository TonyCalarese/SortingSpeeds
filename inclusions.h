/*
Author: Anthony Calarese, Tony Calarese
Class of Referenced code : CSI - 281 - 01
Assignment : PA3 Part 1
Date Assigned : September 14, 2017
Due Date : September 21, 2017 by 9 : 30am
Description :
This lab is designed for us to learn and execute different types of sorting algorithms for an array
Certification of Authenticity :
I certify that this is entirely my own work, except where I have given fullydocumented
references to the work of others.I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of
academic staff; and / or
-Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking)
Note: Most of this work is referenced from professor Wei's answer he provided to us students
*/
#ifndef _INCLUSIONS_H
#define _INCLUSIONS_H

//namespace
//------------------------------------------------
using namespace std;
//------------------------------------------------
//Includes
//------------------------------------------------
#include <iostream>
#include <array>
#include <random>
#include <stdlib.h>  
#include <time.h>
#include <string>

//Headers
#include "timerSystem.h"

//Purely C++ Functions
//------------------------------------------------
void get_C_Menu();
string getMethod();

template <typename T>
void printArray(T size, T *Data) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << Data[i] << " ";
			i++;
		}
		cout << endl;
	}


	delete Data;
}
template <typename T>
void executeSort(string method, int size, T *Data) {
	/*
	The only things that method can be is
	quickC, selectC, insertC
	thus far

	*/
	/*
	//Implement Timer
	TimerSystem timer;

	timer.startClock();
	//timing and the sorting


	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(8);
	*/
}

//Assembly Based Functions
//------------------------------------------------





//Selection Sorting
/*
Pre:numbers and size
Post: print(size, numbers)
purpose: Selection sort uses a selectioning method when it divides, by finding the minimum number and then rearranging by counting upwards
*/
template <typename T>
void selectionSort(T size, T numbers[]) {
	T minIndex, tmp;

	for (T i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (T j = i + 1; j < size; j++)
		{
			if (numbers[j] < numbers[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			tmp = numbers[i];
			numbers[i] = numbers[minIndex];
			numbers[minIndex] = tmp;
		}
	}
}

//Insertion Sorting
/*
pre:size, numbers
post:print(size, numbers)
purpose: This algorithm is designed to sort an array using the insertion method as if it was like trading cards in your hand, picking and then placing the cards in the right order.
This one was challening so I needed online help
Source of reference: http://www.geeksforgeeks.org/insertion-sort/
*/
template <typename T>
void insertionSort(T size, T numbers[])
{
	T point, switchingPoint, tmp; //<-- This variable will act like a point at which the sorting will take place
									//switchingPoint is the point at which the switch is made
	for (long i = 1; i < size; i++)
	{
		// + 1 so switching point is begining 
		point = numbers[i];
		//start at the begining
		switchingPoint = i - 1;

		// need to go through the array until it hits a number it cannot be greater than then work up the list
		while (switchingPoint >= 0 && numbers[switchingPoint] > point)
		{
			tmp = numbers[switchingPoint];
			numbers[switchingPoint + 1] = tmp;
			switchingPoint--;
		}
		numbers[switchingPoint + 1] = point;
	}

}

//Quick Sorting
/*
pre:numbers size, UB, LB
post: print(sie, numbers)
purpose: to use the quickly sort the algorithm by using the divide and conquer technique
*/
template <typename T>
void quickSort(long size, T numbers[], long LB, long UB)
{
	long tmp, i = LB, j = UB;
	T pivot = numbers[(LB + UB) / 2];

	while (i <= j)
	{
		while (numbers[i] < pivot)
		{
			i++;
		}
		while (numbers[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			tmp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = tmp;
			i++;
			j--;
		}
	}
	if (LB < j)
	{
		quickSort(size, numbers, LB, j);
	}

	if (i < UB)
	{
		quickSort(size, numbers, i, UB);
	}
}


#endif
