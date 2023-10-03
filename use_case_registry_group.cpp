//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"
#include <cereal/archives/binary.hpp>

void use_case_registry_group()
{
    using namespace entt::literals;

    int param_a=10;

    param_a=12;
    struct Position {
        float x;
        float y;

        ///这一句可以不要，它有默认的构造函数，不过那不够明确。
//        Position(float x,float y): x(x), y(y) {}

    };

    struct Velocity {
        float dx;
        float dy;
    };

    struct Acceleration {
        float x;
        float y;
    };

    entt::registry registry;
    std::vector<entt::entity> entities;

    ///完全拥有，遍历最快
//    auto group1 = registry.group<Position,Velocity>();

    ///部分拥有，Velocity组件不被拥有。 如果上面的全部拥有被使用了，那么这个就会报错了，因为影响了它的排序结果。
    ///所以，拥有的组件，最好只有一个，这样足够快，也不跟别的group冲突。
    auto group = registry.group<Position>(entt::get<Velocity>,entt::exclude<Acceleration>);

    ///不拥有，最慢,但还是比view快
//    auto group = registry.group<>(entt::get<Position,Velocity>);

    for(int i=0;i<10;i++)
    {
        entities.emplace_back(registry.create());
        registry.emplace<Position>(entities.back(), 0.4f+i,0.9f);
        registry.emplace<int>(entities.back(),i);
//        registry.emplace<int>(entities.back(),i*10);
        if(i%3 ==0)
        {
            registry.emplace_or_replace<Position>(entities.back(),0.5f+i,0.8f);
        }

        if(i%2 ==0)
        {
            registry.emplace<Velocity>(entities.back());
        }

        if(i==4)
        {
            registry.emplace<Acceleration>(entities.back());
        }

    }

//    for(auto entity : group1)
//    {
//        std::cout<<"group : entity id is "<<registry.get<int>(entity)<< std::endl;
//
//        auto [position, velocity] = group1.get<Position, Velocity>(entity);
//        std::cout<<"position is "<<position.x<<","<<position.y<<std::endl;
//        std::cout<<"velocity is "<<velocity.dx<<","<<velocity.dy<<std::endl;
//        std::cout<<"--- "<<std::endl;
//    }
    std::cout<<"========================= "<<std::endl;
    for(auto entity : group)
    {
        std::cout<<"group : entity id is "<<registry.get<int>(entity)<< std::endl;

        auto [position, velocity] = group.get<Position, Velocity>(entity);
        std::cout<<"position is "<<position.x<<","<<position.y<<std::endl;
        std::cout<<"velocity is "<<velocity.dx<<","<<velocity.dy<<std::endl;
        std::cout<<"--- "<<std::endl;
    }
}