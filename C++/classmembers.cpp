#include <iostream>

class student
{
    int marks = 5;
    int average = 10;
    public:
    int students = 20;

    
        int howManyStudents(void)
        {
            return students;
        }
};

int main()
{
    student classA;

    classA.students = 15;
    classA.howManyStudents();
    return 0;
}