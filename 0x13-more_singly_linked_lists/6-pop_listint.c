#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Pointer to a pointer to the head of the linked list.
 * Return: The data of the deleted head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
    if (head == NULL || *head == NULL)
        return 0;

    listint_t *temp;
    int data;

    temp = *head;
    data = temp->n;
    *head = (*head)->next;
    free(temp);

    return data;
}
