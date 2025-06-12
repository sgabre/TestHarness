#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define SHELL_PROMPT "$> "
#define SHELL_NUMBER_OF_COMMAND 32

typedef int (*CallBack_t)(int argc, char **argv);

typedef struct ShellCommand_ts 
{
	const char *Name;
	CallBack_t 	CallBack;
	const char* Help;
} ShellCommand_ts;

typedef struct Shell_ts 
{
	bool IsEnable;
	size_t Write;
	ShellCommand_ts* Commands;
	size_t RxSize;
} Shell_ts;

Shell_ts mShell;
static  ShellCommand_ts __CMD_TABLE__[SHELL_NUMBER_OF_COMMAND];



static void _Echo(char c) 
{
	if ('\n' == c) 
	{
		putchar('\r');
		putchar('\n');
	} 
	else if ('\b' == c) 
	{
		putchar('\b');
		putchar(' ');
		putchar('\b');
	} 
	else 
	{
		putchar(c);
	}
}

void _Printf(const char *format, ...)
{
	char buffer[128]; // Adjust size as needed
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);
	
	for (const char *c = buffer; *c != '\0'; ++c) 
	{
		_Echo(*c);
	}

}

static void Shell_Prompt(void) 
{
	_Printf(SHELL_PROMPT);
}

void Shell_PutLine(char *s) 
{
	puts(s);
	puts("\n");
}

int Shell_Gets(char *s, int len) 
{
	char *t = s;
	char c;
	
	*t = '\000';
	/* read until a <CR> is received */
	while ((c = getchar()) != '\n') 
	{
		if ((c == '\b') || (c == '\127')) 
		{
			if (t > s) 
			{
				/* send ^H ^H to erase previous character */
				_Printf("\b \b");
				t--;
			}
		} 
		else 
		{
			*t = c;
			putchar(c);
			if ((t - s) < len) 
			{
				t++;
			}
		}
		/* update end of string with NUL */
		*t = '\000';
	}
	
	return t - s;
}

void Shell_Enable() 
{
	mShell.IsEnable = true;
}

void Shell_Disable() 
{
	mShell.IsEnable = false;
}

static const ShellCommand_ts* Shell_SearchCommand(const char *name) 
{
	for (const ShellCommand_ts *command = mShell.Commands; command < &mShell.Commands[SHELL_NUMBER_OF_COMMAND]; ++command)
	{
		if(command->Name == NULL)
		{
			break;
		}
		else if (strcmp(command->Name, name) == 0) 
		{
			return command;
		}
	}
	
	return NULL;
}



void Shell_Handler(void) 
{
	char buf[128];
	int len;
	
	char *argv[32] = {0};
	int argc = 0;
	
	
	Shell_Prompt();
	len = Shell_Gets(buf, 128);
	

	//Parsing /token
	char *token = strtok(buf, " \n");
	
	while (token && argc < 32) 
	{
		argv[argc++] = token;
		token = strtok(NULL, " \n");
	}
	argv[argc] = NULL;  // Ensure NULL termination

	const ShellCommand_ts* command = Shell_SearchCommand(buf);
	
	if (len != 0) 
	{
		if ( (command != NULL) && (command->Name != NULL) )
		{
			command->CallBack(argc, argv);
		} 
		else 
		{
			_Printf("FAIL: unrecognized command\n");
		}
	}
	
}

bool Shell_IsEnable() 
{
	return mShell.IsEnable;
}

void SHELL_ADD_CMD(const char* name, const char* help_string, CallBack_t aCommand) 
{
	//sizeof(mShell.Commands)/sizeof(ShellCommand_ts);
	if(mShell.Write <  SHELL_NUMBER_OF_COMMAND)
	{
		mShell.Commands[mShell.Write].Name = name;
		mShell.Commands[mShell.Write].Help = help_string;
		mShell.Commands[mShell.Write].CallBack = aCommand;
		mShell.Write ++;
	}
}

int Help_Handler(int argc, char *argv[]) 
{
	for (const ShellCommand_ts *command = mShell.Commands; command < &mShell.Commands[SHELL_NUMBER_OF_COMMAND]; ++command)
	{
		if(command->Name != NULL)
		{
			_Printf("%s - %s\n", command->Name, command->Help);
		}
		else 
		{
			break;
		}
	}

}

int Quit_Handler(int argc, char *argv[]) 
{
	_Printf("Bye-Bye");
	Shell_Disable();
	return 0;
}

int Info_Handler(int argc, char *argv[]) 
{
	_Printf("--Software--\n");
	_Printf("Version: %d.%d.%d\n", 0, 0, 0);
	_Printf("Revison: %s\n","FFFFFFFFFFFFF");
	_Printf("--Hardware--\n");
	_Printf("Version: %s\n", "F1");
	return 0;
}

void Shell_Init(void) 
{
	memset(&mShell,0, sizeof(Shell_ts) );
	mShell.Commands = &__CMD_TABLE__[0];
	
	SHELL_ADD_CMD("help", "list all commands",  Help_Handler);
	SHELL_ADD_CMD("?", "list all commands",     Help_Handler);
	SHELL_ADD_CMD("quit", "quit execution", 	Quit_Handler);
	SHELL_ADD_CMD("info", "Version & Revision", Info_Handler);
	Shell_Enable();
	
}

int main(int argc, char *argv[]) 
{
	char buf[128];
	int len;
	bool IsEnable = true;
	
	Shell_Init();
	
	while (Shell_IsEnable() != false) 
	{
		Shell_Handler() ;
	}
}