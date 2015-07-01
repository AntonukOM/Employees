#include "Employee.h"
#include <iostream>
using std::cout;
using std::endl;

Employee::Employee
(const string &first, const string &last) :
first_name_(first), last_name_(last) {}

void Employee::set_first_name(const string &first)
{
	first_name_ = first;
}

string Employee::get_first_name() const
{
	return first_name_;
}

void Employee::set_last_name(const string &last) 
{
	last_name_ = last;
}

string Employee::get_last_name() const
{
	return last_name_;
}

void Employee::print() const
{
	cout << get_first_name() << ' ' 
		<< get_last_name() << endl;
}