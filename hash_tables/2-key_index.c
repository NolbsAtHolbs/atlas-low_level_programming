#include "hash_tables.h"

/**
 * key_index - takes hash value made by hash_djb2 and maps it to an index
 * within bounds of hash table's size
 * @key: key string to hash
 * @size: size of the hash table array
 *
 * Return: index in the hash table array where the key/value pair is stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
