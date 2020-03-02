typedef struct dob
{
	int date, month, year;
}dob;

typedef struct friendNode;

typedef struct node
{
	int id;
	int visited;
	char name[25];
	dob birthday;
	int comments;
	struct node *next;
	friendNode *friends;
}node;

typedef struct friendNode
{
	node *friendAddress;
	node *next;
}friendNode;


class graph
{
	node *head;
    public:
   	graph();
   	int isEmpty();
    	void createNode(char name[25], int date, int month, int year, int comments);
    	void displayNode();
    	void display();
    	void makeFriend(char name1[25], char name2[25]);
    	void birthdays();
    	void comments();
    	node *bfs();
    	node *dfs();
};
