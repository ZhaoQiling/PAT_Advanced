#include <iostream>
#include <cmath>
template <typename T>
class AVLNode {
public:
	T key;
	AVLNode<T>* leftChild;
	AVLNode<T>* rightChild;
	int height;

	AVLNode(T k, AVLNode<T>* left, AVLNode<T>* right)
		:key(k), leftChild(left), rightChild(right){}
};

template<typename T>
class AVLTree {
public:
	AVLNode<T>* mRoot;
public:
	AVLTree();
	~AVLTree();

	void preOrder() const;
	void inOrder() const;
	void postOrder() const;

	void insert(T key);

	int getHeight(AVLNode<T>* ) const;
	int max(int a, int b);
private:
	void destory(AVLNode<T>* pNode);

	void preOrder(AVLNode<T>* pNode) const;
	void inOrder(AVLNode<T>* pNode) const;
	void postOrder(AVLNode<T>* pNode) const;

	AVLNode<T>* insert(AVLNode<T>*& pNode, T key);

	AVLNode<T>* leftRotation(AVLNode<T>* pNode);
	AVLNode<T>* rightRotation(AVLNode<T>* pNode);
	AVLNode<T>* leftRightRotation(AVLNode<T>* pNode);
	AVLNode<T>* rightLeftRotation(AVLNode<T>* pNode);

};

template<typename T>
AVLTree<T>::AVLTree()
{
	mRoot = NULL;
}

template<typename T>
AVLTree<T>::~AVLTree()
{
	destory(mRoot);
}

template<typename T>
void AVLTree<T>::destory(AVLNode<T>* pNode)
{
	if (pNode == NULL)
		return;
	destory(pNode->leftChild);
	destory(pNode->rightChild);
	delete pNode;
}

template<typename T>
void AVLTree<T>::preOrder() const
{
	preOrder(mRoot);
}
template<typename T>
void AVLTree<T>::preOrder(AVLNode<T>* pNode) const
{
	if (pNode == NULL)
		return;
	std::cout << pNode->key << " ";
	preOrder(pNode->leftChild);
	preOrder(pNode->rightChild);
}



template<typename T>
void AVLTree<T>::inOrder() const
{
	inOrder(mRoot);
}

template<typename T>
void AVLTree<T>::inOrder(AVLNode<T>* pNode) const
{
	if (pNode == NULL)
		return;
	inOrder(pNode->leftChild);
	std::cout << pNode->key << " ";
	inOrder(pNode->rightChild);
}

template<typename T>
void AVLTree<T>::postOrder() const
{
	postOrder(mRoot);
}
template<typename T>
void AVLTree<T>::postOrder(AVLNode<T>* pNode) const
{
	if (pNode == NULL)
		return;
	postOrder(pNode->leftChild);
	postOrder(pNode->rightChild);
	std::cout << pNode->key << " ";
}

template<typename T>
int AVLTree<T>::getHeight(AVLNode<T>* pNode) const
{
	if (pNode != NULL)
		return pNode->height;
	return 0;
}

template<typename T>
void AVLTree<T>::insert(T key)
{
	insert(mRoot, key);
}
template<typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>*& pNode, T key)
{
	if (pNode == NULL)
	{
		pNode = new AVLNode<T>(key, NULL, NULL);
	}
	else if (key > pNode->key)
	{
		pNode->rightChild = insert(pNode->rightChild, key);
		if (getHeight(pNode->rightChild) - getHeight(pNode->leftChild) == 2)
		{
			if (key > pNode->rightChild->key)
				pNode = leftRotation(pNode);
			else if (key < pNode->rightChild->key)
				pNode = rightLeftRotation(pNode);
		}
	}
	else if (key < pNode->key)
	{
		pNode->leftChild = insert(pNode->leftChild, key);
		if (getHeight(pNode->leftChild) - getHeight(pNode->rightChild) == 2)
		{
			if (key < pNode->leftChild->key)
				pNode = rightRotation(pNode);
			else if (key > pNode->leftChild->key)
				pNode = leftRightRotation(pNode);
		}
	}
	pNode->height = max(getHeight(pNode->leftChild), getHeight(pNode->rightChild)) + 1;
	return pNode;
}

template<typename T>
AVLNode<T>* AVLTree<T>::leftRotation(AVLNode<T>* pRoot)
{
	AVLNode<T>* prChild = pRoot->rightChild;
	pRoot->rightChild = prChild->leftChild;
	prChild->leftChild = pRoot;

	pRoot->height = max(getHeight(pRoot->leftChild), getHeight(pRoot->rightChild)) + 1;
	prChild->height = max(getHeight(prChild->leftChild), getHeight(prChild->rightChild)) + 1;

	return prChild;
}

template<typename T>
AVLNode<T>* AVLTree<T>::rightRotation(AVLNode<T>* pRoot)
{
	AVLNode<T>* prChild = pRoot->leftChild;
	pRoot->leftChild = prChild->rightChild;
	prChild->rightChild = pRoot;

	pRoot->height = max(getHeight(pRoot->leftChild), getHeight(pRoot->rightChild)) + 1;
	prChild->height = max(getHeight(prChild->leftChild), getHeight(prChild->rightChild)) + 1;

	return prChild;
}

template<typename T>
AVLNode<T>* AVLTree<T>::leftRightRotation(AVLNode<T>* pRoot)
{
	pRoot->leftChild = leftRotation(pRoot->leftChild);
	return rightRotation(pRoot);
}

template<typename T>
AVLNode<T>* AVLTree<T>::rightLeftRotation(AVLNode<T>* pRoot)
{
	pRoot->rightChild = rightRotation(pRoot->rightChild);
	return leftRotation(pRoot);
}

template<typename T>
int AVLTree<T>::max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
    AVLTree<int>* myT = new AVLTree<int>();
    int val;
    std::cin >> val;
    while(std::cin >> val)
        myT->insert(val);
    std::cout << myT->mRoot->key;
}
