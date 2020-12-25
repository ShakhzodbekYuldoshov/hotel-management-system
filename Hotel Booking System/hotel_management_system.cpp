#include<iostream>
#include<Windows.h>
#include "allFunctions.h"
using namespace std;
int main()
{
	string first_name, last_name;
	int phone_num;
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
			cin >> day_check_in;
			cout << "month:  " << endl;
			cin >> month_check_in;
			cout << "year:  " << endl;
			cin >> year_check_in;

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
			cin >> day_check_out;
			cout << "month:  " << endl;
			cin >> month_check_out;
			cout << "year:  " << endl;
			cin >> year_check_out;

			day_check_out = int(day_check_out);
			month_check_out = int(month_check_out);
			year_check_out = int(year_check_out);
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
			cout << "Oops! Something went wrong. Please try again!" << endl;
	}
	

	while (true)
	{
		// Prints all information about rooms
		roomTypesPrint();
		while (true)
		{
			cout << "Please choose a room type by its number:" << endl;
			cin >> room_type;
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
		cin >> want_bed;
		system("CLS");

		if (want_bed == 1) {
			while (true)
			{
				cout << "What type of additional bed do you want?" << endl;
				cout << "Enter 1 for single bed" << endl;
				cout << "Enter 2 for double bed" << endl;
				cin >> bed_type;
				system("CLS");

				if (bed_type == 1 || bed_type == 2)
					break;
				else
					printErrorMessage;
			}

			if (bed_type == 1) {
				cout << "How many single beds do you want?	" << endl;
				cin >> additional_beds;
				system("CLS");
			}
			else if (bed_type == 2) {
				cout << "How many double beds do you want?  " << endl;
				cin >> additional_beds;
				system("CLS");
			}
			else
				system("CLS");
				printErrorMessage;
		}	

		due_price = duePriceCalculator(living_days, room_type, additional_beds, bed_type);
		
		while (true)
		{
			cout << "\t\tYOU SHOULD PAY " << due_price << "!" << endl;
			cout << "\n\t\tDo you want continue? 1/2" << endl;
			cout << "If you want to continue enter ' 1 '" << endl;
			cout << "If you do not want to continue enter ' 2 '" << endl;
			cin >> want_continue;
			system("CLS");

			if (want_continue == 1 || want_continue == 2)
				break;
			else
				printErrorMessage;
		}
	}
	
	

	//Get user full name and phone number
	cout << "\nPlease enter your first name:  " << endl;
	cin >> first_name;
	cout << "Please enter your last name:  " << endl;
	cin >> last_name;
	//checking validation of phone number
	while (true)
	{
		cout << "Enter valid phone number without + sign minimum 9 numbers maximum 12 numbers:  " << endl;
		cin >> phone_num;

		if (phone_num > 8 && phone_num < 13)
			break;
		else
		{
			system("CLS");
			printErrorMessage();
		}
	}


	system("pause");
	return 0;
}

