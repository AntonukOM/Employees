#include "EmployeeHour.h"
#include <iostream>
using std::cout;
using std::endl;

Employee_hour::Employee_hour(const string &first, 
const string &last, double payment) : Employee(first, last) 
{
	set_rate(payment);
}

void Employee_hour::set_rate(double payment)
{
	rate_ = payment;
}

double Employee_hour::get_rate() const
{
	return rate_;
}

double Employee_hour::earnings() const
{
	return 20.8 * 8 * get_rate();
}

void Employee_hour::print() const
{
	Employee::print();
	cout << "Payment: " << get_rate() << endl;
}