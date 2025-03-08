
#include <ctype.h>
#include <stdio.h>
#include <string.h>


#include "Shell.h"

#define SHELL_PROMPT "$> "


typedef struct Shell_ts 
{
    bool IsEnable;
} Shell_ts;

Shell_ts mShell;

void mShell_Prompt(void) 
{
    ioShell()->printf(SHELL_PROMPT);
}

const ShellCommand_ts* mShell_SearchCommand(const char *name) 
{
    if(name == NULL)
    {
        return NULL;
    }
    
    // Get the list of registered commands
    const ShellCommand_ts* commandList = Shell_Commands();
    size_t numCommands = Shell_Size();
    size_t nameLen = strlen(name);
    
    if ( (commandList == NULL) || (numCommands == 0)  )
    {
        return NULL;
    }
    
    // Search for a matching command
    for (size_t i = 0; i < numCommands; i++) 
    {
        if (commandList[i].Name == NULL) 
        {
            continue;  // Skip invalid entries
        }
        
        size_t cmdLen = strlen(commandList[i].Name);
        
        // Ensure the length matches before using memcmp
        if ( (cmdLen == nameLen) && (memcmp(commandList[i].Name, name, nameLen) == 0)  )
        {
            return &commandList[i];  // Found a match
        }    
    }
    
    return NULL;
}

int mShell_Gets(char* s, int len) 
{
    char* ptr = s;
    char c;
    
    *ptr = '\000';
    /* read until a <CR> is received */
    while ( (c = ioShell()->getchar() ) != '\n') 
    {
        if ((c == '\b') || (c == '\127')) 
        {
            if (ptr > s) 
            {
                /* send ^H ^H to erase previous character */
                ioShell()->printf("\b \b");
                ptr--;
            }
        } 
        else 
        {
            // Check for available space
            if ( (ptr - s) < (len - 1) )
            {
                *ptr = c;
                ioShell()->putchar(c);
                ptr++;
            }
        }
        
        /* update end of string with NUL */
        *ptr = '\000';
    }
    
    return ptr - s;
}

// Function to parse the input command
int mShell_ParseCommand(char* input, char *argv[], int maxArgs) 
{
    int argc = 0;
    char *token = NULL;
    char *saveptr = NULL;
    
    if (input == NULL) 
    {
        ioShell()->printf("Error invalid input\n");
        return argc;  // Early exit on error
    }
        
    if ( argv == NULL)      
    {
        ioShell()->printf("Error invalid argv\n");
        return argc;  // Early exit on error
    }
    
    // Tokenize the input string
    token = strtok_r(input, " \n", &saveptr);//
    while ( (token != NULL) && (argc < maxArgs) )
    {
        argv[argc++] = token;
        token = strtok_r(NULL, " \n", &saveptr);
    }
    
    if(argc < maxArgs)
    {
        argv[argc] = NULL; // Ensure NULL termination
    }
    return argc; // Return the number of arguments parsed
}


void Shell_Enable() 
{
    mShell.IsEnable = true;
}

void Shell_Disable() 
{
    mShell.IsEnable = false;
}

bool Shell_IsEnable() 
{
    return mShell.IsEnable;
}

void Shell_Handler(void)
{
    char buffer[128] ={0};
    int length = 0;
    char* argv[32] = {0};
    int argc = 0;
    
    
    mShell_Prompt();
    length = mShell_Gets(buffer, 128);
    
    if (length < 0) 
    {
        ioShell()->printf("Error reading input\n");
        return;  
    }

    // Use the ParseCommand function to get the arguments
    argc = mShell_ParseCommand(buffer, argv, 32);
    
    if (argc > 0) // Ensure there is at least one command
    {
        const ShellCommand_ts* command = mShell_SearchCommand(argv[0]);
        
        if (length != 0) 
        {
            if ( (command != NULL) && (command->Name != NULL) )
            {
                command->Handler(argc, argv);
            } 
            else 
            {
                ioShell()->printf("FAIL: unrecognized command\n");
            }
        }
    }
}

void Shell_Init(void)
{
    Shell_Enable();
}