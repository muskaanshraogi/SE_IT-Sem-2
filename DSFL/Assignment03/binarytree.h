
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
    	node *getRoot();
    	void create();
    	node *makeTree();
    	void display(node *Tnode);
    	void displayLeaf(node *Tnode);
    	int depth(node *Tnode);
    	node *copyTree(node *Tnode);
};
