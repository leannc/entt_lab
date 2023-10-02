//
// Created by wangkang on 2023/10/2.
//

#pragma once
#include "entt.hpp"
#include <chrono>
#include <thread>
#include <iostream>

class Scene {
public:
    void use_case_scheduler();


public:
    entt::registry m_Registry;
};