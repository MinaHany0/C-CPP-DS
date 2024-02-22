#include <iostream>
#include <map>
#include <iomanip>

int main()
{
    std::map<int, std::string> m;
    m.insert(std::pair<int,std::string>(1,"mina"));
    m.insert(std::pair<int , std::string>(15,"Eman"));

    std::map<int,std::string>::iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++)
    {
        std::cout << std::setw(3)<< itr->first <<  " " << std::setw(10) << itr->second << std::endl;
    }
    return 0;
}