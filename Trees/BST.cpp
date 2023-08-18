#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#define SPACE 10
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;

	Node()
	{
		left = NULL;
		right = NULL;
		data = 0;
	}
};

class BST
{
public:
	Node* root;

	BST()
	{
		root = NULL;
	}

	bool isempty()
	{
		if (root == NULL)
			return true;
		else
			return false;
	}

	void print2D(Node* r, int space)
	{
		if (r == NULL)
			return;
		space += SPACE;
		print2D(r->right, space);
		cout << endl;
		for (int i = SPACE; i < space; i++)
			cout << " ";
		cout << r->data << "\n";
		print2D(r->left, space);
	}

	void insert(Node* temp, Node* n)
	{
		if (isempty())
		{
			root = n;
		}
		else
		{
			while (temp != NULL)
			{
				if (n->data > temp->data && temp->right != NULL)
				{
					temp = temp->right;
				}
				else
					if (n->data < temp->data && temp->left != NULL)
					{
						temp = temp->left;
					}
					else
						if (n->data > temp->data && temp->right == NULL)
						{
							temp->right = n;
							break;
						}
						else
							if (n->data < temp->data && temp->left == NULL)
							{
								temp->left = n;
								break;
							}
							else
								if (n->data == temp->data)
								{
									cout << "\nNo Dupes Allowed Bye\n";
									break;
								}
			}
		}
	}

	int height(Node* r)
	{
		if (r == NULL)
			return -1;
		else {

			int lheight = height(r->left);
			int rheight = height(r->right);


			if (lheight > rheight)
				return (lheight + 1);
			else return (rheight + 1);
		}
	}

	void printGivenLevel(Node* r, int level,int &count)
	{
		if (r == NULL)
		 return;
		
		else if (level == 0)
		{
			//cout << r->data << " ";
			count++;
		}
		
		else // level > 0  
		{
			printGivenLevel(r->left, level - 1,count);
			printGivenLevel(r->right, level - 1,count);
		}
	}
		
		
	int Width(Node* r)
	{
		int h = height(r);
		int width=0;
		int count = 0;
		for (int i = 0; i <= h; i++)
		{
			cout << endl;
			count = 0;
			printGivenLevel(r, i,count);

			if (count >= width)
			{
				width = count;
			}
		}
		return width;
	}

	Node* minValueNode(Node* node)
	{
		Node* current = node;
		while (current->left != NULL) {
			current = current->left;
		}
		return current;
	}

	Node* deleteNode(Node* r, int v)
	{
		if (r == NULL)
		{
			return NULL;
		}

		else if (v < r->data)
		{
			r->left = deleteNode(r->left, v);
		}

		else if (v > r->data)
		{
			r->right = deleteNode(r->right, v);
		}

		else
		{
			if (r->left == NULL)
			{
				Node* temp = r->right;
				delete r;
				return temp;
			}

			else if (r->right == NULL)
			{
				Node* temp = r->left;
				delete r;
				return temp;
			}

			else
			{
				Node* temp = minValueNode(r->right);
				r->data = temp->data;
				r->right = deleteNode(r->right, temp->data);
			}
		}
		return r;
	}

	bool updatekey(Node*temp,int find, int replace)
	{
		if (isempty())
		{
			return false;
		}
		else
		{
			int arr[10];
			for (int i = 0; i < 10 ; i++)
			{
				arr[i] = -1;
			}
			int i = 0;

			while (temp != NULL)
			{
					if (find < temp->data && temp->left != NULL)
					{
						arr[i] =1;//for left
						i++;
						temp = temp->left;
					}
					else
						if (find > temp->data && temp->right != NULL)
						{
							arr[i] = 0;//for right
							i++;
							temp = temp->right;
						}
						else
								if (find == temp->data)
								{
									cout << "\nThe Desired value has been found\n";
									temp->data = replace;
									break;
								}
			}

			Node* rep = temp;
			bool check = true;
			i = 0;
			temp = root;
			Node* baby = root;

			while (temp->data!=replace && i<10)
			{
				if (arr[i] == 1)
				{
					baby = temp;

					if (temp->left != NULL)
					{
						temp = temp->left;
						i++;
					}

					if (baby->data < temp->data)
					{
						check = false;
					}
	
				}
				else
				if (arr[i] == 0)
				{
					baby = temp;

					if (temp->right != NULL)
					{
						temp = temp->right;
						i++;
					}

					if (baby->data < temp->data)
					{
						check = false;
					}						
				}
				if (arr[i] == -1)
					break;
			}

			if (check == false)
			{
				if (temp->right == NULL && temp->left == NULL)
				{
					i--;
					if (arr[i] == 1)
					{
						baby->left = NULL;
					}
					else
					{
						baby->right = NULL;
					}
				}
				else
				{
					i--;
					if (arr[i] == 1)
					{
						baby->left = temp->left;
					}
					else
					{
						baby->right =temp->right;
					}
				}
				Node* n = new Node;
				n->data = replace;
				insert(root, n);
			}

			return check;
		}


		
	}

	void Search(Node* temp, int find)
	{
		if (isempty())
		{
			return;
		}
		else 
		{
			if (temp == NULL)
				return;

			if (find < temp->data)
			{
				temp = temp->left;
				Search(temp->left, find);
			}
			else
				if (find > temp->data)
				{
					
					temp = temp->right;
					
					Search(temp->right, find);
				}

			if (find == temp->data)
			{
				cout << "\nVALUE FOUNDDD :)\n";
			}
			else
			{
				cout << "\nVALUE NOT FOUND :(\n";
			}
		}
	}

	void preorderrecursive(Node* n)
	{
		if (n == NULL)
			return;
		else
		{
			cout << n->data << " ";
			preorderrecursive(n->left);
			preorderrecursive(n->right);
		}
	}

	void countsum(Node*n,int sum)
	{
		if (n == NULL)
			return;
		else
		{
			if (n->left == NULL)
			{
				sum = sum + n->data;
				cout << sum << " ";
				countsum(n->left, sum-n->data);
				countsum(n->right, sum);
			}
			else
			{
				countsum(n->left, sum);
				countsum(n->right, sum);
			}
		}
	}

	void preorderiterative(Node*temp)
	{
		stack <Node*> stacknode;
		stacknode.push(root);

		while (!stacknode.empty())
		{

			temp = stacknode.top();
			cout << temp->data<<" ";
			stacknode.pop();
			

			if (temp->right != NULL)
			{
				stacknode.push(temp->right);
			}

			if (temp->left != NULL)
			{
				stacknode.push(temp->left);
			}
		}
	}
	
	void inorderiterative(Node* temp)
	{
		stack <Node*> stacknode;
		stacknode.push(root);

		while (!stacknode.empty())
		{
			while (temp->left != NULL)
			{
				stacknode.push(temp->left);
				temp = temp->left;
			}

			temp = stacknode.top();
			cout << temp->data<<" ";
			stacknode.pop();

			if (temp->right != NULL)
			{
				stacknode.push(temp->right);
				temp = temp->right;
			}	
		}
	}

	int CountNodes(Node* temp)
	{
		int count = 0;
		stack <Node*> stacknode;
		stacknode.push(root);

		while (!stacknode.empty())
		{
			while (temp->left != NULL)
			{
				stacknode.push(temp->left);
				temp = temp->left;
			}

			temp = stacknode.top();
			count++;
			stacknode.pop();

			if (temp->right != NULL)
			{
				stacknode.push(temp->right);
				temp = temp->right;
			}

		}
		return count;
	}

	void postorderiterative(Node* temp)
	{
		stack<Node*> stack1, stack2;
		stack1.push(root);

		while (!stack1.empty())
		{
			temp = stack1.top();
			stack1.pop();
			stack2.push(temp);

			if (temp->left != NULL)
				stack1.push(temp->left);
			if (temp->right != NULL)
				stack1.push(temp->right);
		}

		while (!stack2.empty())
		{
			cout << stack2.top()->data<<" ";
			stack2.pop();
		}		
	}

	void inorderrecursive(Node* n)
	{
		if (n == NULL)
			return;
		else
		{
			inorderrecursive(n->left);
			cout << n->data << " ";
			inorderrecursive(n->right);
		}
	}

	void postorderrecursive(Node* n)
	{
		if (n == NULL)
			return;
		else
		{
			postorderrecursive(n->left);
			postorderrecursive(n->right);
			cout << n->data << " ";
		}
	}

	void skewBST(Node*temp, int skew)
	{
		if (temp == NULL)
			return;
		else
		{
			if (skew == 0)
			{
				if (temp->left != NULL)
				{
					temp->right = NULL;
					skewBST(temp->left, 0);
				}		
			}

			if (skew == 1)
			{
				if (temp->right != NULL)
				{
					temp->left = NULL;
					skewBST(temp->right, 1);
				}
			}
		}
	}

	void swappingthedata(Node* baby, Node* mama)
	{
		if (baby == NULL)
			return;
		else
		{
			if (baby->data < mama->data)
			{
				swappingthedata(baby->left, baby);

				int e = mama->data;
				mama->data = baby->data;
				baby->data = e;
			}
			else
			{
				swappingthedata(baby->left, baby);
			}
		}
	}

	//this is to check if it is swapping correctly after skewed
	void check(Node* baby, Node* mama)
	{
		if (baby == NULL)
		{
			return;
		}

		if (baby->data < mama->data)
		{
			swappingthedata(baby, mama);
		}
		else
		{
			check(baby->left, baby);
		}
	}

	void levelorderiterative(Node* temp)
	{
		if (root == NULL)
			return;

		queue<Node*> q;
		q.push(temp);
		q.push(NULL);

		while (q.size() > 1)
		{
			temp = q.front();
			q.pop();

			if (temp == NULL)
			{
				q.push(NULL);
				cout << endl;
			}
			else 
			{
				if (temp->left!=NULL)
					q.push(temp->left);

				if (temp->right!=NULL)
					q.push(temp->right);

				cout << temp->data << " ";
			}
		}
	}

	void mirror(Node* node)
	{
		if (node == NULL)
			return;
		else
		{
			 Node* temp;

			mirror(node->left);
			mirror(node->right);

			temp = node->left;
			node->left = node->right;
			node->right = temp;
		}
	}

	void MirrorBST(Node* n1, Node* n2)
	{
		if (n1 == NULL)
			return;
		if (n2 == NULL)
			return;
		else
		{
			MirrorBST(n1->left, n2->right);
			int temp = n1->data;
			n1->data = n2->data;
			n2->data = temp;
			MirrorBST(n1->right, n2->left);
		}
	}
	
	void commonancestors(int n1,int n2)
	{
		Node* temp = root;
		int i = 0;
		int arr1[10];
		int j = 0;
		int arr2[10];
		int arr3[10] = { -1 };
		int k = 0;

		for (int p = 0; p < 10; p++)
		{
			arr1[p] = -1;
			arr2[p] = -1;
			arr3[p] = -1;
		}

		while (temp != NULL)
		{
			if (n1 < temp->data && temp->left != NULL)
			{
				arr1[i] = temp->data;
				i++;
				temp = temp->left;
			}
			else
				if (n1 > temp->data && temp->right != NULL)
				{
					arr1[i] = temp->data;
					i++;
					temp = temp->right;
				}
				else
					if (n1 == temp->data)
					{
						cout << "\nN1 has been found";
						break;
					}
		}

		temp = root;

		while (temp != NULL)
		{
			if (n2 < temp->data && temp->left != NULL)
			{
				arr2[j] = temp->data;
				j++;
				temp = temp->left;
			}
			else
				if (n2 > temp->data && temp->right != NULL)
				{
					arr2[j] = temp->data;
					j++;
					temp = temp->right;
				}
				else
					if (n2 == temp->data)
					{
						cout << "\nN2 has been found\n";
						break;
					}
		}

		
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (arr1[i] == -1 || arr2[j] == -1)
				{
					continue;
				}
				else if(arr1[i]==arr2[j])
				{
					arr3[k] = arr1[i];
					k++;
				}
			}
		}

		cout << "\nAncestors are: ";
		for (int i = 0; i < 10; i++)
		{
			if (arr3[i] == -1)
				continue;
			else
				cout << arr3[i] << " ";
		}
	}

	void operator==(BST tree2)
	{
		Node* temp1 = root;
		Node* temp2 = tree2.root;
		bool check = true;

		stack <Node*> s1;
		s1.push(root);

		stack <Node*> s2;
		s2.push(tree2.root);

		while (!s1.empty() && !s2.empty())
		{
			while (temp1->left != NULL)
			{
				s1.push(temp1->left);
				temp1 = temp1->left;
			}

			while (temp2->left != NULL)
			{
				s2.push(temp2->left);
				temp2 = temp2->left;
			}

			temp1 = s1.top();
			temp2 = s2.top();
			if (temp1->data != temp2->data)
				check = false;
			s1.pop();
			s2.pop();

			if (temp1->right != NULL)
			{
				s1.push(temp1->right);
				temp1 = temp1->right;
			}

			if (temp2->right != NULL)
			{
				s2.push(temp2->right);
				temp2 = temp2->right;
			}
		}

		
		if (check == false)
			cout << "\nNot Identical";
		else
			cout << "\nIdentical";
	}





	void path_sum()
	{
		vector<int> sum;
		int current_sum = 0;
		path_sum(sum, root, current_sum);
		current_sum = sum.size();
		for (int i = 0; i < current_sum; i++)
		{
			cout << sum[i] << " ";
		}
		cout << endl;
	}

	void path_sum(vector<int>& sum, Node* root, int current_sum)
	{
		if (!root)
			return;
		if (root->left == NULL && root->right == NULL)
		{
			sum.push_back(current_sum + root->data);
			return;
		}
		current_sum += root->data;
		path_sum(sum, root->left, current_sum);
		path_sum(sum, root->right, current_sum);
	}

	void helpisBst(Node* n, int arr[],int i)
	{
		if (n == NULL)
			return;
		else
		{
			helpisBst(n->left,arr,i);
			arr[i] = n->left->data;
			helpisBst(n->right,arr,i);
		}
	}

	void isBst(Node* n, bool &check)
	{
		if (n == NULL)
			return;

		else
		{
			if (n->left != NULL)
			{
				if (n->data < n->left->data)
					check = false;
			}

			if (n->right != NULL)
			{
				if (n->data > n->right->data)
					check = false;
			}

			isBst(n->left, check);
			isBst (n->right, check);

		}
	}

	void copy_helper(Node*& root, Node* s_root)
	{
		if (s_root != NULL)
		{
			Node* new_node = new Node;
			new_node->data = s_root->data;
			root = new_node;
			copy_helper(root->left, s_root->left);
			copy_helper(root->right, s_root->right);
		}
	}

	BST& operator=(BST& s)
	{
		cout << "Assignment operator called!" << endl;
		if (this->root != nullptr)
			delete this;
		copy_helper(this->root, s.root);
		return *this;
	}

	void isSq(Node* n, bool found, bool check, int i,int arr[])
	{
		if (n == NULL)
			return;
		else
		{
			isSq(n->left, found, check, i, arr);
			if (n->data == arr[0])
			{
				found = true;
				i++;
				return;
			}

			if (found == true)
			{
				if (n->data == arr[i])
				{
					check = true;
					i++;
				}
				else
					check = false;
			}
			isSq(n->right, found, check, i, arr);

		}
		if (check == false)
		{
			cout << "\nNO";
		}
		else
			cout << "\nYESSS";
	}
};



int main()
{
	BST obj;
	int ans = 0;

	while (ans != -1)
	{
		cout << "\n1.) Insertion";
		cout << "\n2.) Display";
		cout << "\n3.) Search";
		cout << "\n4.) Delete";

		cout << "\n5.) PreOrder Recursive";
		cout << "\n6.) InOrder Recursive";
		cout << "\n7.) PostOrder Recursive";
		cout << "\n8.) PreOrder Iterative";
		cout << "\n9.) InOrder Iterative";
		cout << "\n10.) PostOrder Iterative";
		cout << "\n11.) Level Order Iterative";

		cout << "\n12.) Update Key";
		cout << "\n13.) Count Nodes";
		cout << "\n14.) Mirror BST";
		cout << "\n15.) Skew the Tree";
		cout << "\n16.) Width of the BST";
		cout << "\n17.) Vector Sums";
		cout << "\n18.) Common Ancestors";
		cout << "\n19.) Identical or Not";
		cout << "\n20.) Is BST or Not";
		cout << "\n99.) Clear Screen";
		
		cout << "\n\nANSWER: ";
		cin >> ans;

		if (ans == 1)
		{
			/*int e;
			cout << "\nEnter Value: ";
			cin >> e;

			Node* n = new Node;
			n->data = e;
			obj.insert(obj.root, n);*/

			int e = 10;
			int p = 8;
			int q = 14;
			int w = 7;
			int x = 9;
			int y = 6;
			int z = 15;
			Node* n = new Node;
			n->data = e;
			obj.insert(obj.root, n);

			Node* r = new Node;
			r->data = p;
			obj.insert(obj.root, r);

			Node* s = new Node;
			s->data = q;
			obj.insert(obj.root, s);

			Node* a = new Node;
			a->data = w;
			obj.insert(obj.root, a);

			Node* b = new Node;
			b->data = x;
			obj.insert(obj.root, b);

			Node* c = new Node;
			c->data = y;
			obj.insert(obj.root, c);

			Node* d= new Node;
			d->data = z;
			obj.insert(obj.root, d);
		}
		if (ans == 2)
		{
			cout << "\n\nDISPLAY\n\n";
			obj.print2D(obj.root, 5);
		}
		if (ans == 3)
		{
			cout << "\nSearch: ";
			cout << "\nEnter value to search: ";
			int f = 0;
			cin >> f;
			obj.Search(obj.root, f);
		}
		if (ans == 4)
		{
			cout << "\nDeletion: ";
			cout << "\nEnter value to delete: ";
			int f = 0;
			cin >> f;
			obj.deleteNode(obj.root, f);
		}
		if (ans == 5)
		{
			cout << "\nPreOrder: ";
			obj.preorderrecursive(obj.root);
		}
		if (ans == 6)
		{
			cout << "\nInOrder: ";
			obj.inorderrecursive(obj.root);
		}
		if (ans == 7)
		{
			cout << "\nPostOrder: ";
			obj.postorderrecursive(obj.root);
		}
		
		if (ans == 8)
		{
			cout << "\nPreOrder Iterative: ";
			obj.preorderiterative(obj.root);
		}
		if (ans == 9)
		{
			cout << "\nInOrder Iterative: ";
			obj.inorderiterative(obj.root);
		}
		if (ans == 10)
		{
			cout << "\nPostOrder Iterative: ";
			obj.postorderiterative(obj.root);
		}
		if (ans == 11)
		{
			cout << "\nLevel Order Iterative: ";
			obj.levelorderiterative(obj.root);
		}
		if (ans == 12)
		{
			cout << "\nUpdate Key";
			cout << "\nEnter value to find: ";
			int f = 0;
			int r = 0;
			cin >> f;
			cout << "\nEnter value to replace: ";
			cin >> r;
			bool flag=obj.updatekey(obj.root, f, r);
		}
		if (ans == 13)
		{
			cout << "\nTotal Nodes: ";
			cout<<obj.CountNodes(obj.root);
		}
		if (ans == 14)
		{
			cout << "\nMirroring the BST";
			obj.mirror(obj.root);
		}
		if (ans == 15)
		{
			cout << "\nSkewing the BST";
			cout << "\nEnter 0 for left-skewed and 1 for right-skewed\n";
			int e = 0;
			cin >> e;
			if (e == 0)
			{
				obj.skewBST(obj.root, 0);
				obj.swappingthedata(obj.root, obj.root);
				obj.check(obj.root, obj.root);
				obj.swappingthedata(obj.root, obj.root);
				obj.check(obj.root, obj.root);
			}
			else
			{
				obj.skewBST(obj.root, 1);
			}
		}
		if (ans == 16)
		{
			cout << "\nWidth of BST: ";
			cout << obj.Width(obj.root);
		}
		if (ans == 17)
		{
			cout << "Vector Sums: ";
			obj.path_sum();
		}
		if (ans == 18)
		{
			cout << "\nCommon Ancestors: ";
			obj.commonancestors(7,9);
		}
		if (ans == 19)
		{
			cout << "\nIs Identical Or Not? ";
			BST obj2;
			int e = 10;
			int p = 8;
			int q = 14;
			int w = 7;
			int x = 9;
			int y = 6;
			int z = 15;
			Node* n = new Node;
			n->data = e;
			obj2.insert(obj2.root, n);

			/*Node* r = new Node;
			r->data = p;
			obj2.insert(obj2.root, r);*/

			Node* s = new Node;
			s->data = q;
			obj2.insert(obj2.root, s);

			Node* a = new Node;
			a->data = w;
			obj2.insert(obj2.root, a);

			Node* b = new Node;
			b->data = x;
			obj2.insert(obj2.root, b);

			Node* c = new Node;
			c->data = y;
			obj2.insert(obj2.root, c);

			///*Node* d = new Node;
			//d->data = z;
			//obj2.insert(obj2.root, d);*/

		    obj == obj2;
		}

		if (ans == 20)
		{
			bool check = true;
			obj.root->left->data = 90;
			obj.isBst(obj.root, check);
			if (check == true)
				cout << "\nIs a BST";
			else
				cout << "\nNot a BST";
		}

		if (ans == 21)
		{
			int arr[3] = { 8,9,10 };
			obj.isSq(obj.root, false, false,0, arr);
		}

		if (ans == 99)
		{
			system("CLS");
		}

	}

	
}