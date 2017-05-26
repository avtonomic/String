#include <stdio.h>
#include "function.h"
#include "strings.h"

void input(char *string)
{
	int i = 0;

    printf("Input path: ");
    while(scanf("%c", &string[i]) == 1 && i < MAX_PATH - 1) {
        if(string[i] == '\n') {
            string[i] = '\0';
            break;
        } else {
            i++;
        }
    }
}

int check(char *string)
{
    int length = slen(string);

    if(length > MAX_PATH) {
        return -1;
    }

    if(length == 0) {
        return -2;
    }

    if(sspn(string) > 0) {
        return sspn(string);
    }

    return 0;
}

int process(char *string)
{
    char array[4] = {'.', 'e', 'x', 'e'};
    int i = 0, slash_one_status = 0, slash_two_status = 0;

    while(string[i] != '\0') {
        if(string[i] == '\\') {
            slash_one_status = 1;
        }
        if(string[i] == '/') {
            slash_two_status = 1;
        }
        i++;
    }

    if(slash_one_status == 1 && slash_two_status == 1) {
        return -5;
    }

    if(string[0] != '\\' || string[1] != '\\') {
        return -3;
    }


    i = 0;

    while(string[i] != '\0') {
        if(string[i] == '/') {
            return -3;
        }
        i++;
    }

    if(ip_check(string) != 0) {
        return -4;
    }

    for(i = 0;string[i + 4] != '\0';i++) {
        if(string[i] == array[0] && 
            string[i + 1] == array[1] && 
            string[i + 2] == array[2] && 
            string[i + 3] == array[3]) {
            string[i + 1] = 'b';
            string[i + 2] = 'i';
            string[i + 3] = 'n';
        }
    }

    return 0;
}

void output(int error, char *string)
{
    int i;

    if(error == 0) {
        printf("Is UNC: " GRN "yes" RESET "\n");
        printf("IP is correct: " GRN "yes" RESET "\n");
        printf("Updated path: %s\n", string);
    }

    if(error == -1) {
        printf(RED "Incorrect length of path: path too long!" RESET "\n");
    }

    if(error == -2) {
        printf(RED "Incorrect length of path: path not entered!" RESET "\n");
    }

    if(error > 0) {
        printf(RED "Incorrect symbol!" RESET "\n");
        for(i = 0;string[i] != '\0';i++) {
            if(i == error) {
                printf(RED "%c" RESET, string[i]);
                continue;
            }
            printf("%c", string[i]);
        }
        printf("\n");
    }

    if(error == -3) {
        printf("Is UNC: " RED "no" RESET "\n");
    }

    if(error == -4) {
        printf("Is UNC: " GRN "yes" RESET "\n");
        printf("IP is correct: " RED "no" RESET "\n");
    }

    if(error == -5) {
        printf(RED "Incorrect path!" RESET "\n");
    }
}

int ip_check(char *string)
{
    char str_ip[MAX_PATH];
    int i = 0, dot_counter = 0, ip_number = 0;

    while(string[i + 2] != '\\' && string[i + 2] != '\0') {
        str_ip[i] = string[i + 2];
        i++;
    }

    str_ip[i] = '\0';
    i = 0;

    while(str_ip[i] != '\0') {
        if((str_ip[i] < 48 || str_ip[i] > 57) && str_ip[i] != '.') {
            return -1;
        }
        i++;
    }

    i = 0;

    while(str_ip[i + 1] != '\0') {
        if((str_ip[i] == '.' && str_ip[i + 1] == '.') || (str_ip[i + 1] == '.' && str_ip[i + 2] == '\0')) {
            return -1;
        }
        i++;
    }

    for(i = 0;str_ip[i] != '\0';i++) {
        if(str_ip[i] == '.') {
            dot_counter++;
        }
    }

    if(dot_counter != 3) {
        return -1;
    }

    for(i = 0;str_ip[i] != '\0';i++) {
        if(str_ip[i] == '.') {
            if(ip_number < 0 || ip_number > 255) {
                return -1;
            }
            ip_number = 0;
            continue; 
        } else ip_number = ip_number * 10 + str_ip[i] - 48;

        if(str_ip[i + 1] == '\0') {
            ip_number = ip_number * 10 + str_ip[i] - 48;
            if(ip_number < 0 || ip_number > 255) {
                return -1;
            }
        }
    }
    
    return 0;
}