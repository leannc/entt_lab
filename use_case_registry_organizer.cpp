//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"


void use_case_registry_organizer_func1(const void* user_data,entt::registry& registry)
{
    std::cout<<"the registry size is "<<registry.storage<entt::entity>().size()<<std::endl;
}

class OrganizerClass1
{
public:
    void class_func1(const void* user_data,entt::registry& registry)
    {
        std::cout<<" in OrganizerClass1 func1 : the registry size is "<<registry.storage<entt::entity>().size()<<std::endl;
    }
};


void use_case_registry_organizer()
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


    entt::organizer organizer;
    organizer.emplace<&use_case_registry_organizer_func1>();
    organizer.emplace<&use_case_registry_organizer_func1>("func_name_1");
    organizer.emplace<&use_case_registry_organizer_func1, Position, Velocity>("func_with_component_name_1");

    OrganizerClass1 instance1;
//    organizer.emplace<&OrganizerClass1::class_func1>(&instance1);
    organizer.emplace(+[](const void *, entt::registry &reg) {std::cout<<" in lambda for OrganizerClass1 : the registry size is "<<reg.storage<entt::entity>().size()<<std::endl; }, &instance1);

    // adds a decayed lambda directly
    organizer.emplace(+[](const void *, entt::registry &reg) {std::cout<<" in lambda : the registry size is "<<reg.storage<entt::entity>().size()<<std::endl;});

    std::vector<entt::organizer::vertex> graph = organizer.graph();

    for(auto &&node: graph) {
        node.prepare(registry);
        if (node.name()) {
            std::cout<<" node name is "<<node.name()<<std::endl;
        } else
        {
            std::cout<<" node name is null"<<std::endl;
        }
    }

}