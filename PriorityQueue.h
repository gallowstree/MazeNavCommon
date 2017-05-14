//
// Created by daniel on 14/05/17.
//

#ifndef UNTITLED_PRIORITYQUEUE_H
#define UNTITLED_PRIORITYQUEUE_H


#include <cstdlib>
#include <cstdio>

template <class T>
class PriorityQueue {
    public:
        PriorityQueue() {
            this->head = nullptr;
        }

        void enqueue(T data, int priority)
        {
            Node * newNode = new Node;
            newNode->data = data;
            newNode-> next = nullptr;
            newNode-> previous = nullptr;
            newNode->priority = priority;
            if(this->isEmpty())
            {
                this->head = newNode;
            }
            else
            {
                Node * node = this->head;
                Node * previousNode = nullptr;
                bool lowPriorityFound = false;
                while((node != nullptr) && !lowPriorityFound)
                {
                    if(node->priority < newNode->priority)
                    {
                        lowPriorityFound = true;
                    }
                    else
                    {
                        previousNode = node;
                        node = node->next;
                    }
                }

                if(lowPriorityFound)
                {

                    if(previousNode != nullptr)
                        previousNode->next = newNode;
                    if(node == this->head)
                        this->head = newNode;
                    newNode->next = node;
                    newNode->previous = previousNode;
                    node->previous = newNode;
                }
                else
                {
                    if(previousNode != nullptr)
                        previousNode->next = newNode;
                    newNode->previous = previousNode;
                }
            }
        }

        T dequeue(int * priority)
        {
            if (!this->isEmpty())
            {
                Node * node = this->head;
                this->head = this->head->next;
                if(this->head != nullptr)
                    this->head->previous = nullptr;

                T data = node->data;
                *priority = node->priority;
                delete node;
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
                printf("priority: %i, ",node->priority);
                node = node->next;
            }
            printf("\n");
        }

        ~PriorityQueue()
        {
            int priority;
            while(!this->isEmpty())
            {
                this->dequeue(&priority);
            }

            if(this->head != nullptr)
                delete this->head;
        }

    private:
        struct Node{
            Node * next;
            Node * previous;
            T data;
            int priority;
        };
        Node * head;
        //Node * tail;
};
#endif //UNTITLED_PRIORITYQUEUE_H
