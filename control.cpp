#include "control.h"
#include "define.h"
#include "game.h"

/**
 * 游戏控制事件逻辑相关
 */

namespace gm{
    // 每次按下的按键命令
    char command;
    // 事件与处理函数的映射器
    std::map<char, std::function<void()>> event_matcher{
        {KEY_Q, event_quit},
        {KEY_W, event_rotate},
        {KEY_S, event_down},
        {KEY_A, event_left},
        {KEY_D, event_right},
    };


    /* 游戏退出事件处理 */
    void event_quit(){
        over();
    }

    void event_rotate(){
        rotate();
    }

    void event_down(){
        down();
    }

    void event_left(){
        left();
    }

    void event_right(){
        right();
    }

    /* 事件读取线程函数，负责监听按键事件的输入 */
    void event_loop(){
        // 循环处理事件...
        while (running){
            // 阻塞获取按键事件，并执行相应的处理动作
            command = accept_event();
            event_matcher[command]();
        }
    }

    /* 启动一个后台线程，负责监听键盘事件. */
    void listener_event(){
        // 创建事件监听线程，负责接收按键事件
        std::thread task(event_loop);
        task.detach();
    }


    /* 从标准输入中 读取一个字符的输入(以无行缓冲模式) */
    char accept_event(){
        // 定义两个结构体，用于保存以及恢复标准输入终端设备的属性和行为
        struct termios recover, cur;
        // 获取当前标准输入的控制信息
        tcgetattr(0, &cur);
        recover = cur;
        // 将标准输入设备 重置为原始模式，禁用输入的回车\换行处理，让输入的字符立即传递给程序
        cfmakeraw(&cur);
        // 让当前标准输入应用该设备
        tcsetattr(0, 0, &cur);
        // 获取标准输入字符(无需回车换行符就可以读取到按键的输入)
        command = getchar();
        // 将标准输入恢复为之前的模式
        tcsetattr(0, 0, &recover);
        return command;
    }

}
