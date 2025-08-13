#pragma once
#include "cellnode.h"

// ”зел двухсв€зного списка содержащий данные €чейки
struct Node {
    CellNode data;
    Node* next;
    Node* prev;

    Node() : next(nullptr), prev(nullptr) {}
    Node(const CellNode& data) : data(data), next(nullptr), prev(nullptr) {}
};

// ƒвусв€зный список дл€ хранени€ €чеек в строке
class DoubleLinkedList {
public:
    Node* head;
    Node* tail;

    DoubleLinkedList();
    ~DoubleLinkedList();

    void Append(Node* newNode);
    void Prepend(Node* newNode);
    void InsertAfter(Node* prevNode, Node* newNode);
    void Remove(Node* node);
    Node* GetNodeAt(int index) const;
    void Clear();
};