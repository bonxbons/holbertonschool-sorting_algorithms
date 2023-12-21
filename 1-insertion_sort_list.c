#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    if (*list == NULL || (*list)->next == NULL) {
        return;  // List is empty or has only one element
    }

    // Move variable declarations to the beginning of the block
    listint_t *current, *next;
    listint_t *prev, *temp;

    for (current = (*list)->next; current != NULL; current = next) {
        next = current->next;

        // Find insertion point
        prev = NULL;
        temp = *list;
        while (temp != NULL && temp->n < current->n) {
            prev = temp;
            temp = temp->next;
        }

        // Detach current node
        if (prev != NULL) {
            prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = prev;
            }
        } else {
            // Detaching head node
            *list = current->next;
            if (current->next != NULL) {
                current->next->prev = NULL;
            }
        }

        // Insert current node before temp
        current->next = temp;
        current->prev = prev;
        if (temp != NULL) {
            temp->prev = current;
        } else {
            // Inserted at the end
            *list = current;
        }

        // Print the list after the insertion
        print_list(*list);
    }
}
