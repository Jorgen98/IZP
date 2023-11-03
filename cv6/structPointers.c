#include <stdio.h>

struct simple_struct_t {
    int first;
    int second;
};

typedef struct {
    int items[5]; // Array in struct
} struct_with_arr_t;
    
int main() {
    // First we create some variables
    struct simple_struct_t simpleStruct;
    struct_with_arr_t structWithArr;
    
    // Next we put some values intro variables
    simpleStruct.first = 0;
    simpleStruct.second = 5;
    
    structWithArr.items[0] = 0;
    structWithArr.items[1] = 1;
    structWithArr.items[2] = 2;
    structWithArr.items[3] = 3;
    structWithArr.items[4] = 4;
    
    printf("%d %d\n", simpleStruct.first, simpleStruct.second);
    // Now we change values in struct with pointer
    struct simple_struct_t *p_simpleStruct;
    // Connect pointer to variable
    p_simpleStruct = &simpleStruct;
    // Update values
    p_simpleStruct->first = 5;
    p_simpleStruct->second = 3;
    
    // Print new values
    // Same as printf("%d %d\n", simpleStruct.first, simpleStruct.second);
    printf("%d %d\n", p_simpleStruct->first, p_simpleStruct->second);
    
    // Print elems in array from struct
    for (int i = 0; i < 5; i++) {
        printf("%d ", structWithArr.items[i]);
    }
    
    // Print elems in array from struct with pointer on struct
    printf("\n");
    struct_with_arr_t *p_structWithArr;
    p_structWithArr = &structWithArr;
    for (int i = 0; i < 5; i++) {
        printf("%d ", p_structWithArr->items[i]);
    }
    
    // Print elems in array from struct with pointer on array in struct
    printf("\n");
    int *p_arr;
    p_arr = structWithArr.items;
    for (int i = 0; i < 5; i++) {
        printf("%d ", *p_arr);
        p_arr++;
    }
    printf("\n");
    
    // Array of structs instead of array in struct and add some values
    struct simple_struct_t arrOfSimpleStructs[3] = {{0, 1}, {3, 2}, {4, 5}};
    // It is same as:
    // arrOfSimpleStructs[0].first = 0;
    // arrOfSimpleStructs[0].second = 1;
    // arrOfSimpleStructs[1].first = 3;
    // arrOfSimpleStructs[1].second = 2;
    // arrOfSimpleStructs[2].first = 4;
    // arrOfSimpleStructs[2].second = 5;
    
    // Switch values
    printf("%d %d \n", arrOfSimpleStructs[0].first, arrOfSimpleStructs[0].second);
    
    int temp = arrOfSimpleStructs[0].first;
    arrOfSimpleStructs[0].first = arrOfSimpleStructs[0].second;
    arrOfSimpleStructs[0].second = temp;
    
    printf("%d %d \n", arrOfSimpleStructs[0].first, arrOfSimpleStructs[0].second);
    
    // Switch values with pointers on values
    printf("%d %d \n", arrOfSimpleStructs[1].first, arrOfSimpleStructs[1].second);
    int *a = &arrOfSimpleStructs[1].first;
    int *b = &arrOfSimpleStructs[1].second;
    
    temp = *a;
    *a = *b;
    *b = temp;
    
    printf("%d %d \n", arrOfSimpleStructs[1].first, arrOfSimpleStructs[1].second);
    
    // Switch values with pointer on array of structs
    printf("%d %d \n", arrOfSimpleStructs[2].first, arrOfSimpleStructs[2].second);
    
    struct simple_struct_t *p_arrOfSimpleStructs;
    p_arrOfSimpleStructs = arrOfSimpleStructs;
    
    temp = (*(p_arrOfSimpleStructs + 2)).first; // temp = arrOfSimpleStructs[2].first;
    (*(p_arrOfSimpleStructs + 2)).first = (*(p_arrOfSimpleStructs + 2)).second; // arrOfSimpleStructs[2].first = // arrOfSimpleStructs[2].second;
    (*(p_arrOfSimpleStructs + 2)).second = temp; // arrOfSimpleStructs[2].second = temp;
    
    printf("%d %d \n", arrOfSimpleStructs[2].first, arrOfSimpleStructs[2].second);
    
    return 0;
}
