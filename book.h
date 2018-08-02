//Book.h

struct Book{
	long int book_id;
	char title[30];
	char author[30];
	char publication[30];
	int year;
	struct Book *next;
};

//prototypes
struct Book* loadBooks(char filename[]);
void storeBooks(char filename[],struct Book*);
struct Book* addBook(struct Book* header,struct Book b);
struct Book* searchBook(struct Book* header,long int id);
void viewAll(struct Book* header);
void deleteBook(struct Book* header,long int id);
void sortBooks(struct Book** header);
void copynode(struct Book* nnode,struct Book* b);
void sortedInsert(struct Book** head,struct Book* b);
void update(struct Book** b);
