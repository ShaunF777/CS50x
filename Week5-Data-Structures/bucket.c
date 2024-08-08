/*Pre-allocate a large array of pointers for hash indexing. Each entry in the table refers to a linked-list of items with that hash.
So the look-up plan is to do your hash, then iterate through the linked-list at that location and read/insert/remove/etc. your item.
The setup is extremely easy and it can be fairly effective, if your hash is decent then your linked-lists shouldn't ever get very long.*/


typedef struct node
{
	struct node *hash_link;
    int key;
} node;

node *hash_table[2048] = { NULL }; /* Initialize all of them to NULL */

/* Calculate the hash */
int hash_get(int key)
{
    /* Extremely simple hash alg, just take the lower bits of the key */
    return (key % (sizeof(hash_table)/sizeof(hash_table[0])));
}

void hash_insert(node *i)
{
    int index = hash_get(i->key);

    /* Insert onto the beginning of the list */
    i->hash_link = hash_table[index];
    hash_table[index] = i;
}

node *hash_index(int key)
{
    int index = hash_get(key);

    node *cur;
    for (cur = hash_table[index]; cur; cur = cur->hash_link)
        if (cur->key == key)
            return cur;

    return NULL;
}
