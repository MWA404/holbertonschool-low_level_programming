#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * update_value - updates value if key already exists
 * @tmp: pointer to first node in bucket
 * @key: key to search for
 * @val_copy: new value to assign
 * Return: 1 if updated, 0 if key not found
 */
int update_value(hash_node_t *tmp, const char *key, char *val_copy)
{
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = val_copy;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

/**
 * hash_table_set - adds or updates an element in the hash table
 * @ht: the hash table
 * @key: the key (cannot be empty)
 * @value: the value associated with key
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;
	char *val_copy;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);

	if (update_value(ht->array[index], key, val_copy) == 1)
		return (1);

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(val_copy);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(val_copy);
		free(new_node);
		return (0);
	}
	new_node->value = val_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
