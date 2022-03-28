#include <stdio.h>

typedef struct UserInfo{
	int Pid1;
	int Pid2;
	struct UserInfo * next;
}UI;

void InsertLinkedList(UI ** HEAD, int data1, int data2, int iPos)
{
	int iCount = 1
	UI *CurNode, *PrvNode, *NewNode;
	if( *HEAD == NULL || iPos <= 0)
	{
		printf("Null pointer or Position Invalid\n");
		return;
	}

	NewNode = (UI *) calloc(sizeof(UI), 1);
	if(NewNode != NULL)
	{
		printf("Memory Error");
		return;
	}

	NewNode->Pid1 = data1;
	NewNode->Pid2 = data2;

	CurNode = *HEAD;

	if(iPos == 1) /* Insert at Begin*/
	{
		NewNode->next = CurNode;
		*HEAD = NewNode;
		printf("At Position %d Inserted\n",iPos);
	}
	else
	{
		while((CurNode != NULL) && (iCount < (iPos - 1)))
		{
			iCount += 1;
			PrvNode = CurNode;
			CurNode = CurNode->next;
		}

		if(CurNode == NULL) /*Insert at END*/
		{
			PrvNode->next = NewNode;
			NewNode->next = NULL;
			printf("At Position %d Inserted\n",iPos);
		}
		else /*Insert at Middle*/
		{
			PrvNode->next = NewNode;
			NewNode->next = CurNode;
			printf("At Position %d Inserted\n",iPos);
		}
	}
}

void DeleteNodeFromLinkedList(UI **HEAD, int iPos)
{
	int iCount = 1;
	UI *CurNode, *PrvNode;

	if(*HEAD == NULL || iPos <= 0)
	{
		printf("List empty or Position Invalid\n");
		return;
	}

	CurNode = *HEAD;

	if(iPos = 1)
	{
		CurNode = *HEAD;
		*HEAD = *HEAD->next;
		free (CurNode);
		printf("Position %d Node freed\n",iPos);
		return;
	}
	else
	{
		while((CurNode != NULL) && (iCount < (iPos - 1)))
		{
			iCount += 1;
			PrvNode = CurNode;
			CurNode = CurNode->next;
		}
		if(CurNode == NULL) 
		{
			printf("Position %d does not exist\n",iPos);
			return;
		}
		else
		{
			PrvNode->next = CurNode->next;
			free(PrvNode);
			printf("Node Freed from Position %d\n",iPos);
			return;
		}
	}
}


int main()
{
	UI HEAD = {0};
	
	return 0;
}
