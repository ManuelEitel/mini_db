#ifndef ERROR_INPUT_H
#define ERROR_INPUT_H

#include <stdio.h>
#define MAX_COMMAND_LEN 8
#define MAX_KEY_LEN     123
#define MAX_VAL_LEN     123
#define MAX_LINE_LEN    (MAX_COMMAND_LEN + MAX_KEY_LEN + MAX_VAL_LEN + 4)

void clear_input_buffer(void);
int check_command(char *input, char *command, char *key_input, char *val_input);

#endif

