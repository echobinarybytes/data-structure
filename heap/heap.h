#ifndef _H_HEAP_H_
#define _H_HEAP_H_

#include <vector>

template <typename T, bool mode> // mode = true 时使用最大堆，mode = false 时使用最小堆
class Heap {
public:
    Heap(); // 构造一个空的堆
    Heap(std::vector<T>& vec); // 根据vector构造堆
    Heap(Heap& h); // 拷贝构造函数
    ~Heap();
    T top() const; // 返回堆中的最大值或者最小值
    // 如何删除元素
    // 不能按照元素的值来删除元素
    // 通过元素的序号来删除元素
    void Delete(int idx); 
    void Insert(T& ele); // 插入元素
    size_t Size() const;
private:
    void CreateHead(std::vector<T>& vec);
    std::vector<T> _heap;
    int _size; // 堆中元素的个数
};
#endif
