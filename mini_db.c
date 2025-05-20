#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error_input.h"
#include "commands.h"
#include "STRUCTURE_PARAMETERS.h"

void get_entry(const char *key) {
    FILE *fp = fopen(DB_FILE, "r");
    if (!fp) {
        printf("Keine Datenbank gefunden.\n");
        return;
    }

    char line[MAX_INPUT_LEN];
    while (fgets(line, sizeof(line), fp)) {
        char current_key[MAX_KEY_LEN];
        char value[MAX_VAL_LEN];
        sscanf(line, "%[^:]:%[^\n]", current_key, value);

        if (strcmp(current_key, key) == 0) {
            printf("%s\n", value);
            fclose(fp);
            return;
        }
    }

    printf("Schlüssel '%s' nicht gefunden.\n", key);
    fclose(fp);
    return;
}


int check_key_value_for_length(const char *key, const char *value){
    if (key == NULL || value == NULL) {
        printf("Fehler: Key oder value ist null.\n");
    }
                
    if (strlen(key) >= MAX_KEY_LEN){
        printf("Key zu lang! Max %d Zeichen.\n", MAX_KEY_LEN - 1);
        return -1;
    }
    if (strlen(value) >= MAX_VAL_LEN){
        printf("Value zu lang! Max %d Zeichen.\n", MAX_VAL_LEN - 1);
        return -1;
    }
    return 0;
}

int parse_input(const char *input, char **command, char **key, char **value){
    static char buffer[MAX_INPUT_LEN];
    strncpy(buffer, input, MAX_INPUT_LEN - 1);
    buffer[MAX_LINE_LEN - 1] = '\0';

    *command = strtok(buffer, " ");
    *key     = strtok(NULL, " ");
    if (*value && strlen(*value) >= MAX_VAL_LEN) {
        printf("Value zu lang! Max %d Zeichen.\n", MAX_VAL_LEN - 1);
        return 0;
    }

    if (*command == NULL) return 0;
    
    if (*value == NULL && strcmp(*command, "set") == 0){
        if (*key == NULL || *value == NULL) {
            return 0;
        }
    }

    if (strcmp(*command, "get") == 0 && *key == NULL){
        return 0;
    }
    return 1;
}


int handle_input(const char *input){ 

    char *command, *key, *value;

    if(!parse_input(input, &command, &key, &value)){
        printf("Syntax!\n");
        printf(" set <key> <value>\n");
        printf(" get <key>\n");
        printf(" exit\n");
        return 1;
    }
        
    if (strcmp(command, "exit") == 0) {
        return -1;
    }

    if (strcmp(command, "get") == 0){
        get_entry (key);
        return 1;
    }

    if (strcmp(command, "set") == 0){
        if (check_key_value_for_length(key, value) == -1){
            return 1;
        }
        set_entry(key, value);
        return 1;
    }
    printf("Syntax!\n");
    return 1;
}


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

        printf("Command: '%s', Key: '%s', Value: '%s'\n", command, key_input, value_input);
        
        if (strcmp(command, "set") == 0) {
            set_entry(key_input, value_input);
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
