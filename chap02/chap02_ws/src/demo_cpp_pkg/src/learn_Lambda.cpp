// 学习lambda表达式-----匿名函数
// 格式：[capture list](parameters) -> return_type {函数体}
#include <iostream>
#include <algorithm>

int main(){
    auto add = [](int a, int b) -> int {return a+b;};
    int sum = add(3,5);
    auto print_sum = [sum]() -> void {std::cout<<"3+5="<<sum<<std::endl;};
    auto print_sum2 = [=]() -> void {std::cout<<"3+5="<<sum<<std::endl;}; // 捕获所有
    print_sum();
    print_sum2();
    return 0;
}