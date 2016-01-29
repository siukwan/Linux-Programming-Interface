PROJECT (LINUX)
#显示路径信息
MESSAGE(STATUS "LPI:This is BINARY dir" ${LINUX_BINARY_DIR})
MESSAGE(STATUS "LPI:This is SOURCE dir" ${LINUX_SOURCE_DIR})

#设置错误函数
SET(LIB_FUNC_ERR_SRC ../lib/error_functions.cpp)
MESSAGE(STATUS "LINUX_FILEIO:This is func_err dir" ${LIB_FUNC_ERR_SRC})

#设置get_num编译文件
SET(GET_NUM_SRC_LIST ../lib/get_num.cpp)

#设置curr_time编译文件
SET(CURR_TIME ../lib/curr_time.cpp)

SET(T_FLOCK t_flock.cpp)
SET(I_FCNTL i_fcntl_locking.cpp)

#连接库
ADD_LIBRARY(FuncErr STATIC ${LIB_FUNC_ERR_SRC} )
ADD_LIBRARY(CurrTime STATIC ${CURR_TIME} )
ADD_LIBRARY(GetNum STATIC ${GET_NUM_SRC_LIST} )


#输出可执行文件
ADD_EXECUTABLE(t_flock ${T_FLOCK})
TARGET_LINK_LIBRARIES(t_flock FuncErr CurrTime GetNum)


ADD_EXECUTABLE(i_fcntl_locking ${I_FCNTL})
TARGET_LINK_LIBRARIES(i_fcntl_locking FuncErr)
