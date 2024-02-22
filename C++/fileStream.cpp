#include <iostream>
#include <fstream>

int main()
{
    std::ofstream ofs ("my.txt", std::ios::trunc);
    ofs << "Hello World!" << std::endl;
    ofs << "This is my new file" << std::endl;
    return 0;
}