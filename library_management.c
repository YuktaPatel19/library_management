#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int year;
} Book;


#define MAX_BOOKS 100
Book library[MAX_BOOKS];
int book_count = 0;


void add_book(char *title, char *author, int year) {
    if (book_count < MAX_BOOKS) {
        strcpy(library[book_count].title, title);
        strcpy(library[book_count].author, author);
        library[book_count].year = year;
        book_count++;
    }
}




// Function to delete a book by title
void delete_book(char *title) {
    for (int i = 0; i < book_count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            break;
        }
    }
}

// Test functions
void test_create_book() {
    Book b;
    strcpy(b.title, "C Programming");
    strcpy(b.author, "Dennis Ritchie");
    b.year = 1978;

    assert(strcmp(b.title, "C Programming") == 0);
    assert(strcmp(b.author, "Dennis Ritchie") == 0);
    assert(b.year == 1978);
}

void test_add_book() {
    add_book("The C Programming Language", "Brian Kernighan", 1978);
    assert(book_count == 1);
    assert(strcmp(library[0].title, "The C Programming Language") == 0);
    assert(strcmp(library[0].author, "Brian Kernighan") == 0);
    assert(library[0].year == 1978);
}



void test_delete_book() {
    delete_book("Clean Code");
    assert(book_count == 2);
    assert(search_book("Clean Code") == NULL);
}

// Main function to run the tests
int main() {
    test_create_book();
    test_add_book();
    test_delete_book();
    printf("All tests passed.\n");
    return 0;
}
