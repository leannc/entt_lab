cmake_minimum_required(VERSION 3.25)
project(entt_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(entt_lab main.cpp Scene.cpp Scene.h use_case_scheduler.cpp UseCase.h use_case_std_any.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/entt/include)