#pragma once

template <typename T>
class Node {
public:
    T Data;
    Node<T>* left;
    Node<T>* right;
};

template <typename T>
class BinaryTree {

public:
    BinaryTree();
    ~BinaryTree();

    int Add(T _item);

    int Delete(T _item);

    int Search(T _item);

	int Modify(T _item);

    int Get(T& _item);

    int Clear();

    int Display();

private:

    Node<T>* root;
    int length;

};

template <typename T>
BinaryTree<T>::BinaryTree() {
    this->root = nullptr;
    this->length = 0;
    return;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    this->root = nullptr;
    delete[] this->root;
    return;
}

template <typename T>
int BinaryTree<T>::Add(T _item) {
    if(InsertNode(this->root, _item)) { 
        this->length++;
        return true;
    }
    else { return false; }
}

template <typename T>
int BinaryTree<T>::Delete(T _item) {
    bool isDeleted = false;
    this->root = DeleteNode(this->root, _item, isDeleted);
    return isDeleted;
}

template <typename T>
int BinaryTree<T>::Search(T _item) {
	if (Get(_item)) {
		std::cout << _item;
		return 1;
	}
	else {
		return 0;
	}
}

template <typename T>
int BinaryTree<T>::Display() {
	if (this->root == nullptr) { return 0; }
	int user = -1;
	std::cout << "\n\t Inorder : 1 \n";
	std::cout << "\n\t Preorder : 2 \n";
	std::cout << "\n\t Postorder : 3 \n";
	std::cout << "\n\t : ";
	std::cin >> user;
	switch (user)
	{
	case 1:
		Inorder(this->root);
		break;
	case 2:
		Preorder(this->root);
		break;
	case 3:
		Postorder(this->root);
		break;
	default:
		break;
	}
	return 1;
}

template <typename T>
int BinaryTree<T>::Modify(T _item) {
	bool isDeleted = false;
	DeleteNode(this->root, _item, isDeleted);
	InsertNode(this->root, _item);
	return 1;
}

template <typename T>
int BinaryTree<T>::Get(T& _item) {
	return Traversal(this->root, _item);
}

template <typename T>
int BinaryTree<T>::Clear() {
	this->root = nullptr;
	delete[] this->root;
	this->root = new Node<T>;
	this->root = nullptr;
	return 1;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
template <typename T>
int InsertNode(Node<T>*& _root, T _item) {
    if(_root == nullptr) {
        Node<T>* temp = new Node<T>;
        temp->Data = _item;
        temp->left = nullptr;
        temp->right = nullptr;

        _root = temp;

        temp = nullptr;
        delete[] temp;        
        return true;
    }
	else {
		if (_root->Data < _item) {
			InsertNode(_root->right, _item);
			return true;
		}
		else if (_root->Data == _item) {
			return false;
		}
		else {
			InsertNode(_root->left, _item);
			return true;
        }
    }
}
template <typename T>
Node<T>* GetMinNode(Node<T>* _root) {
    Node<T>* temp = new Node<T>;
    while(_root != nullptr && _root->left != nullptr) {
        temp = _root->left;
    }
    return temp;
}

template <typename T>
Node<T>* DeleteNode(Node<T>*& _root, T _item, bool& _isDeleted) {
    if(_root == nullptr) {
        return _root;
    }
    if(_root->Data < _item) {
        _root->right = DeleteNode(_root->right, _item, _isDeleted);
    }
    else if(_root->Data >_item) {
        _root->left = DeleteNode(_root->left, _item, _isDeleted);
    }
    else {
        Node<T>* temp = new Node<T>;
        if(_root->left == nullptr) {
            temp = _root->right;
            _root = nullptr;
            _isDeleted = true;
            delete[] _root;
        }
        else if(_root->right == nullptr) {
            temp = _root->left;
            _root = nullptr;
            _isDeleted = true;
            delete[] _root;
        }
        else {
            temp = GetMinNode(_root->right);
            _root->Data = temp->Data;
            _root->right = DeleteNode(_root->right, temp->Data, _isDeleted);
            _isDeleted = true;
        }
    }
    return _root;
}

template <typename T>
void Inorder(Node<T>* _root) {
	if (_root != nullptr) {
		Inorder(_root->left);
		std::cout << _root->Data;
		Inorder(_root->right);
	}
	return;
}

template <typename T>
void Preorder(Node<T>* _root) {
	if (_root != nullptr) {
		std::cout << _root->Data;
		Inorder(_root->left);
		Inorder(_root->right);
	}
	return;
}

template <typename T>
void Postorder(Node<T>* _root) {
	if (_root != nullptr) {
		Inorder(_root->left);
		Inorder(_root->right);
		std::cout << _root->Data;
	}
	return;
}

template <typename T>
int Traversal(Node<T>* _root, T& _item) {
	if (_root != nullptr) {
		if (_root->Data == _item) { 
			_item = _root->Data;
			return 1;
		}
		Traversal(_root->left, _item);
		Traversal(_root->right, _item);
	}
	return 0;
}