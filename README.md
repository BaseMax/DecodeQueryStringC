# Decode Query String Using C

A tiny library for decode query string using c with utf8 support and html entities.

# Using

```c
#include "urldecode.h"
int main() {
    char *value=malloc(sizeof(char)*107*2);
    strcpy(value,"HELLO%2C+%26%231587%3B%26%231604%3B%26%231575%3B%26%231605%3B+%2C+%26%231777%3B%26%231778%3B%26%231779%3B");
    decodeUrl(value,value);
    decodeHtmlEntities(value,value);
    printf("---> %s\n",value);
    return 0;
}
```

**`Output :`**
```
---> HELLO, سلام , ۱۲۳
```
