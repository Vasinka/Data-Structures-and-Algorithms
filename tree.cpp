#include<iostream>
#include<queue>
using namespace std;
template <typename T>
struct node_t
{
	T data;
	node_t<T> *left, *right;

	node_t(T _data, node_t<T> * _left = NULL,
		node_t<T> *_right = NULL) :
		data(_data), left(_left), right(_right) {}
};

template <typename T>
class tree
{
private:

	node_t<T> *root;
	void copyTree(node_t<T> *&, node_t<T> * const&) const;
	void deleteTree(node_t<T> *&);
	void createTree(node_t<T> *&) const;
	void printTree(node_t<T> *p) const;

public:

	tree();
	tree(tree<T> const&);
	tree<T>& operator=(tree<T> const &);
	~tree();
	bool isEmpty() const;
	T getRoot() const;
	tree<T> leftTree() const;
	tree<T> rightTree() const;
	void createRLF(T, tree<T> const&, tree<T> const&);
	void create();
	void print();

	friend bool checkIfTreesHaveSameElementsOnLevel (node_t<T>* root1, node_t<T>* root2, int level);

};



template <typename T>
tree<T>::tree()
{
	root = NULL;
}

template <typename T>
tree<T>::tree(tree<T> const &t)
{
	copyTree(root, t.root);
}

template <typename T>
tree<T>& tree<T>::operator=(tree<T> const &t)
{
	if (this != &t) {
		deleteTree(root);
		copyTree(root, t.root);
	}
	return *this;
}

template <typename T>
tree<T>::~tree()
{
	deleteTree(root);
}

template <typename T>
T tree<T>::getRoot() const
{
	return root->data;
}

template <typename T>
tree<T> tree<T>::leftTree() const
{
	tree<T> t;
	copyTree(t.root, root->left);
	return t;
}

template <typename T>
tree<T> tree<T>::rightTree() const
{
	tree<T> t;
	copyTree(t.root, root->right);
	return t;
}

template <typename T>
bool tree<T>::isEmpty() const
{
	return root == NULL;
}

template <typename T>
void tree<T>::createRLF(T x, tree<T> const& leftTree, tree<T> const& rightTree)
{
	root = new node_t<T>(x);
	copyTree(root->left, leftTree.root);
	copyTree(root->right, rightTree.root);
}

template <typename T>
void tree<T>::create()
{
	createTree(root);
}

template <typename T>
void tree<T>::createTree(node_t<T> *& pos) const
{
	T x; char c;
	cout << "root: ";
	cin >> x;

	pos = new node_t<T>(x);
	pos->left = NULL;
	pos->right = NULL;

	cout << "Add left tree of: " << x << ", y/n? ";
	cin >> c;
	if (c == 'y')
		createTree(pos->left);

	cout << "Add right tree of: " << x << ", y/n? ";
	cin >> c;
	if (c == 'y')
		createTree(pos->right);
}

template <typename T>
void tree<T>::print()
{
	printTree(root);
}

template <typename T>
void tree<T>::copyTree(node_t<T>* &to, node_t<T>* const &from) const
{
	to = NULL;
	if (from)
	{
		to = new node_t<T>(from->data);
		copyTree(to->left, from->left);
		copyTree(to->right, from->right);
	}
}

template <typename T>
void tree<T>::deleteTree(node_t<T>* &r)
{
	if (r)
	{
		deleteTree(r->left);
		deleteTree(r->right);

		delete r;
	}
}

template <typename T>
void tree<T>::printTree(node_t<T> *p) const
{
	if (p)
	{
		printTree(p->left);
		cout << p->data << ' ';
		printTree(p->right);
	}
}

template <typename T>
bool checkIfTreesHaveSameElementsOnLevel (node_t<T>* root1, node_t<T>* root2)
{
    int level=0; // na koe nivo sravnqvame elementite
    while(true)
    {

        int currLevel=0; //za namirane na elementite na tekushtoto nivo

        queue<node_t<T>*> elementsOnLevel1;
        queue<node_t<T>*> elementsOnLevel2;

        elementsOnLevel1.push(root1);
        elementsOnLevel2.push(root2);

        while(currLevel <= level)
        {
            node_t<T>* current = elementsOnLevel1.front();
            if (current.left!=NULL)
            {
                elementsOnLevel1.push(current.left);
            }

            if (current.right!=NULL)
            {
                elementsOnLevel1.push(current.right);
            }
            elementsOnLevel1.pop();

            current = elementsOnLevel2.front();
            if (current.left!=NULL)
            {
                elementsOnLevel2.push(current.left);
            }

            if (current.right!=NULL)
            {
                elementsOnLevel2.push(current.right);
            }

            elementsOnLevel2.pop();
        }

        if(elementsOnLevel1.size() != elementsOnLevel2.size())
        {
            return false;
        }

        if (checkIfQueuesAreEqual(elementsOnLevel1, elementsOnLevel2) == false)
        {
            return false;
        }

        level++;
    }

    return true;
}

template<typename T>
bool checkIfQueuesAreEqual(queue<node_t<T> > q1, queue<node_t<T> > q2)
{
    T* elements1 = new T[q1.size()];

    int i=0;
    while(!q1().empty())
    {
        elements1[i] = q1.front().data;
        q1.pop();
        i++;
    }

    i=0;

    T* elements2 = new T[q2.size()];

    while(!q2().empty())
    {
        elements2[i] = q2.front().data;
        q2.pop();
        i++;
    }

    bool identical;

    for(i = 0; i < q1.size(); i++)
    {
        identical = false;
        for(int j = 0; j < q1.size(); j++)
        {
            if(elements1[i] == elements2[j])
            {
                identical = true;
                break;
            }
        }

        if (identical == false)
        {
            return false;
        }
    }

    return true;
}



int main ()
{
    return 0;
}
