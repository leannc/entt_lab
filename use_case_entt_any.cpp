//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"


void use_case_entt_any()
{

    ///这个可以自定义一个any，设置small buffer optimization的大小。
    using my_any = entt::basic_any<sizeof(double[4])>;
    using my_any_alignment = entt::basic_any<sizeof(double[4]), alignof(double[4])>;

    entt::any value;
    entt::any empty{};

    std::cout<<"empty has value = "<<empty.operator bool()<<std::endl;
    empty="asdfa";
    std::cout<<"empty has value = "<<empty.operator bool()<<std::endl;

    value=10;
    std::cout<<"value is "<<*(int*)value.data()<<std::endl;

    value="kang";
    std::cout<<"value is "<<*(char**)value.data()<<std::endl;
    std::cout<<"value is "<<entt::any_cast<const char*>(value)<<std::endl;

    value=std::string("std kang");
    std::cout<<"value is "<<*(std::string*)value.data()<<std::endl;
    std::cout<<"value is "<<entt::any_cast<std::string>(value)<<std::endl;

    value=123;
    std::cout<<"value is "<<*(int*)value.data()<<std::endl;
    std::cout<<"value is "<<entt::any_cast<int>(value)<<std::endl;


    ///如果assign的时候，给的类型和之前已有的类型不一样，则会失败。
    bool b = value.assign("kang");
    std::cout<<"result is "<<b<<std::endl;
    std::cout<<"value is "<<entt::any_cast<int>(value)<<std::endl; //还是之前的值

    //这一句会失败，因为没有被成功赋值
//    std::cout<<"value is "<<entt::any_cast<const char*>(value)<<std::endl;
}