# Bash
## Bourne Again Shell. Again.

The main goal of this project is to understand essence of Bash execution routines, including redirects handling
and pipelines betwen processes.
As is, this project consists of interpreter (lexer and parser) and ececutor.
This bash variation:

- Working History using readline built-in functionality.

- Can launch based on the PATH variable or by using relative or absolute path)
- Handles redirects (< , <<, >, >>) without any FD redirections (thus, 2> file wont redirect STDERR to a given file FD)
- Handles pipe and chains of pipe accordinglye (ls | grep . | wc, ls > file | wc, etc)
- Handles it's own "global" and local variables, $0 and $? commands
- Handles SIGINT, SIGQUIT and EOF signals accordingly, simulating original bash behaviour
- Single quotes (' ') inhibit all interpretation of a sequence of characters, double quotes(" ") inhibit all interpretation of a sequence of characters except for $.
 
 ![](.sh.gif)
 
This implementation has it's own built-in functions, such as 
- echo with option -n
- cd with only a relative or absolute path	
- pwd with no options
- export with no options
- unset with no options
- env with no options or arguments
- exit with no options

## Installation
	git clone https://github.com/hyonosake/bash && cd bash
Project requires Readline library installed.
```sh
brew install readline
```

When installed, you will need to make changes in LRD_LIB and LRD_INC flags in Makefile.
After that, call 
```sh
make -j8
```
> Makefile supports clean, fclean and re rules
