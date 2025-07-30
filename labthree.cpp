/*
 * Program Requirements:
 * Implement a Queue using LinkedList
*/
#include <iostream>

using namespace std;

template <typename T>
class Node{
private:
    T m_object{};
    Node* m_next{};
public:
    Node() = default;

    void setObject(const T& object){ m_object = object; }
    void setNext(Node* next){ m_next = next; }

    T getObject() const { return m_object; }
    Node* getNext() const { return m_next; }
};

template <typename T>
class Queue{
private:
    Node<T>* m_front{};
    Node<T>* m_rear{};
public:
    Queue() = default;

    bool isEmpty(){ return m_front == nullptr; }

    void enqueue(const T& object){
        Node<T>* node = new Node<T>{};
        node->setObject(object);
        if(isEmpty()){
            m_front = node;
        }
        else{
            m_rear->setNext(node);
        }
        m_rear = node;
    }

    T dequeue(){
        if(isEmpty()){
            std::cout << "Queue is empty.\n";
            throw -10;
        }
        else{
            Node<T>* temp = m_front;
            T object = temp->getObject();
            m_front = m_front->getNext();
            delete temp;
            return object;
        }
    }

    void display(){
        Node<T>* temp = m_front;
        while(temp){
            std::cout << temp->getObject() << ' ';
            temp = temp->getNext();
        }
        std::cout << '\n';
    }
};

int main(){
    Queue<int> q{};

    q.enqueue(30);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(50);
    q.enqueue(40);

    q.display();

    q.dequeue();

    q.display();

    q.dequeue();

    q.display();

    return 0;
}
