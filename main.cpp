#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"

/**
 * 游戏主入口
 * 
 */
int main(int argc, const char* argv[]){
    // tc::move_to(5,0);
    // tc::set_font_color(214);
    // std::cout << "Hello Tetris" << std::endl;
    // tc::reset_color();
    // tc::move_to(10,0);

    int i = 1;
    tc::hide_cursor(); // 将光标隐藏
    while (true){
        tc::clean_screen();

        tc::move_to(i++, 15);
        tc::set_back_color(214); // 设置背景色
        std::cout << "  ";      // 输出两个空格，只显示背景色
        tc::reset_color();      // 取消背景色
        std::cout.flush();      // 刷新标准输出缓冲
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}