#ifndef EMPLOYEE_HOUR
#define EMPLOYEE_HOUR

#include"Employee.h"

class Employee_hour : public Employee
{
public:
	Employee_hour(const string &, const string &, double = 0);

	void set_rate(double );
	double get_rate() const;

	virtual double earnings() const;
	virtual void print() const;

private:
	double rate_;
};

#endif