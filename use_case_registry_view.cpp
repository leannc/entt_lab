//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"
#include <cereal/archives/binary.hpp>

void use_case_registry_view()
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
    auto view = registry.view<Position,Velocity>(entt::exclude<Acceleration>);
    
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
            registry.emplace<Velocity>(entities.back(),3.0f+i,3.4f+i);
        }

        if(i==4)
        {
            registry.emplace<Acceleration>(entities.back());
        }

    }

    for(auto entity : view)
    {
        std::cout<<"view : entity id is "<<registry.get<int>(entity)<< std::endl;

        auto [position, velocity] = view.get<Position, Velocity>(entity);
        std::cout<<"position is "<<position.x<<","<<position.y<<std::endl;
        std::cout<<"velocity is "<<velocity.dx<<","<<velocity.dy<<std::endl;
        std::cout<<"--- "<<std::endl;

    }
}