#include <stdio.h>
#include <stdlib.h>


typedef struct Compartment {
    int number;
    struct Compartment* next;
} Compartment;

typedef struct {
    Compartment* head;
} Train;

Compartment* create_compartment(int number) {
    Compartment* new_compartment = (Compartment*)malloc(sizeof(Compartment));
    new_compartment->number = number;
    new_compartment->next = NULL;
    return new_compartment;
}

void initialize_train(Train* train) {
    train->head = NULL;
}

void add_compartment_at_beginning(Train* train, int number) {
    Compartment* new_compartment = create_compartment(number);
    new_compartment->next = train->head;
    train->head = new_compartment;
}

void add_compartment_at_end(Train* train, int number) {
    Compartment* new_compartment = create_compartment(number);
    if (train->head == NULL) {
        train->head = new_compartment;
    } else {
        Compartment* last = train->head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_compartment;
    }
}

int count_compartments(Train* train) {
    int count = 0;
    Compartment* current = train->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void remove_compartment_from_end(Train* train) {
    if (train->head == NULL) {
        return;
    }
    if (train->head->next == NULL) {
        free(train->head);
        train->head = NULL;
        return;
    }
    Compartment* second_last = train->head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}

void remove_compartment_from_beginning(Train* train) {
    if (train->head == NULL) {
        return;
    }
    Compartment* temp = train->head;
    train->head = train->head->next;
    free(temp);
}

void display_compartments(Train* train) {
    Compartment* current = train->head;
    while (current != NULL) {
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Train train;
    initialize_train(&train);

    add_compartment_at_end(&train, 1);
    add_compartment_at_end(&train, 2);
    add_compartment_at_end(&train, 3);
    add_compartment_at_beginning(&train, 0);
    
    printf("Compartments: ");
    display_compartments(&train);

    printf("Count: %d\n", count_compartments(&train));

    remove_compartment_from_end(&train);
    printf("Compartments after removing from end: ");
    display_compartments(&train);

    remove_compartment_from_beginning(&train);
    printf("Compartments after removing from beginning: ");
    display_compartments(&train);

    printf("Final Count: %d\n", count_compartments(&train));

    return 0;
}
