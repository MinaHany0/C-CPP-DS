#include <iostream>

class student;
class tomodachi;

class tomodachi
{
    int friendMark = 10;
    public:
        void SetFriendMark(int degree, student &tomo);                                     //a normal friend function
};  

class student
{
    int mark;
    int finalMark;
    public:
        int getfinalMark(void) { return finalMark;}
        void setFinalMark(int a) { finalMark = a; return;}
        friend void tomodachi::SetFriendMark(int degree, student &tomo);            // a class method that was declared as a friend
        friend void Detective (student &stud);
};

void tomodachi::SetFriendMark(int degree, student &tomo){ tomo.finalMark = degree; } 
void Detective (student &stud){ std::cout << "---->the student final marks are " << stud.finalMark << std::endl;}       //a normal function that was declared as a friend

int main(void)
{
    student Mina;
    Mina.setFinalMark(50);
    std::cout << Mina.getfinalMark()<<std::endl;

    tomodachi Mark;
    Mark.SetFriendMark(100 , Mina);
    std::cout << Mina.getfinalMark()<<std::endl;

    std::cout << "here comes the detective and says :" << std::endl;
    Detective(Mina);
    return 0;

}