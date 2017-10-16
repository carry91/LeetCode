/*************************************************************************************
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of 
their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

key: dummy head
*************************************************************************************/
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *l1_ptr, *l2_ptr, *sum_ptr, *sum_node;
	int s = 0;
	int x = 0, y = 0;
	l1_ptr = l1;
	l2_ptr = l2;
	sum_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	sum_ptr = sum_node;
	while ((l1_ptr != NULL) || (l2_ptr != NULL))
	{
		x = (l1_ptr == NULL) ? 0 : l1_ptr->val;
		y = (l2_ptr == NULL) ? 0 : l2_ptr->val;
		sum_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		sum_ptr = sum_ptr->next;
		sum_ptr->val = (x + y + s) % 10;
		s = (x + y + s) / 10;
		if (l1_ptr != NULL )
		{
			l1_ptr = l1_ptr->next;
		}
		if (l2_ptr != NULL )
		{
			l2_ptr = l2_ptr->next;
		}

	}
	if (s > 0)
	{
		sum_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		sum_ptr = sum_ptr->next;
		sum_ptr->val = s;
	}
	sum_ptr->next = NULL;
	return sum_node->next;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *l1_ptr, *l2_ptr, *sum_ptr, *sum_node;
	int s = 0;
	int sum = 0;
	l1_ptr = l1;
	l2_ptr = l2;
	sum_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	sum_ptr = sum_node;
	while (1)
	{
		sum = 0;
		if ((l1_ptr == NULL) && (l2_ptr == NULL))
		{
			break;
		}
		else if (l1_ptr == NULL)
		{
			sum = l2_ptr->val + s;
			l2_ptr = l2_ptr->next;
		}
		else if (l2_ptr == NULL)
		{
			sum = l1_ptr->val + s;
			l1_ptr = l1_ptr->next;
		}
		else
		{
			sum = l1_ptr->val + l2_ptr->val + s;
			l1_ptr = l1_ptr->next;
			l2_ptr = l2_ptr->next;
		}
		sum_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		sum_ptr = sum_ptr->next;
		sum_ptr->val = sum % 10;
		s = sum / 10;
	}
	if (s > 0)
	{
		sum_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		sum_ptr = sum_ptr->next;
		sum_ptr->val = s;
	}
	sum_ptr->next = NULL;
	return sum_node->next;
}
