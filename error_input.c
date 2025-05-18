#include <stdio.h>
#include <string.h>
#include "error_input.h"



void clear_input_buffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Eingabe bis zum Zeilenende verwerfen
    }
}

int check_command(char *input, char *command, char *key_input, char *val_input){

    if (fgets(input, MAX_LINE_LEN, stdin) == NULL){
        return -1;
    }

    if (strchr(input, '\n') == NULL) {
        printf("Zu lange Eingabe. Erlaubt sind maximal %int Zeichen.\n", MAX_LINE_LEN);
        clear_input_buffer();
        return -1;
    }
   
    input[strcspn(input,"\n")] = '\0';
    
    static char buffer[MAX_LINE_LEN];
    strncpy(buffer, input, MAX_LINE_LEN - 1);
    buffer[MAX_LINE_LEN - 1] = '\0';
    
    char *token = strtok(buffer, " ");
    if (token != NULL) {
        strncpy(command, token, MAX_COMMAND_LEN - 1);
        command[MAX_COMMAND_LEN - 1] = '\0';
    } else {
        command[0] = '\0';
    }

    token = strtok(NULL, " ");
    if (token != NULL) {
        strncpy(key_input, token, MAX_KEY_LEN - 1);
        key_input[MAX_KEY_LEN - 1] = '\0';
    } else {
        key_input[0] = '\0';
    }

    token = strtok(NULL, "");
    
    if (token != NULL) {
        strncpy(val_input, token, MAX_VAL_LEN - 1);
        val_input[MAX_VAL_LEN - 1] = '\0';
    } else {
        val_input[0] = '\0';
    }
    return 0;
}
