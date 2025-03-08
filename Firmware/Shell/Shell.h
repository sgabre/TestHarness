#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdbool.h>
#include <stdint.h>

#include "Registry.h"
#include "Shell_io.h"

const ShellCommand_ts* mShell_SearchCommand(const char *name);
int mShell_Gets(char* s, int len) ;
int mShell_ParseCommand(char* input, char *argv[], int maxArgs);

void Shell_Enable(void);
void Shell_Disable(void); 
bool Shell_IsEnable(void);
void Shell_Handler(void);
void Shell_Init(void);

#endif /* _SHELL_H_ */
