#pragma once

#include <iostream>
#include <thread>
#include <mutex>

class tree {
	struct Node {
		int data;
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;
	};
	std::shared_ptr<Node> root;
public:
	tree() {
		root = nullptr;
	}
	tree(int temp) {
		std::shared_ptr<Node> t(new(Node));
		root = t;
		root->data = temp;
		root->left = nullptr;
		root->right = nullptr;
	}

	~tree() {
		std::cout << "tree has deleted";
	}

	void addData(int temp) {
		if (root) {
			if (temp != root->data) {
				if (temp < root->data) {
					if (!(root->left)) {
						std::shared_ptr<Node> leave(new(Node));
						leave->data = temp;
						leave->left = nullptr;
						leave->right = nullptr;
						root->left = leave;
					}
					else {
						addBranch(temp, root->left);
					}
				}
				else {
					if (!(root->right)) {
						std::shared_ptr<Node> leave(new(Node));
						leave->data = temp;
						leave->left = nullptr;
						leave->right = nullptr;
						root->right = leave;
					}
					else {
						addBranch(temp, root->right);
					}
				}
			}
		}
		else {
			std::shared_ptr<Node> t(new(Node));
			root = t;
			root->data = temp;
			root->left = nullptr;
			root->right = nullptr;
		}
	}

	void addBranch(int temp, std::shared_ptr<Node> branch) {
		if (temp != branch->data) {
			if (temp < branch->data) {
				if (!(branch->left)) {
					std::shared_ptr<Node> leave(new(Node));
					leave->data = temp;
					leave->left = nullptr;
					leave->right = nullptr;
					branch->left = leave;
				}
				else {
					addBranch(temp, branch->left);
				}
			}
			else {
				if (!(branch->right)) {
					std::shared_ptr<Node> leave(new(Node));
					leave->data = temp;
					leave->left = nullptr;
					leave->right = nullptr;
					branch->right = leave;
				}
				else {
					addBranch(temp, branch->right);
				}
			}
		}
	}

	void deleteBranch(int temp) {
		if (root->data == temp) {
			root = nullptr;
		}
		else {
			if (temp < root->data && root->left) {
				deleteBranch(root->left,temp);
			}
			if (temp > root->data && root->right) {
				deleteBranch(root->right,temp);
			}
		}
	}

	void deleteBranch(std::shared_ptr<Node>& branch,int temp) {
		if (branch->data == temp) {
			if (!(branch->left) && !(branch->right)) {
				branch.reset();
			}
			else {
				if ((branch->left) && !(branch->right)) {
					branch = branch->left;
				}
				else {
					if (!(branch->left) && (branch->right)) {
						branch = branch->right;
					}
					else {
						deepFinding(branch->right,branch);
					}
				}
			}
		}
		else {
			if (temp < branch->data && branch->left) {
				deleteBranch(branch->left,temp);
			}
			if (temp > branch->data && branch->right) {
				deleteBranch(branch->right,temp);
			}
		}
	}

	void deepFinding(std::shared_ptr<Node>& branch, std::shared_ptr<Node>& head) {
		if (!(branch->left)) {
			branch->left = head->left;
			head = branch;
		}
		else {
			leftFinding(branch->left, head);
		}
	}

	void leftFinding(std::shared_ptr<Node>& branch, std::shared_ptr<Node>& head) {
		if (!(branch->left)) {
			branch->left = head->left;
			std::shared_ptr<Node> temp;
			temp = branch;
			head=branch;
			if (temp->right) {
				branch = temp->right;
			}
		}
	}

	void print() {
		if (root) {
			std::cout << root->data << "\n";
			if (root->left) {
				print(root->left);
			}
			if (root->right) {
				print(root->right);
			}
		}
	};

	void print(std::shared_ptr<Node> branch) {
		std::cout << branch->data << "\n";
		if (branch->left) {
			print(branch->left);
		}
		if (branch->right) {
			print(branch->right);
		}
	};

};
