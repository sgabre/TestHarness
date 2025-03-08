#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "History.h"

#define MAX_COMMANDS 10
#define COMMAND_LENGTH 100

typedef struct {
    char commandHistory[MAX_COMMANDS][COMMAND_LENGTH];
    int head; // Points to the next position to write
    int current; // Points to the current command for navigation
} CommandHistory_t;

CommandHistory_t commandHistory = {.head = 0, .current = -1};


void History_addCommand(const char* command) 
{
    strncpy(commandHistory.commandHistory[commandHistory.head], command, COMMAND_LENGTH - 1);
    commandHistory.commandHistory[commandHistory.head][COMMAND_LENGTH - 1] = '\0'; // Ensure null-termination
    commandHistory.head = (commandHistory.head + 1) % MAX_COMMANDS; // Move head forward, wrap around if needed
    
    // Set current to the latest command index
    commandHistory.current = commandHistory.head == 0 ? MAX_COMMANDS - 1 : commandHistory.head - 1;
}

const char* History_GetPreviousCommand() 
{
    {
        if (commandHistory.current == -1) 
        {
            return NULL; // No commands in history
        }
        
        const char* command = commandHistory.commandHistory[commandHistory.current];
        
        // Move to the previous command, wrapping around
        commandHistory.current = (commandHistory.current - 1 + MAX_COMMANDS) % MAX_COMMANDS;
        
        return command;
    }
}

const char* History_GetNextCommand() 
{
    if (commandHistory.current == -1) 
    {
        return NULL; // No commands in history
    }
    
    // Move to the next command
    commandHistory.current = (commandHistory.current + 1) % MAX_COMMANDS;
    
    // Check if we have wrapped around
    if (commandHistory.current == commandHistory.head) {
        return NULL; // Reached the end of the history
    }
    
    return commandHistory.commandHistory[commandHistory.current];
}