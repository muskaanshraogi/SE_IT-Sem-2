
template<class T>
class node
{
    public:
	T data;
	node *next;
};

template<class T>
class linkedList
{
    public:
    	node<T>*head;
    	
    	linkedList();
    	void insertNode(T data,int pos);
    	T deleteNode(int pos);
    	void displayList();
};
