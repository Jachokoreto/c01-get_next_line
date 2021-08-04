# 42_get_next_line

Reading a line on a fd is way too tedious. 
get_next_line reads a line on the file descriptor(fd) and returns it.

## Should do 
- return read line on success; return NULL if nothing to read or error
- read from a file and standard input
- libft is not allowed
- [[#gcc -D | Must compile with flag *-D BUFFER_SIZE=xx* ]](see below)
	- `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.`
- `read` must use the *BUFFER_SIZE* defined during compilation to read from a file or stdin


## gcc -D
D : defines a macro to be used by the preprocessor.
```
$ gcc -D name [options] [source files] [-o output file]  
$ gcc -D name=definition* [options] [source files] [-o output file]
```

## read()



