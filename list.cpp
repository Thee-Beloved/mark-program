#include <iostream>
using namespace std;

struct Node {
    float num;
    Node* next;
};

int main() {
    Node *first, *temp1, *temp2, *last;

    // First node
    first = new Node;
    cout << "Please enter the value of the first node: ";
    cin >> first->num;
    first->next = nullptr;

    // Second node
    temp1 = new Node;
    cout << "Please enter the value of the second node: ";
    cin >> temp1->num;
    temp1->next = nullptr;
    first->next = temp1;

    // Third node
    temp2 = new Node;
    cout << "Please enter the value of the third node: ";
    cin >> temp2->num;
    temp2->next = nullptr;
    temp1->next = temp2;

    // Fourth node
    last = new Node;
    cout << "Please enter the value of the fourth node: ";
    cin >> last->num;
    last->next = nullptr;
    temp2->next = last;

    // Display values
    cout << "The values are: ";
    cout << first->num << " : " << temp1->num << " : " << temp2->num << " : " << last->num << endl;

    return 0;
}
