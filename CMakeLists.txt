########## CMake 编译配置 ##########

# 设置CMake最低版本
cmake_minimum_required(VERSION 3.27)

# 项目名
project(Tetris)

# 设置要使用的C++标准
set(CXX_STANDARD 20)

# 扫描 . 目录下的所有源文件列表，放到src变量中
aux_source_directory(. src)

# 设置要编译可执行程序，以及编译涉及的源文件
add_executable(Tetris ${src})