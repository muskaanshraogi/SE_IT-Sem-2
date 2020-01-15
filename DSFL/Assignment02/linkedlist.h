
class node
{
    public:
	char name[20];
    	int age;
    	int id;
    	char disease[20];
    	int priority;
	node *next;
};


class linkedList
{
    public:
    	node *head, *tail;
    	
    	linkedList();
    	void insertNode(int id, char name[20], int age, char disease[20], int priority);
    	node deleteNode(int pos);
    	void displayList();
};
