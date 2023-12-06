#include <iostream>
#include "QueueOnList.h"
#include <string>
struct QueueElement {
    std::string value;
    int priority;
    QueueElement(const std::string& _value, int _priority) : value(_value), priority(_priority) {}
};

class PriorityQueue {
private:
    std::list<QueueElement> data; // Хранение элементов и их приоритетов в списке

public:
    void enqueue(const std::string& value, int priority) {
        data.push_back(QueueElement(value, priority));
    }

    void dequeue() {
        if (data.empty()) {
            std::cout << "Priority queue is empty." << std::endl;
        }
        else {
            // Ищем элемент с наивысшим приоритетом в списке
            auto highestPriorityElement = data.begin();
            for (auto it = data.begin(); it != data.end(); ++it) {
                if (it->priority > highestPriorityElement->priority) {
                    highestPriorityElement = it;
                }
            }

            // Выводим элемент с наивысшим приоритетом
            std::cout << "Dequeued element: " << highestPriorityElement->value << std::endl;

            // Удаляем элемент из списка
            data.erase(highestPriorityElement);
        }
    }

    const std::string& front() const {
        return data.front().value;
    }

    int frontPriority() const {
        return data.front().priority;
    }

    bool isEmpty() const {
        return data.empty();
    }

    int size() const {
        return data.size();
    }
};

int main() {
    PriorityQueue queue;
    // Добавляем элементы в очередь с указанием приоритета

    queue.enqueue("Apple", 2);
    queue.enqueue("Banana", 1);
    queue.enqueue("Orange", 3);
    queue.enqueue("Grape", 2);

    while (!queue.isEmpty()) {
        queue.dequeue();
    }

    return 0;
}