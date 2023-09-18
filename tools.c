#include "shell.h"

/**
 * free2DArray - Frees memory allocated for a 2D array of strings.
 *
 * @array: A pointer to the 2D array of strings.
 */
void free2DArray(char **array)
{
	int index;

	if (!array)
		return;
	for (index = 0; array[index]; index++)
	{
		free(array[index]), array[index] = NULL;
	}
	free(array);
	array = NULL;
}
