PROJECT (LINUX_FILEBUFF)
#显示路径信息
MESSAGE(STATUS "FileIo:This is BINARY dir" ${LINUX_FILEBUFF_BINARY_DIR})
MESSAGE(STATUS "FileIo:This is SOURCE dir" ${LINUX_FILEBUFF_SOURCE_DIR})

#设置错误函数
SET(LIB_FUNC_ERR_SRC ../lib/error_functions.cpp)
MESSAGE(STATUS "LINUX_FILEIO:This is func_err dir" ${LIB_FUNC_ERR_SRC})

#设置get_num编译文件
SET(GET_NUM_SRC_LIST ../lib/get_num.cpp)

SET(DIRECT_READ direct_read.cpp)

#连接库
ADD_LIBRARY(FuncErr STATIC ${LIB_FUNC_ERR_SRC} )
ADD_LIBRARY(GetNum STATIC ${GET_NUM_SRC_LIST} )


#输出可执行文件
ADD_EXECUTABLE(direct_read ${DIRECT_READ})
TARGET_LINK_LIBRARIES(direct_read FuncErr GetNum)
