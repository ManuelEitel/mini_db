#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error_input.h"
#include "commands.h"
#include "STRUCTURE_PARAMETERS.h"


int main() {
    printf("MiniDB gestartet. Befehle: set <key> <value>, get <key>, exit\n");

    char input[MAX_INPUT_LEN];
    char command[MAX_COMMAND_LEN];
    char key_input[MAX_KEY_LEN];
    char value_input[MAX_VAL_LEN];
    
    while (1) {
        printf("> ");

        if (check_command(input, command, key_input, value_input) == CHECK_SKIP) {
            continue;  
        }

        if (strcmp(command, "set") == 0) {
            set_entry(key_input, value_input);
        }
        
        if (strcmp(command, "get") == 0) {
            get_entry(key_input);
        }
        

        if (strcmp(command, "exit") == 0) {
            break;
        }
        
        /*int result = handle_input(input);

        if (result == -1) {
            break;
        }*/

    }
    return 0;
}
