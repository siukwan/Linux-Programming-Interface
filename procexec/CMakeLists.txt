PROJECT (LINUX_PROCEXEC)
#显示路径信息
MESSAGE(STATUS "FileIo:This is BINARY dir" ${LINUX_PROCEXEC_BINARY_DIR})
MESSAGE(STATUS "FileIo:This is SOURCE dir" ${LINUX_PROCEXEC_SOURCE_DIR})

#设置错误函数
SET(LIB_FUNC_ERR_SRC ../lib/error_functions.cpp)
MESSAGE(STATUS "LINUX_FILEIO:This is func_err dir" ${LIB_FUNC_ERR_SRC})

#设置get_num编译文件
SET(GET_NUM_SRC_LIST ../lib/get_num.cpp)

SET(EXITHANDLERS exit_handlers.cpp)

#连接库
ADD_LIBRARY(FuncErr STATIC ${LIB_FUNC_ERR_SRC} )
ADD_LIBRARY(GetNum STATIC ${GET_NUM_SRC_LIST} )


#输出可执行文件
ADD_EXECUTABLE(exit_handlers ${EXITHANDLERS})
TARGET_LINK_LIBRARIES(exit_handlers FuncErr GetNum)
