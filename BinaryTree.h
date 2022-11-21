#include<iostream>

using namespace std;

template<typename valType>
class BTnode;//前置声明

template<typename valType>
class BinaryTree;//前置声明

template<typename valType>
class BTnode {//节点数据及子树连接情况，会给出该节点的指针，包括点的一些操作
	friend class BinaryTree<valType>;
public:
	BTnode(const valType&);//以某个值为节点值的constructor

	void insert_value(const valType&);//配合insert()函数把插入值插入到具体节点
	static void lchild_leaf(BTnode*, BTnode*);//remove()相关函数用到的左子树嫁接点寻找函数，必须声明为static
	void remove_value(const valType&, BTnode*&);//移除输入值对应的非根节点（若有），若无输入值对应的节点则不用管，属于remove()函数所引申的一个函数

private:
	valType    _val;//节点实值
	int        _cnt;//节点实值数值出现次数
	BTnode* _lchild;//左子节点的指针
	BTnode* _rchild;//右子节点的指针
};

template<typename valType>
class BinaryTree {//二叉树，包括其初始化、遍历和操作等
public:
	BinaryTree();//default constructor
	BinaryTree(const BinaryTree&);//以另一个BinaryTree作为初始的constructor
	~BinaryTree();//destructor

	BinaryTree& operator= (const BinaryTree&); //BinaryTree间赋值操作

	bool empty() { return _root == 0; }//检查此BinaryTree是否空的

	void insert(const valType&);//插值
	void remove(const valType&elem);//移除
	void remove_root();//移除根节点，属于remove()函数特例所引申的一个函数，必须放在class BinaryTree内，因为_root被声明为private
	void find(const valType &val) {
		find(val, _root);
		if (!find_cnt)
			cout << "Not Found! " << val << " is not in the BinaryTree! " << endl;
		find_cnt = 0;
	}//寻值
	void clear() { if (_root) { clear(_root); _root = 0; } }//清空，配合private中的clear()函数来实现清空，private中的clear()函数主要是可以通过从根节点开始并向左右子树延伸，逐个删除节点，方便实现

	//三种遍历算法
	void preorder() { preorder(_root); }
	void inorder() { inorder(_root); }
	void postorder() { postorder(_root); }

private:
	BTnode<valType>* _root;//根节点，在这个树的生长过程中它是不会变的
	int find_cnt = 0;//find(）函数辅助计数值，当find()函数找到BinaryTree中的相应值时，它会变成1

	void copy(BTnode<valType>* tar, BTnode<valType>* src);//将src所指子树复制到tar所指子树
	void find(const valType&, BTnode<valType>*);
	void clear(BTnode<valType>*);
	void preorder(BTnode<valType>*, ostream& os = cout) const;//前序
	void inorder(BTnode<valType>*, ostream& os = cout) const;//中序
	void postorder(BTnode<valType>*, ostream& os = cout) const;//后序
	ostream& printval(BTnode<valType>*, ostream& os = cout) const;//打印节点内容
};

template<typename valType>
BTnode<valType>::
BTnode(const valType &val) : _val(val), _cnt(1), _lchild(0), _rchild(0) {}

template<typename valType>
void BTnode<valType>::
insert_value(const valType& val) {
	if (val == _val) {
		_cnt++; return;
	}
	if (val < _val) {
		if (!_lchild)
			_lchild = new BTnode(val);
		else _lchild->insert_value(val);
	}
	else {
		if (!_rchild)
			_rchild = new BTnode(val);
		else _rchild->insert_value(val);
	}
}

template<typename valType>
void BTnode<valType>::
lchild_leaf(BTnode* leaf, BTnode* subtree) {
	while (subtree->_lchild)
		subtree = subtree->_lchild;//寻找可以插入左子树的地方
	subtree->_lchild = leaf;
}

template<typename valType>
void BTnode<valType>::
remove_value(const valType& val, BTnode*& prev) {
	if (val < _val) {
		if (!_lchild) {
			cout << "\nInvalid Remove! It is not in the BinaryTree! \n" << endl;
			return;
		}
		else
			_lchild->remove_value(val, _lchild);
	}
	else
		if (val > _val) {
			if (!_rchild) {
				cout << "\nInvalid Remove! It is not in the BinaryTree!\n " << endl;
				return;
			}
			else
				_rchild->remove_value(val, _rchild);
		}
		else {
			if (_rchild) {
				prev = _rchild;
				if (!prev->_lchild)
					prev->_lchild = _lchild;
				else lchild_leaf(_lchild, prev->_lchild);
			}
			else prev = _lchild;
			delete this;
		}
}

template<typename valType>
inline BinaryTree<valType>::
BinaryTree() : _root(0) { cout << "\nDefault Constructor! It is a empty BinaryTree!\n " << endl; }

template<typename valType>
inline BinaryTree<valType>::
BinaryTree(const BinaryTree& rhs) {
	copy(_root, rhs._root);
	cout << "\nConstructor with another BinaryTree! They R the same!\n " << endl;
}

template<typename valType>
inline BinaryTree<valType>::
~BinaryTree() {
	clear();
	cout << "\n\nDestructor!\n " << endl;
}

template<typename valType>
inline BinaryTree<valType>& BinaryTree<valType>::
operator= (const BinaryTree& rhs) {
	if (this != &rhs) {
		clear(); copy(_root, rhs._root);
	}
	return *this;
}

template<typename valType>
inline void BinaryTree<valType>::
insert(const valType& elem) {
	if (!_root) {
		_root = new BTnode<valType>(elem);
	}
	else _root->insert_value(elem);
}

template<typename valType>
inline void BinaryTree<valType>::
remove(const valType& elem) {//以右节点（如有）取代原节点，然后其左节点（如有）作为新节点的左子树的叶节点；若无右节点，以左节点取代原节点；若左右节点都没有，则直接删除节点即可
	if (_root) {
		if (_root->_val == elem)
			remove_root();
		else
			_root->remove_value(elem, _root);
	}
	else
		cout << "\nIt is an empty BinaryTree! \n" << endl;
}

template<typename valType>
inline void BinaryTree<valType>::
remove_root() {
	BTnode<valType>* tmp = _root;

	if (_root->_rchild) {
		_root = _root->_rchild;

		BTnode<valType>* lc = tmp->_lchild;
		BTnode<valType>* newlc = _root->_lchild;

		if (!newlc)
			newlc = lc;
		else
			BTnode<valType>::lchild_leaf(lc, newlc);//这里就要求lchild_leaf函数必须声明为static，因为我们没有生成对象就调用了
	}
	else _root = _root->_lchild;

	delete tmp;
}

template<typename valType>
inline void BinaryTree<valType>::
copy(BTnode<valType>* tar, BTnode<valType>* src) {
	if (src) {
		copy(tar->_lchild, src->_lchild);
		copy(tar->_rchild, src->_rchild);
		tar->_val = src->_val;
		tar->_cnt = src->_cnt;
		tar->_lchild = src->_lchild;
		tar->_rchild = src->_rchild;
	}
}

template<typename valType>
inline void BinaryTree<valType>::
find(const valType& val, BTnode<valType>* pt) {
	if (!_root)
		cout << "\nNot Found! It is an empty BinaryTree!\n " << endl;
	else
		if (pt) {
			if (pt->_val == val) {
				cout << "\nFound! " << val <<" occurs " << pt->_cnt << ((pt->_cnt == 1) ? " time. " : " times. ") << endl;
				++find_cnt;
			}
			else {
				find(val, pt->_lchild);
				find(val, pt->_rchild);
			}
		}
}

template<typename valType>
inline void BinaryTree<valType>::
clear(BTnode<valType>* pt) {
	if (pt) {
		clear(pt->_lchild);
		clear(pt->_rchild);
		delete pt;
	}
}

template<typename valType>
inline void BinaryTree<valType>::
preorder(BTnode<valType>* pt, ostream& os) const {
	if (pt) {
		printval(pt, os);
		preorder(pt->_lchild, os);
		preorder(pt->_rchild, os);
	}
}

template<typename valType>
inline void BinaryTree<valType>::
inorder(BTnode<valType>* pt, ostream& os) const {
	if (pt) {
		inorder(pt->_lchild, os);
		printval(pt, os);
		inorder(pt->_rchild, os);
	}
}

template<typename valType>
inline void BinaryTree<valType>::
postorder(BTnode<valType>* pt, ostream& os) const {
	if (pt) {
		postorder(pt->_lchild, os);
		postorder(pt->_rchild, os);
		printval(pt, os);
	}
}

template<typename valType>
inline ostream& BinaryTree<valType>::
printval(BTnode<valType>* pt, ostream& os) const {
	os << pt->_val << " ";
	return os;
}