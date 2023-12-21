#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *temp;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current;

        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            /* Swap nodes */
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            temp->next = temp->prev;
            temp->prev = temp->prev->prev;

            if (temp->prev != NULL)
                temp->prev->next = temp;

            else
                *list = temp;

            temp->next->prev = temp;
            print_list(*list);
        }

        current = current->next;
    }
}

