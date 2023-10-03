cmake_minimum_required(VERSION 3.25)
project(entt_lab)

set(CMAKE_CXX_STANDARD 17)


add_executable(entt_lab main.cpp Scene.cpp Scene.h
        use_case_scheduler.cpp UseCase.h use_case_std_any.cpp
        use_case_entt_any.cpp use_case_enum_as_bitmask.cpp
        use_case_const_expr.cpp use_case_hashed_string.cpp
        use_case_type_xx.cpp use_case_entt_tag.cpp
        use_case_registry_version.cpp use_case_registry_add_component.cpp
        use_case_registry_observe_changes.cpp use_case_registry_observer.cpp
        use_case_registry_helpers.cpp use_case_registry_organizer.cpp

        use_case_registry_ctx_variables.cpp use_case_registry_snapshot_for_serialization.cpp use_case_registry_group.cpp use_case_registry_view.cpp)

target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/entt/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/cereal/include
        )

