#include <iostream>
#include <memory>

class data{
    public:
        void fun(void){std::cout << "This is Function 1 talking" << std::endl;}
        void fun2(void){std::cout << "This is Function 2 talking" << std::endl;}
};
int main(){
    std::unique_ptr<data> p (new data);

    p->fun();
    std::unique_ptr<data> p2 = std::move(p);
    p2->fun();

    std::shared_ptr<data> q{new data};
    std::shared_ptr<data> q2 = q;
    q->fun2();
    q2->fun2();
    std::cout << "counter of shared pointers is " << q.use_count() << std::endl;

    std::weak_ptr<data> d;
    d = q;
    if(!d.expired()){
        (*d.lock()).fun2();
    }


  





}