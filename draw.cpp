#include "draw.h"
#include "define.h"
#include "terminal.h"
#include "utils.h"

/**
 * 游戏窗口绘制相关实现
 */




namespace dw{
    // 定义一些游戏界面样式
    const std::u32string DefaultStyle = U"┌┐└┘─│";
    const std::u32string BoldStyle = U"┏┓┗┛━┃";
    const std::u32string DoubleLineStyle = U"╔╗╚╝═║";
    const std::u32string RoundStyle = U"╭╮╰╯─│";
    // 当前使用的样式
    const std::u32string CurStyle = RoundStyle;

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

        // 获取要使用的界面样式
        auto left_top = util::u32str_to_str({CurStyle[0]});  // ┏
        auto right_top = util::u32str_to_str({CurStyle[1]}); // ┓
        auto line = util::u32str_to_str({CurStyle[4]});      // ━
        auto vertical = util::u32str_to_str({CurStyle[5]});  // ┃
        auto left_down = util::u32str_to_str({CurStyle[2]}); // ┗
        auto right_down = util::u32str_to_str({CurStyle[3]});// ┛

        // 开始绘制图形
        for (int row = 0; row < height; ++row){
            // 移动光标到每一行开头.
            tc::move_to(x + row, util::col2block(y)); 
            for (int col = 0; col < width; ++col){
                if (row == 0){ // 绘制界面第一行
                    if (col == 0){          
                        // 首行 && 首列 
                        std::cout << " " << left_top;
                    }else if (col == width - 1){
                        // 首行 && 末列
                        std::cout << right_top;
                    }
                    else
                    {
                        // 首行其他列
                        std::cout << line << line;
                    }
                }else if (row == height - 1){ // 绘制界面最后一行
                    if (col == 0){          
                        // 末行 && 首列
                        std::cout << " " << left_down;
                    }else if (col == width - 1){
                        // 末行 && 未列
                        std::cout << right_down;
                    }else{
                        // 末行其他列
                        std::cout << line << line;
                    }
                }else{ // 其他普通行
                    if (col == 0){
                        // 其他行 && 首列
                        std::cout << " " << vertical;
                    }else if (col == width - 1){
                        // 其他行 || 未列
                        std::cout << vertical;
                    }else{
                        // 其他列
                        std::cout << "  ";
                    }
                }
            }
        }
        // 设置窗口标题
        // 根据标题长度以及图像的宽度计算合适的位置
        // (图形宽度 * 2 - 标题长度) / 2
        int titleY = util::col2block(y) + (width * 2 - title.length()) / 2;
        tc::move_to(x, titleY);
        std::cout << title;
    }
    

}
