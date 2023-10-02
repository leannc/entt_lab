//
// Created by wangkang on 2023/10/2.
//

#include "UseCase.h"

void use_case_hashed_string()
{
    using namespace entt::literals;
    constexpr auto str = "text"_hs;

    entt::basic_hashed_string<char> str2 = "text"_hs;
    entt::basic_hashed_string<wchar_t> wstr = L"text"_hws;

    if(wstr ==str2)
    {
        std::cout<<"wstr == str2"<<std::endl;
    } else
    {
        std::cout<<"str != str2"<<std::endl;
    }

    auto d=str.data();
    auto wd=wstr.data();
    std::cout<<"str is "<< str.data()<<std::endl;
    std::wcout<<"wstr is "<< wstr.data()<<std::endl;

}