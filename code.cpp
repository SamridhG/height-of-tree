#include<iostream>
using namespace std;
class node{
	public:
		int val;
		node *left,*right;
		node(int val)
		{
			this->val=val;
			right=left=NULL;
		}
};
class tree{
	public:
		node *root;
		tree()
		{
			root=NULL;
		}
		void insert(int data)
		{
			if(root==NULL)
			{
				root=new node(data);
			}
			else
			{
				node *current=root;
				while(true)
				{
					if(current->val>data)
					{
						if(current->left==NULL)
						{
							current->left=new node(data);
							break;
						}
						else
						{
							current=current->left;
						}
					}
					else
					{
						if(current->right==NULL)
						{
							current->right=new node(data);
							break;
						}
						else
						{
							current=current->right;
						}
					}
				}
			}
		}
		node *inorder(node *rt)
		{
			if(rt!=NULL)
			{
				inorder(rt->left);
				cout<<rt->val<<" ";
				inorder(rt->right);
			}
		}
		int max(int right,int left)
		{
			return right>=left?right:left;
		}
		int height(node *rt)
		{
			if(rt==NULL)
			{
				return -1;
			}
			return max(height(rt->left),height(rt->right))+1;
		}
};
int main()
{
	tree A;
	A.insert(50);
	A.insert(8);
	A.insert(9);
	A.insert(45);
	A.insert(35);
	A.insert(23);
	A.insert(64);
	A.insert(14);
	A.insert(4);
	A.insert(38);
	A.inorder(A.root);
	cout<<endl<<"height of tree:"<<A.height(A.root);
}
