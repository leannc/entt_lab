//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"

void use_case_entt_tag()
{
    using namespace entt::literals;

    entt::registry registry;

    // 创建一个实体，并将 PlayerTag 标记添加到该实体
    entt::entity entity = registry.create();

    constexpr entt::basic_hashed_string<char> tag = "PlayerTag"_hs;
    registry.emplace<entt::tag<tag>>(entity);

    // 检查实体是否具有 PlayerTag 标记
    if (registry.all_of<entt::tag<tag>>(entity)) {
        std::cout << "The entity has PlayerTag" << std::endl;
    }

    // 移除实体的 PlayerTag 标记
    registry.remove<entt::tag<tag>>(entity);

    // 再次检查实体是否具有 PlayerTag 标记
    if (!registry.all_of<entt::tag<tag>>(entity)) {
        std::cout << "The entity doesn't have PlayerTag" << std::endl;
    }


}