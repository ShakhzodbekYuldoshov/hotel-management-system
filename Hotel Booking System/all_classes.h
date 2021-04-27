#include<iostream>
#include <sstream>
using namespace std;


class Bed
{
private:
	string type_str;
	int type_int;
	int additional_bed;
public:
	Bed()
	{
		type_str = "None";
		type_int = 0;
		additional_bed = 0;
	}

	void set_type(int type)
	{
		if (type == 1)
			type_str = "Single";
		else if (type == 2)
			type_str = "Double";

		this->type_int = type;
	}

	void set_additional_bed(int additional_bed)
	{
		this->additional_bed = additional_bed;
	}

	string get_bed_type_str()
	{
		return type_str;
	}

	int get_bed_type_int()
	{
		return type_int;
	}

	int get_additional_bed()
	{
		return additional_bed;
	}
};


class Room :private Bed
{
private:
	string type_str;
	int type_int;
	Bed bed;
public:
	Room()
	{
		type_str = "None";
		type_int = 0;
	}

	void set_room_type(int room_type)
	{
		switch (room_type)
		{
		case 1:
			type_str = "Single";
			break;
		case 2:
			type_str = "Double";
			break;
		case 3:
			type_str = "Triple";
			break;
		case 4:
			type_str = "Queen";
			break;
		case 5:
			type_str = "King";
			break;
		case 6:
			type_str = "Double double";
			break;
		case 7:
			type_str = "Apartment";
			break;
		default:
			break;
		}

		this->type_int = room_type;
	}

	void set_bed_type(int bed_type)
	{
		bed.set_type(bed_type);
	}

	void set_additional_bed(int additional_bed)
	{
		bed.set_additional_bed(additional_bed);
	}

	string get_room_type_str()
	{
		return type_str;
	}

	int get_room_type_int()
	{
		return type_int;
	}

	string get_bed_type_str()
	{
		return bed.get_bed_type_str();
	}

	int get_bed_type_int()
	{
		return bed.get_bed_type_int();
	}

	int get_additional_bed()
	{
		return bed.get_additional_bed();
	}
};


class Person 
{
private:
	string first_name, last_name, username, password;
	long int phone_number;
public:
	Person()
	{
		first_name = "Unknown";
		last_name = "Unknown";
		username = "Unknown";
		password = "Unknown";
		phone_number = 0;
	}

	void set_first_name(string first_name)
	{
		this->first_name = first_name;
	}

	void set_last_name(string last_name)
	{
		this->last_name = last_name;
	}

	void set_phone_number(long int phone_number)
	{
		this->phone_number = phone_number;
	}

	void set_username(string username)
	{
		this->username = username;
	}

	void set_password(string password)
	{
		this->password = password;
	}

	string get_first_name()
	{
		return first_name;
	}

	string get_last_name()
	{
		return last_name;
	}

	long int get_phone_number()
	{
		return phone_number;
	}

	string get_username()
	{
		return username;
	}

	string get_password()
	{
		return password;
	}
};


class Client :private Person, private Room
{
private:
	Person person;
	Room room;
	string check_in_date, check_out_date;
	string day_check_out, month_check_out, year_check_out;
	string day_check_in, month_check_in, year_check_in;
	int check_in_days, check_out_days;
	int living_days;
	float due_price;
public:
	Client()
	{
		day_check_in = "0";
		month_check_in = "0";
		year_check_in = "0";
		check_in_date = "0";
		check_in_days = 0;

		day_check_out = "0";
		month_check_out = "0";
		year_check_out = "0";
		check_in_date = "0";
		check_out_days = 0;

		living_days = 0;
		due_price = 0.0;
	}

	void set_check_in_date(int day_check_in, int month_check_in, int year_check_in)
	{
		stringstream ss;
		stringstream mm;
		stringstream yy;

		ss << day_check_in;
		ss >> this->day_check_in;

		mm << month_check_in;
		mm >> this->month_check_in;

		yy << year_check_in;
		yy >> this->year_check_in;

		check_in_days = dateToDay(day_check_in, month_check_in, year_check_in);

		if (check_out_days != 0)
			living_days = check_out_days - check_in_days;

		check_in_date = this->day_check_in + "/" + this->month_check_in + "/" + this->year_check_in; // 10/02/2021
	}

	void set_check_out_date(int day_check_out, int month_check_out, int year_check_out)
	{
		stringstream ss;
		stringstream mm;
		stringstream yy;

		ss << day_check_out;
		ss >> this->day_check_out;

		mm << month_check_out;
		mm >> this->month_check_out;

		yy << year_check_out;
		yy >> this->year_check_out;

		check_out_days = dateToDay(day_check_out, month_check_out, year_check_out);

		if (check_in_days != 0)
			living_days = check_out_days - check_in_days;

		check_out_date = this->day_check_out + "/" + this->month_check_out + "/" + this->year_check_out;
	}

	void set_first_name(string first_name)
	{
		person.set_first_name(first_name);
	}

	void set_last_name(string last_name)
	{
		person.set_last_name(last_name);
	}

	void set_username(string username)
	{
		person.set_username(username);
	}

	void set_password(string password)
	{
		person.set_password(password);
	}

	void set_phone_number(long int phone_number)
	{
		person.set_phone_number(phone_number);
	}

	void set_room_type(int room_type)
	{
		room.set_room_type(room_type);
	}

	void set_bed_type(int bed_type)
	{
		room.set_bed_type(bed_type);
	}

	void set_additional_bed(int additional_bed)
	{
		room.set_additional_bed(additional_bed);
	}

	void set_due_price()
	{
		float due_price = 0;

		// Accoring to room type calculate due money
		switch (room.get_room_type_int())
		{
		case 1:
			due_price += living_days * 84;
			break;
		case 2:
			due_price += living_days * 107;
			break;
		case 3:
			due_price += living_days * 141;
			break;
		case 4:
			due_price += living_days * 120;
			break;
		case 5:
			due_price += living_days * 120;
			break;
		case 6:
			due_price += living_days * 180;
			break;
		case 7:
			due_price += living_days * 300;
			break;
		default:
			cout << "Entered wrong number of the type of room!" << endl;
			break;
		}

		// Adding additional beds price to due_price
		if (room.get_bed_type_int() == 1)
			due_price += room.get_additional_bed() * 34;
		else if (room.get_bed_type_int() == 2)
			due_price += room.get_additional_bed() * 51;
		this->due_price = due_price;
	}

	string get_first_name()
	{
		return person.get_first_name();
	}

	string get_last_name()
	{
		return person.get_last_name();
	}

	string get_username()
	{
		return person.get_username();
	}

	string get_password()
	{
		return person.get_password();
	}

	long int get_phone_number()
	{
		return person.get_phone_number();
	}

	string get_room_type()
	{
		return room.get_room_type_str();
	}

	string get_bed_type()
	{
		return room.get_bed_type_str();
	}

	int get_additional_bed()
	{
		return room.get_additional_bed();
	}

	string get_check_in_date()
	{
		return check_in_date;
	}

	string get_check_out_date()
	{
		return check_out_date;
	}

	int get_living_days()
	{
		return living_days;
	}

	float get_due_price()
	{
		return due_price;
	}

};






// Converter date to days
int dateToDay(int day, int month, int year) {
	int days_in_month = 0, days_until_month = 0, leap_year = 0;//leap year variable is for checking leap year while adding days for february

	// find leap year
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				// Leap year
				leap_year = 1;
		}
		else
			// Leap year
			leap_year = 1;
	}


	// calculating all days until entered month
	// in 1 month add 0 days for days_until_month
	// in 3,5,6,8,10,12 months make 31 value and add it days_until month variable
	// in 2 add 28 or 29 according to leap year for days_until_month
	// in 4,7, 9, 11 months add 30 for days_until_month
	for (int i = 1; i <= month; i++) {
		if (i == 1)
			days_in_month = 0;
		else if (i <= 5 && i % 2 == 1)
			days_in_month = 30;
		else if (i == 3)
		{
			if (leap_year == 1)
				days_in_month = 29;
			else
				days_in_month = 28;
		}
		else if (i >= 6 && i % 2 == 0)
			days_in_month = 30;
		else
			days_in_month = 31;

		days_until_month += days_in_month;
	}
	// negative one is for subtracting last day
	day += days_until_month;
	return day;
}

