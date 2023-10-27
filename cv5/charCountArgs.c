#include <stdio.h>

// Use the program args to specify the name of the input file
//     example: ./prog text.txt

int main(int argc, char *argv[]) {
    char letter = '\0', whatToFind = '\0';
    int occ = 0;
    FILE *input;

    input = fopen(argv[1], "r");
    if (input != NULL) {
        printf("Provide letter you want to count:");
        scanf("%c", &whatToFind);
        while (fscanf(input, "%c", &letter) != EOF) {
            if (letter == whatToFind) {
                occ++;
            }
        }
        
        printf("In file text.txt is letter %c is %d times\n", whatToFind, occ);
        fclose(input);
    } else {
        printf("File can not be opened\n");
        return 1;
    }
    
    return 0;
}
