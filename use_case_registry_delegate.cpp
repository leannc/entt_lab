//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"
#include <cereal/archives/binary.hpp>

int func1(int i)
{
    std::cout<<"func1 is called, param is "<<i<<std::endl;
    return i;
}


int func2(char c, int i)
{
    std::cout<<"-----func2 is called, param is "<<c<<" and "<<i<<std::endl;
    return i;
}



class DelegateClass1
{
public:
    void class_func1(const void* user_data,entt::registry& registry)
    {
        std::cout<<" in OrganizerClass1 func1 : the registry size is "<<registry.storage<entt::entity>().size()<<std::endl;
    }
};


void use_case_registry_delegate()
{
//    using namespace entt::literals;

    entt::delegate<int(int)> delegate;
    delegate.connect<&func1>();
    delegate(10);

    std::function<int(int)> std_f;
    std_f= func1;
    std_f(20);

    const char c = 's';
    delegate.connect<&func2>(c);
    delegate(42);

    std_f= std::bind(func2,c,std::placeholders::_1);
    std_f(32);


}