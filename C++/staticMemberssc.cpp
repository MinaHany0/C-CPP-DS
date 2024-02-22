#include <iostream>

class student{
    private:
        int studentNo;
        

    public:
        static int admittedStudents;
        student(){
            admittedStudents++;
            studentNo = admittedStudents;
        }
        void getNumber(){std::cout << studentNo << std::endl;}
        //static methods can only make use of static members which makes sense because they can be used even without objects created
        static void HowMany(void){std::cout << admittedStudents << std::endl;}  
        
};

int student::admittedStudents = 0;                              //remember static members must be declared outside class
                                                                //as if they are global variables that is only accessible 
                                                                //to that specified class hence scope resolution operator

int main(){

    student mina;
    student nada;
    student dina;
    student halim;
    student hossam;

    std::cout << "no of student is " << student::admittedStudents <<std::endl;
    hossam.getNumber();
    student::HowMany();
    return 0;
}