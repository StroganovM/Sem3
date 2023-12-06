#include <iostream>
#include "QueueOnList.h"
#include <list>
#include <string>
template<typename T>
struct QueueElement {
    T value;
    int priority;
    QueueElement(const T& _value, int _priority) : value(_value), priority(_priority) {}
};
template<typename T>
class PriorityQueue:public TQueueOnList<T> {
private:
    std::list<QueueElement<T>> data; 

public:
    void push_(const T& value, int priority) {
        // вставки элемента с учетом приоритета
        auto position = data.begin();
        QueueElement<T> tmp(value, priority);
        while (position != data.end() && position->priority >= priority) {
            ++position;
        }
        data.insert(position, tmp);
    }
    const std::string& front() const {
        return data.front().value;
    }

    int frontPriority() const {
        return data.front().priority;
    }
    void dequeue() {
        if (!data.empty()) {
            data.pop_front();
        }
    }
    bool IsEmpty() const {
        return data.empty();
    }
};

int main() {
    PriorityQueue<std::string> queue;

    // Добавляем элементы в очередь с указанием приоритета
    queue.push_("Apple", 2);
    queue.push_("Banana", 5);
    queue.push_("Orange", 3);
    queue.push_("Grape", 2);

    // Пока очередь не пуста, извлекаем элементы с приоритетами и выводим их
    while (!queue.IsEmpty()) {
        std::cout << "Element: " << queue.front() << ", Priority: " << queue.frontPriority() << std::endl;
        queue.dequeue();
    }

    return 0;
}