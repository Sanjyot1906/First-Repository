#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void print_list(struct Node *n){
    while(n != NULL){
        cout << n -> data << "\t";
        n = n -> next;
    }
}

int main(){
    // Declaring Structure nodes;
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    
    // Allocating space for them;
    head = (struct Node*)malloc(sizeof(Node));
    second = (struct Node*)malloc(sizeof(Node));
    third = (struct Node*)malloc(sizeof(Node));

    // Assigning data;
    head -> data = 1;
    second -> data = 2;
    third -> data = 3;

    // Linking them together;
    head -> next = second;
    second -> next = third;
    third -> next = NULL;

    // Printing linked list data;
    print_list(head);

    return 0;
}