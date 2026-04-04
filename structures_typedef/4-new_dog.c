#include <stdlib.h>
#include <stddef.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcpy - copies the string src to dest
 * @dest: destination
 * @src: source
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to new dog, or NULL if failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *name_copy, *owner_copy;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	name_copy = malloc(_strlen(name) + 1);
	if (name_copy == NULL)
	{
		free(d);
		return (NULL);
	}

	owner_copy = malloc(_strlen(owner) + 1);
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(d);
		return (NULL);
	}

	_strcpy(name_copy, name);
	_strcpy(owner_copy, owner);

	d->name = name_copy;
	d->age = age;
	d->owner = owner_copy;

	return (d);
}
