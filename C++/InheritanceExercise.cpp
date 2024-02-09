#include <iostream>

class Employee
{
    std::string name;
    public:
    Employee(std::string name = "N/A"): name(name){}
    std::string getName(void);
};

class FulltimeEmployee : public Employee
{
    int salary;
    public:
    FulltimeEmployee(std::string name,int salary = 1000): Employee(name) { this->salary = salary;}
    int getSalary();
};

class ParttimeEmployee : protected Employee
{
    int wage;
    public:
    ParttimeEmployee(std::string name , int wage = 500): Employee(name){ this->wage = wage;}
    int getWage(void);
    std::string getPartTimerName(void);
};

std::string Employee::getName(void){ return name;}
int FulltimeEmployee::getSalary(void) { return salary;}
int ParttimeEmployee::getWage(void) { return wage; }
std::string ParttimeEmployee::getPartTimerName(void) { return getName();}


int main()
{
    FulltimeEmployee mina{"mina", 5000};
    ParttimeEmployee andrew{"andrew" , 4000};

    std::cout << "the salary of employee " << mina.getName() << " is " << mina.getSalary() << std::endl;
    std::cout << "the wage of employee " << andrew.getPartTimerName() << " is " << andrew.getWage() << std::endl;

    return 0;

}