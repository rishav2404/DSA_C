#include <stdio.h>
#include <stdlib.h>

struct slinklist
{
	int data;
	struct slinklist *next;
};
typedef struct slinklist node;

node *start = NULL;
int menu()
{
	int ch;
	printf("The operations are\n");
	printf("1. Create LinkList\n");
	printf("2. Display LinkList\n");
	printf("3. Insert an element at the beginning of LinkList\n");
	printf("4. Insert an element at the end of LinkList\n");
	printf("5. Insert an element in the middle of sorted LinkList\n");
	printf("6. Delete first element of LinkList\n");
	printf("7. Delete last element of LinkList\n");
	printf("8. Delete an element of LinkList\n");
	printf("9. Quit\n");
	printf("10. Search an element\n");
	printf("11. reverse an array\n");
	printf("Enter your choice: ");
	scanf("%d", &ch);
	return ch;
}
node *getnode()
{
	node *newnode;
	newnode = (node *)malloc(sizeof(node));
	printf("Enter data: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	return newnode;
}
void createLL()
{
	int i, n;
	printf("Enter the size of LinkList: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		node *newnode, *temp;
		newnode = getnode();
		if (start == NULL)
		{
			start = newnode;
		}
		else
		{
			temp = start;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
}
void display()
{
	node *temp;
	if (start == NULL)
	{
		printf("LinkList is empty\n");
	}
	else
	{
		temp = start;
		printf("LinkList elements are: ");
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
void search()
{
	node *temp;
	if (start == NULL)
	{
		printf("LinkList is empty\n");
	}
	else
	{
		temp = start;
		int key, f = 0;
		printf("Enter data to search: ");
		scanf("%d", &key);
		while (temp != NULL)
		{
			if (key == temp->data)
			{
				printf("Element found");
				f = 1;
				break;
			}
			temp = temp->next;
		}
		if (f == 0)
		{
			printf("Element not found");
		}
		printf("\n");
	}
}
void insert_at_beginning()
{
	node *newnode;
	newnode = getnode();
	if (start == NULL)
	{
		start = newnode;
	}
	else
	{
		newnode->next = start;
		start = newnode;
	}
}
void insert_in_middle()
{
	node *newnode, *temp;
	newnode = getnode();
	if (start == NULL)
	{
		start = newnode;
	}
	else
	{
		int f = 0;
		temp = start;
		if (temp->next == NULL)
		{
			if (temp->data < newnode->data)
			{
				temp->next = newnode;
			}
			else
			{
				newnode->next = temp;
				start = newnode;
			}
		}
		else
		{
			if (temp->data > newnode->data)
			{
				newnode->next = temp;
				start = newnode;
			}
			else
			{
				while (temp->next->data < newnode->data)
				{
					if (temp->next->next != NULL)
					{
						temp = temp->next;
					}
					else
					{
						f = 1;
						break;
					}
				}
				if (f == 1)
				{
					temp->next->next = newnode;
				}
				else
				{
					newnode->next = temp->next;
					temp->next = newnode;
				}
			}
		}
	}
}

void insert_at_end()
{
	node *newnode, *temp;
	newnode = getnode();
	if (start == NULL)
	{
		start = newnode;
	}
	else
	{
		temp = start;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}
void delete_first()
{
	node *temp;
	if (start == NULL)
	{
		printf("LinkList is empty\n");
	}
	else
	{
		temp = start;
		start = start->next;
		free(temp);
		printf("Element deleted sucessfully\n");
	}
}
void delete_last()
{
	node *temp;
	if (start == NULL)
	{
		printf("LinkList is empty\n");
	}
	else
	{
		temp = start;
		if (temp->next == NULL)
		{
			free(temp);
			start = NULL;
			printf("Element deleted sucessfully\n");
		}
		else
		{
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			free(temp->next);
			temp->next = NULL;
			printf("Element deleted sucessfully\n");
		}
	}
}
void delete_element()
{
	int key, f = 0;
	node *temp, *tempn;
	printf("Enter the element to delete: ");
	scanf("%d", &key);
	if (start == NULL)
	{
		printf("LinkList is empty\n");
	}
	temp = start;
	if (temp->next == NULL)
	{
		if (temp->data == key)
		{
			free(temp);
			start = NULL;
			printf("Element deleted sucessfully\n\n\n");
		}
		else
		{
			printf("Element Not Found\n");
		}
	}
	else
	{
		if (temp->data == key)
		{
			tempn = temp->next;
			free(temp);
			start = tempn;
			printf("Element deleted sucessfully\n\n\n");
		}
		else
		{
			tempn = temp->next;
			while (tempn->next != NULL)
			{
				if (tempn->data == key)
				{
					temp->next = tempn->next;
					free(tempn);
					f = 1;
					printf("Element deleted sucessfully\n\n\n");
					break;
				}
				temp = tempn;
				tempn = tempn->next;
			}
			if (f == 0)
			{
				if (tempn->data == key)
				{
					temp->next = NULL;
					free(tempn);
					printf("Element deleted sucessfully\n\n\n");
				}
				else
				{
					printf("Element Not Found\n");
				}
			}
		}
	}
}
void reverse()
{
	node *node, *t1, *t2, *t3;
	if (start == NULL)
	{
		printf("LinkList is empty\n");
	}
	else
	{
		t1 = start;
		t2 = t1->next;
		while (t2 != NULL)
		{
			t3 = t2->next;
			t2->next = t1;
			t1 = t2;
			t2 = t3;
		}
		start->next = NULL;
		start = t1;
		printf("LinkList reversed successfully\n");
	}
}
int main()
{
	int ch;
	char cont;

	do
	{
		printf("Press enter to continue.");

		scanf("%c", &cont);
		ch = menu();
		switch (ch)
		{
		case 1:
			createLL();
			break;
		case 2:
			display();
			break;
		case 3:
			insert_at_beginning();
			break;
		case 4:
			insert_at_end();
			break;
		case 5:
			insert_in_middle();
			break;
		case 6:
			delete_first();
			break;
		case 7:
			delete_last();
			break;
		case 8:
			delete_element();
			break;
		case 10:
			search();
			break;
		case 11:
			reverse();
			break;
		case 9:
			exit(0);
		default:
			printf("Invalid Choice\nEnter Again\n");
		}
	} while (1);
}