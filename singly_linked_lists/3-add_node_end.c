#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the pointer of the head of the list
 * @str: string to add to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *tmp;
	unsigned int i;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	i = 0;
	while (str[i])
		i++;

	new->len = i;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	return (new);
}
