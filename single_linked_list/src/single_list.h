/*
 * single_list.h
 *
 *  Created on: Oct 17, 2023
 *      Author: Mohamed Saber
 */

#ifndef SINGLE_LIST_H_
#define SINGLE_LIST_H_

#include "std_types.h"
#include <stdio.h>


struct node_t
{
	uint32_t nodeData;
	struct node_t *nodeLink;
};


void insert_node_at_begining(struct node_t **listHead);
void insert_node_at_end(struct node_t **listHead);
void insert_node_after(struct node_t **listHead);
uint32_t Get_Length(struct node_t **listHead);
void delete_node_at_begining(struct node_t **listHead);
void delete_node(struct node_t **listHead);
void display_all_nodes(struct node_t **listHead);
#endif /* SINGLE_LIST_H_ */
