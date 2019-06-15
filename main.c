/* CS 305, SPRING 2018
 * HOMEWORK 3
 *
 * main.c
 * author: Tammy VanDeGrift
 *
 * creates receipts and retail_items and tests them
 *
 * compile with receipt.c and retail_item.c
 * gcc receipt.c retail_item.c main.c
 * OR
 * gcc -o runtest receipt.c retail_item.c main.c
 * OR
 * use makefile:
 * make runtest
 * If creating produce object file, then run with command:
 * produce
 * Otherwise, run with command:
 * a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include "receipt.h"
#include "retail_item.h"

/* prototypes */
int run_test(void);
int run_test2(void);

/* main 
 * using void paramater since we are not using command line arguments
 * for this program
 */
int main(void) {
  run_test();
  //run_test2(); 
  //^uncomment this if you would like to test it (although sample_output2.txt is supplied in zip to show result)
}

/* run_test
 * runs a test, creating receipts and adding/deleting items
 */
int run_test(void) {
  /* create two receipts */
  /* note: using pointers for receipts so the receipt data can be 
     modified */
  receipt *shop = create_receipt();
  receipt *fred = create_receipt();

  /* create retail items */
  /* note: not using pointers to retail_items since once they are created
   * they are not later modified -- only used as data */
  retail_item candy   = create_retail_item(1001, "Snickers", 75);
  retail_item coffee  = create_retail_item(3033, "Starbucks Blend", 699);
  retail_item cookie  = create_retail_item(2222, "Chips Ahoy", 329);
  retail_item shirt   = create_retail_item(9212, "Large T Shirt", 1599);
  retail_item eggs    = create_retail_item(1234, "Dozen Eggs", 369);
  retail_item oranges = create_retail_item(5545, "Clementines", 799);
  retail_item bread   = create_retail_item(3222, "Orowheat bread", 499);
  retail_item grapes  = create_retail_item(5122, "Red grapes", 549);
  retail_item yogurt  = create_retail_item(1121, "Vanilla yogurt", 75);
  retail_item peanuts = create_retail_item(2121, "Planters Peanuts Salt", 802);
  retail_item shampoo = create_retail_item(4424, "Pantene Shampoo", -633);
  retail_item gift_card = create_retail_item(8000, "Fred Meyer Gift Card", 5000);
  
  /* put items into receipt */
  add_item(&shop, candy);
  add_item(&shop, coffee);
  add_item(&shop, cookie);

  /* at point to draw picture 1 in report */

  add_item(&shop, shirt);
  add_item(&shop, eggs);

  /* at point to draw picture 2 in report */

  add_item(&shop, eggs);
  add_item(&shop, oranges);
  add_item(&shop, bread);
  add_item(&shop, grapes);
  add_item(&shop, yogurt);
  add_item(&shop, peanuts);

  /* print the receipt */
  print_receipt(shop);

  /* delete item */
  printf("Trying to delete item 1234\n"); 
  delete_item(&shop, 1234);

  /* print the receipt */
  print_receipt(shop);

  /* delete item */
  printf("Trying to delete item 10000\n");
  delete_item(&shop, 10000);

  /* add items to fred */
  add_item(&fred, coffee);
  add_item(&fred, peanuts);
  add_item(&fred, bread);
  add_item(&fred, shampoo);
  print_receipt(fred);

  /* delete items */
  printf("Trying to delete item 3222\n");
  delete_item(&fred, 3222);
  printf("Trying to delete item 3033\n");
  delete_item(&fred, 3033);
  printf("Trying to delete item 2121\n");
  delete_item(&fred, 2121);
  printf("Trying to delete item 1234\n");
  delete_item(&fred, 1234);
  print_receipt(fred);

  /* add items to fred */
  add_item(&fred, shampoo);
  add_item(&fred, bread);
  add_item(&fred, gift_card);
  print_receipt(fred);

  /* free memory for receipts */
  free_receipt(fred);
  free_receipt(shop);

  return EXIT_SUCCESS;
} /* end main */

int run_test2(void)
{
	receipt* test = create_receipt();//creates test receipt
	
	delete_item(&test, 9999);//attempts to delete an item in an empty receipt
	
	retail_item recipe4disaster = create_retail_item(-9999, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 909090);//makes a retail item asking for nothing but trouble
	
	add_item(&test, recipe4disaster);//adds item
	
	print_receipt(test);//prints to see what it looks like
	
	delete_item(&test, -9999);//attempts to delete with the negative id
	
	print_receipt(test);//shows results
	
	delete_item(&test, 0);//deletes with adjusted id
	
	print_receipt(test);//shows results
	
	free_receipt(test);//frees receipt
	
	return EXIT_SUCCESS;
}