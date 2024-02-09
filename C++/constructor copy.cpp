#include <iostream>

class Data
{
    public:
    int number;
    char letter;

        Data() = default;
        Data(int n, char L)
        {
            number = n;
            letter = L;
        }

};

int main(void)
{
    Data d2;
    //Data d(5,'t');


}