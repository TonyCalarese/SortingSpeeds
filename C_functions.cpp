#include "inclusions.h"


void get_C_Menu()
{
	string input;
	bool flow = false;
	int size = 10, *Data = new int[size], j = 0;

	//Implement Array
	cout << "********** Implementing Array **********" << endl;
	//For data analysis purposes the random array should randomize the same everytime to get the same results
	for (int i = size; i > 0; i--)
	{
		Data[j] = i;
		j++;
	}

	//Loop through to see if the user wants to print
	do {
		cout << "********** Would you like to see the Array unsorted? (Y|N)" << endl;
		cin >> input;

		if (input != "N" && input != "n") {
			cout << "I'm sorry I am a computer and I only understand what I am told, so here is the array" << endl;
			printArray(size, Data);
			flow = true;
		}
		else {
			cout << "Not printing" << endl;
			flow = true;
		}

	} while (flow == false);

	//Lets see how they want to sort
	string sortingMethod = getMethod();
	cout << "You have chosen " << sortingMethod << endl;
	executeSort(sortingMethod, size, Data);

	delete Data;
}

string getMethod()
{
	int i;
	while (true) {
		cout << "How do you want to sort the array?" << endl
			<< "1) QuickSort- C++" << endl
			<< "2) SelectionSort- C++" << endl
			<< "3) InsertionSort- C++" << endl
			<< "4) QuickSort-Assembly" << endl
			<< "5) SelectionSort-Assembly" << endl
			<< "6) InsertionSort-Assembly" << endl;
		cin >> i;
		switch (i) {
		case 1:
			return "quickC";
			break;
		case 2:
			return "selectC";
			break;
		case 3:
			return "insertC";
			break;
		case 4:
			return "quickAsm";
			break;
		case 5:
			return "selectAsm";
			break;
		case 6:
			return "insertAsm";
			break;
		default:
			continue;
		}


	};
}



