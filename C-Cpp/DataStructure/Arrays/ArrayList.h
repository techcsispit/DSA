#include <stdio.h>
#include <stdlib.h>

typedef struct array_list {
    int x;
    int size;
    int *a;
} Array_list;

Array_list* create_array_list() {
    Array_list *p = (Array_list*)malloc(sizeof(Array_list));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    p->a = (int*)malloc(sizeof(int) * 2);
    if (p->a == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    p->x = 0;
    p->size = 2;
    return p;
}

void grow(Array_list *p) {
    p->a = (int*)realloc(p->a, sizeof(int) * p->size * 2);
    if (p->a == NULL) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
    p->size *= 2;
}

void reduce(Array_list *p) {
    p->a = (int*)realloc(p->a, sizeof(int) * (p->size / 1.5));
    if (p->a == NULL) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
    p->size /= 1.5;
}

void add(Array_list *p, int n) {
    if (p->x == p->size) {
        grow(p);
    }
    p->a[p->x++] = n;
}

void add_index(Array_list *p, int n, int index) {
    if (p->x == p->size) {
        grow(p);
    }
    for (int i = p->x; i > index; i--) {
        p->a[i] = p->a[i - 1];
    }
    p->a[index] = n;
    p->x++;
}

int get_size(Array_list *p) {
    return p->x;
}

int get_index(Array_list *p, int index) {
    return p->a[index];
}

int get_last(Array_list *p) {
    return p->a[p->x - 1];
}

int remove_last(Array_list *p) {
    if (p->x > (p->size / 3) && p->size > 20) {
        reduce(p);
    }
    return p->a[--p->x];
}

int remove_index(Array_list *p, int index) {
    if (p->x > (p->size / 3) && p->size > 20) {
        reduce(p);
    }
    int removed = p->a[index];
    for (int i = index; i < p->x - 1; i++) {
        p->a[i] = p->a[i + 1];
    }
    p->x--;
    return removed;
}

void delete_array_list(Array_list *p) {
    free(p->a);
    free(p);
}

void print_array_list(Array_list *p) {
    printf("Array List: ");
    for (int i = 0; i < p->x; i++) {
        printf("%d -> ", p->a[i]);
    }
    printf("end\n");
}