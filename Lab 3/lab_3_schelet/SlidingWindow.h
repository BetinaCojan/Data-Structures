/**
 * LabSD 3
 * SlidingWindow.h
 * Purpose: Skeleton code for the sliding window.
 *
 * @author Gabriel Bercaru
 */

#ifndef __SLIDINGWINDOW_H__
#define __SLIDINGWINDOW_H__

#include <vector>

#include "DoublyLinkedList.h"

template <typename T>
class SlidingWindow {
private:
    int capacity;
    std::vector<T> container;
    DoublyLinkedList<T> window;

public:
    /**
     * Constructor. Initializes a new sliding window
     * based on the given vector. The window
     * will contain at most `capacity` elements.
     */
    SlidingWindow(const std::vector<T> container, int capacity) {
        this->capacity = capacity;
        this->container = container;

        for (int i = 0; i < capacity; i++) {
            window.addLast(container[i]);
        }
    }

    ~SlidingWindow() {
    }

    /**
     * Makes the window advance one position further.
     * 
     * @return A pointer to the new window head node.
     */
    Node<T> *advance() {
        // move the first element of the container to the last position
        T element = container.front();
        container.erase(container.begin());
        container.push_back(element);
        
        Node<T> * current = getWindowHead();
        int i = 0;

        // iterates through the nodes of the window and updates the data of each node with the corresponding element in the container
        while(i < capacity && current != nullptr) {
            current->data = container[i];
            current = current->next;
            i++;
        }

        // if the window nodes have not been filled completely,fill up to maximum capacity
        while(i < capacity && i < container.size()) {
            window.addLast(container[i]);
            i++;
        }

        return getWindowHead();
    }

    // Getter
    Node<T> *getWindowHead() {
        return window.getHead();
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,
            SlidingWindow<U>& window);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, SlidingWindow<T>& window) {
    Node<T> *it = window.getWindowHead();

    os << "[ ";
    while (it != nullptr) {
        os << it->data << " ";
        it = it->next;
    }
    os << "]";

    return os;
}

#endif // __SLIDINGWINDOW_H__
