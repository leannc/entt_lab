//
// Created by wangkang on 2023/10/2.
//
#include "UseCase.h"

void use_case_enum_as_bitmask()
{

    /**----------------------------------
     * 这个会报错，并不支持 & 操作
     * ----------------------------------*/
    enum class my_flag1 {
        unknown = 0x01,
        enabled = 0x02,
        disabled = 0x04
    };

//    const my_flag1 flags1 = my_flag1::enabled;
//    const bool is_enabled1 = !!(flags1 & my_flag1::enabled);
    /**----------------------------------
     * END 这个会报错，并不支持 & 操作
     * ----------------------------------*/


    enum class my_flag {
        unknown = 0x01,
        enabled = 0x02,
        disabled = 0x04,
        _entt_enum_as_bitmask
    };

    const my_flag flags = my_flag::enabled;

    auto result= flags | my_flag::unknown;
    std::cout<<"result : "<< int(result) << std::endl; // result = 3，就是个或操作。

    const bool is_enabled = !!(flags & my_flag::enabled);
    std::cout<<"enabled : "<<is_enabled << std::endl;


}