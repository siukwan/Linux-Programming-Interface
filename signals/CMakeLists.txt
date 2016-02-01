PROJECT (LINUX)
#显示路径信息
MESSAGE(STATUS "FileIo:This is BINARY dir" ${LINUX_BINARY_DIR})
MESSAGE(STATUS "FileIo:This is SOURCE dir" ${LINUX_SOURCE_DIR})

#设置错误函数
SET(LIB_FUNC_ERR_SRC ../lib/error_functions.cpp)
MESSAGE(STATUS "LINUX_FILEIO:This is func_err dir" ${LIB_FUNC_ERR_SRC})

#设置get_num编译文件
SET(GET_NUM_SRC_LIST ../lib/get_num.cpp)
#设置signal_functions编译文件
SET(SIGNAL_FUNCTIONS ../lib/signal_functions.cpp)

SET(OUCH ouch.cpp)
SET(INTQUIT intquit.cpp)
SET(TKILL t_kill.cpp)
SET(SIGSENDER sig_sender.cpp)
SET(SIGRECEIVER sig_receiver.cpp)
SET(NONREENTRANT nonreentrant.cpp)

#连接库
ADD_LIBRARY(FuncErr STATIC ${LIB_FUNC_ERR_SRC} )
ADD_LIBRARY(GetNum STATIC ${GET_NUM_SRC_LIST} )
ADD_LIBRARY(SignalFunctions STATIC ${SIGNAL_FUNCTIONS} )


#输出可执行文件
ADD_EXECUTABLE(ouch ${OUCH})
TARGET_LINK_LIBRARIES(ouch FuncErr GetNum)

ADD_EXECUTABLE(intquit ${INTQUIT})
TARGET_LINK_LIBRARIES(intquit FuncErr GetNum)

ADD_EXECUTABLE(t_kill ${TKILL})
TARGET_LINK_LIBRARIES(t_kill FuncErr GetNum)

ADD_EXECUTABLE(sig_sender ${SIGSENDER})
TARGET_LINK_LIBRARIES(sig_sender FuncErr GetNum)

ADD_EXECUTABLE(sig_receiver ${SIGRECEIVER})
TARGET_LINK_LIBRARIES(sig_receiver FuncErr GetNum SignalFunctions)


ADD_EXECUTABLE(nonreentrant ${NONREENTRANT})
TARGET_LINK_LIBRARIES(nonreentrant FuncErr)
