//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"

void use_case_registry_observer()
{
    using namespace entt::literals;

    int param_a=10;


    std::function<void()> func = [](){std::cout<<"function"<<std::endl;};
    std::function<void()> func_with_current_value = std::bind([](int a){std::cout<<"bind function "<<a<<std::endl;},param_a) ;
    std::function<void()> func_with_ref_value = [&](){std::cout<<"ref value function "<<param_a<<std::endl;};

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

    ///有update的组件，就会被记录下来。
    entt::observer observer{registry, entt::collector.update<Position>()};

    ///当entity的组件被添加的时候，如果添加以后满足有Position和Velocity，则会被记录下来。
    entt::observer observer2{registry, entt::collector.group<Position, Velocity>()};

    ///底下这一句话的意思是：当一个entity的sprite被update时，如果它有position，并且没有velocity，那么它会被collector被记录下来，否则不会。
//    entt::collector.update<sprite>().where<position>(entt::exclude<velocity>);

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
    }


    ///写法1：就用最基本的for，循环完以后，需要手动clear一下，否则不会被清空
//    for(const auto entity: observer) {
//        std::cout<<"entity "<<registry.get<int>(entity)<<" updated"<<std::endl;
//    }
//    observer.clear();


    for(const auto entity: observer2) {
        std::cout<<"entity2 "<<registry.get<int>(entity)<<" entered"<<std::endl;
    }
    observer2.clear();

    ///写法2：用表达式来写，这个循环完以后，会自动被clear掉，相当于消费掉了。
    observer.each([&](const auto entity) {
        std::cout<<"entity "<<registry.get<int>(entity)<<" updated"<<std::endl;
    });
    std::cout<<"------------------------"<<std::endl;
    observer.each([&](const auto entity) {
        std::cout<<"entity "<<registry.get<int>(entity)<<" updated"<<std::endl;
    });
    std::cout<<"------------------------"<<std::endl;
    observer.clear();
    observer.each([&](const auto entity) {
        std::cout<<"entity "<<registry.get<int>(entity)<<" updated"<<std::endl;
    });

}