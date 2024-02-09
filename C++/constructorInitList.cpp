#include <iostream>

class Data
{
    public:
    int number;
    char letter;

        Data() = default;
        Data(int n, char L) :number(n), letter(L)
        {
            
        }

};

int main(void)
{
    Data d(5,'t');

    std::cout << d.letter << std::endl << d.number << std::endl;
}