#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	
	struct node *next;
};

struct node *createNode(int data);

int traverse(struct node *head);

void attachBegin(struct node **head, struct node *tem);
void attachEnd(struct node **head, struct node *tem);
int attachAfter(struct node *head, int sdata, struct node *tem);

int detachBegin(struct node **head);
int detachEnd(struct node **head);
int detachAfter(struct node *head, int sdata);

int search(int data, struct node *head);



int main()
{
	struct node *head = NULL;
	struct node *tem;
	int data, sdata;
	int op = 1;
	int status;
	
	while(op != 0)
	{
		printf("\n\nChoose from following:\n 1>>AttachBegin, 2>>AttachEnd, 3>>AttacheAfter,  \n 4>>DettachBegin, 5>>DetachEnd, 6>>DetachAfter \n 7>>Traverse, 8>>Search, 0>>Exit. \n\n");
		scanf("%d",&op);
		
		if(op == 1)
		{
			printf("Enter your data:\n");
			scanf("%d",&data);
			
			tem = createNode(data);
			
			attachBegin(&head,tem);
			
			traverse(head);
			
		}

		if(op == 2)
		{
			printf("Enter your data:\n");
			scanf("%d",&data);
			
			tem = createNode(data);
			
			attachEnd(&head,tem);
			
			traverse(head);
			
		}
		
		if(op == 3)
		{
			printf("Enter your new data:\n");
			scanf("%d",&data);
			
			tem = createNode(data);
			
			printf("Enter the after which new data will be inserted: \n");
			scanf("%d",&sdata);
			
			status = attachAfter(head, sdata ,tem);
			
			if(status)
			  printf("Attached successfully! \n");
			  
			if(status ==0)
			  printf("Attachment Failed! \n");  
			
			traverse(head);
			
		}
		
		if(op == 4)
		{			
			
			status = detachBegin(&head);
			
			if(status)
			  printf("Detached Successfully! \n");
			
			if(status == 0)
			  printf("Can't Detach! \n");
			
			traverse(head);
			
		}

		if(op == 5)
		{			
			
			status = detachEnd(&head);
			
			if(status)
			  printf("Detached Successfully! \n");
			
			if(status == 0)
			  printf("Can't Detach! \n");
			
			traverse(head);
			
		}
		
		if(op == 6)
		{
			printf("Enter the data after which data will be deleted: \n");
			scanf("%d",&sdata);
			
			status = detachAfter(head, sdata);
			
			if(status)
			  printf("Detached Successfully! \n");
			  
			if(status == 0)
			  printf("Detachment Failed! \n");  
			  
			traverse(head);  
			
		}
		
		
		
		if(op == 7)
		{
			
			
			status = traverse(head);
			
			if(status == 0)
			  printf("List is empty! \n");
			
			
		}
		
		if(op == 8)
		{
			printf("Enter your data to search:\n");
			scanf("%d",&data);
			
			status = search(data,head);
			
			if(status)
			  printf("Data found at node no.: %d \n",status);
			  
			if(status == 0)
			  printf("Data not found! \n");  
			
			
		}
		
		
			      				
		if(op == 0)
		{
			printf("Exited!\n");
		}
		
		
	}
	
	
	
	
	
	
}

struct node *createNode(int data)
{
	struct node *tn;	
	
	tn = (struct node*)malloc(sizeof(struct node));
	
	tn -> data = data;
	
	tn -> next = NULL;
	
	
	return tn;
}



int traverse(struct node *head)
{
	struct node *crnt;
	int nn = 1;
	
	if(head != NULL)
	 {      
	 	crnt = head;
	 	
	 	printf("\nYour current list:\n");
	 
	 	while(crnt != NULL)
	 	{
	 		printf("Node No.: %d\n",nn);
	 		printf("Data: %d\n",crnt -> data);
	 			 		
	 		crnt = crnt -> next;
	 		nn++;
	 	}
	 	
	 	return 1;
	 }
	 
 return 0; 

}



void attachBegin(struct node **head, struct node *tem)
{
	if(*head == NULL)
	 *head = tem;
	
	else
	{
		tem -> next = *head;
		
		*head = tem;
	} 
}

void attachEnd(struct node **head, struct node *tem)
{
	struct node *crnt;

	if(*head == NULL)
	  *head = tem;	
	
	else
	 {
			crnt = *head;

			while(crnt -> next != NULL)
			{
				crnt = crnt -> next;
			}
		
		crnt -> next = tem;
	 }
}

int attachAfter(struct node *head, int sdata, struct node *tem)
{
	struct node *crnt, *nxt;
	int nno = 1;	
		
	if(head != NULL)
	{
		crnt = head;
		nxt = crnt -> next;
		
		while(crnt != NULL)
		{
			if(crnt -> data == sdata)
			{
				tem -> next = nxt;
				
				crnt -> next = tem;
				
				return nno;
			}
			
			nno++;
			
			crnt = crnt -> next;
			
		}
		
		
	}
	
	return 0;	
}


int detachBegin(struct node **head)
{
	struct node *crnt;

	if(*head != NULL)
	{
	
 		crnt = *head;
	
		if(crnt -> next == NULL)
		{
			free(crnt);
		
			*head = NULL;
		}
	
		else
		{
			*head = crnt -> next;
		
			free(crnt);
		}
		
	     return 1;	
	
	}
	return 0;
}


int detachEnd(struct node **head)
{
	struct node *crnt;
	struct node *prvs;

	if(*head != NULL)
	  {

		crnt = *head;

                while(crnt -> next != NULL)
		 {
			prvs = crnt;
			crnt = crnt -> next;
		 }
	       
	       prvs -> next = NULL ;	      
	
  	       free(crnt);	
  	       
  	       return 1;       

	    }
	    
	    return 0;

}

int detachAfter(struct node *head, int sdata)
{
	struct node *crnt, *nxt;

	crnt = head;
	
	nxt = crnt -> next;

	if(head != NULL)
 	  {
		while(nxt != NULL)
		{
			if(crnt -> data == sdata)
			{
				(crnt -> next) = (nxt -> next);
				
				free(nxt);
				
				return 1; 
			}
			
			crnt = crnt -> next;     
			
			nxt = crnt -> next;                                      
		}
		
				
	  }
	else
	  return 0;
}



int search(int data, struct node *head)
{
	struct node *crnt;
	int nno = 1;	
		
	if(head != NULL)
	{
		crnt = head;
		
		while(crnt != NULL)
		{
			if(crnt -> data == data)
			{
				return nno;
			}
			
			nno++;
			
			crnt = crnt -> next;
			
		}
		
		
	}
	
	return 0;	
}























