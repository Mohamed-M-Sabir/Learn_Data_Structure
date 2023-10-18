/*
 * single_list.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Mohamed Saber
 */

#include "single_list.h"




void insert_node_at_begining(struct node_t **listHead)
{
	struct node_t *tempnode;

	tempnode=(struct node_t *)malloc(sizeof(struct node_t));

	if(NULL==tempnode)
	{
		printf("Error, null pointer\n");
	}

	else
	{

		printf("Enter the data you want to insert\n");
		fflush(stdout);
		scanf("%d",&(tempnode->nodeData));
		fflush(stdin);

		if(NULL==*listHead) 		/*listhead is the address of the node if it's null so there is no node it's empty*/
		{
			(tempnode->nodeLink)=NULL;
			*listHead=tempnode;
			printf("the linked list is empty and the data you entered is inserted\n");
		}

		else
		{
			(tempnode->nodeLink)=*listHead;
			*listHead=tempnode;

			printf("the linked list is not empty and the data you entered is inserted at the beginning \n");
		}

	}
}



void insert_node_at_end(struct node_t **listHead)
{
	struct node_t *tempnode;
	struct node_t *lastnode;

	tempnode=(struct node_t *)malloc(sizeof(struct node_t));

	if(NULL==tempnode)
	{
		printf("Error, null pointer\n");
	}

	else
	{

		printf("Enter the data you want to insert\n");
		fflush(stdout);
		scanf("%d",&(tempnode->nodeData));
		fflush(stdin);
		(tempnode->nodeLink)=NULL;

		if(NULL==*listHead) 		/*listhead is the address of the node if it's null so there is no node it's empty*/
		{

			*listHead=tempnode;
			printf("the linked list is empty and the data you entered is inserted \n");
		}

		else
		{
			lastnode=*listHead;
			while(lastnode->nodeLink!=NULL)
			{
				lastnode=lastnode->nodeLink;
			}

			lastnode->nodeLink=tempnode;

			printf("the linked list is not empty and the data you entered is inserted at the end\n");
		}

	}
}





void insert_node_after(struct node_t **listHead)
{
	uint32_t node_position,node_counter,length_list;

	struct node_t *tempnode;
	struct node_t *node_after;

	length_list=Get_Length(listHead);


	printf("Enter node position\n");
	fflush(stdout);
	scanf("%d",&node_position);
	fflush(stdin);

	if(node_position>length_list)
	{
		printf("Invalid node position\n");

	}

	else

	{
		node_after=*listHead;
		for(node_counter=1 ; node_counter<node_position ; node_counter++)
		{
			node_after=node_after->nodeLink;
		}

		tempnode=(struct node_t *)malloc(sizeof(struct node_t));
		if(NULL==tempnode)
			{
				printf("Error, null pointer\n");
			}

			else
			{
				tempnode->nodeLink=node_after->nodeLink;
				node_after->nodeLink=tempnode;

				printf("Enter the data you want to insert\n");
				fflush(stdout);
				scanf("%d",&(tempnode->nodeData));
				fflush(stdin);
			}

	}
}


uint32_t Get_Length(struct node_t **listHead)
{
	uint32_t length=0;
	struct node_t *tempnode;
	tempnode=*listHead;

	while(NULL!=tempnode)
	{
		length++;
		tempnode=tempnode->nodeLink;
	}

	return length;

}


void delete_node_at_begining(struct node_t **listHead)
{
	uint32_t length;
	length=Get_Length(listHead);

	struct node_t *tempnode;
	tempnode=*listHead;
	if(0==length)
	{
		printf("Can't delete , the linked list is empty \n");
	}
	else
	{
		*listHead=tempnode->nodeLink;
		free(tempnode);
		printf("the first node in the linked list is deleted \n");
	}

}


void delete_node(struct node_t **listHead)
{
	uint32_t node_position,node_counter,length_list;

		struct node_t *tempnode;
		struct node_t *node_after;

		length_list=Get_Length(listHead);


		printf("Enter node position\n");
		fflush(stdout);
		scanf("%d",&node_position);
		fflush(stdin);

		if(node_position>length_list)
		{
			printf("Invalid node position\n");

		}

		else

		{
			node_after=*listHead;
			for(node_counter=1 ; node_counter<node_position ; node_counter++)
			{
				node_after=node_after->nodeLink;
			}


			tempnode=node_after->nodeLink;
			node_after->nodeLink=tempnode->nodeLink;
			free(tempnode);
			printf("the node in position you entered is deleted\n");

		}
}



void display_all_nodes(struct node_t **listHead)
{

		struct node_t *tempnode;
		tempnode=*listHead;

		if(NULL==tempnode)
		{
			printf("the list is empty ! \n");
		}
		else
		{
		printf("node values: ");

		while(NULL!=tempnode)
		{
			printf("%d  ->",tempnode->nodeData);
			tempnode=tempnode->nodeLink;
		}

		printf("NULL");

		}
}
