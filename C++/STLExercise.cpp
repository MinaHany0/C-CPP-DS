#include <iostream>
#include <vector>

class items{
    private:
        std::vector<std::string> name;
        std::vector<float>price;
        std::vector<int>quantity;
        static int idx;
    public:
        void add(std::string str, float pr, int q){
            name.push_back(str);
            price.push_back(pr);
            quantity.push_back(q);
            idx++;
        }
        void retreive(int id)
        {
            std::cout << "Item Name is " << name[id] << std::endl;
            std::cout << "Item price is " << price[id] << std::endl;
            std::cout << "Item quantity is " << quantity[id] << std::endl;
        }
        
};

int items::idx = 0;

int main()
{
    items ll;
    ll.add("bag" , 5.2 , 30);
    ll.add("cats" , 155 , 150);
    for(int i = 0; i < 2; i++)
        ll.retreive(i);

    return 0;
}