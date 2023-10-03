//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"

void use_case_registry_version()
{
    using namespace entt::literals;

    entt::registry registry;


    std::cout<<"--------- create ------------"<<std::endl;
    // 创建一个实体，并将 PlayerTag 标记添加到该实体
    entt::entity entity = registry.create();

    // gets the version contained in the entity identifier
    auto version = entt::to_version(entity);
    std::cout<<"version is "<<version<<std::endl;

    // returns true if the entity is still valid, false otherwise
    bool b = registry.valid(entity);
    std::cout<<"entity valid is "<<b<<std::endl;

// gets the actual version for the given entity
    auto curr_version = registry.current(entity);
    std::cout<<"curr_version is "<<curr_version<<std::endl;

    std::cout<<"--------- destroy ------------"<<std::endl;
    registry.destroy(entity);
    b = registry.valid(entity);
    std::cout<<"entity valid is "<<b<<std::endl;


    std::cout<<"--------- create again ------------"<<std::endl;
    entity = registry.create();

    b = registry.valid(entity);
    std::cout<<"entity valid is "<<b<<std::endl;


    version = entt::to_version(entity);
    std::cout<<"version is "<<version<<std::endl;

    // returns true if the entity is still valid, false otherwise
    b = registry.valid(entity);

// gets the actual version for the given entity
    curr_version = registry.current(entity);
    std::cout<<"curr_version is "<<curr_version<<std::endl;


}