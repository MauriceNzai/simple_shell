#include "simple_shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: returns pointer to new memory location
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *array, *helper;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		array = malloc(new_size);
		if (array == NULL)
			return (NULL);
		return (array);
	}
	array = malloc(sizeof(char) * new_size);
	if (array == NULL)
		return (NULL);
	if (new_size > old_size && old_size != 0)
	{
		helper = ptr;
		for (i = 0; i < old_size; i++)
			array[i] = helper[i];
		free(ptr);
	}
	if (new_size < old_size)
	{
		helper = ptr;
		for (i = 0; i < new_size; i++)
			array[i] = helper[i];
		free(ptr);
	}
	return (array);
}
