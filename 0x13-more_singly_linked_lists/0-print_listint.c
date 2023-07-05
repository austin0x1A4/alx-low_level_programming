#include <stdio.h>
#include "lists.h"  /* header file that defines the listint_t struct */

size_t print_listint(const listint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        count++;
    }

    return count;
}

