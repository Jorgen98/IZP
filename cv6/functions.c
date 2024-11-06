#include <stdio.h>
#include <stdbool.h>
typedef struct {
    int items[5];
    int cardinality;
} set_t;

typedef struct {
    int first;
    int second;
} pair_t;

bool is_function(pair_t relation[], int rel_size, set_t set) {
    for (int i = 0; i < set.cardinality; i++) {
        int count = 0;
        for (int j = 0; j < rel_size; j++) {
            if (set.items[i] == relation[j].first)
            count++;
        }
        if (count != 1)
            return 0;
    }
    return 1;
}

int rel_minmax(pair_t rel[], int rel_size, pair_t *min, pair_t *max) {
    *min = rel[0];
    *max = rel[0];
    for (int i = 1; i < rel_size; i++) {
        if (rel[i].second < min->second) {
            *min = rel[i];
        } else if (rel[i].second > max->second) {
            *max = rel[i];
        }
    }
    
    return 0;
}

int main() {
    set_t set = {{ 1, 2, 3, 4, 5 }, 5};
    pair_t rel1[5] = { {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5} };
    pair_t rel2[5] = { {1, 3}, {3, 1}, {1, 2}, {2, 1}, {4, 4} };
    pair_t rel3[5] = { {1, 2}, {2, 3}, {3, 3}, {5, 1}, {4, 4} };
    
    if (!is_function(rel1, 5, set)) {
        printf("Relation 1 is not a function\n");
    }
    
    if (!is_function(rel2, 5, set)) {
        printf("Relation 2 is not a function\n");
    }
    
    if (!is_function(rel3, 5, set)) {
        printf("Relation 3 is not a function\n");
    }
    
    pair_t max, min;
    rel_minmax(rel1, 5, &max, &min);
    
    printf("Maximum of function 1 is %d\n", max.second);
    printf("Minimum of function 1 is %d\n", min.second);

return 0;
}
