#include <iostream>
#include <list>
#include <fstream>
#include "Employee.h"
#include "EmployeeFixed.h"
#include "EmployeeHour.h"
using namespace std;

void show_employees(list<Employee*> emp_list);
void show_employees(list<Employee*> emp_list, int size);
list<Employee*> create_employees();
bool compare_by_name(Employee* e1, Employee* e2);
bool compare_by_last_name(Employee* e1, Employee* e2);
bool compare_by_salary(Employee* e1, Employee* e2);
void write_to_file(list<Employee*> emp_list, string file_name);
void read_from_file(string file_name);

int main()
{
	list<Employee*> emp_list = create_employees();
	show_employees(emp_list);

	cout << "------------------TASK a)  ------------" << endl;
	cout << "Sort list by salary: " << endl;
	emp_list.sort(compare_by_salary);
	show_employees(emp_list);

	cout << "\n------------------TASK b)  ------------" << endl;
	show_employees(emp_list, 5);

	cout << "\n------------------TASK c)  ------------" << endl;
	emp_list.reverse();
	show_employees(emp_list, 3);

	cout << "\n------------------TASK d-e)  ------------" << endl;
	try
	{
		write_to_file(emp_list, "List of Employees.dat");
		read_from_file("List of Employees.dat");
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

void show_employees(list<Employee*> emp_list)
{
	double total_earnings = 0;
	for each (Employee* e in emp_list)
	{		
		cout << e->get_first_name() << " " << e->get_last_name() << " " << e->earnings() << endl;
		total_earnings += e->earnings();
	}
	cout << "Total earnings in the list: " << total_earnings << endl;
}

void show_employees(list<Employee*> emp_list, int size)
{
	double total_earnings = 0;
	int i = 0;
	for each (Employee* e in emp_list)
	{
		i++;
		cout << e->get_first_name() << " " << e->get_last_name() << " " << e->earnings() << endl;
		total_earnings += e->earnings();
		if(i == size) { break; }
	}
	cout << "Total earnings in the list: " << total_earnings << endl;
}

list<Employee*> create_employees()
{
	list<Employee*> emp_list;
	emp_list.push_back(new Employee_fixed("Bob", "Scott", 2256.6));
	emp_list.push_back(new Employee_fixed("Bob", "Smith", 2156.0));
	emp_list.push_back(new Employee_fixed("Alan", "Osbourne", 3658.0));
	emp_list.push_back(new Employee_fixed("Peter", "Parker", 5678.5));
	emp_list.push_back(new Employee_fixed("Colin", "Anderson", 4236.5));
	emp_list.push_back(new Employee_fixed("Alan", "Clarkson", 6256.6));
	emp_list.push_back(new Employee_fixed("Mikel", "Jhonson", 8693.0));
	emp_list.push_back(new Employee_hour("John", "Peterson", 30.25));
	emp_list.push_back(new Employee_hour("Ioan", "Coleson", 30.25));
	emp_list.push_back(new Employee_hour("Eva", "Foz", 30.25));
	emp_list.push_back(new Employee_hour("Linkoln", "Pharell", 30.25));
	emp_list.push_back(new Employee_hour("Scarlet", "Clarkson", 30.25));
	emp_list.push_back(new Employee_hour("Eva", "Fox", 30.25));
	emp_list.push_back(new Employee_hour("Britney", "Johansson", 30.25));
	return emp_list;
}

bool compare_by_salary(Employee* e1, Employee* e2)
{
	if (e1->earnings() == e2->earnings())
	{
		return compare_by_name(e1, e2);
	}
	return e1->earnings() > e2->earnings();
}

bool compare_by_name(Employee* e1, Employee* e2)
{
	if (e1->get_first_name() == e2->get_first_name())
	{
		return compare_by_last_name(e1, e2);
	}
	return e1->get_first_name() < e2->get_first_name();
}

bool compare_by_last_name(Employee* e1, Employee* e2)
{
	return e1->get_last_name() < e2->get_last_name();
}

void write_to_file(list<Employee*> emp_list, string file_name)
{
	ofstream out_file(file_name);
	if (!out_file)
	{
		throw exception("File could not be write!");
	}
	for each (Employee* e in emp_list)
	{
		out_file << e->get_first_name() << "\t" <<
			e->get_last_name() << "\t" << e->earnings() << endl;
	}
	cout << "File was written with name: " << file_name << endl;
}

void read_from_file(string file_name)
{
	ifstream in_file(file_name);
	if (!in_file)
	{
		throw exception("File could not be found!");
	}
	cout << "File name: " << file_name << " contains:\n";
	cout << in_file.rdbuf();
}