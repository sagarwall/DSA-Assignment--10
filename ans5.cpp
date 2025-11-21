#include <iostream>
#include <unordered_set>
using namespace std;

// Define linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Detect loop in linked list
bool hasLoop(Node* head) {
    unordered_set<Node*> visited;

    Node* current = head;
    while (current != nullptr) {
        if (visited.find(current) != visited.end()) {
            return true; // loop detected
        }
        visited.insert(current);
        current = current->next;
    }
    return false; // no loop
}

int main() {
    // Create nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    // Connect nodes: 1->2->3->4
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create loop: 4->2
    fourth->next = second;

    // Check for loop
    if (hasLoop(head))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
