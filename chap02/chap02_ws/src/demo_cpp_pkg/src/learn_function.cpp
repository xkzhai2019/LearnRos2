/*
函数包装器：为函数、方法、Lambda表达式等提供统一的调用接口
*/
#include <iostream>
#include <functional>

// 自由函数
void save_with_free_fun(const std::string &file_name){
    std::cout<<"调用了自由函数，保存："<<file_name<<std::endl;
}

// 成员方法
class FileSave{
    public:
        void save_with_member_fun(const std::string &file_name){
            std::cout<<"调用了成员方法，保存："<<file_name<<std::endl;
        }
};

int main(){
    auto save_with_lambda_fun = [](const std::string &file_name) -> void {
        std::cout<<"调用了lambda函数，保存："<<file_name<<std::endl;
    };

    // 传统调用方式
    //1. 自由函数
    save_with_free_fun("file.txt");
    //2. 成员方法：需创建对象
    FileSave file_save;
    file_save.save_with_member_fun("file.txt");
    //3. lambda函数
    save_with_lambda_fun("file.txt");


    // 使用包装器，实现统一调用
    std::function<void(const std::string &)> save1 = save_with_free_fun;
    std::function<void(const std::string &)> save2 = save_with_lambda_fun;
    std::function<void(const std::string &)> save3 = std::bind(&FileSave::save_with_member_fun,&file_save,std::placeholders::_1); // 使用std::bind()将成员函数变成std::function对象
    save1("file.txt");
    save2("file.txt");
    save3("file.txt");
    return 0;
}