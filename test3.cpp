#include <iostream>
#include <memory>
using namespace std;
struct A;
struct B;
struct A{
    A(){
        cout<<"A 생성자 생성"<<endl;
    }
    ~A(){
        cout<<"A 소멸"<<endl;
    }
    shared_ptr<B> b1;
};

struct B{
    B(){
        cout<<"B 생성자 생성"<<endl;
    }
    ~B(){
        cout<<"B 소멸"<<endl;
    }
    weak_ptr<A> a1;  // 약한 참조
};


int main(){
    //shared_ptr<A> a2(new A());
    auto a2=make_shared<A>();
    //shared_ptr<B> b2(new B());
    auto b2=make_shared<B>();
    // A와 B가 서로를 참조
    a2->b1 = b2;
    b2->a1 = a2;
    // A와 B를 해제
    a2.reset();
    b2.reset();
}