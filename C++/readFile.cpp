#include <iostream>
#include <fstream>

int main()
{
    std::ifstream is;                   //make an object of input file stream
    is.open("my.txt");                  //open the selected file to read from
    std::string str;                    //create strings to hold your data
    std::string str2;
    
    while(is.eof() != true)             //while eof is not reached keep reading and cout
    {
        is >> str;
        std::cout << str << " ";
    }   
    is.close();                         //close file when finished
    return 0;
}