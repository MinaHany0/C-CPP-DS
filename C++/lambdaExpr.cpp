#include <iostream>

int main(){
    //lambda expression assigned to an auto variable and then called with certain parameters
    auto le = [](int x , int y){std::cout << "the summation is " << x+y << std::endl;};
    le(15,60);

    //lambda expression which captures a variable from main scope
    int a = 5;
    auto le2 =[a](){std::cout << "value of a variable is " << a << std::endl;};
    le2();
    //the value of captured variable does not get updated when variable changes because of capture by value
    a++;
    le2();

    //the value of captured variable changes when captured by reference
    auto le3 = [&a](){std::cout << "value of a variable in le3 is " << a << std::endl;};
    le3();
    a+=5;
    le3();

    int b = 5;
    //notice that here you assign the lambda expression to an int
    //this means that you are storing the result of lambda not the lambda expression itself
    //you cannot use the identifier le4 to call the lambda anymore
    int le4 = [](int x , int y )->int{ return x+y; }(5,7);
    //so you need the auto keyword to assign the function itself to a variable to be used later
    //and donot give parameters, else it will also store the result of lambda not the lambda itself
    auto le5 = [](int x , int y )->int{ return x+y; }(10,11);   //le5 is an int variable
    auto le6 = [](int x , int y )->int{ return x+y; };          //le6 is a lambda expression name variable

    int lastVar = le6(77,55);

    std::cout << "Last Variable equals " << lastVar << std::endl;
    return 0;
}