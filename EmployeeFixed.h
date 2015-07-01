#ifndef EMPLOYEE_FIXED
#define EMPLOYEE_FIXED

#include"Employee.h"

class Employee_fixed : public Employee
{
public:
	Employee_fixed(const string &, const string &, double = 0);

	void set_salary(double );
	double get_salary() const;

	virtual double earnings() const;
	virtual void print() const;

private:
	double salary_;
};

#endif