// DataStructure.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

struct st{
	int val;
	struct st *next;
};

int createNode(struct st **Node, int  iData)
{
	struct st *NewNode = (struct st*)calloc(1, sizeof(struct st));
	NewNode->val = iData;
	
	(*Node) = NewNode;
	NewNode->next = NULL;

	return 0;
}
int InsertNode(struct st** sNode, int iData) 
{
	struct st* NewNode = (struct st*)calloc(1, sizeof(struct st));
	NewNode->val = iData;	
	struct st *CurNode = *sNode;
#if 0
	while(
	(*sNode)->next = NewNode;
	NewNode = NULL;
#else
	while(CurNode != NULL)
	{
		CurNode = CurNode->next;
	}
	NewNode->next = CurNode;
	CurNode = NewNode;
#endif
	return 0;
}	
int AddNode(struct st**Node, int iPos, int iData)
{
	struct st* NewNode = (struct st*)calloc(1, sizeof(struct st));
	struct st* PrvNode = NULL;
	struct st* CurNode = NULL;
	CurNode = *Node;
	int iCount = 1;
	
	NewNode->val = iData;

	// count the position 
	while((CurNode != NULL) && (iPos > iCount))
	{
		PrvNode = CurNode;	CurNode = CurNode->next;	iCount++;
	}

	if(CurNode == NULL) //add at Last
	{
		PrvNode->next = NewNode;
		NewNode->next = CurNode; //Since curNode is NULL we can assign NULL also
		return 0;
	}
	else
	{	
		PrvNode->next = NewNode;
		NewNode->next = CurNode;	
		return 0;	
	}
	
}

struct st * CreateNode(struct st* Node)
{
	struct st *NewNode = (struct st *)calloc(1,sizeof(struct st));
	struct st *CurNode = Node;
	int iData = 0;
	
	if(Node == NULL)
	{
		printf("Enter the data:");
		scanf("%d", &iData);
		NewNode->val = iData;
		NewNode->next = Node;
		Node = NewNode;
	}
	else
	{
		printf("Node is already created\nTry with Insert Node Selection Option\n");
		free(NewNode);
		return Node;
	}

	return NewNode;
}

struct st * InsertFirst(struct st* Node)
{
	struct st *NewNode = (struct st *)calloc(1,sizeof(struct st));
	struct st *CurNode = Node;
	int iData = 0;
	printf("Enter the data:");
	scanf("%d", &iData);
	NewNode->val = iData;
	
	NewNode->next = Node;
	Node = NewNode;

	return NewNode;
}

struct st * InsertLast(struct st* Node)
{
	struct st *NewNode = (struct st *)calloc(1,sizeof(struct st));
	int iData = 0;
	printf("Enter the data:");
	scanf("%d", &iData);
	NewNode->val = iData;
	struct st *CurNode = Node;
	struct st *PrvNode = Node;
		
	while(CurNode != NULL)
	{
		PrvNode = CurNode;
		CurNode = CurNode->next;
	}
	
	NewNode->next = CurNode;
	PrvNode->next = NewNode;
	
	return Node;
}
struct st* InsertMiddle(struct st* Node)
{
	struct st *NewNode = (struct st *)calloc(1,sizeof(struct st));
	int iData = 0;
	int iCount = 0;
	printf("Enter the data:");
	scanf("%d", &iData);
	NewNode->val = iData;
	struct st *CurNode = Node;
	struct st *SlowNode = Node;
	struct st *FastNode = Node;

	while((FastNode != NULL) && (FastNode->next != NULL))
	{
		iCount++;
		CurNode = SlowNode;
		SlowNode = SlowNode->next;
		FastNode = FastNode->next;
		FastNode = FastNode->next;
	}
	
	printf("\nMiddle Position is [%d]\n", iCount);

	CurNode->next = NewNode;
	NewNode->next = SlowNode;
	
	//free(NewNode);
	return Node;

}

struct st * InsertPos(struct st* Node)
{
	struct st *NewNode = (struct st *)calloc(1,sizeof(struct st));
	struct st *CurNode = Node;
	struct st *PrvNode = Node;

	int iData = 0;
	int iPos = 0;
	int iCount = 0;

	printf("Enter the position\n");
	scanf("%d", &iPos);
	
	printf("Enter the data:");
	scanf("%d", &iData);
	
	NewNode->val = iData;

	while((CurNode != NULL) && (iCount < (iPos - 1)))
	{
		iCount++;
		PrvNode = CurNode;
		CurNode = CurNode->next;
	}

	if(CurNode == NULL) // Last node
	{
		PrvNode->next = NewNode;
		NewNode->next = NULL;
		return Node;
	}
	else //Position Node
	{
		PrvNode->next = NewNode;
		NewNode->next = CurNode;
		return Node;
	}

	return Node;
}

void PrintList(struct st* Node)
{
	struct st* CurNode = Node;
	int iCount = 0;
	
	if(Node ==  NULL)
	{
		printf("List is empty..");
		return;
	}
	
	printf("\n\n");		
	while(CurNode != NULL)
	{
		printf("[%d]: %d\t", ++iCount, CurNode->val);
		CurNode = CurNode->next;
	}
	printf("\n\n");
}

struct st * DeleteNode(HEAD)
{
	struct  st *NewNode = (strut st *)calloc(struct st *);

}

struct st * DeleteAllNodes(HEAD)
{
	struct  st *NewNode = (strut st *)calloc(struct st *);

}

struct st * ReverseNodes(HEAD)
{
	struct  st *CurNode = HEAD;
	struct  st *LastNode = NULL;
	struct st *TempNode = NULL;

	while(CurNode != NULL)
	{
		LastNode = CurNode;
		CurNode = CurNode->next;
	}

}

struct st * SwapNode(HEAD)
{
	struct  st *NewNode = (strut st *)calloc(struct st *);

}


int main(int argc, char* argv[])
{
	struct st *HEAD = NULL;
	
	int iSel = 0;
	do{
		printf("\t\tCreate Node\t\t:1\n\t\tInsert at Begninning\t:2\n\t\tInsert at End\t\t:3\n\t\tInsertMiddle\t\t:4\n");
		printf("\t\tInsert at n'th Position\t:5\n\t\tPrint the list\t\t:6\n\t\tDeleteNode\t\t:7\n\t\tDeleteAll\t\t:8\n");
		printf("\t\tReverseList\t\t:9\n\t\tSwapData\t\t:10\n\t\tExit\t\t\t:0\n");
		scanf("%d",&iSel);
		
		switch(iSel)
		{
		case 1:
			HEAD = CreateNode(HEAD);
			PrintList(HEAD);
			break;
		case 2:
			HEAD = InsertFirst(HEAD);
			PrintList(HEAD);
			break;
		case 3:
			HEAD = InsertLast(HEAD);
			PrintList(HEAD);
			break;
		case 4:
			HEAD = InsertMiddle(HEAD);
			PrintList(HEAD);
			break;
		case 5:
			HEAD = InsertPos(HEAD);
			PrintList(HEAD);
			break;
		case 6:
			PrintList(HEAD);
			break;
		case 7:
			HEAD = DeleteNode(HEAD);
			break;
		case 8:
			HEAD = DeleteAllNodes(HEAD);
			break;
		case 9:
			HEAD = ReverseNodes(HEAD);
			break;
		case 10:
			HEAD = SwapNode(HEAD);
			break;
		case 0:
			exit(0);
		default:
			printf("Invalid Selection\nExiting Program...\n");
			exit(0);
		}

	}while(iSel != 0);
	
	
	return 0;
}


