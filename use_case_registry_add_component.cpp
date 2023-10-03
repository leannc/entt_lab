//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"

void use_case_registry_add_component()
{
    struct Position {
        float x;
        float y;

        ///这一句可以不要，它有默认的构造函数，不过那不够明确。
        Position(float x,float y): x(x), y(y) {}

    };

    struct Velocity {
        float dx;
        float dy;
    };

    entt::registry registry;

    entt::entity entity = registry.create();

    auto &pos = registry.emplace<Position>(entity, 0.4,0.9);
    std::cout<<"position is "<<pos.x<<","<<pos.y<<std::endl;



    auto &vel = registry.emplace<Velocity>(entity);
    vel.dx = 0.6;
    vel.dy = 0.3;

}