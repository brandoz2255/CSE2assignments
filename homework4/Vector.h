#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cassert>   // For assert

template <typename T>
class Vector {
public:
    typedef T value_type;  // Make this typedef public

    // Constructor
    explicit Vector(int initSize = 0)
        : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY) {
        data = new T[theCapacity];
    }

    // Constructor with initial value
    Vector(int initSize, int initVal)
        : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY) {
        data = new T[theCapacity];
        for (int i = 0; i < theCapacity; i++)
            data[i] = initVal;
    }

    // Copy constructor
    Vector(const Vector& rhs)
        : theSize(rhs.theSize), theCapacity(rhs.theCapacity), data(nullptr) {
        data = new T[theCapacity];
        for (int k = 0; k < theSize; ++k)
            data[k] = rhs.data[k];
    }

    // Assignment operator
    Vector& operator=(const Vector& rhs) {
        Vector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Move constructor
    Vector(Vector&& rhs)
        : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, data{rhs.data} {
        rhs.data = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

    // Move assignment operator
    Vector& operator=(Vector&& rhs) {
        std::swap(theSize, rhs.theSize);
        std::swap(theCapacity, rhs.theCapacity);
        std::swap(data, rhs.data);
        return *this;
    }

    // Other member functions...
    bool empty() const {
        return size() == 0;
    }

    int size() const {
        return theSize;
    }

    int capacity() const {
        return theCapacity;
    }

    void clear() {
        while (!empty())
            pop_back();
        return;
    }

    T& operator[](int index) {
        assert(index >= 0 && index < theSize);
        return data[index];
    }

    const T& operator[](int index) const {
        assert(index >= 0 && index < theSize);
        return data[index];
    }

    void resize(int newSize) {
        if (newSize > theCapacity)
            reserve(newSize * 2);
        theSize = newSize;
    }

    void reserve(int newCapacity) {
        if (newCapacity < theSize)
            return;

        T* newArray = new T[newCapacity];
        for (int k = 0; k < theSize; ++k)
            newArray[k] = std::move(data[k]);

        theCapacity = newCapacity;
        std::swap(data, newArray);
        delete[] newArray;
    }

    void push_back(const T& x) {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);
        data[theSize++] = x;
    }

    void push_back(T&& x) {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);
        data[theSize++] = std::move(x);
    }

    void pop_back() {
        assert(theSize >= 1);
        --theSize;
    }

    const T& back() const {
        assert(theSize >= 1);
        return data[theSize - 1];
    }

    // Iterators
    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin() {
        return &data[0];
    }

    const_iterator begin() const {
        return &data[0];
    }

    iterator end() {
        return &data[size()];
    }

    const_iterator end() const {
        return &data[size()];
    }

    static const int SPARE_CAPACITY = 2;

private:
    int theSize;
    int theCapacity;
    T* data;
};

#endif
