# ch 3 File I/O

## File Descriptors vocab
1. file descriptor
  positive interger in process table that allows process to talk with kernel about a path
  has pathname and behavior flags
2. process table
  A table maintained by a process that stores file descriptors so that a process can talk to other files, process, etc
  maintains:
    - file descriptor
    - fd flags (http://www.gnu.org/software/libc/manual/html_node/Descriptor-Flags.html)
      - currently only FD_CLOEXEC
    - file pointer
3. File table
  Allocated per process, but kept in kernel space
  For each file, maintains:
    - file status flags
      - read only, write only, read/write etc.
    - current file offset
    - v-node pointer
4. v-node
  an object in KERNEL memory that speaks UNIX file interface (the fxns below)
5. v-node table
  the table of v-nodes the kernel is tracking
  for each v-node maintains:
    - v-node information
    - i-node information
    - current file size

## Key Commands in I/O
1. open (const char \*pathname, int oflag, ... / modet /)
  oflag = ORDONLY | OWRONLY | ORDWR
2. creat
3. close
4. off_t lseek (int filedes, off_t offset, int whence) : set the offset explicitly
5. read
6. ssize_t write(int filedes, const void \*buf, size_t nbytes)

## Efficiency

## Atomic Operations
### Key Commands in Atomic Operations
1. dup (int filedes) : duplicate existing file descriptor
2. dup2 (int filedes, int filedes2) : dplicate existing file descriptor
3. sync
4. fsync
5. fdatasync
6. fcntl : change properties of a file that is currently open
7. ioctl
8. pwrite (int filedes, void \*buf, size_t nbytes, offset_t offset)
9. pread

## Exercises

1. are these functions really unbuffered?
  No. They all have to make requests to the kernel, which judges how to handle from there.
  CORRECT!
  the kernel mantains it's own buffer, /kernel buffer cache/. 
  unbuffered IO means the automatic in-user-process buffering is disabled, and each read/write
    corresponds directly to a system call

2.  no answer yet

3. my picture was correct. 
  open creates new file table entries. dup does not.
  SET_FD sets file descriptor flags, therefore only fd1 affected
  SET_FL sets file status flags, therefore fd1 and fd2 affected
    
4. basically correct, dup2 understanding increased

5. correct

6. read w/ anywhere using lseek? yes!
   use lseek to replace existing data? 
    if use write? no
    if use pwrite? yes

