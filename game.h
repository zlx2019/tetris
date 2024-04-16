#pragma once

/* 游戏主要逻辑相关 */

namespace gm{

    // 游戏状态，是否正在运行
    extern bool running;
    // 当前光标所处位置
    extern int row, col;

    /* 游戏初始化函数 */
    void init();
    /* 游戏结束函数 */
    void over();

    void rotate();
    void down();
    void left();
    void right();
}