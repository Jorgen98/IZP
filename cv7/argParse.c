#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

const char *usage = "syntax: -x -n COUNT -s STR\n"
    "-x is optional\n"
    "-s STR - mandatory, STR is a string\n"
    "-n COUNT - unsigned int (default: 10)\n";
 
typedef struct {
    bool flag;
    int number;
    char *string;
} config_t;

config_t config = { 
    .flag = false,
    .number = 10,
    .string = NULL
};

int parse_args(int argc, char **argv) {
    bool nSet = false;
    for (int arg = 1; arg < argc; arg++) {
        if(strcmp(argv[arg], "-x") == 0) {
            // Every flag can be used only once
            if (config.flag) {
                return 2;
            }
            config.flag = true;
        } else if (strcmp(argv[arg], "-n") == 0) {
            // Check if -n is already set and if there is some actual value
            if (nSet || arg + 1 >= argc) {
                return 4;
            }
            config.number = atoi(argv[++arg]);
            nSet = true;
        } else if (strcmp(argv[arg], "-s") == 0) {
            if (config.string != NULL || arg + 1 >= argc) {
                return 5;
            }
            config.string = argv[arg + 1];
            return 1;
        } else {
            return 6;
        }
    }
    return 1;
}
 
int main(int argc, char *argv[])
{
    if (parse_args(argc, argv) != 1) {
        fprintf(stderr, usage);
        return 1;
    }

    printf("Parsed arguments:\n");
    printf(" - flag: %d\n", config.flag);
    printf(" - number: %d\n", config.number);
    printf(" - string: %s\n", config.string);
    
    return 0;
}

