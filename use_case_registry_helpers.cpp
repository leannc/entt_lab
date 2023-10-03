//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"


void use_case_registry_helpers()
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

    entt::registry registry;
    std::vector<entt::entity> entities;

    std::cout<<"registry size is "<<registry.storage<entt::entity>().size()<<std::endl;
    entt::entity ent1 = registry.create();
    Position& pos = registry.emplace_or_replace<Position>(ent1); ///这里要加引用，pos才是registry里面的component
    std::cout<<"registry size is "<<registry.storage<entt::entity>().size()<<std::endl;

    ///这里的to_entity是将一个component的指针转换为entity
    ///但是，这个entity并不在registry里面
    entt::entity ent2 = entt::to_entity(registry,pos);
    std::cout<<"registry size is "<<registry.storage<entt::entity>().size()<<std::endl;

    if(ent2 == entt::null)
    {
        std::cout<<"ent2 is null"<<std::endl;
    }




}