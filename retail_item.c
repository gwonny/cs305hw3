/**
 * HW 3: file provided for students
 * retail_item.c
 * author: Tammy VanDeGrift
 * models a retail_item as an number, name, and price
 * supports creation of retail_item and printing
 * 
 * also compile with receipt.c and main.c
 *
 */

#include <stdio.h>
#include "receipt.h"
#include "retail_item.h"

/* functions on retail_item structs */

/* create_retail_item
 * parameters: int num, char *name, int price
 * sets the values of retail item according to the parameters
 * and returns the structure
 */
retail_item create_retail_item (int num, char *name, int price) {
  retail_item ret;
  if(num < 0) {
    num = 0;
  }
  if(price < 0) {
    price = 0;
  }
  ret.number = num;
  /* set first MAX_NAME_LENGTH chars to name */
  /* find length of name by finding the null char */
  int i;
  int found = 0;
  for(i=0; i<MAX_NAME_LENGTH; i++) {
    if(found == 1) {
      ret.name[i] = ' ';
    } else if(name[i] == '\0') {
      ret.name[i] = ' ';
      found = 1;
    } else {
      ret.name[i] = name[i];
    }
  }
  ret.name[MAX_NAME_LENGTH] = '\0';
  ret.price_cents = price;
  return ret;
}

/* print
 * parameter: retail_item ri
 * prints the retail item number, name, and price separated by tabs
 */
void print(retail_item ri) {
  int price_dollars = ri.price_cents / 100;
  int price_cent = ri.price_cents - price_dollars*100;
  printf("Item %d\t%s\t$%d.%02d\n", ri.number, ri.name, price_dollars, price_cent);
  return;
}
