#ifndef RECEIPT_H
#define RECEIPT_H

#include "retail_item.h"

/* receipt struct, defined as a linked list
   each node is a receipt; each receipt has item
   as the data */
typedef struct receipt_tag receipt;
struct receipt_tag {
  retail_item item;   // item stored in the node
  receipt * next;     // next receipt node in linked list
};

/* function prototypes */
receipt * create_receipt();
void add_item(receipt ** rec_ptr, retail_item it);
int delete_item(receipt ** rec_ptr, int item_num);
void print_receipt(receipt * rec);
void free_receipt(receipt * rec);

#endif
