#ifndef STRUCTURE_PARAMETERS_H
#define STRUCTURE_PARAMETERS_H

#define DB_FILE "/home/manuel/Projekte/C_Programme/05_my_database/db.txt"
#define MAX_COMMAND_LEN 8
#define MAX_KEY_LEN     20 
#define MAX_VAL_LEN     123
#define MAX_INPUT_LEN    (MAX_COMMAND_LEN + MAX_KEY_LEN + MAX_VAL_LEN + 4)
#define MAX_LINE_LEN (MAX_KEY_LEN + MAX_VAL_LEN + 2)

#define CHECK_SKIP 0 
#define CHECK_OK 1

#define CMD_EXIT -1
#define CMD_SKIP 0
#define CMD_OK 1

#endif
