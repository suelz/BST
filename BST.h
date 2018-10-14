#pragma once

#include <iostream>

using namespace std;


class BST {
private:
	struct node {
		int data;
		node* left;
		node* right;
	};

	node* root;

	node* insert(int x, node* t) {
		if (t == NULL) {
			t = new node;
			t->data = x;
			t->left = NULL;
			t->right = NULL;
		}
		else if (x < t->data)
			t->left = insert(x, t->left);
		else if (x > t->data)
			t->right = insert(x, t->right);
		return t;
	}

	void inorder(node* t) {
		if (t == NULL) {
			return;
		}
		inorder(t->left);
		cout << t->data << " ";
		inorder(t->right);
	}

	node* makeEmpty(node *t) {
		if (t == NULL) {
			return NULL;
		}
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;

		return NULL;
	}

	node* remove(int x, node* t)
	{
		node* temp;
		if (t == NULL)
			return NULL;
		else if (x < t->data)
			t->left = remove(x, t->left);
		else if (x > t->data)
			t->right = remove(x, t->right);
		else if (t->left && t->right)
		{
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = remove(t->data, t->right);
		}
		else
		{
			temp = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			delete temp;
		}

		return t;
	}

	node* findMin(node *t) {
		if (t->data == NULL) {
			return NULL;
		}
		else if (t->left == NULL) {
			return t;
		}
		else
			return findMin(t->left);
	}

	node* findMax(node *t) {
		if (t->data == NULL) {
			return NULL;
		}
		else if (t->right == NULL) {
			return t;
		}
		else
			return findMin(t->right);
	}

public:
	BST() {
		root = NULL;
	}

	~BST() {
		root = makeEmpty(root);
	}

	void insert(int x) {
		root = insert(x, root);
	}

	void remove(int x) {
		root = remove(x, root);
	}

	void print() {
		inorder(root);
		cout << endl;
	}
};