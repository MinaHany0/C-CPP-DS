#include <iostream>
#include <sstream>

int main()
{
    int value = 12345;

    std::stringstream stream;

    stream << value;

    std::string s;

    stream >> s;

    std::cout << s+"6" << std::endl;
    return 0;
}