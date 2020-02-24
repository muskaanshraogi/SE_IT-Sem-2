
class node
{
    public:
	int data;
	node *left;
	node *right;
};

class bst
{
	node *root;
    public:
    	bst();
    	int isEmpty();
    	node *getRoot();
    	void insertNode();
    	void deleteNode();
    	node *searchNode(node *Tnode,int data);
    	node *copyBST(node *Tnode);
    	void mirrorImage(node *Tnode);
    	void display(node *Tnode);
    	void displayLevel();
};
