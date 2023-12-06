#include<iostream>
#include <stdexcept>
#include <list>
template <class T> class TQueueOnList;
template <class T> std::ostream& operator<<(std::ostream& out,
    const TQueueOnList<T>& lst) {
    out << lst.list;
    return out;
}
template<class T>
class TQueueOnList {
    std::list<T> list;
public:
    TQueueOnList() = default;
    TQueueOnList(const TQueueOnList& st) : list(st.list) {}

    ~TQueueOnList() = default;
    bool isEmpty_() {
        return list.empty();
    }
    T& top() {
        if (list.empty() == true)
            throw std::out_of_range("stack is empty");
        return list.end();
    }
    void pop_() {
        if (!list.empty()) {
            list.pop_front();
        }
    }
            
        
    void push_(const T& a) {
        list.push_front(a);
    }
    int size() {
        return list.size();
    }
    friend std::ostream& operator << <T>(std::ostream& out, const TQueueOnList<T>& lst);
};