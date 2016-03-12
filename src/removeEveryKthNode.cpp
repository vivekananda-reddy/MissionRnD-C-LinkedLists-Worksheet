/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
struct node*remove1(struct node**, struct node*);
struct node * removeEveryKthNode(struct node *head, int K) {
	struct node*temp = head;
	int i;
	if (head == NULL || K < 2)
	{
		return NULL;
	}
	while (temp != NULL)
	{
		i = K;
		while (i > 1)
		{
			if (temp == NULL)
			{
				return head;
			}
			temp = temp->next;
			i--;
		}
		if (temp == NULL)
		{
			return head;
		}
		temp=remove1(&head, temp);
		temp = temp->next;
	}
	return head;
}

struct node* remove1(struct node**head, struct node*temp)
{
	struct node*temp1=*head, *temp2=*head;
	temp2 = temp2->next;
	while (temp2 != temp)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if (temp2->next != NULL)
	{
		temp2 = temp2->next;
		temp1->next = temp2;
	
	}
	else
	{
		temp1->next = NULL;
	}

	return temp1;
}