#include "rb_tree.h"


template<typename T>
struct RedBlackTree<T>::RB_Node {
    T val; // 值
    RB_COLOR rb_color; // 节点颜色
    RB_Node* ftr; // 父亲节点
    RB_Node* lc; // 左孩子
    RB_Node* rc; // 右孩子

    RB_Node(T v = T(), RB_COLOR rbc = RB_COLOR_RED, RB_Node* f = NULL, RB_Node* lchild = NULL, RB_Node* rchild = NULL) : val(v), rb_color(rbc), ftr(f), lc(lchild), rc(rchild) {  }

    // 找到中序遍历真后继
    RB_Node* Succ() {
        RB_Node* ptn = rc; // 当rc为Null时
        while (ptn->lc) {
            ptn = ptn->lc;
        }
        return ptn;
    }

    // 找到中序遍历的前驱节点
    RB_Node* PreNode() {
        RB_Node* ptn = this;
        if (!lc) { // 没有左子树
            // 向祖先查找
            while (ptn->ftr && ptn->ftr->lc == ptn) { // 有父亲节点，且父亲节点的左子树是自己，表示自己在父亲节点之前被访问
                ptn = ptn->ftr;
            }
            ptn = ptn->ftr; // 当ptn->ftr = null时，表示该节点是第一关被访问的节点

        } else { // 有左子树
            ptn = ptn->lc;
            while (ptn->rc) { // 左子树最右边的节点
                ptn = ptn->rc; 
            }
        }
        return ptn;
    }
};


template<typename T>
struct RedBlackTree<T>::Iterator {
protected:
    RB_Node* _real_node;
public:
    T operator*() {
        return _real_node->val;
    }

    bool operator==(Iterator const& itr) { // ? 这里的const&表示什么, 等价于const iterator&
        return _real_node == itr._real_node;
    }

    bool operator!() {
        return !_real_node;
    }

    Iterator& operator++() {
        _real_node = _real_node->right_node(); // 这里的right_node表示什么
        return *this;
    }

    Iterator& operator--() {
        _real_node = _real_node->left_node(); // 这里的left_node表示什么
        return *this;
    }

    Iterator(RB_Node* node_nn = NULL) : _real_node(node_nn) {  }
    Iterator(T const& val) : _real_node(find(val)) {  }
    Iterator(Iterator const& itr) : _real_node(itr._real_node) {  }
};

template<typename T>
typename
RedBlackTree<T>::RB_Node* RedBlackTree<T>::Find(T v) {
    RB_Node* ptn = _root;
    _hot = NULL;
    while (ptn && ptn->val != v) {
        _hot = ptn;
        if (ptn->val > v) {
            ptn = ptn->lc;
        } else {
            ptn = ptn->rc;
        }
    }

    return ptn;
}

template<typename T>
typename
RedBlackTree<T>::Iterator RedBlackTree<T>::Search(T v) {
    return Iterator(find(v));
}

template<typename T>
typename
RedBlackTree<T>::Iterator RedBlackTree<T>::Lower_bound(T v) { // 还有些不是很理解
    RB_Node* ptn = _root;
    _hot = NULL;
    while (ptn) {
        _hot = ptn;
        if (ptn->val >= v) {
            ptn = ptn->lc;
        } else {
            ptn = ptn->rc;
        }
    }
    if (_hot->val >= v) {
        ptn = _hot;
    } else {
        ptn = _hot->right_node();
    }
    return Itearator(ptn);
}

template<typename T>
typename
RedBlackTree<T>::Iterator RedBlackTree<T>::Upper_bound(T v) { // 还有些不是很理解
    RB_Node* ptn = _root;
    _hot = NULL;
    while (ptn) {
        _hot = ptn;
        if (ptn->val > v) {
            ptn = ptn->lc;
        } else {
            ptn = ptn->rc;
        }
    }
    if (_hot->val >= v) {
        ptn = _hot;
    } else {
        ptn = _hot->right_node();
    }
    return Itearator(ptn);
}

int main() {
    return 0;
}
