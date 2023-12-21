#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *tracknode = NULL;
    listint_t *last = NULL;
    listint_t *placeholder = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    tracknode = (*list)->next;

    while (tracknode != NULL)
    {
        placeholder = tracknode->next;
        last = tracknode->prev;

        while (last != NULL && tracknode->n < last->n)
        {
            if (last->prev != NULL)
                last->prev->next = tracknode;
            last->next = tracknode->next;
            tracknode->next = last;

            tracknode->prev = last->prev;
            last->prev = tracknode;
            if (last->next != NULL)
                last->next->prev = last;
            
            if (tracknode->prev == NULL)
                (*list) = tracknode;

            last = tracknode->prev;

            print_list(*list);
        }
        tracknode = placeholder;
    }
}
