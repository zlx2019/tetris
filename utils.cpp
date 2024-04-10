#include <chrono>
#include <locale>
#include <codecvt>
#include "utils.h"

/**
 * 工具函数定义实现 
 */

/**
 * 计算以及控制游戏帧率
 */
int util::fps(){
    // 每秒开始刷新游戏帧的起始时间(首次使用游戏启动时间，作为起始时间)
    static auto start = std::chrono::steady_clock::now();
    // 当前秒已刷新的游戏帧数
    static int frames = 0;
    // 每秒刷新的游戏帧总数
    static int fps = 0;
    // 每次刷新游戏帧的时间
    auto end = start;

    // 通过每次刷新帧的时间，计算是否超过1秒
    end = std::chrono::steady_clock::now();
    frames++;
    if (end - start > std::chrono::seconds(1)){
        // 超过了1秒，重置帧数和起始时间
        fps = frames;
        frames = 0;
        start = end;
    }
    return fps;
}

/**
 * 将 u32string 类型转换为 string
 * 
 * @s: 要转换的u32string
 */
std::string util::u32str_to_str(std::u32string s){
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
    return convert.to_bytes(s);
}
