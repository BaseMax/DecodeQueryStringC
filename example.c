/**
*
* @Name : Example.c
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-03-08
* @Released under : https://github.com/BaseMax/DecodeQueryStringC/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/DecodeQueryStringC
*
**/
#include "decodequery.h"
int main() {
    char *value=malloc(sizeof(char)*107*2);
    // A Sample text with utf8 character.
    strcpy(value,"HELLO%2C+%26%231587%3B%26%231604%3B%26%231575%3B%26%231605%3B+%2C+%26%231777%3B%26%231778%3B%26%231779%3B");
    printf("Input: %s\n",value);
    decodeUrl(value,value);
    decodeHtmlEntities(value,value);
    printf("Output: %s\n",value);
    return 0;
}
