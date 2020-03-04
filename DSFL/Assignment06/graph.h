typedef struct dob
{
	int date, month, year;
}dob;

struct friendNode;

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
	friendNode *next;
}friendNode;


class graph
{
	node *head;
    public:
   	graph();
   	int isEmpty();
    	void createNode(char name[25], int date, int month, int year, int comments);
    	void displayNode(char name[25]);
    	void display();
    	void makeFriend(char name1[25], char name2[25]);
    	void dfs(int month);
    	void bfs(int comments);
};
