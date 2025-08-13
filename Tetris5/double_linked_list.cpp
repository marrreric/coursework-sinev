#include "double_linked_list.h"


DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(nullptr) {}

DoubleLinkedList::~DoubleLinkedList() {
    Clear();
}

void DoubleLinkedList::Append(Node* newNode) {
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoubleLinkedList::Prepend(Node* newNode) {
    if (!head) {
        head = tail = newNode;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void DoubleLinkedList::InsertAfter(Node* prevNode, Node* newNode) {
    if (!prevNode) return;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if (newNode->next) {
        newNode->next->prev = newNode;
    }
    else {
        tail = newNode;
    }
}

void DoubleLinkedList::Remove(Node* node) {
    if (!node) return;
    if (node->prev) {
        node->prev->next = node->next;
    }
    else {
        head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    else {
        tail = node->prev;
    }
    delete node;
}

Node* DoubleLinkedList::GetNodeAt(int index) const {
    Node* current = head;
    int count = 0;
    while (current) {
        if (count == index) return current;
        count++;
        current = current->next;
    }
    return nullptr;
}

void DoubleLinkedList::Clear() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
}