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

SET(MULTIWAIT multi_wait.cpp)
SET(CHILDSTATUS child_status.cpp)
SET(RINTWAITSTATUS print_wait_status.cpp)
SET(MAKEZOMBIE make_zombie.cpp)
#连接库
ADD_LIBRARY(FuncErr STATIC ${LIB_FUNC_ERR_SRC} )
ADD_LIBRARY(GetNum STATIC ${GET_NUM_SRC_LIST} )
ADD_LIBRARY(PrintWaitStatus STATIC ${RINTWAITSTATUS} )


#输出可执行文件
ADD_EXECUTABLE(exit_handlers ${EXITHANDLERS})
TARGET_LINK_LIBRARIES(exit_handlers FuncErr GetNum)

ADD_EXECUTABLE(multi_wait ${MULTIWAIT})

ADD_EXECUTABLE(child_status ${CHILDSTATUS})
TARGET_LINK_LIBRARIES(child_status FuncErr GetNum PrintWaitStatus)

ADD_EXECUTABLE(make_zombie ${MAKEZOMBIE})
TARGET_LINK_LIBRARIES(make_zombie FuncErr )