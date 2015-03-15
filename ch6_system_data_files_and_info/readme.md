## Password / Shadow
 `#include <pwd.h>`
1. `struct passwd *getpwuid(uid_t uid)`
2. `struct passwd *getpwnam(const char *name)`

### Shadow
`#include <shadow.h>`

1. `struct spwd *getspnam(const char *name)`
2. `struct spwd *getspent (void)`
3. `void setspent(void)`
4. `coid endspent(void)`

## System Identification
`#include <sys/utsname.h>`

1. `int uname(struct utsname *name)`
2. 
```
struct utsname {
  char sysname[];
  char nodename[];
  char release[];
  char varsion[];
  char machine[];
};
```
3. `int gethostname(char *name, int namelen)`

## Time and Date
`#include <time.h>`

1. `time_t time(time_t *calptr)`

`#include <sys/time.h>`
2. `int gettimeofday(struct timeval *restrict tp, void *restrict tzp)`
3. 
```
struct timeval {
  time_t tv_sec;
  long   tv_usec;
};
```
4. `struct tm *gmtime(const time_t *calptr)`
5. `struct tm *localtime(const time_t *calptr)`
6. `time_t mktime(struct tm *tmptr)`
7. `char *asctime(const struct tm *tmptr)`
8. `char *ctime(const time_t *calptr)`
9. `size_tstrftime(char *restrict buf, size_t maxsize, const char *restrict format,
                   const struct tm *restrict tmptr)`
10.
```
struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdt;
};
```

### Exercises
1. You have to look at the shadow file. It's implementation dependent, but a good starting place is /etc/shadow
  Look for the username:password combo ofthe username you're looking for
2. no /etc/shadow on OSX, but if there were, I would get my username (`whoami`), and then use that as input to `getspnam(<my_username>)`
3. see print_uname.c
4. time_t is a signed int, therefore 2^31 - 1 seconds. => 1938, Feb 5 around 3AM
  when it loops, the numbers will be be negative and threfore substracted from 1970
5. 

