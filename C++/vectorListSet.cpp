#include <iostream>
#include<vector>
#include <list>
#include <set>

int main()
{
    std::vector<int>v = {1,2,3,4,5,6};
    
    std::cout << "size of my vector is " << v.size() << std::endl;
    std::vector<int>::reverse_iterator itr;

    for(itr = v.rbegin(); itr != v.rend(); itr++) std::cout << *itr << " ";
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    for(itr = v.rbegin(); itr != v.rend(); itr++) std::cout << *itr << " ";

    std::cout << "\n ***********************************************************************\n";

    std::list<int>l = {1,2,3,4,5,6};
    
    std::cout << "size of my list is " << l.size() << std::endl;
    std::list<int>::reverse_iterator itr2;

    for(itr2 = l.rbegin(); itr2 != l.rend(); itr2++) std::cout << *itr2 << " ";
    l.push_back(7);
    l.push_back(7);
    l.push_back(7);
    for(itr2 = l.rbegin(); itr2 != l.rend(); itr2++) std::cout << *itr2 << " ";

    std::cout << "\n ***********************************************************************\n";

    //you can easily replace the type of DS used in a program only 
    //this is the strong point of the STL standard template libraries

    std::set<int>s = {1,2,3,4,5,6};
    
    std::cout << "size of my set is " << s.size() << std::endl;
    std::set<int>::reverse_iterator itr3;

    for(itr3 = s.rbegin(); itr3 != s.rend(); itr3++) std::cout << *itr3 << " ";
    s.insert(7);
    s.insert(7);
    s.insert(7);
    for(itr3 = s.rbegin(); itr3 != s.rend(); itr3++) std::cout << *itr3 << " ";

    //remember SET allows no duplicated members
}