//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"
#include <cereal/archives/binary.hpp>

void use_case_registry_snapshot_for_serialization()
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


    //创建一个用于写入的stream，命名为output
    std::ofstream output("snapshot.bin", std::ios::binary);
    cereal::BinaryOutputArchive archive( output );

    //TODO 失败，这个还没有研究清楚
//    entt::snapshot snap{registry}
//            .get<entt::entity>(archive)
//            .get<Position>(archive)
//            .get<Velocity>(archive);



}