#include "define.h"
#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"

void init();
void run();
void exit();

/**
 * 游戏主入口
 */
int main(int argc, const char* argv[]){
    // 初始化游戏配置
    init();
    // 运行游戏
    run();
    // 结束游戏
    exit();
    return 0;
}

/**
 * 游戏运行逻辑函数. 
 */
void run(){
    int i = 1;
    while (gm::running){
        // 显示fps信息
        // tc::move_to_block(8, 2);
        // std::cout << "FPS:" << util::fps();
        // tc::move_to(5, 15);
        tc::move_to(gm::row, util::col2block(gm::col));
        tc::set_back_color(214); // 设置背景色
        std::cout << "  ";      // 输出两个空格，只显示背景色
        tc::reset_color();      // 取消背景色
        std::cout.flush();      // 刷新标准输出缓冲
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    // 游戏结束.
    exit();
}

/**
 * 初始化游戏界面.
 */
void init(){
    // 隐藏终端光标
    tc::hide_cursor();
    tc::clean_screen();
    // 绘制游戏界面
    dw::drwa_game_window();

    // 初始化游戏参数.
    gm::init();
    // 开始监听键盘事件，并且处理
    gm::listener_event();
}

/**
 * 游戏退出
 */
void exit(){
    // 清屏，并且将光标移动到原点(左上角起始位).
    tc::clean_screen();
    tc::move_to(1, 1);
    tc::set_font_color(9);
    std::cout << "Game Over, Bye~" << std::endl;

    // 恢复终端属性
    tc::show_cursor();
    tc::reset_color();
    std::exit(0);
}