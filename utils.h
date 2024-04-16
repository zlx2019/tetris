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

    /**
     * 将指定的 Y 轴坐标换算为 游戏中的块位置.
     * 一个方块，占两个单元，也就是两列位置，所以需要换算一下。
     */
    inline int col2block(int col){
        return 2 * col - 1;
    }
}
