#include <stdio.h>

#define REC_NUM 3

typedef struct date_t Date;
struct date_t {
    int year;
    int month;
    int day;
};

struct rec_t {
    Date date;
    double temp;
};

struct rec_t loadData(){
    struct rec_t rec;
    printf ("Please specify the date and temperature (format yyyy mm dd temp): ");
    scanf("%d %d %d %lf", &rec.date.year, &rec.date.month, &rec.date.day, &rec.temp);

    return rec;
}

int checkDate(Date date) {
    if (date.year < 0 || date.year > 2500 || date.month < 1 ||
        date.month > 12 || date.day < 1 || date.day > 31) {
        return 0;
    }
    if (date.day == 31 && date.month != 1 &&
        date.month != 3 && date.month != 5 &&
        date.month != 7 && date.month != 8 &&
        date.month != 10 && date.month != 12) {
        return 0;
    }
    return 1;
}

int main() {
    struct rec_t records[REC_NUM];
    double avg = 0;

    for (int i = 0; i < REC_NUM; i++) {
        records[i] = loadData();
        if (!checkDate(records[i].date)) {
            printf("Provided date is not valid\n");
            return 1;
        }
        avg += records[i].temp;
    }

    printf("Average temp of records is %lf\n", avg / REC_NUM);
    return 0;
}
