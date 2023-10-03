//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"



void use_case_registry_ctx_variables()
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

    Position pos;


// creates a new context variable by type and returns it
    std::cout<<"++++++++++ registry.ctx().emplace<Position>(0.4f,0.9f) +++++++++"<<std::endl;
    pos = registry.ctx().emplace<Position>(0.4f,0.9f);
    pos = registry.ctx().get<Position>();
    std::cout<<"pos is "<<pos.x<<","<<pos.y<<std::endl;

    std::cout<<"++++++++++ registry.ctx().emplace<Position>(0.3f,0.9f) +++++++++"<<std::endl;
    ///已经有了，这一句就失效了，需要用下面的insert_or_assign
    pos = registry.ctx().emplace<Position>(0.3f,0.9f);
    pos = registry.ctx().get<Position>();
    std::cout<<"pos is "<<pos.x<<","<<pos.y<<std::endl;

    std::cout<<"++++++++++ registry.ctx().insert_or_assign(Position{42.0f, 20.0f}) +++++++++"<<std::endl;
    registry.ctx().insert_or_assign(Position{42.0f, 20.0f});

    pos = registry.ctx().get<Position>();
    std::cout<<"pos is "<<pos.x<<","<<pos.y<<std::endl;


// creates a new named context variable by type and returns it
    std::cout<<"++++++++++++ registry.ctx().emplace_as<Position>(\"named_position\"_hs,5.4f,0.9f) ++++++++++++++++"<<std::endl;
    registry.ctx().emplace_as<Position>("named_position"_hs,5.4f,0.9f);

    pos = registry.ctx().get<Position>();
    std::cout<<"pos is "<<pos.x<<","<<pos.y<<std::endl;

    pos = registry.ctx().get<Position>("named_position"_hs);
    std::cout<<"named_position pos is "<<pos.x<<","<<pos.y<<std::endl;
    std::cout<<"----------------------------------"<<std::endl;


// inserts or assigns a named context variable by (deduced) type and returns it
    std::cout<<"++++++++++ registry.ctx().insert_or_assign(\"named_position_2\"_hs, Position{12.0f, 2.0f}) +++++++++"<<std::endl;
    registry.ctx().insert_or_assign("named_position_2"_hs, Position{12.0f, 2.0f});

    pos = registry.ctx().get<Position>();
    std::cout<<"pos is "<<pos.x<<","<<pos.y<<std::endl;

    pos = registry.ctx().get<Position>("named_position"_hs);
    std::cout<<"named_position pos is "<<pos.x<<","<<pos.y<<std::endl;

    pos = registry.ctx().get<Position>("named_position_2"_hs);
    std::cout<<"named_position_2 pos is "<<pos.x<<","<<pos.y<<std::endl;



    std::cout<<"++++++++++ registry.ctx().contains<Position>(\"named_position_2\"_hs) +++++++++"<<std::endl;
    bool b = registry.ctx().contains<Position>("named_position_2"_hs);
    std::cout<<"contains the named_position_2 is "<<b<<std::endl;

    std::cout<<"++++++++++ registry.ctx().find<Position>(\"named_position_2\"_hs) +++++++++"<<std::endl;
    Position* p =registry.ctx().find<Position>("named_position_2"_hs);
    std::cout<<"find the named_position_2 is "<<p->x<<","<<p->y<<std::endl;

    std::cout<<"----------------------------------"<<std::endl;
// resets the context variable associated with the given name
    std::cout<<"++++++++++ registry.ctx().erase<Position>(\"named_position_2\"_hs) +++++++++"<<std::endl;
    registry.ctx().erase<Position>("named_position_2"_hs);

    std::cout<<"++++++++++ registry.ctx().contains<Position>(\"named_position_2\"_hs) +++++++++"<<std::endl;
    b = registry.ctx().contains<Position>("named_position_2"_hs);
    std::cout<<"contains the named_position_2 is "<<b<<std::endl;

    std::cout<<"++++++++++ registry.ctx().find<Position>(\"named_position_2\"_hs) +++++++++"<<std::endl;
    p =registry.ctx().find<Position>("named_position_2"_hs);
    if (p)
    {
        std::cout<<"find the named_position_2 is "<<p->x<<","<<p->y<<std::endl;
    } else
    {
        std::cout<<"find the named_position_2 is null"<<std::endl;
    }


// resets the context variable by type
    registry.ctx().erase<Position>();
}