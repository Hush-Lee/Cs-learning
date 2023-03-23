 ### XSI接口分组
 - 加密：由符号常量标记 *_XOPEN_CRYYPE*
 - 实时：由符号常量标记 *_XOPEN_REALTIME*
 - 高级实时
 - 实时线程：*_XOPEN_REALTIME_THREADS*
 - 高级实时线程
 - 跟踪
 - XSI STREAM:*_XOPEN_STREAM*
 - 遗留接口：*_XOPEN_LEGACY*

#### sysconf pathconf fpathconf
```cpp
#include<unistd.h>
long sysconf(int name);
long pathconf(const char *pathname,in name);
long fpathconf(int filedes,int name);
```

 