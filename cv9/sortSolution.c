/**
 * Kostra programu pro praci s polem.
 * 2020, Ales Smrcka
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned year;
    char *name;
} Person;

typedef struct {
    unsigned len;
    Person *data;
} PersonArray;

// Konstruktor. Nastavi data o osobe z parametru
void person_ctor(Person *p, unsigned year, const char *name)
{
    p->year = year;
    p->name = malloc(strlen(name)+1);
    strcpy(p->name, name);
}

// Destruktor. Vycisti zaznam o osobe
void person_dtor(Person *p)
{
    p->year = 0;
    free(p->name);
    p->name = NULL;
}

// Presune data osoby src na dst
void person_move(Person *src, Person *dst)
{
    *dst = *src;
}

// Vytvoří nový objekt a zkopiruje data o osobe ze src na dst
// Vraci NULL, pokud se nepovedlo
void *person_copy(Person *src, Person *dst)
{
    person_ctor(dst, src->year, src->name);
    return dst;
}

// Zameni data dvou zaznamu
void person_swap(Person *a, Person *b)
{
    Person tmp = *a;
    *a = *b;
    *b = tmp;
}

// Porovna dve osoby. Vraci <0, >0, 0, pokud a<b, a>b, a=b.
int person_cmp(Person *a, Person *b)
{
    if (a->year < b->year)
        return -1;
    if (a->year > b->year)
        return +1;
    return strcmp(a->name, b->name);
}

// Konstruktor pole.
void array_ctor(PersonArray *a)
{
    a->len = 0;
    a->data = NULL;
}

//
void array_dtor(PersonArray *a)
{
    if (a->len)
    {
        for (unsigned int i = 0; i < a->len; i++)
        {
            person_dtor(&a->data[i]);
        }
        free(a->data);
    }
}

// Zvetsi velikost pole o 1 (increment).
// Vraci NULL, pokud se nepovedlo.
void *array_inc(PersonArray *a)
{
    void *p = realloc(a->data, (a->len+1)*sizeof(Person));
    if (p == NULL)
        return NULL;
    a->len++;
    return a->data = p;
}

// Vlozi zaznam o osobe na posledni pozici v poli, ktere bude rozsireno.
// Zaznam o osobe je zkopirovan.
void *array_append(PersonArray *a, Person *p)
{
    if (array_inc(a))
        return person_copy(p, &a->data[a->len-1]);
    else
        return NULL;
}

// Odstrani z pole prvek na indexu idx.
void array_remove(PersonArray *a, unsigned int idx)
{
    for (unsigned i = idx+1; i < a->len; i++)
        person_move(&a->data[i-1], &a->data[i]);
    if (a->len)
        a->data = realloc(a->data, (a->len-1)*sizeof(Person));
}

// Najde v poli osobu, ktera ma nejmensi year (a pripadne prvni v abecede)
// Minimum hleda od indexu idx. Pro hledani v celem poli treba zadat index 0.
// Vyuzijte funkci person_cmp
unsigned int array_find_min(PersonArray *a, int idx)
{
    unsigned int min = idx;
    for (int i = idx + 1; i < a->len; i++)
    {
        if (person_cmp(&a->data[i], &a->data[min]) < 0)
        {
            min = i;
        }
    }
    
    return min;
}

// Seradi osoby v poli podle jejich roku (a pripadne jmena)
void array_sort(PersonArray *a)
{
    unsigned int min = 0;
    for (int i = 0; i < a->len - 1; i++) {
        min = array_find_min(a, i);
        person_swap(&a->data[i], &a->data[min]);
    }
}

void array_print(PersonArray *a)
{
    for (unsigned i = 0; i < a->len; i++)
    {
        if (i)
            printf(", ");
        printf("[%d, %s]", a->data[i].year, a->data[i].name);
    }
    putchar('\n');
}

int main()
{
    PersonArray a;
    array_ctor(&a);

    // Vytvorime nekolik osob
    Person p1;
    person_ctor(&p1, 2000, "Bill");
    Person p2;
    person_ctor(&p2, 2010, "Amanda");
    Person p3;
    person_ctor(&p3, 1990, "Joe");

    // Osoby postupne NAKOPIRUJEME do pole (na konec, append)
    array_append(&a, &p1);
    array_append(&a, &p2);
    array_append(&a, &p3);
    // jeste vytvorime ctvrtou osobu, oproti 1. se bude lisit rokem.
    p1.year = 1990;
    array_append(&a, &p1);

    // Odstranime docasne vytvorene zaznamy o osobach
    // Vsechny osoby by mely mit zaznam v poli
    person_dtor(&p1);
    person_dtor(&p2);
    person_dtor(&p3);

    // [2000, Bill], [2010, Amanda], [1990, Joe], [1990, Bill]
    array_print(&a);

    // Najdeme prvni prvek
    unsigned int idx = array_find_min(&a, 0);
    printf("Minimalni prvek v poli je na indexu: %u\n", idx);

    // Seradime
    array_sort(&a);

    // [1990, Bill], [1990, Joe], [2000, Bill], [2010, Amanda]
    array_print(&a);

    array_dtor(&a);
    return 0;
}

