#ifndef _SHELL_REGISTRY_H_
#define _SHELL_REGISTRY_H_

#include <stddef.h>
#include <stdint.h>

typedef void (*CommandHandler)(int argc, char *argv[]);

typedef struct
{
	const char *Name;
	CommandHandler Handler;
	const char* Help;
}ShellCommand_ts;

size_t Shell_Size(void);
ShellCommand_ts* Shell_Commands(void);
void Shell_Register(const char* aName, const char* aHelp, CommandHandler aCommand);
void Shell_Delete(void);


#endif /* _SHELL_REGISTRY_H_ */
