# 42_get_next_line

Reading a line on a fd is way too tedious. 
get_next_line reads a line on the file descriptor(fd) and returns it.

## Should do 
- return read line on success; return NULL if nothing to read or error
- libft is not allowed, needed functions will be contain in allowed .c files
- Must compile with flag *-D BUFFER_SIZE=xx* (see below)

`gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.`
- `read()` must use the *BUFFER_SIZE* defined during compilation to read from a file or stdin
- `lseek()` not allowed. File reading must only done once? 
- undefined behavior 
	- if the fd switches to a different file before reading everything from the first fd. (due to the the change of file position)
	- when reading from binary file. However, if you wish, you can make this behavior coherent
- Global variables are forbidden
- IMPORTANT: return the line that has been read followed by a '\n' unless EOF

> Does your function still work if BUFFER_SIZE is 9999, 1, 10000000? Why?

> Read each char one by one, to find '\n'

> TEST!

## Bonus part
- Make get_next_line with a single static variable
- Manage multiple fd, able to read from multiple fd and switch around without losing the reading thread on each fd.
(I did not do, rumors said its undoable)
## gcc Flags
D : defines a macro to be used by the preprocessor.
```
$ gcc -D name [options] [source files] [-o output file]  
$ gcc -D name=definition* [options] [source files] [-o output file]
```
g : Produce debugging information in the operating system’s native format (stabs, COFF, XCOFF, or DWARF). GDB can work with this debugging information.
```
$ gcc -g $(CFLAGS) -D BUFFER_SIZE=42 *.c && $(VALGRIND) ./a.out
```
For Valgrind(mentioned in link[1] below) and VScode debugger(did not figure out how to build in vsc, so I just use make to compile and run with debugger)
For Valgrind, mentioned in [link][1] below, and VScode debugger(did not figure out how to build in vsc, so I just use make to compile and run with debugger)
## Struggles
Encountered a lot new valgrind error messages, just CtrlC + CtrlV them onto google, debugging them helped fix my initial code that didn't work. I also try to do my code as compact and readable.

## Tester
[Tripouille/gnlTester: Tester for the get_next_line project of 42 school (github.com)](https://github.com/Tripouille/gnlTester)
Encountered a lot new valgrind error messages, just CtrlC + CtrlV them onto google, debugging them helped fix my initial code that didn't work.

## References
[What is a File Descriptor? (computerhope.com)](https://www.computerhope.com/jargon/f/file-descriptor.htm)

https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/

[Reading from file using read()](https://stackoverflow.com/questions/19769542/reading-from-file-using-read-function)

[Read Binary File in C | Delft Stack](https://www.delftstack.com/howto/c/read-binary-file-in-c/)

[Answer: How to Run Valgrind](https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks)

[Debug : Understanding Valgrind’s messages](https://epitech-2022-technical-documentation.readthedocs.io/en/latest/valgrind.html)


[1]:https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks
