#include<iostream>
#include<Windows.h>
#include "allFunctions.h"
#include "all_classes.h"
using namespace std;
int main()
{
	Client client;
	string first_name, last_name, room_type_str, bed_type_str, username, password;
	long int phone_number;
	int day_check_in, month_check_in, year_check_in;
	int day_check_out, month_check_out, year_check_out;
	int living_days = -1, room_type;
	int additional_beds = 0, want_bed, bed_type = 0;
	int due_price, want_continue = 1, program_num;

	system("Color 0A");

	while (true)
	{

		// Print name of Hotel HEADER
		cout << "\t\t\t**********************************" << endl;
		cout << "\t\t\tWelcome to booking system of hotel" << endl;
		cout << "\t\t\t**********************************" << endl;


		while (true)
		{
			cout << "Please enter order number of program:" << endl;
			cout << "1.Register" << endl;
			cout << "2.Log in" << endl;
			cout << "3.Exit" << endl;
			while (!(cin >> program_num))
			{
				cout << "ERROR: enter only number: " << endl;
				cin.clear();
				cin.ignore();
			}
			system("CLS");

			switch (program_num)
			{
				// Register page
			case 1:
				cout << "***************************" << endl;
				cout << "     REGISTRATION" << endl;
				cout << "***************************" << endl;
				cout << endl;
				cout << endl;

				cout << "First name:" << endl;
				while (!(cin >> first_name))
				{
					cout << "ERROR: enter only your name not a number: " << endl;
					cin.clear();
					cin.ignore();
				}
				client.set_first_name(first_name);

				cout << "Last name:" << endl;
				while (!(cin >> last_name))
				{
					cout << "ERROR: enter only your name not a number: " << endl;
					cin.clear();
					cin.ignore();
				}
				client.set_last_name(last_name);

				cout << "Phone number:" << endl;
				while (!(cin >> phone_number))
				{
					cout << "ERROR: enter only a number: " << endl;
					cin.clear();
					cin.ignore();
				}
				client.set_phone_number(phone_number);


				cout << "Username:" << endl;
				while (!(cin >> username))
				{
					cout << "ERROR: enter only your username not a number: " << endl;
					cin.clear();
					cin.ignore();
				}
				client.set_username(username);


				cout << "Password:" << endl;
				while (!(cin >> password))
				{
					cout << "ERROR: enter only your password not a number: " << endl;
					cin.clear();
					cin.ignore();
				}
				client.set_password(password);

				system("CLS");

				cout << "***************************" << endl;
				cout << "     REGISTRATION" << endl;
				cout << "***************************" << endl;
				cout << endl;
				cout << endl;

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

							cout << "***************************" << endl;
							cout << "     REGISTRATION" << endl;
							cout << "***************************" << endl;
							cout << endl;
							cout << endl;

							printErrorMessage();
						}

					}
					client.set_check_in_date(day_check_in, month_check_in, year_check_in);

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

						cout << "***************************" << endl;
						cout << "     REGISTRATION" << endl;
						cout << "***************************" << endl;
						cout << endl;
						cout << endl;

						// If entered values are proper, then clear the terminal and break the loop else print error message
						if (day_check_out <= 31 && day_check_out > 0 && month_check_out <= 12 && month_check_out > 0 && year_check_out >= 2021)
							break;
						else
						{
							system("CLS");

							cout << "***************************" << endl;
							cout << "     REGISTRATION" << endl;
							cout << "***************************" << endl;
							cout << endl;
							cout << endl;

							printErrorMessage();
						}
					}
					client.set_check_out_date(day_check_out, month_check_out, year_check_out);

					system("CLS");

					cout << "***************************" << endl;
					cout << "     REGISTRATION" << endl;
					cout << "***************************" << endl;
					cout << endl;
					cout << endl;

					// Calculate days stays at hotel
					living_days = dateToDay(day_check_out, month_check_out, year_check_out) - dateToDay(day_check_in, month_check_in, year_check_in);
					if (living_days <= 0)
						printErrorMessage();
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

						cout << "***************************" << endl;
						cout << "     REGISTRATION" << endl;
						cout << "***************************" << endl;
						cout << endl;
						cout << endl;

						if (room_type == 1 || room_type == 2 || room_type == 3 || room_type == 4 || room_type == 5 || room_type == 6 || room_type == 7)
							break;
						else
						{
							printErrorMessage();
						}
					}
					client.set_room_type(room_type);

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


					cout << "***************************" << endl;
					cout << "     REGISTRATION" << endl;
					cout << "***************************" << endl;
					cout << endl;
					cout << endl;


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

							cout << "***************************" << endl;
							cout << "     REGISTRATION" << endl;
							cout << "***************************" << endl;
							cout << endl;
							cout << endl;

							if (bed_type == 1 || bed_type == 2)
								break;
							else
								printErrorMessage();
						}
						client.set_bed_type(bed_type);

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

							cout << "***************************" << endl;
							cout << "     REGISTRATION" << endl;
							cout << "***************************" << endl;
							cout << endl;
							cout << endl;
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

							cout << "***************************" << endl;
							cout << "     REGISTRATION" << endl;
							cout << "***************************" << endl;
							cout << endl;
							cout << endl;
						}
						else
						{
							system("CLS");
							cout << "***************************" << endl;
							cout << "     REGISTRATION" << endl;
							cout << "***************************" << endl;
							cout << endl;
							cout << endl;
							printErrorMessage();
						}
						client.set_additional_bed(additional_beds);
					}
					break;
				}

				// Calculate due price
				client.set_due_price();

				// ask for want continue
				while (true)
				{
					cout << "\t\tYOU SHOULD PAY $" << client.get_due_price() << "!" << endl;
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

					cout << "***************************" << endl;
					cout << "     REGISTRATION" << endl;
					cout << "***************************" << endl;
					cout << endl;
					cout << endl;

					if (want_continue == 1 || want_continue == 2 || want_continue == 0) {
						system("CLS");
						break;
					}
					else
						printErrorMessage();
				}

				break;

				//Lout page
			case 2:

				break;

			case 3:
				exit(1);

			default:
				break;
			}
			cout << "Additional bed:  " << client.get_additional_bed() << endl;
			cout << "Bed Type:  " << client.get_bed_type() << endl;
			cout << "Check in date:  " << client.get_check_in_date() << endl;
			cout << "Check out date:  " << client.get_check_out_date() << endl;
			cout << "Due price:  " << client.get_due_price() << endl;
			cout << "First name:  " << client.get_first_name() << endl;
			cout << "Last name:  " << client.get_last_name() << endl;
			cout << "Living days:  " << client.get_living_days() << endl;
			cout << "Password" << client.get_password() << endl;
			cout << "Phone number" << client.get_phone_number() << endl;
			cout << "Room type:  " << client.get_room_type() << endl;
			cout << "Username:  " << client.get_username() << endl;
		}
		

	}



	system("pause");
	return 0;
}

