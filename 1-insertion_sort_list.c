#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (*list == NULL || (*list)->next == NULL)
        return;  // List is empty or has only one element

    listint_t *current, *next;

    for (current = (*list)->next; current != NULL; current = next)
    {
        next = current->next;

        // Insert current node into the sorted part of the list
        listint_t *prev = NULL;
        listint_t *temp = *list;
        while (temp != NULL && temp->n < current->n)
        {
            prev = temp;
            temp = temp->next;
        }

        if (prev != NULL)
        {
            // Detach the current node
            prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = prev;

            // Insert the current node before temp
            current->next = temp;
            current->prev = prev;
            if (temp != NULL)
                temp->prev = current;
            else
                // Inserted at the end
                *list = current;
        }

        // Print the list after the insertion
        print_list(*list);
    }
}
