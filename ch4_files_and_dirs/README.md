# ch 4 Files and Directories

## vocab:
1. inode: contains all information about a file. 
  1. type
  2. access permission bits
  3. size of file
  4. pointer to data blocks
2. directory : stores lists of {inode: filename} pairs

## Functions to examine files

1. `int stat(const char *restrict pathname, struct stat *restrict buf)` 
info on opened path
2. `int fstat(int fildes, struct stat *buf)` 
info on opened file
3. `int lstat(const char *restrict pathname, struct stat *restrict buf)`
same as stat, but doesn't follow symlinks

## struct stat
```
struct stat {
  mode_t  st_mode; // file access permissions
  ino_t   st_ino; // the inode number
  dev_t   st_dev;
  dev_t   st_rdev;
  nlink_t st_nlink;
  uid_t   st_uid;
  gip_t   st_gid;
  off_t   st_size; // file size in bytes
  time_t  st_atime;
  time_t  st_mtime;
  time_t  st_ctime;
  blksize_t st_blksize;
  blkcnt_t  st_blocks;
};
```

## file types
1. regular file
2. directory file
3. device types
  1. block special file : provides buffered i/o in fixed size units to devices
  2. character special file: unbuffered i/o in variable sized units to devices
4. FIFO, a named pipe used for communication between processes
5. Socket
  file for network comunication
7. symbolic link: file that points to another file

## Permissions / Ownership

### commands
1. `access(const char *pathname, int mode)`
test access based on real user and group ids
  i. filename
  ii. mode to test (read / write etc.)
2. `mode_t umask(mode_t cmask)`
  set file mode creation_mask for process, returns previous value
  the mask describes which permissions are OFF when creating a file
3. `int chmod(const char *pathname, mode_t mode)`  
  man 2 chmod
  change for unopened files
4. `int fchmod(int filedes, mode_t mode)`
  man 2 fchmod
  change for opened files
5. chown
6. fchown
7. lchown

## File Systems
### description
Every file system has MAJOR, MINOR device numbers encoded as dev_t
major: device driver
minor: specific subdevice
### varieties
1. UFS unix file system
2. PDFS read adn write DOS-formatted
3. HSFS for CD file systems

### filesystem navigation command
1. mkdir
2. rmdir
3. chdir
4. fchdir
5. getcwd

### disk drive
disk: partition | partition | partition

partition: filesystem = boot_block(s) | super block | cynlinder group 0..n

cynlinder group: super block copy | cg info | i-node map | block bitmap | inodes | data,directory  blocks

i-node: data_block 0..n

directory block: inode | filename

## Move / delete files
### commands
1. `link(existing_path, newpath)`
  create (hard) link for existing file
2. `unlink(const char *pathname)`
  remove an existing directory entry (could be directory or file)
3. remove
4. rename
5. symlink
6. `readlink(pathname, buf, bufsize)`
  opens symbolic links, allowing us to read the name of the file referenced!
7. `truncate(const char *pathname, off_t length)`
  chop off specified file length (in bytes) from end of file)
8. ftruncate

## file times
### commands
1. utime(pathname, const struct utimebuf \*times)
  control access and modification time of file


## Exercises

1. become unable to detect symbolic links.. left with..? whatever the source_file type is
2. all permissions off
3. when not root... it certainly does!
4. creat and open don't mod existing file perms
5. no, 0 for dirs and symlink size not allowed
6. skip for now
7. shell and kernel have different umask, default perms!
8. yep, because df on file systems and du on files
9. if the file is ref'd by open process or has other links still existing, only ctime will change
10. when recursively descending, may hit max number of open descriptors
11. only briefly writing necessary fxns
```
chdir(pathname);
filename = path_alloc(&len);

strncopy(filename,pathname,len);
filename[len-1];

retval = dopath(func);

chdir("..");
return retval;
```
12. chroot is great for testing new software packages, and providing security...
  the root named can not be superceded by child processes!
13. use stat to get current value, supply that back to utime for the one we don't want to change
14. look at access (read), mod (received mail) times
17. unlink fails, but since we don't check error message, no problem.
  the creat will open a copy (as we want) and the program will proceed as planned
