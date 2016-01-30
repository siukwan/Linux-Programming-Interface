PROJECT (LINUX)
#显示路径信息
MESSAGE(STATUS "LPI:This is BINARY dir" ${LINUX_BINARY_DIR})
MESSAGE(STATUS "LPI:This is SOURCE dir" ${LINUX_SOURCE_DIR})

#设置错误函数
SET(LIB_FUNC_ERR_SRC ../lib/error_functions.cpp)
MESSAGE(STATUS "LINUX_FILEIO:This is func_err dir" ${LIB_FUNC_ERR_SRC})


SET(SIMPLE_PIPE simple_pipe.cpp)
SET(I_FCNTL i_fcntl_locking.cpp)

#连接库
ADD_LIBRARY(FuncErr STATIC ${LIB_FUNC_ERR_SRC} )


#输出可执行文件
ADD_EXECUTABLE(simple_pipe ${SIMPLE_PIPE})
TARGET_LINK_LIBRARIES(simple_pipe FuncErr)


