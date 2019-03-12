#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node* Lft;
	Node* Rgt;
	Node()//constructor
	{
		Rgt=NULL;
		Lft=NULL;
	}
};
class tree		//class tree
{				
	public:				
	Node *root;		//root the main reference
	tree()			
	{			// default constructor
		root=NULL;
	}
	void Insert(int val)		// insert function
	{
		if(root==NULL)		//first insertion
		{			
		Node* temp=new Node;	/// creating new node
		temp->data=val;
		root=temp;		// assiging root to temp

		}
		else
		InsertH(root,val);	//  the insert function which actually does insertion
	}
	
	void InsertH(Node* current, int Val)		// actual insertion function which inserts elements
	{
		if(Val < current->data)		//if val is less than value of current node
		{
			if(current->Lft==NULL)		//if the left node is empty add the new node here
			{
				Node* temp=new Node;
				temp->data=Val;
				current->Lft=temp;	
			}
			else		//else call the function again
			InsertH(current->Lft,Val);	// 	
		}
		else			// inserting on right side
		{
			if(current->Rgt==NULL)		// checking whether the left is empty or not
			{
				Node* temp=new Node;
				temp->data=Val;
				current->Rgt=temp;	
			}
			else
			InsertH(current->Rgt,Val); //if left position is not empty call the function again
		}
			
	}
	void display()		//display function 
	{
		displayM(root);	//display main function call
	}
	void displayM(Node* current)
	{
		// base condition
		if(current==NULL)
		return;
		//display left
		displayM(current->Lft);
		//display centre
		cout<<current->data<<",";	
		//display right
		displayM(current->Rgt);
	}
	bool search(int E)		//helper search function
	{
		searchM(E,root);		//calling the maIN SEARCH FUNCTION
	}
	bool searchM(int V, Node* current)
	{
		if(current==NULL) //stopping condition
		return 0;
		else
		{
			if(current->data==V) //stopping condition
			return 1;	//returning 1
			if(V > current->data) //if the value is greater than current value 
			searchM(V,current->Rgt);
			else 		//if the v is less than current data go to the left side
			searchM(V,current->Lft); //search in the left position
		}
		
			
	}
};
int main()
{
	tree A;
	int AR[9]={10,45,23,101,89,34,67,99,454};
	for(int i=0;i<9;i++)
	A.Insert(AR[i]);
	A.display();
	cout<<endl<<A.search(454)<<endl;
	return 0;
}
