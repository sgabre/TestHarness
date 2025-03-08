#ifndef _SHELL_IO_H_
#define _SHELL_IO_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct Shell_io_ts
{
	int (*getchar)(void);
	int (*putchar)(int character );
	void(*printf)(const char *format, ...);
} Shell_io_ts;

Shell_io_ts * ioShell(void);

#endif /* _SHELL_IO_H_ */
