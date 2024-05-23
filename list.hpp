#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef> 
#include <cstdlib> 
#include <iostream> 

template<typename T>
class List {
public:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
    };

    class iterator {
    private:
        Node* node;

    public:
        iterator(Node* n = nullptr) : node(n) {}
        T& operator*() const { return node->data; }
        iterator& operator++(); 
        iterator& operator--(); 
        bool operator!=(const iterator& other) const { return node != other.node; }
        Node* getNode() const { return node; }
    };

private:
    Node* head;
    Node* tail;
    size_t count;

public:
    List();
    ~List();
    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    size_t size() const { return count; }
    bool empty() const { return count == 0; }
    iterator begin() const { return iterator(head); }
    iterator end() const { return iterator(nullptr); }
};

#include "list.inl"

#endif // LIST_HPP
