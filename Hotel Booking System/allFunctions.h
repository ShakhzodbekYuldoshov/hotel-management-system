#include<iostream>
using namespace std;
//Date to day converter
int dateToDay(int day, int month, int year);
// Print all room types
void roomTypesPrint();
// Calculate 
int duePriceCalculator(int difference_in_day, int room_type, int additional_beds, int additional_bed_type);
// Error message printer
void printErrorMessage() {
	cout << "\t\tOops! You entered wrong value. Please try again!\n" << endl;
}





// Print types of rooms with information
void roomTypesPrint()
{
	int have_read;

	//Information about room types and price list
	while (true)
	{
		cout << "There are 7 types of rooms and here is price list: " << endl;

		// Additional beds information
		cout << "\nYou may add additional beds for all the rooms" << endl;

		//Single room information
		cout << "\n1.Single" << endl;
		cout << "\tRoom size: 37m^2" << endl;
		cout << "\tNumber of beds: 1" << endl;
		cout << "\tPrice: $84" << endl;

		//Double room information
		cout << "\n2.Double" << endl;
		cout << "\tRoom size: 45m^2" << endl;
		cout << "\tNumber of beds: 1 double bed" << endl;
		cout << "\tPrice: $107" << endl;

		// Triple room information
		cout << "\n3.Triple" << endl;
		cout << "\tRoom size: 65m^2" << endl;
		cout << "\tNumber of beds: 3 single beds" << endl;
		cout << "\tPrice: $141" << endl;

		// Queen room information
		cout << "\n4.Queen" << endl;
		cout << "\tRoom size: 40m^2" << endl;
		cout << "\tNumber of beds: 1 queen sized bed" << endl;
		cout << "\tPrice: $120" << endl;

		// King room information
		cout << "\n5.King" << endl;
		cout << "\tRoom size: 40m^2" << endl;
		cout << "\tNumber of beds: 1 king sized bed" << endl;
		cout << "\tPrice: $120" << endl;

		// Double double room information
		cout << "\n6.Double Dobule" << endl;
		cout << "\tRoom size: 60m^2" << endl;
		cout << "\tNumber of beds: 2 double sized beds" << endl;
		cout << "\tPrice: $180" << endl;

		//Apartment room information
		cout << "\n7.Apartment(for long stay guests)" << endl;
		cout << "\tRoom size: 150m^2" << endl;
		cout << "\tNumber of beds: 1 double" << endl;
		cout << "\tAvailable:" << endl;
		cout << "\t\tOpen kitchen" << endl << "\t\tCooking equipments" << endl << "\t\tDryer" << endl << "\t\tWasher" << endl << "\t\tHouse Keeping(twice a week)" << endl;
		cout << "\tPrice: $300" << endl;

		cout << "If you would like to continue plese enter 1" << endl;
		cout << "If you want to quit program please enter 2" << endl;
		cin >> have_read;

		if (have_read == 1)
			break;
		else if (have_read == 2)
			exit(2);

		system("CLS");
	}
}



// Calculates money that should be paid
int duePriceCalculator(int difference_in_day, int room_type, int additional_beds = 0, int additional_bed_type = 0)
{
	int due_price = 0;

	// Accoring to room type calculate due money
	switch (room_type)
	{
	case 1:
		due_price += difference_in_day * 84;
		break;
	case 2:
		due_price += difference_in_day * 107;
		break;
	case 3:
		due_price += difference_in_day * 141;
		break;
	case 4:
		due_price += difference_in_day * 120;
		break;
	case 5:
		due_price += difference_in_day * 120;
		break;
	case 6:
		due_price += difference_in_day * 180;
		break;
	case 7:
		due_price += difference_in_day * 300;
		break;
	default:
		cout << "Entered wrong number of the type of room!" << endl;
		break;
	}

	// Adding additional beds price to due_price
	if (additional_bed_type == 1)
		due_price += additional_beds * 34;
	else if (additional_bed_type == 2)
		due_price += additional_beds * 51;


	return due_price;
}
