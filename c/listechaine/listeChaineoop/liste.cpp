#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

class LinkedList {
private:
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  void append(int value) {
    Node *newNode = new Node{value, nullptr};
    if (!head) {
      head = newNode;
    } else {
      Node *temp = head;
      while (temp->next) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void display() const {
    Node *temp = head;
    while (temp) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "nullptr" << endl;
  }

  void remove(int value) {
    if (!head)
      return;

    if (head->data == value) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node *temp = head;
    while (temp->next && temp->next->data != value) {
      temp = temp->next;
    }

    if (temp->next) {
      Node *toDelete = temp->next;
      temp->next = temp->next->next;
      delete toDelete;
    }
  }

  ~LinkedList() {
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main() {
  LinkedList list;

  list.append(10);
  list.append(20);
  list.append(30);

  cout << "Initial list: ";
  list.display();

  list.remove(20);
  cout << "After removing 20: ";
  list.display();

  return 0;
}