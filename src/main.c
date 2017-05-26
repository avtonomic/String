#include <stdio.h>
#include "function.h"

int main()
{
	char string[MAX_PATH];
	int i = 0;

	input(string);

	if(check(string) > 0 && (i = process(string)) == -3) {
		output(i, string);
	} else {
		if((i = check(string)) != 0) {
			output(i, string);
		} else {
			if((i = process(string)) != 0) {
				output(i, string);
			} else output(0, string);
		}
	}


	return 0;
}