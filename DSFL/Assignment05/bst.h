
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
    	node *insertNode(node *Tnode);
    	void deleteNode(node *Tnode);
    	int searchNode(node *Tnode);
    	node *mirrorImage();
    	void display(node *Tnode);
    	void displayLevel(node *Tnode);
}
