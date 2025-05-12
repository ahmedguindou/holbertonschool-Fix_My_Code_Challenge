#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index in a dlistint_t list
 * @head: Double pointer to the head of the list
 * @index: Index of the node to delete
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    dlistint_t *tmp;
    unsigned int p;

    if (*head == NULL)
    {
        return (-1);
    }

    saved_head = *head;
    p = 0;
    while (p < index && *head != NULL)
    {
        *head = (*head)->next;
        p++;
    }
    if (p != index)
    {
        *head = saved_head;
        return (-1);
    }

    /* If the node to delete is the head node */
    if (0 == index)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        if (tmp != NULL)
        {
            tmp->prev = NULL;
        }
    }
    else
    {
        /* Fix the previous node's next pointer to the current node's next */
        if ((*head)->prev != NULL)
        {
            (*head)->prev->next = (*head)->next;
        }

        /* Fix the next node's prev pointer to the current node's prev */
        if ((*head)->next != NULL)
        {
            (*head)->next->prev = (*head)->prev;
        }

        tmp = (*head)->next;  /* Store the next node */
        free(*head);           /* Free the current node */
        *head = saved_head;    /* Restore the head pointer */
        *head = tmp;           /* Move to the next node (if it exists) */
    }

    return (1);
}
