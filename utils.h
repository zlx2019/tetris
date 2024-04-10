#pragma once
#include <string>

/**
 * 工具函数声明
 */

namespace util{
    // 计算和控制游戏帧率
    int fps();

    // 将 u32string 类型转换为 string
    std::string u32str_to_str(std::u32string s);
}
