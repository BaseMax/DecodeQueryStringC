# Decode Query String Using C

A tiny library for decode query string using c with utf8 support and html entities.

# Using

```c
decodeUrl(destination,source);
decodeHtmlEntities(destination,source);
```

### Functions

```c
void decodeUrl(char *destination,const char *source);
size_t decodeHtmlEntities(char *destination,const char *source);
// char *urlDecode(const char *str);
// static inline char toUpper(char c);
static int parseEntity(const char *current,char **to,const char **from);
static size_t putUtf8Char(unsigned long value,char *buffer);
static const char *getNamedEntity(const char *name);
static int stringCompare(const void *key,const void *value);
```

### Global Variable

```
// const char asciiHex[23] = {...};
static const char *const NamedEntities[][2] = {...};
```

## Example I/O

```
Input: HELLO%2C+%26%231587%3B%26%231604%3B%26%231575%3B%26%231605%3B+%2C+%26%231777%3B%26%231778%3B%26%231779%3B
Output: HELLO, سلام , ۱۲۳
```

## Copyright

Many resources have been used to implement this library. (Eg NamedEntities, ...)

Also, some of the code has been follow from certain libraries.

So, if you use this complete library, keep the author's name.

