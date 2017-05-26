#ifndef FUNCTION_H
#define FUNCTION_H

enum {
    MAX_PATH = 260
};

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void input(char *string);
int process(char *string);
int check(char *string);
void output(int error, char *string);
int ip_check(char *string);

#endif