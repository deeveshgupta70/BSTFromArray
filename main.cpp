#include<bits/stdc++.h>
using namespace std;

#define Fast1 ios_base::sync_with_stdio(0)
#define Fast2 cin.tie(0)
#define Fast3 cout.tie(0)
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef short int SI;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

class binarySearchTree
{public:
	int data;
	binarySearchTree* left;
	binarySearchTree* right;
	binarySearchTree(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~binarySearchTree(){
		delete left;
		delete right;
	}
};

void LevelOrderTraversal(binarySearchTree* root){

	if(!root) return;

	queue<binarySearchTree*> node;
	node.push(root);

	while(!node.empty()){

		int count = node.size();
		while(count--){

			binarySearchTree* ptr = node.front();
			cout<<ptr->data<<" ";
			node.pop();

			if(ptr->left) node.push(ptr->left);

			if(ptr->right) node.push(ptr->right);
		}
		cout<<"\n";
	}
}

binarySearchTree* builtFromArray( int a[],int low,int high)
{
	if(low > high ) return NULL;

	int mid = low + abs(low - high)/2;
	binarySearchTree* root = new binarySearchTree(a[mid]);
	root->left = builtFromArray(a,low,mid-1);
	root->right = builtFromArray(a,mid+1,high);

	return root;
}

bool isBST(binarySearchTree* root,int min = INT_MIN, int max = INT_MAX){

	if( !root) return true;

	if( root->data < min || root->data > max) return false;

	bool leftT = isBST(root->left,min,root->data - 1);
	bool rightT = isBST(root->right,root->data+1,max);

	return leftT&rightT;	
}

int main(){

	int n;
	cin>>n;

	int a[n];
	FOR(i,n){
		cin>>a[i];
	}

	binarySearchTree* root = builtFromArray(a,0,n-1);

	cout<<"\n Level Order Traversal :";
	LevelOrderTraversal(root);

	cout<<"\n isBST :"<<isBST(root);

	delete root;
	return 0;

}

/*
input :
10
1 2 3 4 5 6 7 8 9 10

output:

 Level Order Traversal :5 
2 8 
1 3 6 9 
4 7 10 

 isBST :1

*/
