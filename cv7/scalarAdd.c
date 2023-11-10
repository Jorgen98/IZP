#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int size;
} vector_t;

void vector_print(vector_t *v) {
    printf("Vector = [");
    for (int i = 0; i < v->size - 1; i++) {
        printf("%d, ", v->items[i]);
    }
    printf("%d]\n", v->items[v->size - 1]);
}

int vector_ctor(vector_t *v, unsigned int size) {
    v->items = malloc(size * sizeof(int));
    if (v->items == NULL) {
        return 0;
    }
    v->size = size;
    return 1;
}

void vector_init(vector_t *v) {
    for (int i = 0; i < v->size; i++) {
        v->items[i] = i;
    }
}

void vector_dtor(vector_t *v) {
    if (v->items != NULL) {
        free(v->items);
        v->items = NULL;
    }
    v->size = 0;
}

int vector_add(vector_t *v1, vector_t *v2) {
    if (v1->size != v2->size) {
        return 0;
    }
    for (int i = 0; i < v1->size; i++) {
        v1->items[i] += v2->items[i];
    }
    return 1;
}


int main() {
    vector_t v1, v2;
    
    if (!vector_ctor(&v1, 5)) {
        printf("Vector construction failed!\n");
        return 1;
    }
    
    if (!vector_ctor(&v2, 5)) {
        printf("Vector construction failed!\n");
        return 1;
    }
    
    vector_init(&v1);
    vector_init(&v2);

    printf("Vectors addition.\n");
    if (!vector_add(&v1, &v2)) {
        printf("Vectors have different sizes!\n");
    }
    
    vector_print(&v1);
    vector_print(&v2);

    vector_dtor(&v1);
    vector_dtor(&v2);

    return 0;
}

