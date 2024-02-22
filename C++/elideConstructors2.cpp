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
    Name &&Stud1= makeInstance();     // now tmp obj assigned in a r value reference so destructor not called for tmp obj
}

// result is:
// Calling Destructor of Name 
// Calling Destructor of Name 


//call using
//g++ elideConstructors.cpp -g -fno-elide-constructors -std=c++14  && ./a.out
//it will call destructor 3 times
//1 for objcet stud1
//2 for te