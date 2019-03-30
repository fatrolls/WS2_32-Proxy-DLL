#ifndef __LOG_H__
#define __LOG_H__

#include <Windows.h>
#include <stdio.h>

void Log(const char *fmt, ...);
void Hexdump(void *ptr, int buflen);

#endif
