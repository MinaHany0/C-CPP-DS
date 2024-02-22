#include <iostream>

class Name{
    private:
    std::string namee;
    public:
    Name(std::string str = "N/A") :namee(str){};
    ~Name(){ std::cout << "Calling Destructor of Name \n"; }
};
    Name makeInstance(void)     //    <-        
    {                            //    |
        Name tmp;                  //  |
        return tmp;                 // |    object temp got destroyed and new temporary object was made to keep result
    }

int main()
{
    Name Stud1= makeInstance();     // now temp object got returned and was destoyed after new object Stud1 was created
                                    // and had its value assigned .... then the object Stud1 was destroyed at end of program
}

// result is:
// Calling Destructor of Name 
// Calling Destructor of Name 
// Calling Destructor of Name 


//call using
//g++ elideConstructors.cpp -g -fno-elide-constructors -std=c++14  && ./a.out
//it will call destructor 3 times
//1 for objcet stud1
//2 for te