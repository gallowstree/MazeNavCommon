//
// Created by daniel on 17/04/17.
//

#ifndef STRUCTURES_QUEUE_H
#define STRUCTURES_QUEUE_H

template <class T>
class Queue {
    public:
        Queue() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        ~Queue()
        {
            //falta implementar XD
        }

        void enqueue(T data)
        {
            Node * node = new Node;
            node->data = data;
            node-> next = nullptr;
            if(this->isEmpty())
            {
                printf ("this shit is empty\n");
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
                int data = NULL;
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
                printf("%c,", node->data);
                node = node->next;
            }
            printf("\n");
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
