#include <iostream>
#include <algorithm>

int main(void)
{

    class data
    {
        public:
        int data_num;
        float data_float;
    };
    int f{};
    std::string s{"Hello this is Mina Hany speaking"};                      // this is value initialization
    std::string s2("\nI would like to welcome you all ghere abraod\n");     // this is direct init.
    std::string s3 = "I'm very happy to have you all here today";           // this is copy initialziation

    std::cout << s << s2 << s3 << std::endl << f<< std::endl;

    data d{};

    std::cout << d.data_num <<std::endl << d.data_float << std::endl;
    return 0;

}