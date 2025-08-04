/*
 * Create a BST with following requirements:
 * 1: First, you will enter the length of the name.
 * 2: Enter the name that will be stored in a character array.
 * 3: Construct the Binary Search Tree by inserting the values stored in the character array.
 * 4: The insert method should not enter the duplicate character in binary tree, you can enter the name that contain different characters only.
 * 5: After the construction of Binary tree, the program should be able to print the characters in pre-order, post order, and in-order traversal of the name entered by the user.
*/

#include <iostream>

using namespace std;

template <typename T>
class TreeNode{
private:
    T* m_object{nullptr};
    TreeNode* m_left{nullptr};
    TreeNode* m_right{nullptr};
public:
    TreeNode() = default;

    TreeNode(T* object){
        m_object = object;
    }

    void setObject(T* object){ m_object = object; }
    void setLeft(TreeNode* left){ m_left = left; }
    void setRight(TreeNode* right){ m_right = right; }

    T* getObject() const { return m_object; }
    TreeNode* getLeft() const { return m_left; }
    TreeNode* getRight() const { return m_right; }
};

void insert(TreeNode<char>* root, char* object){
    TreeNode<char>* node = new TreeNode<char>(object);

    // Temp will traverse whole tree until null while
    // secondLast will track the node before temp
    TreeNode<char> *temp = root, *secondLast = root;

    while(temp){
        secondLast = temp;
        if(*object < *secondLast->getObject()){
            temp = secondLast->getLeft();
        }
        else if(*object > *secondLast->getObject()){
            temp = secondLast->getRight();
        }
        else{
            std::cout << "Not inserting duplicate!\n";
            delete node;
            return;
        }
    }

    if(*object < *secondLast->getObject()){
        secondLast->setLeft(node);
    }
    else if(*object > *secondLast->getObject()){
        secondLast->setRight(node);
    }
}

void inOrder(TreeNode<char>* root){
    if(root == nullptr) return;
    inOrder(root->getLeft());
    std::cout << *root->getObject() << ' ';
    inOrder(root->getRight());
}

void preOrder(TreeNode<char>* root){
    if(root == nullptr) return;
    std::cout << *root->getObject() << ' ';
    preOrder(root->getLeft());
    preOrder(root->getRight());
}

void postOrder(TreeNode<char>* root){
    if(root == nullptr) return;
    postOrder(root->getLeft());
    postOrder(root->getRight());
    std::cout << *root->getObject() << ' ';
}

int main(){
    std::cout << "Enter name length: ";
    int nameLength{};
    std::cin >> nameLength;

    std::cout << "Enter name: ";
    char* name = new char[nameLength];
    std::cin >> name;

    TreeNode<char>* root = new TreeNode<char> {};

    root->setObject(&name[0]);

    for(int i{1}; name[i] != '\0'; i++){
        insert(root, &name[i]);
    }

    std::cout << "InOrder: ";
    inOrder(root);
    std::cout << '\n';

    std::cout << "PreOrder: ";
    preOrder(root);
    std::cout << '\n';

    std::cout << "PostOrder: ";
    postOrder(root);
    std::cout << '\n';

    return 0;
}
