#include "game.h"

/**
 * 游戏主要逻辑相关实现
 */
namespace gm{

    // 游戏状态，是否正在运行.
    bool running = false;
    // 当前光标位置
    int row, col;

    /* 初始化游戏 */
    void init(){
        running = true;

        // 设置光标初始位置，默认设置在游戏窗口左上角原点
        row = 2;
        col = 11;
    }

    /* 游戏结束. */
    void over(){
        running = false;
    }

    void rotate(){
        row--;
    }

    void down(){
        row++;
    }

    void left(){
        col--;
    }

    void right(){
        col++;
    }
}