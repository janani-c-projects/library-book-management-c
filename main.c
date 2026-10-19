
#include <stdio.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int issued;
};

struct Book books[MAX_BOOKS];
int count = 0;

int findBookIndex(int id) {
    int i;

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            return i;
        }
    }

    return -1;
}

void addBook(void) {
    int id;

    if (count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        return;
    }

    if (findBookIndex(id) != -1) {
        printf("Book ID already exists!\n");
        return;
    }

    printf("Enter Book Title: ");
    if (scanf(" %49[^\n]", books[count].title) != 1) {
        printf("Invalid title!\n");
        return;
    }

    printf("Enter Author Name: ");
    if (scanf(" %49[^\n]", books[count].author) != 1) {
        printf("Invalid author name!\n");
        return;
    }

    books[count].id = id;
    books[count].issued = 0;
    count++;

    printf("Book added successfully!\n");
}

void displayBooks(void) {
    int i;

    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\n===== LIBRARY BOOK LIST =====\n");

    for (i = 0; i < count; i++) {
        printf("\nBook ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);

        if (books[i].issued == 1) {
            printf("Status: Issued\n");
        } else {
            printf("Status: Available\n");
        }
    }
}

void searchBook(void) {
    int id;
    int index;

    printf("Enter Book ID to search: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        return;
    }

    index = findBookIndex(id);

    if (index == -1) {
        printf("Book not found!\n");
    } else {
        printf("\nBook found!\n");
        printf("Book ID: %d\n", books[index].id);
        printf("Title: %s\n", books[index].title);
        printf("Author: %s\n", books[index].author);
        printf("Status: %s\n",
               books[index].issued ? "Issued" : "Available");
    }
}

void issueBook(void) {
    int id;
    int index;

    printf("Enter Book ID to issue: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        return;
    }

    index = findBookIndex(id);

    if (index == -1) {
        printf("Book not found!\n");
    } else if (books[index].issued == 1) {
        printf("This book is already issued!\n");
    } else {
        books[index].issued = 1;
        printf("Book issued successfully!\n");
    }
}

void returnBook(void) {
    int id;
    int index;

    printf("Enter Book ID to return: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        return;
    }

    index = findBookIndex(id);

    if (index == -1) {
        printf("Book not found!\n");
    } else if (books[index].issued == 0) {
        printf("This book was not issued!\n");
    } else {
        books[index].issued = 0;
        printf("Book returned successfully!\n");
    }
}

int main(void) {
    int choice;

    while (1) {
        printf("\n===== LIBRARY BOOK MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please restart and enter a number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                printf("Thank you for using the Library System!\n");
                return 0;

            default:
                printf("Invalid choice! Enter a number from 1 to 6.\n");
        }
    }
}
