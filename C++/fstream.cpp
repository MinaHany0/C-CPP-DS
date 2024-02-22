#include <iostream>
#include <fstream>

class Student{
    public:
    int rollNumber;
    std::string name;
    int marks;
    friend std::ofstream& operator<<(std::ofstream &osp, Student &stud);
    friend std::ifstream& operator>>(std::ifstream &ifs, Student &stud);
    friend std::ostream& operator<<(std::ostream& os, Student& stud);
};
 
std::ifstream& operator>>(std::ifstream &ifs, Student &stud)
{
    ifs >> stud.name >> stud.rollNumber >> stud.marks;
    return ifs;
}

std::ofstream& operator<<(std::ofstream &osp, Student &stud)
{
    osp << stud.name << std::endl;
    osp << stud.rollNumber << std::endl;
    osp << stud.marks << std::endl;
    return osp;
}

std::ostream& operator<<(std::ostream& os, Student& stud)
{
    std::cout << "Student Name is " << stud.name << std::endl;
    std::cout << "Student rollnumber is " << stud.rollNumber << std::endl;
    std::cout << "Student marks are " << stud.marks << std::endl;
    return os;
}

int main(){
    std::ofstream osp("myfile.txt", std::ios::trunc);
    std::ifstream ifs("myfile.txt");

    Student mina;
    mina.name ="Mina"; 
    mina.rollNumber = 1; 
    mina.marks = 10;
    Student andrew;
    andrew.name = "Andrew"; 
    andrew.rollNumber= 2; 
    andrew.marks = 15;

    osp << mina;
    osp << andrew;

    Student MinaCopy, AndrewCopy;
    ifs>>MinaCopy >>AndrewCopy;

    std::cout << MinaCopy << AndrewCopy;
}