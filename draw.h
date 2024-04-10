#pragma once
#include <string>

/* 窗口界面绘制相关 */

namespace dw{
    // 在终端界面中指定位置处，绘制一个矩形，作为部分窗口
    void draw_rec(int x, int y, int width, int height, std::string title);
    // 在终端界面中绘制游戏界面
    void drwa_game_window();
}