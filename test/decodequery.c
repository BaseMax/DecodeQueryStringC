/**
*
* @Name : DecodeQueryTest.c
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-03-09
* @Released under : https://github.com/BaseMax/DecodeQueryStringC/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/DecodeQueryStringC
*
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../source/decodequery.h"

char *execute(const char *input) {
	char *temp=malloc(sizeof(char)*200);
	strcpy(temp,input);
	decodeUrl(temp,temp);
	return temp;
}
int main() {
	assert(strcmp(execute("a+b"),"a b") == 0);
	assert(strcmp(execute("a+ b"),"a  b") == 0);
	return 0;
}
