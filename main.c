//main program

#include "Book.c"
#include <stdio.h>

void menu()
{
	printf("\n1.Search book\n2.Add book\n3.Delete book\n4.Sort books\n5.Update\n6.View all\n7.Quit"); //display menu
}


int main()
{
	int ch=0;
	struct Book *header=NULL;
	struct Book b,*t; //this is for input from user
	long int id;
	header=loadBooks("books.txt"); //calling and loading existing books in database

	while(ch!=7) //repeat choice is quit
	{
		menu();
		printf("\n");//shows menu
		scanf("%d",&ch); //input menu choice
		switch(ch)
		{
			case 1:
					printf("\n enter the book id u want to search\n ");
					scanf("%d",&id);
					t=searchBook(header,id);
					if(t!=NULL)
					printf("\n %ld %s %s %s %d",t->book_id,t->title,t->author,t->publication,t->year);
					break;
			case 2:
					//input from user
					printf("Enter Book id: ");
					scanf("%ld",&b.book_id);
					printf("Enter Book title: ");
					scanf("%s",b.title);
					printf("Enter Book author: ");
					scanf("%s",b.author);
					printf("Enter Book publication: ");
					scanf("%s",b.publication);
					printf("Enter Book year: ");
					scanf("%d",&b.year);
					header=addBook(header,b); //calling add book method
					break;
			case 3:
					printf("\n enter the book id u want to delete\n ");
					scanf("%d",&id);
					deleteBook(header,id);
					break;
			case 4:
					sortBooks(&header);
					break;
			case 5:
					printf("\nEnter the book_id of book u want to update\n");
					scanf("%d",&id);
					t=searchBook(header,id);
					update(&t);
					break;
			case 6:
					printf("\nExisiting books below : ");
					viewAll(header);
					break;
			case 7:
					//code for store books
					storeBooks("books.txt",header);
					printf("\nBye, end of program...");
					break;
			default:
					printf("\nSorry, invalid choice(1 to 7 valid)!!!");
		}
	}

	return 0;
}

