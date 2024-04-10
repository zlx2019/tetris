#pragma once

/**
 * terminal control - 终端控制相关函数声明
 */

namespace tc{
    // ============= 移动光标相关 ================
    // 将光标移动到指定的行/列位置。
    void move_to(int row, int col);
    // 将光标移动到指定的行/列位置(以一个方块为基本单位，一个方块占2个col)
    void move_to_block(int row, int col);
    // 将光标向上移动n行
    void move_up(int n);
    // 将光标向下移动n行
    void move_down(int n);
    // 将光标向左移动n列
    void move_left(int n);
    // 将光标向右移动n列
    void move_right(int n);
    // 将光标向下移动n行，并且处于行起始位置
    void move_next(int n);
    // 将光标向上移动n行，并且处于行起始位置
    void move_prev(int n);
    // 将光标移动到第col列
    void move_to_col(int col);
    // 隐藏光标
    void hide_cursor();
    // 显示光标
    void show_cursor();
    // ==========================================

    // 设置字体颜色(前景色)
    void set_font_color(int id);
    // 设置背景颜色
    void set_back_color(int id);
    // 清除终端
    void clean_screen();
    // 重置默认颜色和样式
    void reset_color();
}