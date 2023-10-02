//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"
#include <any>

void use_case_std_any()
{
    std::any value;

    // 存储不同类型的值
    value = 5;
    std::cout << std::any_cast<int>(value) << std::endl; // 输出: 5

    value = 3.14;
    std::cout << std::any_cast<double>(value) << std::endl; // 输出: 3.14

    value = "Hello";
    std::cout << std::any_cast<const char*>(value) << std::endl; // 输出: Hello

    // 检查值是否为空
    if (value.has_value()) {
        std::cout << "Value is not empty." << std::endl;
    } else {
        std::cout << "Value is empty." << std::endl;
    }

    // 重置值
    value.reset();

    // 再次检查是否为空
    if (value.has_value()) {
        std::cout << "Value is not empty." << std::endl;
    } else {
        std::cout << "Value is empty." << std::endl; // 输出: Value is empty.
    }
}