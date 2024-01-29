/**
 * LabSD 3
 * Algorithms.h
 * Purpose: Wrapper class for Lab3 algorithms.
 *
 * @author Gabriel Bercaru
 */

#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

#include "DoublyLinkedList.h"

template <typename T>
class Algorithms {
public:
    /**
     * Sort a non empty singly linked list.
     * You should also check if head is null.
     *
     * @param head First node of the list to be sorted.
     * @return pointer to the first node of the sorted list.
     */
    static Node<T> *sort(Node<T> *head) {
        Node<T> *beforeCurrent;
        Node<T> *afterCurrent;
        Node<T> *current;
        Node<T> *check;
        Node<T> *tailSorted;

        tailSorted = head;
        check = head;

        // update tail of sorted list
        while(tailSorted->next != nullptr) {
            tailSorted = check;
            check = check->next;

            // compare the data of tail with the data of the next node 
            if (check->data < tailSorted->data) {
                current = head;

                // go to the position where the node must be inserted
                while((current != check) && (current->data < check->data)) {
                    beforeCurrent = current;
                    current = current->next;
                }

                afterCurrent = current->next;

                // change position of the found node
                tailSorted->next = check->next;
                check->next = current;
                
                if (current == head) {
                    head = check;
                } else {
                    beforeCurrent->next = check;
                }
            }
        }

        return head;
    }

    /**
     * Reverses the order of the elements in the linked
     * list pointed to by head.
     *
     * @param head First node of the list to be sorted.
     * @return pointer to the first node of the reversed list.
     */
    static Node<T> *reverse(Node<T> *head) {
        Node<T>* tail;
        Node<T>* second;
        Node<T>* newHead;
        Node<T>* current;

        current = head;
        while (current->next != nullptr) {
            second = current;
            current = current->next;
        }

        if (current != second) {
            // set the head of the new list
            newHead = current;
            current->next = second;
            second->next = nullptr;

            // build connections for the reversed list
            while (head->next != nullptr) {
                tail = second;

                // go through the list again with "current" pointer
                current = head;
                while (current->next != nullptr) {
                    second = current;
                    current = current->next;
                }

                // change the direction of the link between the end nodes
                if (current != second) {
                    current->next = second;
                    second->next = nullptr;
                } 
            }
        } 

        head = newHead;

        return head;
    }
};

#endif // __ALGORITHMS_H__
