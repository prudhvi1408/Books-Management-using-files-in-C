//Book.c
#include "book.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//Definition
struct Book* loadBooks(char filename[])
{
	//code here
	struct Book *header=NULL; //nothing

	FILE *fp=fopen(filename,"r");//open file for reading
	struct Book b; //create a book variable
	while(1)
    {
        fscanf(fp,"%ld%s%s%s%d",&b.book_id,b.title,b.author,b.publication,&b.year);//reading second record onwards from book
        if(!feof(fp))  //repeat until end of file
        {
            header=addBook(header,b); //adding each book to linked list of books header
           // fscanf(fp,"%ld%s%s%s%d",&b.book_id,b.title,b.author,b.publication,&b.year);//reading second record onwards from book
        }
        else break;
    }

	fclose(fp); //close the file
	return header;
}
void deleteBook(struct Book* header,long int id)
{
    struct Book *t,*t1;
    t=header;
	while(t!=NULL)
    {
        if(t->book_id==id)
        {
            printf("\nBook with the below details is deleted");
            printf("\n %ld %s %s %s %d",t->book_id,t->title,t->author,t->publication,t->year);
            t1->next=t->next;
            free(t);
            return;//printing book details
        }
        else
        {
            t1=t;
            t=t->next;
        }

    }
    printf("\n Book not found");
}

void sortBooks(struct Book** header)
{
    struct Book *t,*head;
    t=*header;
    head=NULL;
    while(t!=NULL)
    {
        sortedInsert(&head, t);
        t=t->next;
    }
    *header=head;
}
void copynode(struct Book* nnode,struct Book* b)
{
    nnode->book_id=b->book_id;
    strcpy(nnode->author,b->author);
    strcpy(nnode->title,b->title);
    strcpy(nnode->publication,b->publication);
    nnode->year=b->year;
    nnode->next=NULL;
}
void sortedInsert(struct Book** head,struct Book* b)
{
    struct Book *t,*nnode,*t1;
    nnode=(struct Book*)malloc(sizeof(struct Book));
    copynode(nnode,b);
    t=*head;
    if(t==NULL)
        *head=nnode;
    else
    {
        while(t&&(t->book_id<b->book_id))
        {
            t1=t;
            t=t->next;
        }
        if(t==NULL)
            t1->next=nnode;
        else if(t==*head)
        {
            nnode->next=*head;
            *head=nnode;
        }
        else
        {
            nnode->next=t;
            t1->next=nnode;
        }
    }
}
void storeBooks(char filename[],struct Book* header)
{
    FILE *fp=fopen(filename,"w");
    struct Book *b=header;
    while(b!=NULL)
    {
        fprintf(fp,"%ld %s %s %s %d\n",b->book_id,b->title,b->author,b->publication,b->year);
        b=b->next;
    }
}


struct Book* addBook(struct Book* header,struct Book b)
{
	//code here
	if(header==NULL) //when reading first book and add to list
	{
		header=(struct Book*)malloc(sizeof(struct Book)); //new node is allocated as header
		*header=b; //set book b values as header
		header->next=NULL; //first book next is nothing
	}
	else //when reading and adding second book onwards
	{
		struct Book *nb=(struct Book*)malloc(sizeof(struct Book)); //new node is allocated as new node nb
		struct Book *t=header; //traversing purpose
		*nb=b; //set b values to nb
		nb->next=NULL; //new book next is nothing
		while(t->next!=NULL) //traverse upto null before
			t=t->next; //move next
		t->next=nb;
	}
	return header;
}


struct Book* searchBook(struct Book* header,long int id)
{
	//code here
	struct Book* t=header;
	while(t!=NULL)
    {
        if(t->book_id==id)
        {
            return t;
        }
        else t=t->next;
    }
    printf("\n Book not found");
    return NULL;
}

void update(struct Book** b)
{
    int ch,tmp;
    char t[30];
    printf("\nwhat do u want to update :\n1.book_title\n2.book_author\n3.publication\n4.year\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 :
            printf("Enter book title\n");
            scanf("%s",t);
            strcpy((*b)->title,t);
            break;
        case 2 :
            printf("Enter book author\n");
            scanf("%s",t);
            strcpy((*b)->author,t);
            break;
        case 3 :
            printf("Enter publication\n");
            scanf("%s",t);
            strcpy((*b)->publication,t);
            break;
        case 4 :
            printf("Enter year\n");
            scanf("%d",&tmp);
            (*b)->year=tmp;
            break;
        default : printf("\nInvalid option");
    }
}

void viewAll(struct Book* header)
{
	//code here
	struct Book *t=header; //t starts for traversing
	int slno=0;
	while(t!=NULL) //traverse upto end of books list
	{
		slno++; //serial number increment
		printf("\n#%d : %ld %s %s %s %d",slno,t->book_id,t->title,t->author,t->publication,t->year); //printing book details
		t=t->next;//move to next book
	}
}



