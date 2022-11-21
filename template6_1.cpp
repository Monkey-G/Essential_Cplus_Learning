#include"BinaryTree.h"
#include<string>

int main() {
	BinaryTree<string> bt;

	bt.insert( "Piglet" );
	bt.insert( "Eeyore" );
	bt.insert( "Roo" );
	bt.insert( "Tigger" );
	bt.insert( "Chris" );
	bt.insert( "Pooh" );
	bt.insert( "Kanga" );

	cout << "Preorder traversal: \n";
	bt.preorder();
	bt.find("Piglet");
	bt.find("Pooh");
	bt.find("PooH");

	bt.remove("Piglet");
	bt.remove("PooH");
	cout << "\n\nPreorder traversal after Piglet removal:\n";
	bt.preorder();

	bt.remove("Eeyore");
	cout << "\n\nPreorder traversal after Eeyore removal:\n";
	bt.preorder();

	//BinaryTree<string> bt1;
	//bt1 = bt;
	//cout << "\n\nInorder traversal after Eeyore removal:\n";
	//bt1.inorder();

	return 0;
}