PROJECT (LINUX_PROC)
#显示路径信息
MESSAGE(STATUS "FileIo:This is BINARY dir" ${LINUX_PROC_BINARY_DIR})
MESSAGE(STATUS "FileIo:This is SOURCE dir" ${LINUX_PROC_SOURCE_DIR})

#设置错误函数
SET(LIB_FUNC_ERR_SRC ../lib/error_functions.cpp)
MESSAGE(STATUS "LINUX_FILEIO:This is func_err dir" ${LIB_FUNC_ERR_SRC})

#设置get_num编译文件
SET(GET_NUM_SRC_LIST ../lib/get_num.cpp)

SET(MODIFY_ENV modify_env.cpp)
SET(DISPLAY_ENV display_env.cpp)
SET(NECHO necho.cpp)
SET(LONGJMP longjmp.cpp)

#连接库
ADD_LIBRARY(FuncErr STATIC ${LIB_FUNC_ERR_SRC} )
ADD_LIBRARY(GetNum STATIC ${GET_NUM_SRC_LIST} )


#输出可执行文件
ADD_EXECUTABLE(modify_env ${MODIFY_ENV})
TARGET_LINK_LIBRARIES(modify_env FuncErr GetNum)

ADD_EXECUTABLE(display_env ${DISPLAY_ENV})
ADD_EXECUTABLE(necho ${NECHO})
ADD_EXECUTABLE(longjmp ${LONGJMP})