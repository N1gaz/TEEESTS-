#pragma once
#include <iostream>

using namespace std;

template <typename T>
void checkenter(T& enter)
{
	do
	{

		cin >> enter;
		if (cin.fail())
		{
			cout << "Некорректный ввод, повторите попытку." << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else
			break;

	} while (true);
}

class date
{
private:
	friend istream& operator >>(istream& is, date& right);
	template <typename T>
	friend void checkenter(T& a);

	int day;
	int month;
	int year;

public:
	date();
	date(int day, int month, int year);
	void set()
	{
		cout << "Введите год" << endl;
		checkenter(year);

		cout << "Введите месяц" << endl;
		checkenter(month);
		while (month < 1 || month>12)
		{
			cout << "Не существует такого месяца. Повторите попытку" << endl;
			checkenter(month);
		}

		cout << "Введите день" << endl;
		switch (month)
		{
		case 1:
			checkenter(day);
			while (day < 1 || day>31)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		case 2:
			checkenter(day);
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				while (day < 1 || day>29)
				{
					cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
					checkenter(day);
				}
			}
			else
			{
				while (day < 1 || day>28)
				{
					cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
					checkenter(day);
				}
			}
			break;
		case 3:
			checkenter(day);
			while (day < 1 || day>31)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		case 4:
			checkenter(day);
			while (day < 1 || day>30)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		case 5:
			checkenter(day);
			while (day < 1 || day>31)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		case 6:
			checkenter(day);
			while (day < 1 || day>30)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		case 7:
			checkenter(day);
			while (day < 1 || day>31)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		case 8:
			checkenter(day);
			while (day < 1 || day>31)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		case 9:
			checkenter(day);
			while (day < 1 || day>30)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		case 10:
			checkenter(day);
			while (day < 1 || day>31)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		case 11:
			checkenter(day);
			while (day < 1 || day>30)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		case 12:
			checkenter(day);
			while (day < 1 || day>31)
			{
				cout << "Нет такого дня в выбранном месяце. Повторите попытку" << endl;
				checkenter(day);
			}
			break;
		default:
			break;
		}
	}

	int get_year()
	{
		return this->year;
	}

	int get_month()
	{
		return this->month;
	}

	int get_day()
	{
		return this->day;
	}


	bool operator ==(date& d1)
	{
		return (this->year == d1.get_year() &&
			this->month == d1.get_month() &&
			this->day == d1.get_day());
	}

	bool operator !=(date d1)
	{
		return (this->year != d1.get_year() ||
			this->month != d1.get_month() ||
			this->day != d1.get_day());
	}

	bool operator >(date d1)
	{
		return (this->year > d1.get_year() ||
			(this->year == d1.get_year() && this->month > d1.get_month()) ||
			(this->year == d1.get_year() && this->month == d1.get_month() && this->day > d1.get_day()));
	}

	bool operator <(date d1)
	{
		return (this->year < d1.get_year() ||
			(this->year == d1.get_year() && this->month < d1.get_month()) ||
			(this->year == d1.get_year() && this->month == d1.get_month() && this->day < d1.get_day()));
	}

	bool operator >=(date d1)
	{
		return (this->year >= d1.get_year() ||
			(this->year == d1.get_year() && this->month >= d1.get_month()) ||
			(this->year == d1.get_year() && this->month == d1.get_month() && this->day >= d1.get_day()));
	}

	bool operator <=(date d1)
	{
		return (this->year <= d1.get_year() ||
			(this->year == d1.get_year() && this->month <= d1.get_month()) ||
			(this->year == d1.get_year() && this->month == d1.get_month() && this->day <= d1.get_day()));
	}
};

date::date()
{
	day = 0;
	month = 0;
	year = 0;
}

date::date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

istream& operator >>(istream& is, date& right)
{
	return is >> right.day >> right.month >> right.year;
}