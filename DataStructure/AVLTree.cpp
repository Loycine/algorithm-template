#include<iostream>

template <typename T>
class AVLTree {
public:
    class Node{
    public:
        T key;
        int height;
        Node* left;
        Node* right;

        int countSubTree;
        int repeat;

        Node(T x){
            key = x;
            height = 1;
            left = NULL;
            right = NULL;

            countSubTree = 1;
            repeat = 1;
        }
    };

    Node* root = NULL;

    /*
                 y                             x
                / \      Right Rotate         / \
               x   C    -------------->      A   y
              / \                               / \
             A   B                             B   C
    */
    Node* rightRotate(Node* head){
        Node* newHead = head->left;
        head->left = newHead->right;
        newHead->right = head;

        newHead->countSubTree = head->countSubTree;
        head->countSubTree = newHead->countSubTree - newHead->repeat - ((newHead->left!=NULL)?newHead->left->countSubTree:0);

        head->height = max((head->left!=NULL)?head->left->height:0, (head->right != NULL)? head->right->height:0) + 1;
        newHead->height = max((newHead->left!= NULL)?newHead->left->height:0, newHead->right->height ) + 1;
        return newHead;
    }

    /*
             x                              y
            / \        Left Rotate         / \
           A   y      ------------->      x   C
              / \                        / \
             B   C                      A   B
    */
   Node* leftRotate(Node* head){
        Node* newHead = head->right;
        head->right = newHead->left;
        newHead->left = head;


        newHead->countSubTree = head->countSubTree;
        head->countSubTree = newHead->countSubTree - newHead->repeat - ((newHead->right!=NULL)?newHead->right->countSubTree:0);

        head->height = max((head->left!=NULL)?head->left->height:0, (head->right != NULL)? head->right->height:0) + 1;
        newHead->height = max(newHead->left->height, (newHead->right!= NULL)?newHead->right->height:0 ) + 1;

        return newHead;
    }


    void insert(T x){
        root = insertUtil(root, x);
    }

    int getBalance(Node* head){
        if(head == NULL) return 0;

        return ((head->left != NULL)?head->left->height:0) - ((head->right != NULL)? head->right->height:0);
    }

    int searchSmaller(T x)
    {
        return searchSmallerUtil(x, root);
    }

    int searchSmallerUtil(T i, Node* head){
        if(head == NULL) return 0;
        int total = 0;                        
        Node* cur = head;
        while(cur != NULL){
            if(i > cur->key){
                total += (cur->countSubTree - ((cur->right!=NULL)?cur->right->countSubTree:0));
                cur = cur->right;
            }else if(i < cur->key){
                cur = cur->left;
            }else
                return total+=((cur->left!=NULL)?cur->left->countSubTree:0);                    
        }
        return total;
    }

    Node* insertUtil(Node* head, T x){
        if(head == NULL){
            Node* n = new Node(x);
            return n;
        }

        if(x< head->key){
            head->left = insertUtil(head->left, x);
        }else if(x > head->key){
            head->right = insertUtil(head->right, x);
        }else{
            head->repeat++;
            head->countSubTree++;
            return head;
        }

        // Note about the NULL check here
        head->height = max((head->left!= NULL)? head->left->height:0, (head->right != NULL)? head->right->height:0) + 1;
        head->countSubTree = ((head->left!= NULL)? head->left->countSubTree:0) + ((head->right != NULL)? head->right->countSubTree:0) + head->repeat;

        int balFactor = getBalance(head);
        if(balFactor > 1 && x < head->left->key){
            return rightRotate(head);
        }

        if(balFactor > 1 && x > head->left->key){
            head->left = leftRotate(head->left);
            return rightRotate(head);
        }

        if(balFactor < -1 && x > head->right->key){
            return leftRotate(head);
        }

        if(balFactor < -1 && x < head->right->key){
            head->right = rightRotate(head->right);
            return leftRotate(head);
        }
        return head;
    }    

    void traverse()
    {
        traverseUtil(root);
        cout<<endl;
    }

    void traverseUtil(Node* cur)
    {
        if(cur == NULL)
        {
            cout << "_ ";
            return;
        }
        cout << cur->key << " ";
        traverseUtil(cur->left);
        traverseUtil(cur->right);
    }
};

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        AVLTree<int> tree;
        vector<int> ret;
        int n = nums.size();
        for(int i=n-1; i>=0; i--)
        {
            tree.insert(nums[i]);
            //tree.traverse();
            ret.push_back(tree.searchSmaller(nums[i]));
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
