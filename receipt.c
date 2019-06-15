/*
 * Johnny Huang
 * CS 305 HW 3
 * receipt.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "receipt.h"
#include "retail_item.h"

receipt * create_receipt()//receipt is initialized with null
{
	return NULL;
}
void add_item(receipt ** rec_ptr, retail_item it)//double pointer sent to reference enter linked list in subject to change
{
	receipt* rec = *rec_ptr;//easily refers to linked list instead of needing to type *rec_ptr constantly
	if(rec == NULL)//if linked list is empty...
	{
		rec = (receipt*)malloc(sizeof(receipt));//creates very first node for list
		(*rec).item = it;//assigns item and ground-pointer to null
		(*rec).next = NULL;
		*rec_ptr = rec;//allows original passed list to point at memory block
		return;
	}
	else if((*rec).item.number>it.number)//if even the first list item is greater than passed item's id number, you will put node in the very front
	{
		receipt* rec_front = (receipt*)malloc(sizeof(receipt));
		(*rec_front).item = it;
		(*rec_front).next = rec;//puts newly created node in front of everything
		*rec_ptr = rec_front;//assigns the head pointer to new first node
		return;
	}
	else if((*rec).item.number<it.number)//if item id is somewhere in the list
	{
		receipt* prev;
		while(rec != NULL)
		{
			if((*rec).item.number>it.number)//searches for when the id ends up being greater than given node id
			{
				receipt* rec_mid = (receipt*)malloc(sizeof(receipt));
				(*rec_mid).item = it;
				(*rec_mid).next = rec;//rec_mid is the new item, wedged in between the two nodes compared
				(*prev).next = rec_mid;
				return;
			}
			prev = rec;//previous node used in reference for wedging node in if placement found
			rec = (*rec).next;//goes through linked list to look for id
		}
		receipt* rec_end = (receipt*)malloc(sizeof(receipt));//this will happen if item id exceeds all ids in list, puts item at very end
		(*rec_end).item = it;
		(*rec_end).next = NULL;//groundpoints to null because it's the very last item
		(*prev).next = rec_end;//previous item's next becomes this
		return;
	}
}

int delete_item(receipt ** rec_ptr, int item_num)
{
	receipt* rec = *rec_ptr;
	receipt* prev;
	if(rec == NULL)//if list is empty, no item deleted
	{
		return 0;//indicates nothing get deleted
	}
	else if((*rec).item.number == item_num)//if item for deletion is first node...
	{
		*rec_ptr = (*rec).next;//assigns passed pointer to next item, since first is about to be deleted
		free(rec);//deletes item
		return 1;//returns success
	}
	while(rec != NULL)
	{
		if((*rec).item.number == item_num)
		{
			(*prev).next = (*rec).next;
			free(rec);
			return 1;
		}
		prev = rec;
		rec = (*rec).next;
	}
	return 0;
}

void print_receipt(receipt * rec)
{
	printf("Receipt\n");
	int count_cost = 0;
	while(rec != NULL)
	{
		print((*rec).item);
		count_cost = count_cost + (*rec).item.price_cents;
		rec = (*rec).next;
	}
	int count_cost_d = count_cost / 100;
	int count_cost_c = count_cost - count_cost_d*100;
	printf("Total: $%d.%02d\n\n", count_cost_d, count_cost_c);
}

void free_receipt(receipt * rec)
{
	if(rec == NULL)
	{
		return;
	}
	else
	{
		while(rec != NULL)
		{
			receipt* rec_next = (*rec).next;
			free(rec);
			rec = rec_next;
		}
		free(rec);
	}
}