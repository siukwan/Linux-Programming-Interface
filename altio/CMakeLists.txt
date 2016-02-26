PROJECT (LINUX)
#显示路径信息
MESSAGE(STATUS "File:This is BINARY dir" ${LINUX_BINARY_DIR})
MESSAGE(STATUS "File:This is SOURCE dir" ${LINUX_SOURCE_DIR})

#设置错误函数
SET(LIB_FUNC_ERR_SRC ../lib/error_functions.cpp)
MESSAGE(STATUS "LINUX_FILEIO:This is func_err dir" ${LIB_FUNC_ERR_SRC})

#设置get_num编译文件
SET(GET_NUM_SRC_LIST ../lib/get_num.cpp)

SET(TSELECT t_select.cpp)

#连接库
ADD_LIBRARY(FuncErr STATIC ${LIB_FUNC_ERR_SRC} )
ADD_LIBRARY(GetNum STATIC ${GET_NUM_SRC_LIST} )


#输出可执行文件
ADD_EXECUTABLE(t_select ${TSELECT})
TARGET_LINK_LIBRARIES(t_select FuncErr GetNum)
