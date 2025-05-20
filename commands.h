#ifndef COMMANDS_H
#define COMMANDS_H

int set_entry(const char *key, const char *value);
int get_entry(const char *key); 
int list_all_entries();
int delete_entry(int target_id); 

#endif

