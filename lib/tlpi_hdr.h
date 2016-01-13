/*
程序3-1：大多数程序示例所使用的头文件
P40
*/
/*防止重复包含头文件*/
#ifndef TLPI_HDR_H
#define TLPI_HDR_H

#include<sys/types.h> /*大部分程序需要使用的类型定义*/
#include<stdio.h>     /*标准IO函数*/
#include<stdlib.h>    /*公共库函数，EXIT_SUCCES EXIT_FAILURE*/

#include<unistd.h>    /*系统调用*/
#include<errno.h>     /*errno和错误变量*/
#include<string.h>

#include "get_num.h"


#include "error_functions.h"

typedef enum {FALSE,TRUE} Boolean;

#define min(m,n) ((m)<(n)?(m):(n))
#define max(m,n) ((m)>(n)?(m):(n))

#endif
