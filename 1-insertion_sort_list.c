#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: A pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *temp;

    for (current = (*list)->next; current != NULL; current = temp)
    {
        temp = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            /* Swap nodes in the list */
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
            
            current->next = current->prev;
            current->prev = current->next->prev;

            if (current->prev != NULL)
                current->prev->next = current;
            else
                *list = current;

            current->next->prev = current;
            
            print_list(*list);
        }
    }
}
