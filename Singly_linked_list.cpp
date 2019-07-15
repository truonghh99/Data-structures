#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head = new Node();
Node* tail = new Node();

void append(int data) {
  Node* new_node = new Node();
  new_node->data = data;
  tail->next = new_node;
  tail = tail->next;
}

void rmv(Node* address) {
  Node* prev = head;
  while (prev->next != NULL && prev->next != address) {
    prev = prev->next;
  }
  prev->next = prev->next->next;
}

void insert(int data, int pos) {
  Node* prev = head;
  int i = 0;
  while (i < pos - 1) {
    ++i;
    prev = prev->next;
  }
  Node* new_node = new Node();
  new_node->data = data;
  new_node->next = prev->next;
  prev->next = new_node;
}

int main() {
  head->data = 0;
  head->next = tail;
  tail->data = 1;
  tail->next = NULL;
  for (int i = 2; i < 10; ++i) {
    append(i);
  }
  Node* currentNode = head;
  while (currentNode->next != NULL) {
    cout << currentNode->data << ' ';
    currentNode = currentNode->next;
  }
  cout << endl;
  insert(15, 5);
  currentNode = head;
  while (currentNode->next != NULL) {
    cout << currentNode->data << ' ';
    currentNode = currentNode->next;
  }
  rmv(currentNode);
  currentNode = head;
  cout << endl;
  while (currentNode->next != NULL) {
    cout << currentNode->data << ' ';
    currentNode = currentNode->next;
  }
  return 0;
}