#include <iostream>
using namespace std;

class SinglyLinkedListNode { // SinglyLinkedListNode class
    
    public:
        int data;
        SinglyLinkedListNode* next;
    
    // method to add node to list
    void append(SinglyLinkedListNode**headRef, int newData) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(); // create the node
        SinglyLinkedListNode *last = *headRef; // will be used to find last element in list
        
        // assign newNode->data to newData value
        newNode->data = newData;
        // assign newNode->next to NULL as this will be last item in list eventually
        newNode->next = NULL;
        
        if(*headRef == NULL) { // if list is empty, simply make our new node the head and return
            *headRef = newNode;
            return;
        }
        
        while(last->next != NULL) { // iterate to the end of the list to find 'last' node prior to append
            last = last->next;
        }
        last->next = newNode; // assign the last->next to our new node, appending to list
        return;
    }
};

// func signature
void printLinkedList(SinglyLinkedListNode* head);

// Driver program
int main() {
    int n, temp;
    cin >> n;
    SinglyLinkedListNode* list = NULL;
    while(n > 0) {
        cin >> temp;
        list->append(&list, temp);
        n--;
    }
    printLinkedList(list);
    return 0;
}

// func implementation
void printLinkedList(SinglyLinkedListNode* head) {
    while(head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
}
