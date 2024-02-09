#include <iostream>

class rational
{
    private:
        int p;
        int q;
    public:
        rational(int a = 0, int b = 0)
        {
            p = a; q = b;
        }

    friend std::istream& operator>>(std::istream &i , rational &r);
    friend std::ostream& operator<<(std::ostream &o , rational &r);
    friend rational operator+(rational &r1 , rational &r2);

};

std::istream& operator>>(std::istream &i , rational &r)
{
    i >> r.p >> r.q;
    return i;
}
std::ostream& operator<<(std::ostream &o , rational &r)
{
    o << r.p << "/" << r.q<<std::endl;
    return o;
}
rational operator+(rational &r1 , rational &r2)
{
    rational temp;
    if(r1.q == r2.q)
    {
        temp.q = r1.q;
        temp.p = r1.p + r2.p;
    }
    else if(r1.q % r2.q == 0)
    {
        temp.q = r1.q;
        temp.p = r1.p + r2.p * (r1.q / r2.q);
    }
    else if(r2.q % r1.q == 0)
    {
        temp.q = r2.q;
        temp.p = r2.p + r1.p * (r2.q / r1.q);
    }
    else
    {
        temp.q = r2.q * r1.q;
        temp.p = r2.p * r1.q + r1.p * r2.q ;
    }
    return temp;
}

int main()
{
    rational r1,r2,r3,r4;

    std::cin >> r1;
    std::cin >> r2;
    std::cout << r1 << r2;
    r3 = r1+r2;
    std::cout << r3;
}