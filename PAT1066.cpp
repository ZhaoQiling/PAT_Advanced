#include <cstdio>
using namespace std;
int max(int a, int b){
    return a > b ? a : b;
}
struct Node{
    Node(int k, Node* l, Node* r, int h)
    : key(k), left(l), right(r), height(h){}
    int key;
    Node* left, *right;
    int height;
};
int getHeight(Node* root){
    if(root == NULL)
        return -1;
    return root->height;
}
Node* llrotation(Node* root){
    Node* ret = root->left;
    root->left = ret->right;
    ret->right = root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    ret->height = max(getHeight(ret->left), getHeight(ret->right)) + 1;
    return ret;
}
Node* rrrotation(Node* root){
    Node* ret = root->right;
    root->right = ret->left;
    ret->left = root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    ret->height = max(getHeight(ret->left), getHeight(ret->right)) + 1;
    return ret;
}
Node* lrrotaion(Node* root){
    root->left = rrrotation(root->left);
    return llrotation(root);
}
Node* rlrotaion(Node* root){
    root->right = llrotation(root->right);
    return rrrotation(root);
}
Node* insertNode(Node* root, int key){
    if(root == NULL)
        return new Node(key, NULL, NULL, 0);

    if(key < root->key){
        root->left = insertNode(root->left, key);
        if(getHeight(root->left) - getHeight(root->right) == 2){
            //llrotation
            if(key < root->left->key)
                root = llrotation(root);
            //lrrotaion
            else if(root->left->key < key)
                root = lrrotaion(root);
        }
    }
    else if(root->key < key){
        root->right = insertNode(root->right, key);
        if(getHeight(root->right) - getHeight(root->left) == 2){
            if(key < root->right->key)
                root = rlrotaion(root);
            else if(root->right->key < key)
                root = rrrotation(root);
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}
int main(){
    int nNode;
    scanf("%d", &nNode);
    Node* root = NULL;
    for(int i = 0; i < nNode; i++){
        int key;
        scanf("%d", &key);
        root = insertNode(root, key);
    }
    printf("%d", root->key);
    return 0;
}
