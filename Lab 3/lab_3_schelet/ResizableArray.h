/**
 * LabSD 3
 * ResizableArray.h
 * Purpose: Skeleton code for the resizable array.
 *
 * @author Gabriel Bercaru
 */

#ifndef __RESIZABLEARRAY_H__
#define __RESIZABLEARRAY_H__

#include <assert.h>

template <typename T>
class ResizableArray {
private:
    int defaultCapacity = 5;
    int expandFactor = 2;

    int numElements;
    int maxCapacity;
    T *data;

public:
    // Constructor
    ResizableArray() {
        numElements = 0;
        maxCapacity = defaultCapacity;

        data = new T[maxCapacity];
    }

    // Another constructor
    ResizableArray(int initialCapacity) {
        numElements = 0;
        maxCapacity = initialCapacity;

        data = new T[maxCapacity];
    }

    // Another constructor
    ResizableArray(int initialCapacity, int defaultFactor) {
        numElements = 0;
        maxCapacity = initialCapacity;
        expandFactor = defaultFactor;

        data = new T[maxCapacity];
    }

    // Destructor
    ~ResizableArray() {
        delete[] data;
    }

    /**
     * Adds the specified element at the end of the array.
     *
     * @param element Element to be added at the end of the array.
     */
    void addLast(T element) {

        // check if it will exceed the maximum capacity
        if(numElements >= maxCapacity) {
            resizeArray(maxCapacity * expandFactor);
        } 

        data[numElements] = element;
        numElements++;

    }

    /**
     * Adds the specified element at the beginning of the array.
     *
     * @param element Elment to be added at the beginning of the array.
     */
    void addFirst(T element) {
        
        // check if it will exceed the maximum capacity
        if(numElements >= maxCapacity) {
            resizeArray(maxCapacity * expandFactor);
        }

        // move all the elements 
        for (int i = numElements; i > 0; i--) {
            data[i] = data[i - 1];
        }

        data[0] = element;
        numElements++;

    }

    /**
     * Removes and returns the last element of the array.
     *
     * @return Value of the last element stored in the array.
     */
    T removeLast() {
        T lastElement;

        if (isEmpty()) {
            std::cerr << "The list is empty";
        } else {
            lastElement = data[numElements - 1];
            numElements--;

            // Reducing the capacity when the array is less than half full
            int halfCapacity = maxCapacity / 2;
            if (halfCapacity >= defaultCapacity && halfCapacity > numElements) {
                resizeArray(halfCapacity);
            }
        
        }

        return lastElement;
    }

    /**
     * Removes and returns the first element of the array.
     *
     * @return Value of the first element stored in the array.
     */
    T removeFirst() {
        T firstElement;

        if (isEmpty()) {
            std::cerr << "The list is empty";
        } else {
            firstElement = data[0];

            for (int i = 1; i < numElements - 1; i++) {
                data[i - 1] = data[i];
            }
            numElements--;

            // Reducing the capacity when the array is less than half full 
            int halfCapacity = maxCapacity / 2;
            if (halfCapacity > numElements && halfCapacity >= defaultCapacity) {
                resizeArray(halfCapacity);
            }
        }

        return firstElement;
    }

    /**
     * Checks if the array contains any elements.
     *
     * @return True if the array contains no elements, False otherwise.
     */
    bool isEmpty() {
        return (numElements == 0);
    }

    /**
     * Returns the number of elements in the array.
     *
     * @return The number of elements stored in the array.
     */
    int size() {
        return numElements;
    }

    /**
     * Adds the specified element on pos'th position of the array.
     *
     * @param element Element to be added on the specified position in the array.
     * @param pos Position on which the new element should be placed.
     */
    void addOnPos(T element, int pos) {

        // check if it will exceed the maximum capacity
        if(numElements >= maxCapacity) {
            resizeArray(maxCapacity * expandFactor);
        }

        // check if the pos is valid
        if (pos < 0 || pos > numElements) {

            throw std::out_of_range("Invalid position");

        } else {

            for (int i = numElements; i > pos; i--) {
                data[i] = data[i - 1];
            }

            data[pos] = element;
            numElements++;
        }
    }

    /**
     * Removes and returns the pos'th element of the array.
     *
     * @param pos Position from which to extract the element.
     * @return Value stored on pos'th position.
     */
    T removeFromPos(int pos) {
        T removedElement;

        // check if the pos is valid
        if (pos < 0 || pos > numElements - 1) {

            throw std::out_of_range("Invalid position");
        
        } else {

            removedElement = data[pos];

            for (int i = pos; i < numElements - 1; i++) {
                data[i] = data[i + 1];
            }
            numElements--;

            // Reducing the capacity when the array is less than half full 
            int halfCapacity = maxCapacity / 2;
            if (halfCapacity > numElements && halfCapacity >= defaultCapacity) {
                resizeArray(halfCapacity);
            }    
        }
        return removedElement;
    }


    /**
     * Resize the array to a larger/smaller capacity
     * 
     */
    void resizeArray(int newCapacity) {
        // Create a new array with the updated capacity
        T *newData = new T[newCapacity];

        // Copy elements from the old array to the new array
        for(int i = 0; i < numElements; i++) {
            newData[i] = data[i];
        }

        // Update maxCapacity and data pointer
        maxCapacity = newCapacity;
        delete[] data;
        data = newData;

    }


    // Getters & Setters
    T *getData() {
        return data;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,
            const ResizableArray<U>& ra);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, ResizableArray<T>& ra) {
    os << "[ ";
    for (int i = 0; i < ra.size(); i++) {
        os << (ra.getData())[i] << " ";
    }
    os << "]";

    return os;
}

#endif // __RESIZABLEARRAY_H__
