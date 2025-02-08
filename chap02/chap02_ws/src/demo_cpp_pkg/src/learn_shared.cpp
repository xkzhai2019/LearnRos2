#include <iostream>
#include <memory>

int main(){
    auto p1 = std::make_shared<std::string>("this is a str"); // 指向字符串的指针
    std::cout<< "p1的引用计数为："<<p1.use_count()<<",指向的地址为："<<p1.get()<<std::endl; // 1
    auto p2 = p1;
    std::cout<< "p1的引用计数为："<<p1.use_count()<<",指向的地址为："<<p1.get()<<std::endl; // 2
    std::cout<< "p2的引用计数为："<<p2.use_count()<<",指向的地址为："<<p2.get()<<std::endl; // 2

    p1.reset();
    std::cout<< "p1的引用计数为："<<p1.use_count()<<",指向的地址为："<<p1.get()<<std::endl; // 0
    std::cout<< "p2的引用计数为："<<p2.use_count()<<",指向的地址为："<<p2.get()<<std::endl; // 1
    std::cout<<"p2指向资源的内容为："<<*p2<<std::endl;
    std::cout<<"p2指向资源的内容为："<<p2->c_str()<<std::endl;
    return 0;
}