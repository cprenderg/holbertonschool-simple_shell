# Integration Project: Simple Shell
Directory for Integration Project: Simple Shell at Holberton completed by Chris & Felix.
## Header file 
[main.h](./main.h)
## Compiler
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Project File Table 
The following files are included in this project:

| File      | Description |
|---------- |-------------|
| [main.c](./main.c)	|The main function for the simple shell	|
| [cd_func.c](./cd_func.c)          | Changes directory in shell            |
| [exit_func.c](./exit_func.c)	|	Called when the user enters "Exit" to exit the shell| 
| [free_history.c](./free_history.c)          | Frees the history list            |
| [function_search.c](./function_search.c)          | Checks to see if a function can be accessed and forks a process           |
| [get_arg.c](./get_argc.c)          | Returns the amount of arguments from user input            |
| [get_argv.c](./get_argv.c)          | Returns a pointer to a list of strings created from user input            |
|[_getenv.c](./_getenv)	|Returns the value of an the environment variable	|
| [getline_reader.c](./getline_reader.c)          | Returns a string of user input            |
| [handle_condition.c](./handle_condition.c)	|Handles commands with "&" and " \| "	|
| [handle_input.c](./handle_user_input.c)	| Handles all user input, passing it to the correct function	|
| [history_func.c](./history_func.c)           | Adds a user input as a new node in a historylist_t struct            |
| [path_execution.c](./path_execution.c)| Checks and executes a program when the user entered the path|
| [print_banner.c](./print_banner.c)          | Prints the welcome banner on start            |
| [print_history.c](./print_history.c)          | Prints the history of all user input            |
|[_strdup.c](./_strdup.c)	| Copies and mallocs a string	|
|[_strtok.c](./_strtok.c)	| Tokenizes a string	|


## Known limitations
* If you attempt to cd with no parameters and OLDPWD is home, it will print the home directory.
## Advantages
* Welcomes you with a cool banner when you start the shell in interactive mode
