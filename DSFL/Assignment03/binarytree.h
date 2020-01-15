
class node
{
    public:
	int data;
	node *left;
	node *right;
};

class binaryTree
{
	node *root;
    public:
    	binaryTree();
    	int isEmpty();
    	node createBTree();
    	void displayBTree(node *TNode);
};
