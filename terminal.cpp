#include "terminal.h"
#include "define.h"

/**
 * 终端控制相关函数实现
 */

// ANSI转义码前缀
#define ESC "\033["
// 参数分隔符
#define SEP ";"
// ANSI重置转义码
#define RESET "\033[0m"

/**
 * 将光标移动到指定的行和列
 *   转义码格式: `\033[行;列H`
 * 
 * @row: 要移动到的行
 * @col: 要移动到的列
 */
void tc::move_to(int row, int col){
    std::cout << ESC << row << SEP << col << "H";
}

/**
 * 将光标移动到指定的行/列位置(以一个方块为基本单位，一个方块占2个col)
 * @row: 要移动到的行
 * @col: 要移动到的游戏块位置
 */
void tc::move_to_block(int row, int col){
    std::cout << ESC << row << SEP << 2 * col - 1 << "H";
}

/**
 * 将光标向上移动n行
 *  转义码格式: `ESC[{n}A`
 * @n: 移动的行数 
 */
void tc::move_up(int n){
    std::cout << ESC << n << "A";
}

/**
 * 将光标向下移动n行
 *  转义码格式: `ESC[{n}B`
 * 
 * @n: 移动的行数 
 */
void tc::move_down(int n){
    std::cout << ESC << n << "B";
}


/**
 * 将光标向右移动n列
 *  转义码格式: `ESC[{n}C`
 * 
 * @n: 移动的列数 
 */
void tc::move_right(int n){
    std::cout << ESC << n << "C";
}

/**
 * 将光标向下移动n行，并且处于行起始位置
 *  转义码格式: `ESC[{n}E`
 * 
 * @n: 移动的行数 
 */
void tc::move_next(int n){
    std::cout << ESC << n << "E";
}

/**
 * 将光标向上移动n行，并且处于行起始位置
 *  转义码格式: `ESC[{n}F`
 * 
 * @n: 移动的行数 
 */
void tc::move_prev(int n){
    std::cout << ESC << n << "F";
}

/**
 * 将光标向左移动n列
 *  转义码格式: `ESC[{n}D`
 * 
 * @n: 移动的列数 
 */
void tc::move_left(int n){
    std::cout << ESC << n << "D";
}

/**
 * 将光标移动到第col列
 *  转义码格式: `ESC[{col}G`
 * 
 * @col: 要移动到的列号
 */
void tc::move_to_col(int col){
    std::cout << ESC << col << "G";
}


/**
 * 将光标隐藏起来
 *  命令格式: `ESC[?25l`
 */
void tc::hide_cursor()
{
    std::cout << ESC << "?25l";
}

/**
 * 将光标显示出来
 *  命令格式: `ESC[?25h`
 */
void tc::show_cursor(){
    std::cout << ESC << "?25h";
}




/**
 * 设置字体颜色(前景色)
 * @id: 颜色的ID，可选值0~255
 *  转义码格式: `\033[38;5;{id}m`
 *
 */
void tc::set_font_color(int id)
{
    std::cout << ESC << "38;5;" << id << "m";
}

/**
 * 设置背景色
 * @id: 颜色ID
 *  转义码格式: `\033[48;5;{id}m`
*/
void tc::set_back_color(int id){
    std::cout << ESC << "48;5;" << id << "m";
}

/**
 * 擦除整个终端 
 */
void tc::clean_screen(){
    std::cout << ESC << "2J";
}

/**
 * 重置颜色和样式
 */
void tc::reset_color(){
    std::cout << RESET;
}



