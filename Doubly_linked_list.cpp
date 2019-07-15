#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

Node* head = new Node();
Node* tail = new Node();

void append(int data) {
  Node* new_node = new Node();
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = tail;
  tail->next = new_node;
  tail = tail->next;
}

void rmv(Node* target) {
  Node* current_node = head;
  while (current_node->next != NULL && current_node != target) {
    current_node = current_node->next;
  } 
  if (current_node == tail) {
    current_node->prev->next = NULL; 
    tail = current_node->prev;
    return;
  }
  if (current_node == head) {
    current_node->next->prev = NULL;
    head = current_node->next;
    return;
  }
  current_node->prev->next = current_node->next; 
  current_node->next->prev = current_node->prev;
}

void insert(int data, int pos) {
  Node* new_node = new Node();
  new_node->data = data;
  int i = 0;
  Node* current_node = head;
  while (i < pos - 1) {
    ++i;
    current_node = current_node->next;
  }
  new_node->next = current_node->next;
  new_node->prev = current_node;
  current_node->next->prev = new_node;
  current_node->next = new_node;
}

int main() {
  head->data = 0;
  head->next = tail;
  head->prev = NULL;
  tail->data = 1;
  tail->next = NULL;
  tail->prev = head;
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