cmake_minimum_required(VERSION 2.8)
PROJECT (LINUX)
#显示路径信息
MESSAGE(STATUS "File:This is BINARY dir" ${LINUX_BINARY_DIR})
MESSAGE(STATUS "File:This is SOURCE dir" ${LINUX_SOURCE_DIR})
include_directories ("../lib/")
#设置错误函数
SET(LIB_FUNC_ERR_SRC ../lib/error_functions.cpp)
MESSAGE(STATUS "LINUX_FILEIO:This is func_err dir" ${LIB_FUNC_ERR_SRC})

#设置get_num编译文件
SET(GET_NUM_SRC_LIST ../lib/get_num.cpp)

#设置tty编译文件
SET(TTY_FUNC ../lib/tty_functions.cpp)

SET(TSELECT t_select.cpp)
SET(POLLPIPE poll_pipes.cpp)
SET(DEMOSIGIO demo_sigio.cpp)

#连接库
ADD_LIBRARY(FuncErr STATIC ${LIB_FUNC_ERR_SRC} )
ADD_LIBRARY(GetNum STATIC ${GET_NUM_SRC_LIST} )
ADD_LIBRARY(TTY STATIC ${TTY_FUNC} )


#输出可执行文件
ADD_EXECUTABLE(t_select ${TSELECT})
TARGET_LINK_LIBRARIES(t_select FuncErr GetNum)

ADD_EXECUTABLE(poll_pipes ${POLLPIPE})
TARGET_LINK_LIBRARIES(poll_pipes FuncErr GetNum)

ADD_EXECUTABLE(demo_sigio ${DEMOSIGIO})
TARGET_LINK_LIBRARIES(demo_sigio FuncErr GetNum TTY)