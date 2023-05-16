#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct StrArray {
	char **elements;
	int length;
};
#define nlprintf(...) printf("\n"__VA_ARGS__)
#define growby(e) (e->length + 1) * sizeof(char*)
void pushString(struct StrArray *list, const char *data) {
	if (!list)
		return;

	char **newElements = realloc(list->elements, growby(list));
	if (!newElements)
		return;

	list->elements = newElements;

	char *newString = strdup(data);
	if (!newString)
		return;

	list->elements[list->length++] = newString;
}

void destroyarraay(struct StrArray *list) {
	// Go through each string and attempt to free the memory used by it
	// IF! the element is not (non-used)
	for (int i = 0; i < list->length; i++) {
		// Check if the element exists
		if (list->elements[i]) {
			// Free the memory used by the string
			free(list->elements[i]);
		}
	}
	// Free the memory used by the elements array itself
	free(list->elements);
	//o Set the length to zero
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
	destroyarraay(&list);
	return 0;
}
