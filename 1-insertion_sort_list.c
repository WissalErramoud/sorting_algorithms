#include "sort.h"

/* Function to swap two adjacent nodes in a doubly linked list */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    /* Adjusting the links around node1 and node2 */
    if (node1->prev)
        node1->prev->next = node2;
    else
        *list = node2;  /* node1 was the head of the list, so update the head */

    if (node2->next)
        node2->next->prev = node1;

    /* Swapping node1 and node2 */
    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/* Insertion sort function */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *tmp;

    if (list == NULL || *list == NULL)
        return;

    current = (*list)->next;  /* Start with the second node */

    while (current)
    {
        tmp = current;
        while (tmp->prev && tmp->n < tmp->prev->n)
        {
            swap_nodes(list, tmp->prev, tmp);
            print_list(*list);  /* Print the list after each swap */
        }
        current = current->next;
    }
}
