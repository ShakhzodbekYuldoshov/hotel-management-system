#include<iostream>
#include <sstream>
using namespace std;


class Bed
{
private:
	string type;
	int additional_bed;
public:
	Bed()
	{
		type = "None";
		additional_bed = 0;
	}

	void set_type(string type)
	{
		this->type = type;
	}

	void set_additional_bed(int additional_bed)
	{
		this->additional_bed = additional_bed;
	}

	string get_bed_type()
	{
		return type;
	}

	int get_additional_bed()
	{
		return additional_bed;
	}
};


class Room :public Bed
{
private:
	string type;
	Bed bed;
public:
	Room()
	{
		type = "None";
	}

	void set_room_type(string room_type)
	{
		this->type = room_type;
	}

	void set_bed_type(string bed_type)
	{
		bed.set_type(bed_type);
	}

	void set_additional_bed(int additional_bed)
	{
		bed.set_additional_bed(additional_bed);
	}

	string get_room_type()
	{
		return type;
	}

	string get_bed_type()
	{
		return bed.get_bed_type();
	}

	int get_additional_bed()
	{
		return bed.get_additional_bed();
	}
};


class Person 
{
private:
	string first_name, last_name;
	long int phone_number;
public:
	Person()
	{
		first_name = "Unknown";
		last_name = "Unknown";
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
};


class Client :public Person, public Room
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

		ss << day_check_in;
		ss >> this->day_check_in;

		ss << month_check_in;
		ss >> this->month_check_in;

		ss << year_check_in;
		ss >> this->year_check_in;

		check_in_days = dateToDay(day_check_in, month_check_in, year_check_in);

		if (check_out_days != 0)
			living_days = check_out_days - check_in_days;

		check_in_date = this->day_check_in + "/" + this->month_check_in + "/" + this->year_check_in; // 10/02/2021
	}

	void set_check_out_date(int day_check_out, int month_check_out, int year_check_out)
	{
		stringstream ss;

		ss << day_check_out;
		ss >> this->day_check_out;

		ss << month_check_in;
		ss >> this->month_check_out;

		ss << year_check_out;
		ss >> this->year_check_out;

		check_out_days = dateToDay(day_check_out, month_check_out, year_check_out);

		if (check_in_days != 0)
			living_days = check_out_days - check_in_days;

		check_out_date = this->day_check_out + "/" + this->month_check_out + "/" + this->year_check_out;
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

