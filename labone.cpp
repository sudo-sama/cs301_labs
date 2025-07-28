/*
 * Lab Requirements:
 * 1: Create 5 Faculty members and assign them roles based on their ages
 * 2: Build a singly linked list
 * This program is quite self descriptive
 */

#include <iostream>
#include <string>

using namespace std;

// This is model for a Faculty Member
class Faculty{
private:
    std::string m_name{};
    int m_age{};
    std::string m_post{};
public:
    Faculty() = default;
    Faculty(std::string name, int age, std::string post)
    : m_name{name}, m_age{age}, m_post{post} {}

    void setName(std::string name){ m_name = name; }
    void setAge(int age){ m_age = age; }
    void setPost(std::string post){ m_post = post; }

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }
    std::string getPost() const { return m_post; }
};

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
class List{
private:
    Node<T>* m_head{};
    Node<T>* m_current{};
    int m_size{};
public:
    List(): m_head{nullptr}, m_current{nullptr}, m_size{-1}
    {}
    void add(const T& object){
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

        m_current = node;
        ++m_size;
    }

    void print(){
        Node<T>* temp = m_head;
        while(temp){
            Faculty member = temp->getObject();
            std::cout << member.getName() << ' ' << member.getAge()
            << ' ' << member.getPost() << '\n';
            temp = temp->getNext();
        }
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

// Asks user for input for a faculty member
Faculty createMember(){
    std::cout << "Enter name: ";
    std::string name{};
    std::cin >> name;
    std::cout << "Enter age: ";
    int age{};
    std::cin >> age;
    if(age >= 25 && age <= 35){
        return Faculty{ name, age, "Lecturer" };
    }
    else if(age >= 36 && age <= 45){
        return Faculty{ name, age, "Assistant Professor" };
    }
    else if(age >= 46 && age <= 60){
        return Faculty{ name, age, "Professor" };
    }
    else{
        return Faculty{ name, age, "No Position" };
    }
}

int main(){
    List<Faculty> l{};

    for(int i{0}; i < 5; i++){
        Faculty member{ createMember() };
        l.add(member);
    }

    l.print();

    return 0;
}
