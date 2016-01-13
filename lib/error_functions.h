/*
程序3-2：常用错误处理函数的声明
P41
*/
/*防止重复包含头文件*/
#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

void errMsg(const char *format, ...);

#ifdef __GNUC__

#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void errExit(const char *format, ...) NORETURN;
void err_exit(const char *format, ...) NORETURN;
void errExitEn(int errnum, const char *format, ...) NORETURN;
void fatal(const char *format, ...) NORETURN;
void usageErr(const char *format, ...) NORETURN;
void cmdLineErr(const char *format, ...) NORETURN;

#endif
