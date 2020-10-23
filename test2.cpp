#include <iostream>
#include <memory>

using namespace std;

template<typename T>
struct ArrayDeleter{
    void operator() (T* ptr){
        delete[] ptr;
    }
};

int main(){
    shared_ptr<int> A(new int[100], ArrayDeleter<int>());
    auto B = A;

    cout << "reference count: " << B.use_count() << endl;
    A.reset();

    cout << "reference count: " << B.use_count() << endl;
    B.reset();   // reference count = 0, 객체 해제 (delete[] 연산자 사용)

    return 0;
}
