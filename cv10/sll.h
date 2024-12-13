#ifndef _SLL_H
#define _SLL_H

#include <stdbool.h>

/**
 * struktura Object
 */
typedef struct {
    int id;
    char *name;
} Object;
 
/**
 * Polozka seznamu
 */
typedef struct item Item;
struct item {
    Object data;
    Item *next;
};
 
/**
 * Typ seznam
 */
typedef struct {
    Item *first;
} List;


/**
 * Inicializace seznamu. Vytvori prazdny seznam.
 */
List list_ctor();
 
/**
 * Inicializace polozky seznamu. Z objektu vytvori polozku bez naslednika.
 */
Item *item_ctor(Object data);

/**
 * Vlozi polozku na zacatek seznamu.
 */
void list_insert_first(List *list, Item *i);
 
/**
 * Vrati true, pokud je seznam prazdny.
 */
bool list_empty(List *list);
 
/**
 * Odstrani prvni prvek seznamu, pokud je.
 */
void list_delete_first(List *list);
 
/**
 * Vrati pocet polozek seznamu.
 */
unsigned list_count(List *list);
 
 
/**
 * Najde polozku seznamu s nejmensim identifikatorem. Vraci NULL, pokud je
 * seznam prazdny.
 */
Item *list_find_minid(List *list);
 
/**
 * Najde polozku seznamu s odpovidajicim jmenem objektu. Vraci NULL, pokud
 * takova polozka v seznamu neni.
 */
Item *list_find_name(List *list, char *name);
 
/**
 * Uvolneni seznamu.
 */
void list_dtor(List *list);

#endif

