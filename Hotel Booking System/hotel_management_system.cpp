#include<iostream>
#include<Windows.h>
#include "allFunctions.h"
using namespace std;
int main()
{
	string first_name, last_name, room_type_str, bed_type_str;
	long int phone_num;
	int day_check_in, month_check_in, year_check_in;
	int day_check_out, month_check_out, year_check_out;
	int living_days = -1, room_type;	
	int additional_beds = 0,  want_bed, bed_type=0;
	int due_price, want_continue = 1;

	system("Color 0A");

	// Print name of Hotel HEADER
	cout << "\t\t\t**********************************" << endl;
	cout << "\t\t\tWelcome to booking system of hotel" << endl;
	cout << "\t\t\t**********************************" << endl;

	// days when stays at hotel is less than or equal to 0 
	// initially it is equal to one 
	// if all the values added properly then its value will change to positive value and stop this loop
	while (living_days <= 0)
	{
		// Get Check In Date
		// While loop is for repeat if values entered by the user for day month or year is wrong 
		while (true)
		{
			cout << "\nYou may book any day after the year of 2021" << endl;
			cout << "For what date do you want to book your room?" << endl;
			cout << "day:  " << endl;
			while (!(cin >> day_check_in))
			{
				cout << "ERROR: enter only number: " << endl;
				cin.clear();
				cin.ignore();
			}
			cout << "month:  " << endl;
			while (!(cin >> month_check_in))
			{
				cout << "ERROR: enter only number: " << endl;
				cin.clear();
				cin.ignore();
			}
			cout << "year:  " << endl;
			while (!(cin >> year_check_in))
			{
				cout << "ERROR: enter only number: " << endl;
				cin.clear();
				cin.ignore();
			}

			// If entered values are proper, then clear the terminal and break the loop else print error message
			if (day_check_in <= 31 && day_check_in > 0 && month_check_in <= 12 && month_check_in > 0 && year_check_in >= 2021)
				break;
			else 
			{
				system("CLS");
				printErrorMessage();
			}
		}


		// Get Check Out Date
		// While loop is for repeat if values entered by the user for day month or year is wrong 
		while (true)
		{
			cout << "\nYou may live for any number of days after " << day_check_in << "/" << month_check_in << "/" << year_check_in << endl;
			cout << "Until what date do you want to book your room?" << endl;
			cout << "day:  " << endl;
			while (!(cin >> day_check_out))
			{
				cout << "ERROR: enter only number: " << endl;
				cin.clear();
				cin.ignore();
			}
			cout << "month:  " << endl;
			while (!(cin >> month_check_out))
			{
				cout << "ERROR: enter only number: " << endl;
				cin.clear();
				cin.ignore();
			}
			cout << "year:  " << endl;
			while (!(cin >> year_check_out))
			{
				cout << "ERROR: enter only number: " << endl;
				cin.clear();
				cin.ignore();
			}
			system("CLS");

			// If entered values are proper, then clear the terminal and break the loop else print error message
			if (day_check_out <= 31 && day_check_out > 0 && month_check_out <= 12 && month_check_out > 0 && year_check_out >= 2021)
				break;
			else
			{
				system("CLS");
				printErrorMessage;
			}
		}

		system("CLS");
	
		// Calculate days stays at hotel
		living_days = dateToDay(day_check_out, month_check_out, year_check_out) - dateToDay(day_check_in, month_check_in, year_check_in);
		if (living_days <= 0)
			printErrorMessage;
	}
	

	while (true)
	{
		// Prints all information about rooms
		roomTypesPrint();
		while (true)
		{
			cout << "Please choose a room type by its number:" << endl;
			while (!(cin >> room_type))
			{
				cout << "ERROR: enter only number: " << endl;
				cin.clear();
				cin.ignore();
			}
			system("CLS");
			if (room_type == 1 || room_type == 2 || room_type == 3 || room_type == 4 || room_type == 5 || room_type == 6 || room_type == 7)
				break;
			else
			{
				printErrorMessage;
			}
		}

		cout << "Price per additional bed:" << endl;
		cout << "\t\tSingle beds: $34" << endl;
		cout << "\t\tDouble beds: $51" << endl;
		cout << "Do you want any additional beds?" << endl;
		cout << "Enter '1' if you want additional beds" << endl;
		cout << "Enter 'any number' if you do not want additional beds" << endl;
		while (!(cin >> want_bed))
		{
			cout << "ERROR: enter only number: " << endl;
			cin.clear();
			cin.ignore();
		}
		system("CLS");

		// if bed is necessary then gather all information about bed type number of beds ...
		if (want_bed == 1) {
			while (true)
			{
				cout << "What type of additional bed do you want?" << endl;
				cout << "Enter 1 for single bed" << endl;
				cout << "Enter 2 for double bed" << endl;
				while (!(cin >> bed_type))
				{
					cout << "ERROR: enter only number: " << endl;
					cin.clear();
					cin.ignore();
				}
				system("CLS");

				if (bed_type == 1 || bed_type == 2)
					break;
				else
					printErrorMessage;
			}

			if (bed_type == 1) {
				cout << "How many single beds do you want?	" << endl;
				while (!(cin >> additional_beds))
				{
					cout << "ERROR: enter only number: " << endl;
					cin.clear();
					cin.ignore();
				}
				bed_type_str = "Single";
				system("CLS");
			}
			else if (bed_type == 2) {
				cout << "How many double beds do you want?  " << endl;
				while (!(cin >> additional_beds))
				{
					cout << "ERROR: enter only number: " << endl;
					cin.clear();
					cin.ignore();
				}
				bed_type_str = "Double";
				system("CLS");
			}
			else
			{
				system("CLS");
				printErrorMessage;
			}
		}	

		// Calculate due price
		due_price = duePriceCalculator(living_days, room_type, additional_beds, bed_type);
		

		//ask for want continue
		while (true)
		{
			cout << "\t\tYOU SHOULD PAY $" << due_price << "!" << endl;
			cout << "\n\t\tDo you want continue? 1/2" << endl;
			cout << "If you want to continue enter ' 1 '" << endl;
			cout << "If you do not want to continue enter ' 2 '. If you want choose room type again" << endl;
			cout << "If you want exit the program enter ' 0 '." << endl;
			while (!(cin >> want_continue))
			{
				cout << "ERROR: enter only number: " << endl;
				cin.clear();
				cin.ignore();
			}
			system("CLS");

			if (want_continue == 1 || want_continue == 2 || want_continue == 0)
				break;
			else
				printErrorMessage;
		}
		if (want_continue == 1)
			break;
		else if (want_continue == 0)
			exit(1);

	}
	
	

	//Get user full name and phone number
	cout << "\nPlease enter your first name:  " << endl;
	while (!(cin >> first_name))
	{
		cout << "ERROR: enter only number: " << endl;
		cin.clear();
		cin.ignore();
	}
	cout << "Please enter your last name:  " << endl;
	while (!(cin >> last_name))
	{
		cout << "ERROR: enter only number: " << endl;
		cin.clear();
		cin.ignore();
	}
	//Phone number
	cout << "Enter valid phone number without + sign: " << endl;
	while (!(cin >> phone_num))
	{
		cout << "ERROR: enter only number: " << endl;
		cin.clear();
		cin.ignore();
	}
	system("CLS");

	// print all the information about customer
	cout << "Full Name             " << first_name << " " << last_name << endl;
	cout << "\nPhone Number        " << phone_num << endl;
	switch (room_type)
	{
	case 1:
		room_type_str = "Single";
		break;
	case 2:
		room_type_str = "Double";
		break;
	case 3:
		room_type_str = "Triple";
		break;
	case 4:
		room_type_str = "Queen";
		break;
	case 5:
		room_type_str = "King";
		break;
	case 6:
		room_type_str = "Double double";
		break;
	case 7:
		room_type_str = "Apartment";
		break;
	default:
		break;
	}
	cout << "\nRoom Type           " << room_type_str << endl;
	cout << "\nAdditional beds     " << additional_beds << endl;
	if (bed_type == 1)
		cout << "\nAdditional bed type " << bed_type_str << endl;
	else if (bed_type == 2)
		cout << "\nAdditional bed type " << bed_type_str << endl;
	cout << "\nDue Price            $" << due_price << endl;


	system("pause");
	return 0;
}

