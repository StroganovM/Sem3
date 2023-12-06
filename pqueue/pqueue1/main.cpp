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
    std::list<QueueElement> data; // �������� ��������� � �� ����������� � ������

public:
    void enqueue(const std::string& value, int priority) {
        data.push_back(QueueElement(value, priority));
    }

    void dequeue() {
        if (data.empty()) {
            std::cout << "Priority queue is empty." << std::endl;
        }
        else {
            // ���� ������� � ��������� ����������� � ������
            auto highestPriorityElement = data.begin();
            for (auto it = data.begin(); it != data.end(); ++it) {
                if (it->priority > highestPriorityElement->priority) {
                    highestPriorityElement = it;
                }
            }

            // ������� ������� � ��������� �����������
            std::cout << "Dequeued element: " << highestPriorityElement->value << std::endl;

            // ������� ������� �� ������
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
    // ��������� �������� � ������� � ��������� ����������

    queue.enqueue("Apple", 2);
    queue.enqueue("Banana", 1);
    queue.enqueue("Orange", 3);
    queue.enqueue("Grape", 2);

    while (!queue.isEmpty()) {
        queue.dequeue();
    }

    return 0;
}