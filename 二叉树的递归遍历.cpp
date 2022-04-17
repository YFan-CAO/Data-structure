#include<bits/stdc++.h>
using namespace std;
struct Bstnode {
	char data;
	Bstnode* left;
	Bstnode* right;
};
//�����½ڵ�
Bstnode* GetNewNode(int data) {
	Bstnode* newNode = new Bstnode();
	(*newNode).data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
//����
void CreateBiTree(Bstnode** bt) {
	char ch;
	ch = getchar();
	if (ch == '#') *bt = NULL;
	else {
		*bt = new Bstnode;
		(*bt)->data = ch;
		CreateBiTree(&((*bt)->left));
		CreateBiTree(&((*bt)->right));
	}
}
//��α���
void LevelOrder(Bstnode* root) {
	if (root == NULL) return;
	queue<Bstnode*> Q;
	Q.push(root);
	while (!Q.empty()) {
		Bstnode* current = Q.front();
		cout << current->data << " ";
		if (current->left != NULL) Q.push(current->left);
		if (current->right != NULL) Q.push(current->right);
		Q.pop();
	}
}
//ǰ�����
void Preorder(Bstnode* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}
//�������
void Inorder(Bstnode* root) {
	if (root == NULL) return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}
//�������
void Postorder(Bstnode* root) {
	if (root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}
int main() {
	Bstnode* root = NULL;
	CreateBiTree(&root);
	//	LevelOrder(root);
	//	cout << endl;
	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;
	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
}