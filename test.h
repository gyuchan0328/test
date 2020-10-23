// test.h
#include <memory>

class test{
    private:
        struct testImpl;
        std::unique_ptr<testImpl> pImpl;

    public:
        test();  // 생성자 생성
        ~test(); // 소멸자 생성

        // 이동 작업
        test(test&& rhs);
        test& operator=(test&& rhs);

        // 복사 작업 (깊은 복사)
        test(const test& rhs);
        test& operator=(const test& rhs);
};