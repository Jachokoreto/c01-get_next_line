# 42_get_next_line

Reading a line on a fd is way too tedious. 
get_next_line reads a line on the file descriptor(fd) and returns it.

## Should do 
- return read line on success; return NULL if nothing to read or error
- read from a file and standard input
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
`*(ft_strchr(buffer, '\n')) = 0;` I maybe over-reacting, but this worksss!!
## Bonus part
- Make get_next_line with a single static variable
- Manage multiple fd, able to read from multiple fd and switch around without losing the reading thread on each fd.
## gcc -D
D : defines a macro to be used by the preprocessor.
```
$ gcc -D name [options] [source files] [-o output file]  
$ gcc -D name=definition* [options] [source files] [-o output file]
```

## Tester
[Tripouille/gnlTester: Tester for the get_next_line project of 42 school (github.com)](https://github.com/Tripouille/gnlTester)

[GitHub - harm-smits/gnl-unit-test: A simple get next line unit tester (yizimg.com)](http://phoenix.yizimg.com/harm-smits/gnl-unit-test)

[Moulitest (awesomeopensource.com)](https://awesomeopensource.com/project/yyang42/moulitest)

## References
[What is a File Descriptor? (computerhope.com)](https://www.computerhope.com/jargon/f/file-descriptor.htm)

https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/

[Reading from file using read()](https://stackoverflow.com/questions/19769542/reading-from-file-using-read-function)

[Read Binary File in C | Delft Stack](https://www.delftstack.com/howto/c/read-binary-file-in-c/)