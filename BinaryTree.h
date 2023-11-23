#include <iostream>
using namespace std;


struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value){
        this->value = value;
    }
};

class BinaryTree {
public:
    Node* head;

    BinaryTree(){
        this->head = nullptr;
    }

    void insert(int value){
        Node* newNode = new Node(value);

        if (this->head == nullptr){
            this->head = newNode;
            return;
        }
        Node* current = this->head;
        while (true){
            if (current->value <= value){
                if (current->left == nullptr){
                    current->left = newNode;
                    return;
                }
                current = current->left;
                continue;
            } else {
                if (current->right == nullptr){
                    current->right = newNode;
                    return;
                }
                current = current->right;
                continue;
            }
        }
        return;
    }

    void remove(int value){
        if (this->head == nullptr){
            return;
        }

        if (this->head->value == value){
            if (this->head->left != nullptr){
                Node* temp = this->head->right;
                this->head = this->head->left;
                if (temp != nullptr){
                    this->mergeBinaryTrees(temp);
                }
                return;
            } else if (this->head->left != nullptr){
                this->head = this->head->right;
            } else{
                this->head = nullptr;
                return;
            }
        }
        
        Node* current = this->head;
        Node* prev = nullptr;
        while (true){
            if (current == nullptr){
                return;
            }
            
            if (current->value == value){
                if (prev->left == current){
                    prev->left = nullptr;
                } else {
                    prev->right = nullptr;
                }
                

                this->mergeBinaryTrees(current->left);
                this-> mergeBinaryTrees(current->right);

                break;

            }
            
            if (current->value <= value){
                prev = current;
                current = current->left;
                continue;

            } else {
                prev = current;
                current = current->right;
                continue;

            }
        }
        return;
    }

    void mergeBinaryTrees(Node* node){
        if (node != nullptr){
            this->insert(node->value);
            if (node->left != nullptr){
                mergeBinaryTrees(node->left);
            }

            if (head->right != nullptr){
                mergeBinaryTrees(node->right);
            }
        }

        return;
    }

    void printTree(){
        if (this->head != nullptr){
            printTree(this->head->left, 1);
            cout << endl << this->head->value << endl;
            printTree(this->head->right, 1);
            cout << endl;
            

        }
    }

    void printTree(Node* node, int counter){
        if (node != nullptr){
            printTree(node->left, counter + 1);
            cout << counter << ":" << node->value << " ";
            printTree(node->right, counter + 1);
            

        }
    }

};