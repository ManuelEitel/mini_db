# The small txt-file based mini_db
This is a small CLI programm written in C for storation of small bits of information.
When I need to write something down real quick, then I want to be able to just dump that bit of information somewhere. 
Thus this tool was created. 

## How does it work?
I have set it up with an alias, so I can quickly open the program and then do my small notes. I did not want this to become too big, but if you want to add usage to it, feel free to.
```bash
> manuel@fedora:~$ mini_db
> MiniDB gestartet. Befehle: set <key> <value>, get <key>, listall, delete <id>, exit
> set birthday_gift_idea piece of wood for easy reading on garden chair
```

## Commands
```bash
manuel@fedora: mini_db
MiniDB gestartet. Befehle: set <key> <value>, get <key>, listall, delete <id>, exit
> set name manuel
> set name anton
> get name
+-----+----------------+
| ID  | VALUE          |
+-----+----------------+
| 001 | manuel        
| 002 | anton         
+-----+----------------+
> listall
+-----+--------+-------------------------
| ID  | KEY    | VALUE
+-----+--------+-------------------------
| 001 | name   | manuel
| 002 | name   | anton
+-----+--------+-------------------------
> set name wrongname
> listall
+-----+--------+-------------------------
| ID  | KEY    | VALUE
+-----+--------+-------------------------
| 001 | name   | manuel
| 002 | name   | anton
| 003 | name   | wrongname
+-----+--------+-------------------------
> delete 3
Deleted entry: ID 003 | name = wrongname
> listall
+-----+--------+-------------------------
| ID  | KEY    | VALUE
+-----+--------+-------------------------
| 001 | name   | manuel
| 002 | name   | anton
+-----+--------+-------------------------
> exit
```


### What is not allowed?
- Keys can only be 20 chars. If you want to change that, you can go into the STRUCTURE_PARAMETERS.h file and change the MAX_VAL_LEN. I personally wanted this whole programm small.
- The Values can only be 123 chars. You can fix this in the STRUCTURE_PARAMETERS.h file with the value MAX_VAL_LEN. Again, I wanted a small tool to work quickly with! It escalades otherwise.
- The symbol/char " is not allowed in the key, or value, since that is how I differentiate key and values. That is the only thing, that I don't check for. You can try to break the programm in any other way and I think I got all the possible errors. (Tell me, if you found a way to break the programm - I would be interested.)

### Here is my alias
Copy this:
> alias 'mini_db'='~/[[INSERT PATH TO PROJECT]]/mini_db'

I have put this into my .sourcerc file and then run this to update the bashrc file.

> source ~/.bashrc

# Notes
This is a small CLI programm to store quick infos. This is not ment to be an actual db replacement. 
I am very often inside the CMD, so I needed a tool to write stuff down real quick without opening another textfile all the time and anywhere.
When I wrote this, I wanted it to be quick, but later on I've decided to add the deletion method in a dirty way, where I am not fast at all. I might change that, but for my needs it fits very well.

I do like this, because it is an easy C programm that did not use many different C libraries. It still has some fairly quick methods to browse through the db.txt file, expecially set_entry and it's dependend methods. 

If you fork this, feel free to contact me in this hub. 
Best Regards
Manuel Eitel

