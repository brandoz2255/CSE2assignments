#ifndef VECTOR20_H
#define VECTOR20_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Vector20 {

public:
    // Default constructor
    Vector20()
        : theSize{0}, theCapacity{20}
    {
        data = new T[theCapacity];
    }

    // Copy constructor
    Vector20(const Vector20 &rhs)
        : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, data{nullptr}
    {
        data = new T[theCapacity];
        for (int k = 0; k < theSize; ++k)
            data[k] = rhs.data[k];
    }

    // Copy assignment operator
    Vector20& operator=(const Vector20 &rhs)
    {
        if (this != &rhs) {
            delete[] data; // Delete the old data
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            data = new T[theCapacity]; // Allocate new space
            for (int k = 0; k < theSize; ++k)
                data[k] = rhs.data[k];
        }
        return *this;
    }

    // Destructor
    ~Vector20()
    {
        delete[] data;
    }

    // Check if vector is empty
    bool empty() const
    {
        return theSize == 0;
    }

    // Return the size of the vector
    int size() const
    {
        return theSize;
    }

    // Return the capacity of the vector
    int capacity() const
    {
        return theCapacity;
    }

    // Access element by index (non-const)
    T& operator[](int index)
    {
        assert(index >= 0 && index < theSize);
        return data[index];
    }

    // Access element by index (const)
    const T& operator[](int index) const
    {
        assert(index >= 0 && index < theSize);
        return data[index];
    }

    // Get last element
    T& back() const
    {
        assert(theSize > 0);
        return data[theSize - 1];
    }

    // Get first element
    T& front() const
    {
        assert(theSize > 0);
        return data[0];
    }

    // Add element at the end
    void push_back(const T &x)
    {
        if (theSize >= theCapacity) {
            expandCapacity();
        }
        data[theSize++] = x;
    }

    // Remove last element
    void pop_back()
    {
        assert(theSize > 0);
        --theSize;
    }

    // Erase element at a specific index
    void erase(int index)
    {
        if (index >= 0 && index < theSize) {
            for (int i = index; i < theSize - 1; ++i) {
                data[i] = data[i + 1];
            }
            --theSize;
        } else {
            cout << "Index out of bounds!" << endl;
        }
    }

    // Insert an element at a specific index
    void insert(int index, const T& value)
    {
        if (index < 0 || index > theSize) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        if (theSize >= theCapacity) {
            expandCapacity();
        }

        // Shift elements to the right to make space for the new element
        for (int i = theSize; i > index; --i) {
            data[i] = data[i - 1];
        }

        // Insert the new element at the given index
        data[index] = value;
        ++theSize;
    }

private:
    int theSize;       // Current size of the vector
    int theCapacity;   // Maximum capacity of the vector
    T* data;           // Pointer to the array of data

    // Helper function to expand capacity when needed
    void expandCapacity()
    {
        cout << "EXPANDING capacity..." << endl;
        theCapacity = theCapacity * 2 + 1;
        T* moredata = new T[theCapacity];

        // Move the data to the new larger array
        for (int i = 0; i < theSize; ++i) {
            moredata[i] = std::move(data[i]);
        }

        delete[] data;
        data = moredata;
    }
};

#endif
