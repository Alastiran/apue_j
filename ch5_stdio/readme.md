# ch5 Standard I/O Library

## Buffering
1. Fully buffered
  - malloc to obtain
  - flush to write
2. Line buffered
  - perform I/O on encountering newline
  - frequently used on streams refering to terminals (stdin, stdout)
  - buffer size is fixed
  - whenever data read from kernel, all line-buffered streams flushed
3. unbuffered
  - use a function (e.g. fputs) and expect output ASAP

### ISO C Reqs
1. std i/o fully buffered ONLY when non-interactive devic# ch5 Standard I/O Library
2. All other streams are line-buffered for terminals, otherwise FULLY buffered
3. By Concention, stderror norally unbuffered

### Buffering Functions
Must call After opening the strream, but before other operations

`#include <stdio.h>`

1. `void setbuf(FILE *restrict fp, char *restrict buf)`
  - buf = BUFSIZ length pointer? -> fully buffered on
  - buf = NULL? -> buffering off
2. `int setvbuf(FILE *restict, char *restrict buf, int mode, size_t size)`
  - mode = (_IOFBF, _IOLBF, _IONBF)_
  - allows full specification for buffering
3. `int fflush (FILE *fp)`
  - inputs
    - fp : stream file pointer to flush. if NULL, flush all output streams
  - returns
    - 0: ok
    - EOF: error

## Open a Stream, Close a Stream
`#include <stdio.h>`

1. `FILE *fopen(const char *restrict pathname, const char *restrict type)`
  - open specified file
2. `FILE *freopen(const char *restrict pathname, const char *restrict type, FILE *restrict fp)`
  - open specified file on specified stream. clears previous orientation
3. `FILE *fdopen(int filedes, const char *type)`
  - associates file descriptor with standard i/o stream
  - type specifies : read | write | rw | truncate-> write ,etc
4. `int fclose(FILE *fp)`
  - auto-flush any buffered data
  - discard buffered input 

## Reading and Writing Streams
### Character at a time
`include <stdio.h>`
Return next character as /unsigned char/ converted to /int/. 
EOF or error is same value, therefore, call check functions to confirm.

1. `int getc(FILE *fp)`
2. `int fgetc(FILE *fp)`
  - guaranteed to be a function, therefore can get it's address
  - usually slower than getc because function calls slower
3. `int getchar(void)`
  - same as getc, get getc can be macro, Therefore:
    - getc args can not be function with side effects

#### check functions
Return nonzero if condition true, 0 if false

1. `int ferror(FILE *fp)`
2. `int feof(FILE *fp)`
3. `void clearerr(FILE *fp)`
  - clear flags associated with a stream

### Push onto stream (after reading)
1. `int ungetc(int c, FILE *fp)`

Characters pushed back do not go to disk/device. They stay incore in std i/o buffer for the stream.

### Output
1. `int putc(int c, FILE *fp)`
  - can be implemented as a macro
2. `int fputc(int c, FILE *fp)`
3. `int putchar(int c)`
  - same as putc

### Line at-a-Time I/O
1. `char *fgets(char *restrict buf, int n, FILE *restrict fp)`
  - specify size of buffer, n
  - read n - 1 characters into buffer, terminate with null byte
2. `char *gets(char *buf)`
  - always from standard in
  - neveruse, buffer overflow risk
3. `int fputs(const char *restrict str, FILE *restrict fp)`
  - terminate str w/ null before putting in as argument
4. `int puts(const char *str)`

As a rule using fgets and fputs allows a consistent, easy to handle style for dealing 
w/ newlines.

### Binary I/O
To read entire structures, which may have null bytes, etc in them. fgets/fputs not very suitable.
Therefore, use:
1. `fread(void *restrict ptr, size_t size, size_t nobj, FILE *restrict fp)`
2. `fwrite(void *restrict ptr, size_t size, size_t nobj, FILE *restrict fp)`

### Positioning in a Stream
1. `long ftell(FILE *fp)`
2. `long fseek(FILE *fp, long offset, int whence)`
3. `void rewind(FILE *fp)`
4. `off_t ftello(FILE *fp)`
5. `int fseeko(FILE *fp, off_t offset, int whence)`
6. `int fgetpos(FILE *restrict fp, fpos_t *restrict pos)`
7. `int fsetpos(FILE *fp, const fpos_t *pos)`

### Formatted Output
Use the 4 variations of the printf function
The first two write directly to files

1. printf : always to stdout
2. fprintf : to the fp specified
3. sprintf : write to string buffer, but may buffer overflow if supplied long string
4. snprintf : write to string buffer and throw bytes that would make overflow

#### Formatted Output w/ variable length arg list
4 variations of vprintf
`include <stdarg.h>`
1. vprintf
2. vfprintf
3. vsprintf
4. vsnprintf

### Formatted Input
3 variations on scanf
1. scanf
2. fsanf
3. sscanf

#### Formatted Input w/ variable length arg list
1. vscanf
2. vfscanf
3. vsscanf

### Temporary Files
1. `char *tmpnam(char *ptr)`
2. `FILE *tmpfile(void)`


### Restrictions 
1. when using r+, w+ (both input/outputallowed)
  - output cannot follow input w/o fflush, fseek, fsetpos, rewind
  - input cannot follow output w/o fseek, fsetpos, rewind

## Exercises
1. see "setbuf_using_setvbuf"
2. see effeciency_check_by_line.c
  fgets reads up to and including newline. fputs writes until null byte. Therefore,
  they don't care about buffer size, but keep making calls until the correct 
  character is enountered. (newline or nullbyte)
3. fprintf returns 0 when no characters stored in the array
  printf returns 0 when no characters output
  see check_print

4. if unsigned characters are used, comparing to EOF fails and loop never terminates
5. 5 prefix length is due to historical conditions.
  4 char per process identifier
  5 character per system identifer (process id)
  5 character prefix
  = 14 chars, original limit on pathname length

6. If we image 3 levels of storage: a) in memory buffer b) kernel buffer c) disk
  then, we use stdio and fsync as follows
  1) write out of my app using stio output function, i.e.e fputs -> (a) now in memory buffer 
  2) flush out of memory and to kernel, using fflush    (a) --> fflush --> (b)
  3) sync from kernel buffers to disk using fsync (b) -- > fsync --> (c)

7. stdin and stdout line buffered when run interactively (i.e. terminal).
  Therefore, when fgets is called, stdout is flushed. This must be because they are connected 
  to same terminal. Therefore, fgets calls and then blocks until it receives input.
  
(Aside note: therefore, all those loops that have while(fgets(buf, size, ...) != EOF)
must rely on the function contract of fgets to block until it receives a an appropriate signal (i.e. newline)
