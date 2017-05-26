#include <stdio.h>
#include "strings.h"

int slen(char *string)
{
	int length = 0;

	while(*string != '\0') {
        length++;
        string++;
    }

    return length;
}

int sspn(char *string)
{
    char arr[] = {':', '*', '?', '"', '<', '>', '|'};
    int i, j, length_arr = slen(arr);
    for(i = 0; string[i] != '\0'; i++) {
        for(j = 0; j < length_arr; j++) {
            if(string[i] == arr[j]) {
                return i;
            }
        }
    }

    for (i = 1; string[i + 1] != '\0'; i++) {
    	if((string[i] == '/' && string[i + 1] == '\\')) {
    		return i;
    	}
    	if((string[i] == '\\' && string[i + 1] == '\\') || (string[i] == '\\' && string[i + 1] == '/')) {
    		return i + 1;
    	}
    }

    return 0;
}