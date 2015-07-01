#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

class Employee
{
public:
	Employee(const string &, const string &);

	void set_first_name(const string &);
	string get_first_name() const;

	void set_last_name(const string &);
	string get_last_name() const;

	virtual double earnings() const = 0;
	virtual void print() const;

private:
	string first_name_;
	string last_name_;
};
#endif