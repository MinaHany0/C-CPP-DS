#include <iostream>

class student
{
    public:
    void funStudent(void) {std::cout << "Welcome from the student\n";}
};

class MathStudent : public student
{
    public:
    void funMathStudent(void) { std::cout << "Hello from the Math Student\n";}
};



int main()
{   
    student *mina;
    mina  = new MathStudent;

    mina->funStudent();

}