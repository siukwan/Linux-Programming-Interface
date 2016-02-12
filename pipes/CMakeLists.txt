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

SET(SIMPLE_PIPE simple_pipe.cpp)
SET(PIPE_SYNC pipe_sync.cpp)
SET(FIFO_SEQNUM_CLIENT fifo_seqnum_client.cpp)
SET(FIFO_SEQNUM_SERVER fifo_seqnum_server.cpp)

#连接库
ADD_LIBRARY(FuncErr STATIC ${LIB_FUNC_ERR_SRC} )
ADD_LIBRARY(CurrTime STATIC ${CURR_TIME} )
ADD_LIBRARY(GetNum STATIC ${GET_NUM_SRC_LIST} )


#输出可执行文件
ADD_EXECUTABLE(simple_pipe ${SIMPLE_PIPE})
TARGET_LINK_LIBRARIES(simple_pipe FuncErr)

ADD_EXECUTABLE(pipe_sync ${PIPE_SYNC})
TARGET_LINK_LIBRARIES(pipe_sync FuncErr CurrTime GetNum) 


ADD_EXECUTABLE(fifo_seqnum_client ${FIFO_SEQNUM_CLIENT})
TARGET_LINK_LIBRARIES(fifo_seqnum_client FuncErr CurrTime GetNum) 
ADD_EXECUTABLE(fifo_seqnum_server ${FIFO_SEQNUM_SERVER})
TARGET_LINK_LIBRARIES(fifo_seqnum_server FuncErr CurrTime GetNum) 
