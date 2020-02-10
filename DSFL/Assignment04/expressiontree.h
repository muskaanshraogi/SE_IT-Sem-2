
class node
{
    public:
    	char data;
    	node *left;
    	node *right;
};

class expressionTree
{
	node *root;
    public:
    	expressionTree();
    	int isEmpty();
    	void create(char expression[50]);
    	node *getRoot();
    	node *createTree(char expression[50]);
    	void inOrderRec(node *Tnode);
    	void preOrderRec(node *Tnode);
    	void postOrderRec(node *Tnode);
    	void inOrder(node *Tnode);
    	void preOrder(node *Tnode);
    	void postOrder(node *Tnode);
};


class Snode
{
    public:
    	node *data;
    	Snode *next;
};

class Stack
{
	Snode *top;
    public:
    	Stack();
    	int isEmpty();
    	void push(node *data);
    	node *pop();
};
