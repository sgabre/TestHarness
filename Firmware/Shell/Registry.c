#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "Registry.h"
#include "Shell_io.h"

#define DYNAMIC_MEMORY 1
#define STATIC_MEMORY  2 

//#define MEMORY_TYPE    DYNAMIC_MEMORY
#define MEMORY_TYPE    STATIC_MEMORY


static size_t mCommandCount = 0;
#if (MEMORY_TYPE == DYNAMIC_MEMORY)
static size_t mCommandCapacity = 0;
#endif
#if(MEMORY_TYPE == DYNAMIC_MEMORY)
#define SHELL_MIN_COMMAND 2
static ProtocolCommand_ts* mCommands = NULL;
#elif (MEMORY_TYPE == STATIC_MEMORY)
#define SHELL_NUMBER_OF_COMMAND 32
static ShellCommand_ts mCommands[SHELL_NUMBER_OF_COMMAND] = {0};
#endif

size_t Shell_Size(void)
{
    return mCommandCount;
}

ShellCommand_ts* Shell_Commands(void)
{
    return mCommands;
}

void Shell_Delete(void)
{
    mCommandCount = 0;
    memset(mCommands, 0, SHELL_NUMBER_OF_COMMAND * sizeof(ShellCommand_ts));
    
}

void Shell_Register(const char* aName, const char* help_string, CommandHandler aHandler)
{
    if (aName == NULL)
    {
        ioShell()->printf("Error: Command Name cannot be NULL.\n");
        return;
    }
    
    if (help_string == NULL)
    {
        ioShell()->printf("Error: Command Help cannot be NULL.\n");
        return;
    }
    
    if (aHandler == NULL)
    {
        ioShell()->printf("Error: Handler cannot be NULL.\n");
        return;
    }
    
    // Check for duplicate command
    for (size_t i = 0; i < mCommandCount; i++)
    {
        //printf("Command mCommands[%d].Name: %s, aName: %s\n", i, mCommands[i].Name, aName);
        if ( strcmp(mCommands[i].Name, aName) == 0)
        {
            ioShell()->printf("Warning: Command mCommands[i].Name %s == %s already registered. Skipping.\n", mCommands[i].Name, aName);
            return;
        }
    }
    
#if (MEMORY_TYPE == DYNAMIC_MEMORY)
    if (mCommands == NULL)
    {
        mCommandCapacity = SHELL_MIN_COMMAND;
        mCommands = malloc(mCommandCapacity * sizeof(ShellCommand_ts));
        if (mCommands == NULL)
        {
            ioShell()->printf("Error: Memory allocation failed.\n");
            return;
        }
        memset(mCommands, 0, mCommandCapacity * sizeof(ProtocolCommand_ts));
    }
    
    if (mCommandCount >= mCommandCapacity)
    {
        size_t newCapacity = mCommandCapacity + SHELL_MIN_COMMAND;
        ProtocolCommand_ts* newCommands = (ShellCommand_ts*) realloc(mCommands, newCapacity * sizeof(ShellCommand_ts));

        if (newCommands == NULL)
        {
            // Handle reallocation failure
            return;
        }

        mCommands = newCommands;
        memset(&mCommands[mCommandCapacity], 0, (newCapacity - mCommandCapacity) * sizeof(ShellCommand_ts));
        mCommandCapacity = newCapacity;
    }
#elif (MEMORY_TYPE == STATIC_MEMORY)
    if (mCommandCount >= SHELL_NUMBER_OF_COMMAND)
    {
        ioShell()->printf("Error: Maximum number of commands reached.\n");
        return;
    }
    else
#endif
    {
        mCommands[mCommandCount].Name = aName;
        mCommands[mCommandCount].Help = help_string;
        mCommands[mCommandCount].Handler = aHandler;
        mCommandCount++;
        ioShell()->printf("Info: command %s added.\n", aName);
    }
}
/*
void MockHandler(int argc, char *argv[]) {}
    
int main(int argc, char *argv[]) 
{
    
    uint8_t rxBuffer[10] = {0};
    size_t rxSize = sizeof(rxBuffer);
    uint8_t txBuffer[10] = {0};
    size_t txSize = sizeof(txBuffer);
    
    
    Shell_Register("help", "list all commands",  MockHandler);
    Shell_Register("?", "list all commands",     MockHandler);
    Shell_Register("quit", "quit execution", 	MockHandler);
    Shell_Register("info", "Version & Revision", MockHandler);

    for (size_t i = 0; i < 32; i++) 
    {
        char name[10];
        sprintf(name, "cmd%zu", i);
        Shell_Register(name, "A command", MockHandler);
    }

    for(size_t i = 0; i< 32;i++)
    {
        printf("Command mCommands[i].Name: %s\n", mCommands[i].Name );
    }


    for(size_t i = 0; i< 32;i++)
    {
        
        if (mCommands[i].Handler != NULL)
        {
            mCommands[i].Handler(0,0);
        }
        else
        {
            printf("Error: No commands registered or handler is NULL.\n");
        }
    }

#if (MEMORY_TYPE == DYNAMIC_MEMORY)
    // Free allocated memory
    free(mCommands);
#endif
    
    return 0;
}
*/