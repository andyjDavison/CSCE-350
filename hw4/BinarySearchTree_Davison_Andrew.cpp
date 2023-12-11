#include<string>
#include<iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class BSTree {
    struct node {
        int data;
        node* left;
        node* right;
    };

    public:
        // consrtucts an empty tree
        BSTree(): root(nullptr) {}
        // constructs a tree with a given root
        BSTree(node* rootNode): root(rootNode) {}
        void insert(int val) {
            root = insert(val, root);
        }
        void search(int val) {
            cout << "Path traversed: ";
            node* temp = search(val, root);
            cout << endl;
            if(temp == nullptr)
                cout << "Search key not found" << endl;
            else
                cout << "Node " << temp->data << " found in BST" << endl;
        }
        void findMin() {
            cout << "Smallest Value in BST: " << findMinValue(root)->data << endl;
        }
        void findMax() {
            cout << "Largest Value BST: "<< findMaxValue(root)->data << endl;
        }
        void remove(int val) {
            root = remove(val, root);
        }
        void display() {
            cout << "BST nodes are: ";
            inorderTraversal(root);
            cout << endl;
        }

    private:
        node* root;

        node* insert(int value, node* n) {
            if(n == nullptr) {
                n = new node;
                n->data = value;
                n->left = nullptr;
                n->right = nullptr;
            } else if(value < n->data) {
                n->left = insert(value, n->left);
            } else if(value > n->data) {
                n->right = insert(value, n->right);
            } else if(value == n->data) {
                cout << "Node " << value << " is a duplicate node. Cannot insert Node " << value << " again" << endl;
            }
            return n;
        }

        node* search(int value, node* n) {
            if(n == nullptr) 
                return nullptr;
            else if(value < n->data) {
                cout << n->data << " ";
                return search(value, n->left);
            }
            else if(value > n->data) {
                cout << n->data << " ";
                return search(value, n->right);
            }
            else {
                return n;
            }
        }

        node* findMinValue(node* n) {
            if(n == nullptr) 
                return nullptr;
            else if(n->left == nullptr) 
                return n;
            else 
                return findMinValue(n->left);
        }

        node* findMaxValue(node* n) {
            if(n == nullptr)
                return nullptr;
            else if(n->right == nullptr)
                return n;
            else
                return findMaxValue(n->right);
        }

        node* remove(int value, node* n) {
            node* temp;
            if(n == nullptr)
                return nullptr;
            else if(value < n->data)
                n->left = remove(value, n->left);
            else if(value > n->data)
                n->right = remove(value, n->right);
            else if(n->left && n->right) {
                temp = findMinValue(n->right);
                n->data = temp->data;
                n->right = remove(n->data, n->right);
            }
            else {
                temp = n;
                if(n->left == nullptr)
                    n = n->right;
                else if(n->right == nullptr)
                    n = n->left;
                delete temp;
            }
            return n;
        }

        void inorderTraversal(node* n) {
            if(n == nullptr) 
                return;
            inorderTraversal(n->left);
            cout << n->data << " ";
            inorderTraversal(n->right);
        }

};

int main() {
    BSTree t;
    // t.insert(5);
    // t.insert(3);
    // t.insert(7);
    // t.insert(1);
    // t.insert(8);
    // t.insert(4);
    // t.display();
    // t.remove(4);
    // t.display();
    // t.insert(2);
    // t.display();
    // t.insert(7);
    // t.display();
    // t.insert(6);
    // t.display();
    // t.remove(7);
    // t.display();
    // t.search(9);
    bool quit = false;
    while(!quit) {
        int choice;
        cout << "Enter the numeber to perform its action on a BST:\n1.Insert a value\n2.Search for a value\n3.Delete a value\n4.Find the min. value\n5.Find the max. value" << endl;
        cin >> choice;
        switch (choice)
        {
        int val;
        case 1:
            cout << "Enter a value you wish to be inserted into BST:" << endl;
            cin >> val;
            t.insert(val);
            t.display();
            break;
        case 2:
            cout << "Enter value you wish to search for in BST:" << endl;
            cin >> val;
            t.search(val);
            t.display();
            break;
        case 3:
            cout << "Enter a value you wish to be removed from the BST:" << endl;
            cin >> val;
            t.remove(val);
            t.display();
            break;
        case 4:
            t.findMin();
            t.display();
            break;
        case 5:
            t.findMax();
            t.display();
            break;
        default:
            quit = true;
            break;
        }
    }
    return 0;
}

