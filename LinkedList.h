#include <iostream>
using namespace std;


class Node {
public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insert(int value){
        this->size++;
        if (head == nullptr){
            head = new Node(value);
            tail = head;
            return;
        }

        this->tail->next = new Node(value);
        this->tail = this->tail->next;
        return;
    }

    void remove(int value){
        this->size--;
        Node* prev = nullptr;
        for (auto node = this->head; node != nullptr; node = node->next){
            if (node->value == value){
                if (node == tail){
                    prev->next = nullptr;
                    tail = prev;
                    delete node;
                    return;
                }

                if (node == head){
                    head = node->next;
                    delete node;
                    return;
                }

                prev->next = node->next;
                delete node;
                return;
            }
            prev = node;
        }
        this->size++;
        return;
    }

};