#include "sll.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


List list_ctor()
{
    return (List){.first = NULL};
}

Item *item_ctor(Object data)
{
    Item *i = malloc(sizeof(*i));
    if (i != NULL) {
        i->data = data;
        i->next = NULL;
    }
    return i;
}
 

void list_insert_first(List *list, Item *i)
{
    i->next = list->first;
    list->first = i;
}


bool list_empty(List *list)
{
    return list->first == NULL;
}
 
void list_delete_first(List *list)
{
    if (list_empty(list)) {
        return;
    }

    Item *tmp = list->first->next;
    free(list->first);
    list->first = tmp;
}

unsigned list_count(List *list)
{
    unsigned cnt = 0;
    Item *tmp = list->first;
    while (tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
 

Item *list_find_minid(List *list)
{
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

Item *list_find_name(List *list, char *name)
{
    for (Item *tmp = list->first; tmp != NULL; tmp = tmp->next) {
        if (strcmp(name, tmp->data.name) == 0) {
            return tmp;
        }
    }
    return NULL;
}

void list_dtor(List *list)
{
    while (list->first != NULL) {
        list_delete_first(list);
    }
}

