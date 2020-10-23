// test.cpp
#include <iostream>
#include "test.h"
#include <string>
#include <vector>

using namespace std;

struct test::testImpl{
	string name;
	vector<double> data;
};

test::test() : pImpl(make_unique<testImpl>()){} // 생성자 생성
test::~test() = default; // 소멸자 생성

// 이동 작업
test::test(test&& rhs) = default;
test& test::operator=(test&& rhs) = default;

// 복사 작업 (깊은 복사)
test::test(const test& rhs) : pImpl(make_unique<testImpl>(*rhs.pImpl)){}
test& test::operator=(const test& rhs){
	*pImpl = *rhs.pImpl;
	return *this;
}

int main(){
	test t;
}