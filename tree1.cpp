//BINARY TREE TRAVERSALS
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int val){
			data=val;
			left=NULL;
			right=NULL;
		}
};
void preorder(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(Node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
    cout<<root->data<<" ";
}
void printlevelorder(Node* root){
	if(root==NULL) return;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* node=q.front();
		q.pop();
		if(node!=NULL){
			cout<<node->data<<" ";
		
		     if(node->left){
			    q.push(node->left);
		   }
		      if(node->right){
			   q.push(node->right);
		}
	}
	else if(!q.empty()){
		q.push(NULL);
	}
			
		
	}
}
int sumatklevel(Node* root,int k){
	if(root==NULL) return -1;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	int level=0;
	int sum=0;
	while(!q.empty()){
		Node* node=q.front();
		q.pop();
		if(node!=NULL){
			if(level==k){
				sum+=node->data;
			}
			if(node->left){
				q.push(node->left);
			}
			if(node->right){
				q.push(node->right);
			}
		}
		else if(!q.empty()){
			q.push(NULL);
			level++;
		}
	}
	return sum;
}
void rightview(Node* root){
	if(root==NULL) return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		int n=q.size();
		for(int i=0;i<n;i++){
			Node* curr=q.front();
			q.pop();
			if(i==n-1){
				cout<<curr->data<<" ";
			}
			if(curr->left!=NULL){
				q.push(curr->left);
			}
			if(curr->right!=NULL){
				q.push(curr->right);
			}
			
		}
		
	}
}
void leftview(Node* root){
	if(root==NULL) return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		int n=q.size();
		for(int i=1;i<=n;i++){
			Node* temp=q.front();
			q.pop();
			if(i==1){
				cout<<temp->data<<" ";
			}
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right) ;
			}
		}
	}
}
int main(){
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	printlevelorder(root);
	cout<<endl;
	cout<<sumatklevel(root,2);
	cout<<endl;
	rightview(root);
//	Its time complexity is O(n).
    cout<<endl;
    leftview(root);
	
}
