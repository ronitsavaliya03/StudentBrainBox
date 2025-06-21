#include <stdio.h>

struct Student {
    int id;
    char name[50];
};

int main() {
    // Structure variable
    struct Student s1 = {1, "Ronit"};

    // Access using dot operator
    printf("Using dot: ID = %d, Name = %s\n", s1.id, s1.name);

    // Pointer to structure
    struct Student *ptr = &s1;

    // Access using arrow operator
    printf("Using arrow: ID = %d, Name = %s\n", ptr->id, ptr->name);

    return 0;
}
