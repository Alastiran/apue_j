# Process Environment

## start-up and shutdown processes
### startup
1. `int main(int argc, char *argv[])`
2. pass args via kernel, which takes from...
  1. command-line arguments
  2. environment variables

### Setting up memory
1. `void *malloc(size_t size)` : allocate specific bytes of memory
2. `void *calloc(size_t nobj, size_t size)` : allocate space for n objects of spec'd size
3. `void *realloc(void *ptr, size_t newsize)` : reallocate previously alloted area
4. `void *free(void *ptr)`

### Standard terminations 
1. return from main
2. calling exit
3. calling _exit or _Exit
4. return of the last thread from start routine
5. calling pthread_exit from last thread

### abnormal terms
1. calling abort
2. receipt of signal
3. last thread responds to cancellation request

### Termination Functions
1. `int exit(in status)`: process cleanup then exit
2. `_exit(int status)`: immediately exit to kernel
3. `_Exit(int status)`: immediately exit to kernel

### Exit Handlers
functions automatically called by exit when process exits
called in reverse order (last reg'd first called)

1. `int atexit(void (*func) (void))` : register exit handlers

## Environment
global variable that holds pointer to array of character pointers
`extern char **environ`

environ -> environment list -> environment strings
environment list: [1], [2], [3], etc... [NULL]
environment strings: name=value, i.e. HOME=/home/sar\0

### access functions
1. `char *getenv(const char *name)` : get pointer to string of name
2. `int putenv(char *str)` : takes pointer to string of form "name=value" and puts on env
3. `int setenv(const char *name, const char *value, int rewrite)`
4. `int unsetenv(const char *name)`

## Memory Layout of C program
1. text segment, where instructions are
2. initialized data segment, w/ variable declarations
3. unitialized data segment = "bss"
4. stack; automatic variables and information saved each tiem function called
5. heap; dynamic memory allocation

## Navigating a program non-locally
use setjmp to establish a place to anchor, and then longjmp to it w/ varying return values
to judge where you came from! stacks in-between are discarded
1. `int setjmp(jmp_bug env)` : call from location we want to return to
2. `void longjmp(jmp_buf env, int val)` 

## Altering the limits of a program
1. `int getrlimit(int resource, struct rlimit *rlptr)` : get limit of resource specified
2. `int setrlimit(int resource, const struct rlimit *rlptr)` : set limit of specified resource

```
struct rlimit {
  rlim_t rlim_cur;
  rlim_t rlim_max;
}
```

## Exercises
1. 13? is what printf returns
2. stdout has line buffering ... so print line by line (when you log newline for next line)
  but files have whole-buffering, so probably not until i/o cleanup (after all exit-handlers)
3. can we see args without using argc, argv or environ? --> NO!
  (my thoughts were correct)
4. Good for terminating when a null ointer is dereferenced
5. current progress is here

### Inspect a compiled program
1. `size` : print size of sections in object (compiled c program) file

## Shared Libraries
1. reduce executable size, share code among several programs
2. upgrade library without relinking all the code that uses it!


