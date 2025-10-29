
// Josephus Problem Simulation
// Author: Ali Rıza Öztürk
// Date: 28 Oct 2025
// Description: Solves the Josephus problem using a circular linked list.

#include <iostream>
using namespace std;

// Represents each soldier as a node in a circular linked list
struct Soldiers {
    int id;
    Soldiers* next = nullptr;
    Soldiers(int id = 0, Soldiers* next = nullptr) : id(id), next(next) {}
};

// Manages the circular linked list and the Josephus elimination process
struct Master {
    Soldiers* head = nullptr;

    bool isEmpty() const;
    void add2List(int n);        // Create circular list with n soldiers
    void printList() const;      // Debug: print all soldiers in the list
    void theGame(int k);  // Run Josephus elimination
    ~Master();                   // Properly free memory
};

// Checks if the list is empty
bool Master::isEmpty() const {
    return head == nullptr;
}

// Creates a circular linked list of n soldiers
void Master::add2List(int n) {
    if (n <= 0) {
        head = nullptr;
        return;
    }
    head = new Soldiers(1);
    Soldiers* temp = head;
    for (int i = 2; i <= n; i++) {
        temp->next = new Soldiers(i);
        temp = temp->next;
    }
    temp->next = head; // Make it circular
}

// Simulates the Josephus problem
void Master::theGame(int k) {
    if (isEmpty()) {
        cout << "Enter a valid number of soldiers\n";
        return;
    }
    if (k == 1) {
        Soldiers* temp = head;
        do {
            temp = temp->next;
        } while (temp->next != head);
        cout << "The Winner: " << temp->id << "\n";
        return;
    }
    Soldiers* prev = head;
    while (prev->next != head) {
        prev = prev->next;
    }

    while (head->next != head) { // Continue until one soldier remains

        // Move (k-1) steps forward
        for (int i = 1; i != k; i++) {
            prev = prev->next;
        }
        Soldiers* toDelete = prev->next;
        // Adjust head if the removed soldier was the head
        if (toDelete == head)
            head = head->next;

        prev->next = toDelete->next;
        delete toDelete;
    }

    cout << "The Winner: " << head->id << "\n";
}

// Optional: print the current list (for debugging)
void Master::printList() const {
    if (isEmpty()) {
        cout << "List is empty.\n";
        return;
    }
    Soldiers* temp = head;
    do {
        cout << temp->id << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

int main() {
    Master master;
    int n, k;

    cout << "Number of soldiers: ";
    cin >> n;
    cout << "Step count: ";
    cin >> k;

    master.add2List(n);
    master.theGame(k);
}

// Destructor: safely delete all nodes in the circular list
Master::~Master() {
    if (!head) return;
    Soldiers* cur = head->next;
    while (cur != head) {
        Soldiers* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    delete head;
}

