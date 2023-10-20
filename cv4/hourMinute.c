#include <stdio.h>
#include <locale.h>

void printHour(int hour){
    if (hour == 1) {
        printf("Je %d hodina", hour);
    } else if (hour == 2 || hour == 3 || hour == 4) {
        printf("Sú %d hodiny", hour);
    } else {
        printf("Je %d hodín", hour);
    }
    
    printf(" a ");
}

void printMinute(int minute){
    if (minute == 1) {
        printf("%d minúta", minute);
    } else if (minute == 2 || minute == 3 || minute == 4) {
        printf("%d minúty", minute);
    } else {
        printf("%d minút", minute);
    }
    
    printf("\n");
}

int main() {
    int hour = 0, minute = 0;
    printf("Zadajte hodinu: ");
    scanf("%d", &hour);
    printf("Zadajte minútu: ");
    scanf("%d", &minute);
    
    printHour(hour);
    printMinute(minute);
    
    return 0;
}
