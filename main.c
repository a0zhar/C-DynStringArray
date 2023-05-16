#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
ADDING:
INIT FUNCTION
POP FUNCTION
*/
struct StrArray {
    char **elements;
    int length;
};

// Automatic newline because I'm lazy; makes it much easier to do printf
#define nlprintf(...) printf("\n" __VA_ARGS__)

// Using this (passing the StrArray struct variable as "e" argument) makes the code look nicer
#define growBy(e) (e->length + 1) * sizeof(char*)

// Pushes a new string into the "elements" property
void pushString(struct StrArray *list, const char *data) {
    if (!list) return;

    char **newElements = realloc(list->elements, growBy(list));
    if (!newElements) {
        nlprintf("realloc failed to resize element array");
        return;
    }

    char *newString = strdup(data);// Deprecated use _strdup instead ;)
    if (!newString) {
        free(newElements);
        return;
    }
    
    list->elements = newElements;
    list->elements[list->length++] = newString;
}

void destroyArray(struct StrArray *list) {
    // Go through each element and attempt to free the memory used by it
    for (int i = 0; i < list->length; i++) {
        // Check if the element exists
        if (list->elements[i]) {
            // Free the memory used by the string
            free(list->elements[i]);
        }
    }
    free(list->elements);// Free the memory used by the elements array itself
    list->length = 0;// Set the length to zero

}

int main() {
    struct StrArray list;
    list.length = 0;

    list.elements = malloc(sizeof(char *));
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    pushString(&list, "duajwjdiajwudiajw");
    
    for (int i = 0; i < list.length; i++) {
        nlprintf("content of element %d: %s", i, list.elements[i]);
    }
    
    nlprintf("number of elements: %d", list.length);
    destroyArray(&list);
    
    return 0;
}
