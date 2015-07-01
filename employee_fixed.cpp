#include "EmployeeFixed.h"
#include <iostream>
using std::cout;
using std::endl;

Employee_fixed::Employee_fixed(const string &first, 
const string &last, double payment) : Employee(first, last) 
{
	set_salary(payment);
}

void Employee_fixed::set_salary(double payment)
{
	salary_ = payment;
}

double Employee_fixed::get_salary() const
{
	return salary_;
}

double Employee_fixed::earnings() const
{
	return get_salary();
}

void Employee_fixed::print() const
{
	Employee::print();
	cout << "Salary: " << get_salary() << endl;
}