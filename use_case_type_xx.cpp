//
// Created by wangkang on 2023/10/2.
//

#include "UseCase.h"

void use_case_type_xx()
{
    struct Rotation {
        float x;
        float y;
        float z;
    };

    struct Position {
        float x;
        float y;
    };




    constexpr auto name =  entt::type_name<Rotation>();
    std::cout << "type name is : "<<name.value() << std::endl;  // 获取 Position 类型的名称

    auto index_r = entt::type_index<Rotation>::value();
    std::cout << "rotation type index is : "<<index_r << std::endl;

    auto index_p = entt::type_index<Position>::value();
    std::cout << "position type index is : "<<index_p << std::endl;


    uint32_t hash = entt::type_hash<Position>::value();
    std::cout<<"hash is "<< hash<<std::endl;


    // by type
    entt::type_info info = entt::type_id<Position>();
    std::cout<<"info name is "<< info.name() <<" , index is "<<info.index()<<" , the hash is "<<info.hash()<<std::endl;

// by value
    entt::type_info other_info = entt::type_id(42);
    std::cout<<"other_info name is "<< other_info.name()<<" , index is "<<other_info.index()<<" , the hash is "<<other_info.hash()<<std::endl;

}