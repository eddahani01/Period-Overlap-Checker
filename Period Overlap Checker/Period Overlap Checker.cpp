// PeriodOverlapChecker
 //Period Overlap Checker is a C++ console application that reads two time periods and determines if they overlap.
 //It uses the function IsOverlapPeriods(), which compares the start and end dates of both periods to check for any intersection.
 //This tool is useful for handling scheduling conflicts, date range validations, and time-based logic.

#include <iostream>

using namespace std;


short ReadYear()
{
	short year = 0;
	cout << "Please Enter a Year? ";
	cin >> year;

	return year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "Please Enter a Month? ";
	cin >> Month;

	return Month;
}

short ReadDay()
{
	short Day = 0;
	cout << "Please Enter a Day? ";
	cin >> Day;

	return Day;
}

struct stDate
{
	short Year;
	short Month;
	short Day;
};

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

struct stPeriod {

	stDate StartDate;
	stDate EndDate;
};

stPeriod ReadPeriod()
{
	stPeriod Period;
	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();
	return Period;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	/*if (IsDate1AfterDate2(Date1, Date2))
		return enDateCompare::After;*/

		//this is faster
	return enDateCompare::After;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
	if (
		CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before
		||
		CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After
		)
		return false;
	else
		return true;
}

int main()
{
	cout << "\nEnter Period 1:";
	stPeriod Period1 = ReadPeriod();
	cout << "\nEnter Period 2:";
	stPeriod Period2 = ReadPeriod();

	if (IsOverlapPeriods(Period1, Period2))
		cout << "\n Yes, Periods Overlap\n";
	else
		cout << "\nNo, Periods do not Overlap\n";

	system("pause>0");
	return 0;
}
