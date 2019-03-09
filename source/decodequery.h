/**
*
* @Name : DecodeQuery.h
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-03-08
* @Released under : https://github.com/BaseMax/DecodeQueryStringC/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/DecodeQueryStringC
*
**/
#ifndef DECODE_QUERY
#define DECODE_QUERY

    #include <errno.h>  //errno
    #include <stdio.h>  //printf,memcpy,memmove
    #include <stdlib.h> //malloc,bsearch
    #include <string.h> //strcpy,strchr,strtoul,strncmp,strlen
    #include <ctype.h>  //isxdigit

    void decodeUrl(char *destination,const char *source);
	size_t decodeHtmlEntities(char *destination,const char *source);
	// char *urlDecode(const char *str);
	// static inline char toUpper(char c);
	static int parseEntity(const char *current,char **to,const char **from);
	static size_t putUtf8Char(unsigned long value,char *buffer);
	static const char *getNamedEntity(const char *name);
	static int stringCompareLength(const void *key,const void *value);

#endif
