#include <iostream>

class stack
{
    private:
        int* st = nullptr;
        int size;
        int last = 0;
    public:
        stack(int size = 5):size(size)
        {
            st = new int[size];
        }
        void push(int x)
        {
            try
            {
                if(last == size-1) throw std::string{"stack Full!!!"};
                st[last++] = x;
            }
            catch(std::string str){ std::cout << str << std::endl; }
            
        }
        int pop(void)
        {
            try
            {
                if(last == 0) throw std::string{"Stack empty"};
                return st[last--];                
            }
            catch(...){ std::cout << "Exception !! exiting now" << std::endl; }
        }
};

int main()
{
    stack myStack(3);

    //myStack.pop();

    myStack.push(5);
    myStack.push(5);
    myStack.push(5);
    myStack.push(5);
    myStack.push(5);

    return 0;


}