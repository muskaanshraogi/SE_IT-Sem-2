

class node
{
    public:
	char data;
	node *next;
};

class linkedList
{
    public:
    	node *head;
    	
    	linkedList();
    	void insertNode(char data,int pos);
    	char deleteNode(int pos);
    	void displayList();
};
