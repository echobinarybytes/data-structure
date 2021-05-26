#ifndef _H_RB_TREE_H_
#define _H_RB_TREE_H_
#include <cstdio>

#define bro(x) (((x)->ftr->lc == (x)) ? ((x)->ftr->rc) : ((x)->ftr->lc))

typedef bool RB_COLOR;
#define RB_COLOR_RED true
#define RB_COLOR_BLACK false


template <typename T> // ?
class RedBlackTree {
protected: // 什么情况下使用protected ? , 为什么不用private
    struct RB_Node; // ? 名字空间的意味, 类中类

    RB_Node* _root; // 根节点
    RB_Node* _hot; // 父亲节点

    int _size;

    void Init(T); // 第一个元素的初始化
    RB_Node* Zig(RB_Node*); // 左旋
    RB_Node* Zag(RB_Node*); // 右旋

    void SolveDoubleRed(RB_Node*); // 双红修正
    void SolveLostBlack(RB_Node*); // 失黑修正

    RB_Node* Find(T); // 找节点

    void RemoveTree(RB_Node*); // dfs后续遍历

public:
    struct Iterator; // 迭代器 ? 怎么构造迭代器

    RedBlackTree() : _root(NULL), _hot(NULL), _size() {}

    Iterator Insert(T);
    bool Remove(T);
    bool Remove(Iterator&);

    Iterator Search(T);
    Iterator Lower_bound(T v); // 返回 >= v , 为什么要有lower bound
    Iterator Upper_bound(T v); // 返回 > v, 为什么要有upper bound
 

    void Clear(); // dfs后续遍历

    int Size();

    bool Empty();

    Iterator Begin();
    static Iterator End(); // ? 为什么要用static
};

#endif
