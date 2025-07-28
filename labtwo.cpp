/*
 * Program Requirements:
 * 1: Implement a stack of integer array
 * 2: Implement a stack of linked list which store int values
 * The program is quite self descriptive
 */

#include <iostream>

using namespace std;

template <typename T>
class StackArray{
private:
    T* m_stack;
    int m_size;
    int m_current;
public:
    StackArray(int size){
        m_stack = new T[size];
        m_size = size;
        m_current = -1;
    }
    bool isFull(){ return m_current == m_size; }
    bool isEmpty(){ return m_current <= -1; }
    void push(T object){
        if(isFull()){
            std::cout << "Stack is full!\n";
            return;
        }
        m_stack[++m_current] = object;
    }
    T pop(){ return m_stack[m_current--]; }
};

template <typename T>
class Node{
private:
    T m_object{};
    Node<T>* m_next;
public:
    Node() = default;

    void setObject(const T& object) { m_object = object; }
    void setNext(Node<T>* next) { m_next = next; }

    T getObject() const { return m_object; }
    Node<T>* getNext() const { return m_next; }
};

template <typename T>
class StackLinkedList{
private:
    Node<T>* m_head{};
public:
    void push(T object){
        Node<T>* node = new Node<T>{};
        node->setObject(object);
        if(m_head == nullptr){
            m_head = node;
        }
        else{
            Node<T>* last = m_head;
            while(last && last->getNext()){
                last = last->getNext();
            }
            last->setNext(node);
        }
    }
    T pop(){
        Node<T>* last = m_head;
        Node<T>* secondLast = last;
        while(last && last->getNext()){
            secondLast = last;
            last = last->getNext();
        }
        int lastObject = last->getObject();
        delete last;
        secondLast->setNext(nullptr);
        return lastObject;
    }
    ~StackLinkedList(){
        Node<T>* temp = nullptr;
        while(m_head){
            temp = m_head;
            m_head = m_head->getNext();
            delete temp;
        }
    }
};

int main(){
    int stackSize{5};
    StackArray<int> a{stackSize};

    std::cout << "===== This is Array Stack =====\n";

    for(int i{1}; i <= stackSize; i++){
        a.push(i * 2);
    }

    for(int i{1}; i <= stackSize; i++){
        std::cout << a.pop() << ' ';
    }

    std::cout << "\n ===== This is Linked List Stack =====\n";

    StackLinkedList<int> l{};

    for(int i{1}; i <= stackSize; i++){
        l.push(i * 3);
    }

    for(int i{1}; i <= stackSize; i++){
        std::cout << l.pop() << ' ';
    }

    std::cout << '\n';

    return 0;
}
