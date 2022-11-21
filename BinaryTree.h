#include<iostream>

using namespace std;

template<typename valType>
class BTnode;//ǰ������

template<typename valType>
class BinaryTree;//ǰ������

template<typename valType>
class BTnode {//�ڵ����ݼ��������������������ýڵ��ָ�룬�������һЩ����
	friend class BinaryTree<valType>;
public:
	BTnode(const valType&);//��ĳ��ֵΪ�ڵ�ֵ��constructor

	void insert_value(const valType&);//���insert()�����Ѳ���ֵ���뵽����ڵ�
	static void lchild_leaf(BTnode*, BTnode*);//remove()��غ����õ����������޽ӵ�Ѱ�Һ�������������Ϊstatic
	void remove_value(const valType&, BTnode*&);//�Ƴ�����ֵ��Ӧ�ķǸ��ڵ㣨���У�����������ֵ��Ӧ�Ľڵ����ùܣ�����remove()�����������һ������

private:
	valType    _val;//�ڵ�ʵֵ
	int        _cnt;//�ڵ�ʵֵ��ֵ���ִ���
	BTnode* _lchild;//���ӽڵ��ָ��
	BTnode* _rchild;//���ӽڵ��ָ��
};

template<typename valType>
class BinaryTree {//���������������ʼ���������Ͳ�����
public:
	BinaryTree();//default constructor
	BinaryTree(const BinaryTree&);//����һ��BinaryTree��Ϊ��ʼ��constructor
	~BinaryTree();//destructor

	BinaryTree& operator= (const BinaryTree&); //BinaryTree�丳ֵ����

	bool empty() { return _root == 0; }//����BinaryTree�Ƿ�յ�

	void insert(const valType&);//��ֵ
	void remove(const valType&elem);//�Ƴ�
	void remove_root();//�Ƴ����ڵ㣬����remove()���������������һ���������������class BinaryTree�ڣ���Ϊ_root������Ϊprivate
	void find(const valType &val) {
		find(val, _root);
		if (!find_cnt)
			cout << "Not Found! " << val << " is not in the BinaryTree! " << endl;
		find_cnt = 0;
	}//Ѱֵ
	void clear() { if (_root) { clear(_root); _root = 0; } }//��գ����private�е�clear()������ʵ����գ�private�е�clear()������Ҫ�ǿ���ͨ���Ӹ��ڵ㿪ʼ���������������죬���ɾ���ڵ㣬����ʵ��

	//���ֱ����㷨
	void preorder() { preorder(_root); }
	void inorder() { inorder(_root); }
	void postorder() { postorder(_root); }

private:
	BTnode<valType>* _root;//���ڵ㣬����������������������ǲ�����
	int find_cnt = 0;//find(��������������ֵ����find()�����ҵ�BinaryTree�е���Ӧֵʱ��������1

	void copy(BTnode<valType>* tar, BTnode<valType>* src);//��src��ָ�������Ƶ�tar��ָ����
	void find(const valType&, BTnode<valType>*);
	void clear(BTnode<valType>*);
	void preorder(BTnode<valType>*, ostream& os = cout) const;//ǰ��
	void inorder(BTnode<valType>*, ostream& os = cout) const;//����
	void postorder(BTnode<valType>*, ostream& os = cout) const;//����
	ostream& printval(BTnode<valType>*, ostream& os = cout) const;//��ӡ�ڵ�����
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
		subtree = subtree->_lchild;//Ѱ�ҿ��Բ����������ĵط�
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
remove(const valType& elem) {//���ҽڵ㣨���У�ȡ��ԭ�ڵ㣬Ȼ������ڵ㣨���У���Ϊ�½ڵ����������Ҷ�ڵ㣻�����ҽڵ㣬����ڵ�ȡ��ԭ�ڵ㣻�����ҽڵ㶼û�У���ֱ��ɾ���ڵ㼴��
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
			BTnode<valType>::lchild_leaf(lc, newlc);//�����Ҫ��lchild_leaf������������Ϊstatic����Ϊ����û�����ɶ���͵�����
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