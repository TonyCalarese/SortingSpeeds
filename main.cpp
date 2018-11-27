#include "inclusions.h"


int main()
{
	
		while (true) {
			get_C_Menu();
			int input;
			cout << "Would you like to sort again? Any answer other than '0' will reloop through" << endl;
			cin >> input;
			if (input == 0) {
				break;
			}
			system("cls");
			cout << "********** Reworking ********** " << endl;
		};
	

	return 0;
}