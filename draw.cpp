#include <iostream>
#include <vector>

#include "draw.h"
#include "terminal.h"

/**
 * 游戏窗口绘制相关实现
 */



/**
 * 将指定的 Y 轴坐标换算为 游戏中的块位置.
 * 一个方块，占两个单元，也就是两列位置，所以需要换算一下。
 */
inline int y2block(int col){
    return 2 * col - 1;
}


namespace dw{


    /**
     * 在终端界面中绘制游戏界面
     */
    void drwa_game_window(){
        // 显示暂存的物体窗口
        draw_rec(1, 1, 9, 6, "Hold");
        //游戏主窗口
        draw_rec(1, 10, 12, 22, "Tetris");
        // 状态窗口
        draw_rec(7, 1, 9, 16, "Status");
        // 提示信息窗口
        draw_rec(19, 22, 8, 4, "Info");
        // 提示下一个窗口
        draw_rec(1,22, 8, 18, "Next");
    }

    /**
     * 在终端界面中指定位置，绘制一个矩形图形，作为窗口(只画周长，面中不绘制任何物体)，如下:
     * ┏━━┓
     * ┃  ┃
     * ┗━━┛
     * 
     * @x,y: 矩形的左上顶点位置.
     * @height: 矩形的高度
     * @width:  矩形的宽度
     */
    void draw_rec(int x,int y, int width, int height, std::string title){
        // 注意: 界面的第一行|最后一行|第一列|最后一列，这些都需要特殊处理
        // 绘制图形
        for (int row = 0; row < height; ++row){
            // 移动光标到每一行开头.
            tc::move_to(x + row, y2block(y)); 
            for (int col = 0; col < width; ++col){
                if (row == 0){ // 绘制界面第一行
                    if (col == 0){          
                        // 首行 && 首列
                        std::cout << " ┏";
                    }else if (col == width - 1){
                        // 首行 && 末列
                        std::cout << "┓";
                    }
                    else
                    {
                        // 首行其他列
                        std::cout << "━━";
                    }
                }else if (row == height - 1){ // 绘制界面最后一行
                    if (col == 0){          
                        // 末行 && 首列
                        std::cout << " ┗";
                    }else if (col == width - 1){
                        // 末行 && 未列
                        std::cout << "┛";
                    }
                    else
                    {
                        // 末行其他列
                        std::cout << "━━";
                    }
                }else{ // 其他普通行
                    if (col == 0){
                        // 其他行 && 首列
                        std::cout << " ┃";
                    }else if (col == width - 1){
                        // 其他行 || 未列
                        std::cout << "┃";
                    }else {
                        // 其他列
                        std::cout << "  ";
                    }
                }
            }
        }
        // 设置窗口标题
        // 根据标题长度以及图像的宽度计算合适的位置
        // (图形宽度 * 2 - 标题长度) / 2
        int titleY = y2block(y) + (width * 2 - title.length()) / 2;
        tc::move_to(x, titleY);
        std::cout << title;
    }
    

}
