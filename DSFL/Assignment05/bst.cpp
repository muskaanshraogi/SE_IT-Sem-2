
bst::bst()
{
	root = NULL;
}

int bst::isEmpty()
{
	if(root == NULL)
		return 1;
	return 0;
}

node *bst::insertNode()
{
	node *current = new node;
	node *temp;
	cout<<"\nEnter the number to be added to the tree :"<<endl;
	cin>>current->data;
	current->left = NULL;
	current->right = NULL;
	
	if(isEmpty())
		root = current;
	else
	{
		temp = root;
		while(temp)
		{
			if(temp->data == current->data)
			{
				cout<<"\nNode already exsists."<<endl;
				return;
			}
		}
	}
}
