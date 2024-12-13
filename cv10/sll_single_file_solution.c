/**
 * Kostra pro cviceni operaci nad jednosmerne vazanym seznamem.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
List list_ctor() {
    List newList;
    newList.first = NULL;
    return newList;
}
 
/**
 * Inicializace polozky seznamu. Z objektu vytvori polozku bez naslednika.
 */
Item *item_ctor(Object data) {
    Item *newItem;
    newItem = malloc(sizeof(Item)*1);
    if (newItem != NULL) {
        newItem->data = data;
        newItem->next = NULL;
    }
    return newItem;
}

/**
 * Vlozi polozku na zacatek seznamu.
 */
void list_insert_first(List *list, Item *i) {
    i->next = list->first;
    list->first = i;
}
 
/**
 * Vrati true, pokud je seznam prazdny.
 */
bool list_empty(List *list) {
    return list->first == NULL;
}
 
/**
 * Odstrani prvni prvek seznamu, pokud je.
 */
void list_delete_first(List *list) {
    if (list->first != NULL) {
        Item *tmp = list->first->next;
        free(list->first);
        list->first = tmp;
    }
}
 
/**
 * Vrati pocet polozek seznamu.
 */
unsigned list_count(List *list) {
    unsigned cnt = 0;
    Item *tmp = list->first;
    while (tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
 
 
/**
 * Najde polozku seznamu s nejmensim identifikatorem. Vraci NULL, pokud je
 * seznam prazdny.
 */
Item *list_find_minid(List *list) {
    if (list_empty(list)) {
        return NULL;
    }
    
    Item *min_id = list->first;
    for (Item *tmp = list->first->next; tmp != NULL; tmp = tmp->next) {
        if (tmp->data.id < min_id->data.id) {
            min_id = tmp;
        }
    }
    return min_id;
}
 
/**
 * Najde polozku seznamu s odpovidajicim jmenem objektu. Vraci NULL, pokud
 * takova polozka v seznamu neni.
 */
Item *list_find_name(List *list, char *name) {
    for (Item *tmp = list->first; tmp != NULL; tmp = tmp->next) {
        if (strcmp(name, tmp->data.name) == 0) {
            return tmp;
        }
    }
    return NULL;
}
 
/**
 * Uvolneni seznamu.
 */
void list_dtor(List *list) {
    while (list->first != NULL) {
        list_delete_first(list);
    }
}

 
int main()
{
    printf("list_ctor...\n");
    List list = list_ctor();
 
    printf("list_empty...\n");
    printf("Seznam prazdny: %s\n", list_empty(&list) ? "ano" : "ne");
 
    Item *item;
 
    Object o1 = {42, "Honza"};
    printf("item_ctor...\n");
    item = item_ctor(o1);
    printf("list_insert_first...\n");
    list_insert_first(&list, item);
 
    printf("Seznam prazdny: %s\n", list_empty(&list) ? "ano" : "ne");
    printf("list_count...\n");
    printf("Pocet prvku v seznamu: %d\n", list_count(&list));
 
    Object o2 = {2, "Malem"};
    item = item_ctor(o2);
    printf("list_insert_first...\n");
    list_insert_first(&list, item);
 
    Object o3 = {0, "Kralem"};
    item = item_ctor(o3);
    printf("list_insert_first...\n");
    list_insert_first(&list, item);
 
    printf("Pocet prvku v seznamu: %d\n", list_count(&list));
 
    printf("Odstraneni prvniho prvku ze seznamu \n");
    list_delete_first(&list);
    printf("Pocet prvku v seznamu: %d\n", list_count(&list));
 
 
    // opetovne vlozeni objektu o1		
    item = item_ctor(o1);
    printf("list_insert_first...\n");
    list_insert_first(&list, item);
 
    printf("list_find_minid...\n");
    item = list_find_minid(&list);
    if (item != NULL) {
        printf("Polozka s nejmensim identifikatorem: {%d, \"%s\"}\n",
            item->data.id, item->data.name);
	}
	else
        printf("Polozka s nejmensim identifikatorem nenalezena\n");
 
    printf("list_find_name...\n");
    char* name = "Honza";
    item = list_find_name(&list, name);
    if (item != NULL) {
        printf("Polozka s daty %s nalezena\n", name);
	} 
	else
        printf("Polozka s daty %s nenalezena.\n",name);
 
    printf("list_dtor...\n");
    list_dtor(&list);
    printf("Seznam prazdny: %s\n", list_empty(&list) ? "ano" : "ne");
 
    return 0;
}

