#pragma

/* 游戏控制事件逻辑相关 */



namespace gm{
    // 按下的按键命令
    extern char command; 

    /* 以无缓冲方式，阻塞接受一个键盘事件. */
    char accept_event();
    /* 开始监听按键事件 */
    void listener_event();
    /* 事件读取线程函数. */
    void event_loop();


    /* ============= 事件处理函数 ================= */
    /* 游戏退出事件 - Q */
    void event_quit();
    /* 方块旋转事件 - W */
    void event_rotate();
    /* 方块下坠事件 - S */
    void event_down();
    /* 方块左移事件 - A */
    void event_left();
    /* 方块右移事件 - D */
    void event_right();
}