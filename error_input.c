#include <stdio.h>
#include <string.h>
#include "error_input.h"
#include "STRUCTURE_PARAMETERS.h"



void clear_input_buffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Eingabe bis zum Zeilenende verwerfen
    }
}

int read_input(char *input, int max_len) {
     if (fgets(input, max_len, stdin) == NULL){
        return CHECK_SKIP;
    }

    if (strchr(input, '\n') == NULL) {
        printf("Zu lange Eingabe. Erlaubt sind maximal %d Zeichen.\n", MAX_LINE_LEN);
        clear_input_buffer();
        return CHECK_SKIP;
    }
    return CHECK_OK;
}

int parse_command(const char *token, char *command) {
    if (token != NULL) {
        if (strlen(token) >= MAX_COMMAND_LEN) {
            printf("Command too long - aborted\n");
            return CHECK_SKIP;
        }
        
        strncpy(command, token, MAX_COMMAND_LEN - 1);
        command[MAX_COMMAND_LEN - 1] = '\0';
        return CHECK_OK;
    } else {
        command[0] = '\0';
        printf("Insert command not null!\n");
        return CHECK_SKIP;
    }
}

int parse_key(const char *token, char *key_input) {
     if (token != NULL) {
        
        if (strlen(token) >= MAX_KEY_LEN) {
            printf("Key too long - aborted\n");
            return CHECK_SKIP;
        }

        strncpy(key_input, token, MAX_KEY_LEN - 1);
        key_input[MAX_KEY_LEN - 1] = '\0';
        return CHECK_OK;  
    } else {
        key_input[0] = '\0';
        return CHECK_OK;
    }
}

int parse_value(const char *token, char *val_input) {//why const char?
 
    if (token != NULL) {
        
        if (strlen(token) >= MAX_VAL_LEN) {
            printf("Value too long - aborted\n");
            return CHECK_SKIP;
        }

        strncpy(val_input, token, MAX_VAL_LEN - 1);
        val_input[MAX_VAL_LEN - 1] = '\0';
        return CHECK_OK;
    } else {
        val_input[0] = '\0';
        return CHECK_OK;
    }
}


int check_command(char *input, char *command, char *key_input, char *val_input){

    if (read_input(input, MAX_INPUT_LEN) == CHECK_SKIP)
        return CHECK_SKIP; 

    input[strcspn(input,"\n")] = '\0'; 
    
    static char buffer[MAX_INPUT_LEN];
    strncpy(buffer, input, MAX_LINE_LEN - 1);
    buffer[MAX_LINE_LEN - 1] = '\0'; 

    char *token = strtok(buffer, " ");
    if (parse_command(token, command) == CHECK_SKIP)
        return CHECK_SKIP;

    token = strtok(NULL, " ");
    if (parse_key(token, key_input) == CHECK_SKIP)
        return CHECK_SKIP;

    token = strtok(NULL, "");
    if (parse_value(token, val_input) == CHECK_SKIP)
        return CHECK_SKIP;

    return CHECK_OK;
}
