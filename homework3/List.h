#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class List {
private:
    

    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value = T(), Node* p = nullptr, Node* n = nullptr)
            : data(value), prev(p), next(n) {}
    };

    Node* head;  
    Node* tail;  
    int theSize; 

    
    void init() {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

public:
    

    class iterator {
    public:
        Node* current;

        

        iterator() : current(nullptr) {}

        

        iterator(Node* p) : current(p) {}

        

        T& operator*() { return current->data; }

        

        iterator& operator++() {
            current = current->next;
            return *this;
        }

        

        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

        

        iterator& operator--() {
            current = current->prev;
            return *this;
        }

        

        iterator operator--(int) {
            iterator old = *this;
            --(*this);
            return old;
        }


        bool operator==(const iterator& rhs) const { return current == rhs.current; }
        bool operator!=(const iterator& rhs) const { return !(*this == rhs); }
    };


    

    List() { init(); }

    

    List(const List& rhs) {
        init();
        for (auto& x : rhs) {
            push_back(x);
        }
    }

    
    
    ~List() {
        clear();
        delete head;
        delete tail;
    }

    


    List& operator=(const List& rhs) {
        if (this != &rhs) {
            clear();
            for (auto& x : rhs) {
                push_back(x);
            }
        }
        return *this;
    }

    


    void clear() {
        while (!empty()) {
            erase(begin());
        }
    }

    

    bool empty() const { return theSize == 0; }

    

    int size() const { return theSize; }

    

    iterator insert(iterator itr, const T& value) {
        Node* p = itr.current;
        theSize++;
        Node* newNode = new Node(value, p->prev, p);
        p->prev->next = newNode;
        p->prev = newNode;
        return iterator(newNode);
    }

    

    iterator erase(iterator itr) {
        Node* p = itr.current;
        iterator retVal(p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;
        return retVal;
    }

    
    void push_back(const T& value) {
        insert(end(), value);
    }

    

    iterator begin() { return iterator(head->next); }

    

    iterator end() { return iterator(tail); }

    

    class const_iterator {
    public:
        const Node* current;

        
        const_iterator() : current(nullptr) {}

        
        const_iterator(const Node* p) : current(p) {}

        
        const T& operator*() const { return current->data; }

        
        const_iterator& operator++() {
            current = current->next;
            return *this;
        }

        
        const_iterator operator++(int) {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        
        const_iterator& operator--() {
            current = current->prev;
            return *this;
        }

        
        const_iterator operator--(int) {
            const_iterator old = *this;
            --(*this);
            return old;
        }

        bool operator==(const const_iterator& rhs) const { return current == rhs.current; }
        bool operator!=(const const_iterator& rhs) const { return !(*this == rhs); }
    };


    const_iterator begin() const { return const_iterator(head->next); }


    const_iterator end() const { return const_iterator(tail); }
};

#endif



