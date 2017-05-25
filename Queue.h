//
// Created by daniel on 17/04/17.
//

#ifndef STRUCTURES_QUEUE_H
#define STRUCTURES_QUEUE_H

#include <cstdlib>
#include <cstdio>

template <class T>
class Queue {
    public:
        Queue() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void enqueue(T data)
        {
            Node * node = new Node;
            node->data = data;
            node-> next = nullptr;
            if(this->isEmpty())
            {
                this->head = this->tail = node;
            }
            else
            {
                node->next = this->head;
                this->head = node;
            }
        }

        T dequeue()
        {
            if (!this->isEmpty())
            {
                Node *currentTail = nullptr;
                T data = NULL;
                if (this->head == this->tail) {
                    currentTail = this->tail;
                    this->head = this->tail = nullptr;
                }
                else
                {
                    Node *node = this->head;
                    while ((node->next != this->tail) && (node->next != nullptr)) {
                        node = node->next;
                    }
                    currentTail = this->tail;
                    this->tail = node;
                    this->tail->next = nullptr;
                }
                data = currentTail->data;
                delete currentTail;
                return data;
            }
            return NULL;
        }

        bool isEmpty()
        {
            return this->head == nullptr;
        }

        void print()
        {
            Node * node = this->head;
            while(node != nullptr)
            {
                printf("%i,", node->data);
                node = node->next;
            }
            printf("\n");
        }

        ~Queue()
        {
            while(!this->isEmpty())
            {
                this->dequeue();
            }

            if(this->head != nullptr)
                delete this->head;
            if(this->tail != nullptr)
                delete this->tail;
        }

    private:
        struct Node{
            Node * next;
            T data;
        };
        Node * head;
        Node * tail;
};


#endif //STRUCTURES_QUEUE_H
