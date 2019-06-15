#ifndef RETAIL_ITEM_H
#define RETAIL_ITEM_H

#define MAX_NAME_LENGTH 16

/* retail_item struct */
typedef struct retail_item {
  int number;
  char name[MAX_NAME_LENGTH + 1];
  int price_cents;
} retail_item;

/* function prototypes */
retail_item create_retail_item (int num, char *name, int price);
void print(retail_item ri);

#endif
