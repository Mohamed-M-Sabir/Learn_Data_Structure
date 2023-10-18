/*
 ============================================================================
 Name        : single_linked_list.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "single_list.h"
int main(void) {

	struct node_t *listhead=NULL;


	insert_node_at_begining(&listhead);
	insert_node_at_begining(&listhead);
	insert_node_at_begining(&listhead);

	insert_node_after(&listhead);


	insert_node_at_end(&listhead);
	//insert_node_at_end(&listhead);

	//insert_node_after(&listhead);

	//delete_node_at_begining(&listhead);

	//delete_node(&listhead);

	display_all_nodes(&listhead);

	return 0;
}
