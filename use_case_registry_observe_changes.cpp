//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"

void use_case_registry_observe_changes_function_on_construct_callbak()
{
    std::cout<<"component added"<<std::endl;
}

void use_case_registry_observe_changes_function_on_destroy_callbak(std::function<void()> func)
{
    func();
    std::cout<<"component destroyed"<<std::endl;
}

void use_case_registry_observe_changes_function_on_update_callbak(std::function<void()> func)
{
    func();
    std::cout<<"component updated, param value is "<<std::endl;
}

void use_case_registry_observe_changes()
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

    //TODO 这里要等running pool弄清楚以后再来看，怎么在回调函数中加入tag信息，有什么用
    entt::entity entity = registry.create();
    registry.emplace<entt::tag<"test"_hs>>(entity);

    entt::entity entity2 = registry.create();
    entt::entity entity3;

    // connects a free function
    registry.on_construct<Position>("test"_hs).connect<&use_case_registry_observe_changes_function_on_construct_callbak>();
    registry.on_destroy<Position>().connect<&use_case_registry_observe_changes_function_on_destroy_callbak>(func_with_current_value);
    registry.on_update<Position>().connect<&use_case_registry_observe_changes_function_on_update_callbak>(func_with_ref_value);
//// connects a member function
//    registry.on_construct<position>().connect<&my_class::member>(instance);
//
//// disconnects a free function
//    registry.on_construct<position>().disconnect<&my_free_function>();
//
//// disconnects a member function
//    registry.on_construct<position>().disconnect<&my_class::member>(instance);

    std::cout<<"--------- construct ------------"<<std::endl;
    auto &pos = registry.emplace<Position>(entity, 0.4,0.9);
    pos = registry.emplace<Position>(entity2, 0.4,0.8);
    std::cout<<"position is "<<pos.x<<","<<pos.y<<std::endl;

    std::cout<<"--------- update ------------"<<std::endl;
    param_a=11;
    registry.emplace_or_replace<Position>(entity,10.0f,20.0f);


    std::cout<<"--------- destroy ------------"<<std::endl;
    registry.remove<Position>(entity);
    registry.destroy(entity);
    std::cout<<"entity valid is "<<registry.valid(entity)<<std::endl;


    std::cout<<"registry size is "<<registry.storage<entt::entity>().size()<<std::endl;

    ///对Position进行操作，会触发on_construct回调。
    std::cout<<"----- error entity3---------------"<<std::endl;
    auto &pos2 = registry.emplace<Position>(entity3);
//    pos2 = registry.emplace<Position>(entity3); ///虽然entity3不在registry中，但是这里还是会报错，说已经有Position了。
    pos2.x = 0.6;
    pos2.y = 0.3;

    ///返回entity3依然是无效的。
    std::cout<<"entity3 valid is "<<registry.valid(entity3)<<std::endl;

    std::cout<<"registry size is "<<registry.storage<entt::entity>().size()<<std::endl;




}