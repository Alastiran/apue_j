# Process Control

## Essential Primitives of process control
fork -> exec -> wait -> exit

## Start Proceses
1. fork
2. vfork

Nearly the same function, except for the ways in which they are used. 
Forking a process means creating a /child/ process, which starts sharing much of the
same state as the parent, but then evolves independently. It also carries it's own process id.

Reasons to use forking include
1. multi-tasking. A common example is networking. Parent waits for request to come in, 
child handles requests as they come.
2. Spawning new processes via fork -> exec combo.

## Get results from child processes
1. wait
2. waitpid

waitpid is a more tuneable version of wait, that allows non-blocking checking of a child's resolution status. When children quit, they send SIGCHILD to parent, but default is to ignore it until we check with a wait() function.

## Terminate child processes
use `_exit`, instead of `exit`, it seems to not have so many problems re: cleaning up i/o 
and mistakenly resetting buffers

## Starting different Processes (executable binaries)
The 'exec' family of functions provides several varieties of how to call another process. 
The process called in such a manner replaces the process that did the exec -- the new
process takes over text space, data space, stack space, etc. but retains the PID of 
the process that called exec.

1. `execl`
2. `execv`
3. `execle`
4. `execlp`
5. `execvp`

The functions differ in how they pass arguments and environment variables. 
the ones with 'p' use filename arguments (not path, I know, worst naming /ever/)

```
execvp --> execv --> execve       execve is usually the only system call
 ^          ^           ^
execlp     execl     execle
```
