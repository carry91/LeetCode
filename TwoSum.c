/*************************************************************************************************************
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
**************************************************************************************************************/

/*************************************************************************************************************
key words: brute force, hash table
space VS speed

*************************************************************************************************************/
/*Brute froce*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0, j = 0;
    int *indice_array;
   
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                indice_array = (int *)malloc(sizeof(int) * 2);
                indice_array[0] = i;
                indice_array[1] = j;
            }
        }
    }
    return indice_array;
}

/*************************************************************************************************************
Solution2 hash table
*************************************************************************************************************/
#define PRIME_NUMBER 271

typedef struct _ListNode
{
	int value;
	struct _ListNode *next;
	struct _ListNode *prev;
}ListNode;

typedef ListNode *List;
typedef ListNode *Position;

void hash_put(ListNode table[], int key, int value)
{
	int bias = abs(key % PRIME_NUMBER);
	if (table[bias].value == -1)
	{
		table[bias].prev = NULL;
		table[bias].value = value;
	}
	else
	{
		List p = &table[bias];
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = (List)malloc(sizeof(ListNode));
		p->next->next = NULL;
		p->next->prev = p;
		p->next->value = value;
	}
}

int hash_find(ListNode table[], int key, int *nums)
{
	int bias = abs(key % PRIME_NUMBER);
	if (table[bias].value != -1 && nums[table[bias].value] == key)
	{
		return table[bias].value;
	}
	else
	{
		List p = &table[bias];
		while (p->next != NULL)
		{
			if (nums[p->next->value] == key)
			{
				return p->next->value;
			}
			else
			{
				p = p->next;
			}
		}
	}
	return -1;
}

void hash_init(ListNode table[], int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		table[i].next = NULL;
		table[i].prev = (List)-1;
		table[i].value = -1;
	}
}

int* twoSum(int* nums, int numsSize, int target) {
	int i = 0, j = 0;
	int k = -1;
	int *indice_array;
	
	indice_array = (int *)malloc(sizeof(int)* 2);
	ListNode hash_table[PRIME_NUMBER];
	hash_init(hash_table, PRIME_NUMBER);
	for (i = 0; i < numsSize; i++)
	{
		hash_put(hash_table, nums[i], i);
	}
	for (i = 0; i < numsSize; i++)
	{
		j = target - nums[i];
		k = hash_find(hash_table, j, nums);
		if (k != -1 && k != i)
		{
			indice_array[0] = i;
			indice_array[1] = k;
			return indice_array;
		}
	}
	
	return indice_array;
}
