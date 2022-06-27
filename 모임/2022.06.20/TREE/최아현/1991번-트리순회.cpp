#include<iostream>
#include<vector>

using namespace std;

struct Node {
	char c;
	Node *left = NULL;
	Node *right = NULL;
};

void pre(Node *node) {
	cout << node->c;
	if (node->left != NULL) {
		pre(node->left);
	}
	if (node->right != NULL) {
		pre(node->right);
	}
}
void in(Node *node) {
	if (node->left != NULL) {
		in(node->left);
	}
	cout << node->c;
	if (node->right != NULL) {
		in(node->right);
	}
}
void post(Node *node) {
	if (node->left != NULL) {
		post(node->left);
	}
	if (node->right != NULL) {
		post(node->right);
	}
	cout << node->c;
}

int main() {

	int N;
	char p, l, r;
	vector<Node> node(26);
	Node * root;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> p >> l >> r;

		node[p - 'A'].c = p;

		if (l != '.') {
			node[p - 'A'].left = &node[l - 'A'];
		}
		if (r != '.') {
			node[p - 'A'].right = &node[r - 'A'];
		}
	}
	root = &node[0];

	pre(root);
	cout << "\n";
	in(root);
	cout << "\n";
	post(root);

	return 0;
}
