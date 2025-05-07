#include <iostream>
#include <stack>

class PriorityQueue {
private:
    std::stack<int> stack1; // Main stack for incoming elements
    std::stack<int> stack2; // Temporary stack to sort elements

public:
    // Insert element into the priority queue
    void push(int value) {
        // Move elements from stack1 to stack2 to maintain order
        while (!stack1.empty() && stack1.top() < value) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        // Push the new element onto stack1
        stack1.push(value);

        // Move elements back from stack2 to stack1
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    // Remove the element with the highest priority (largest value)
    void pop() {
        if (stack1.empty()) {
            std::cout << "Priority Queue is empty.\n";
            return;
        }
        stack1.pop();
    }

    // Get the element with the highest priority
    int top() {
        if (stack1.empty()) {
            std::cout << "Priority Queue is empty.\n";
            return -1; // Return a sentinel value
        }
        return stack1.top();
    }

    // Check if the priority queue is empty
    bool isEmpty() {
        return stack1.empty();
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(12);
    pq.push(6);
    pq.push(8);
    pq.push(2);
    pq.push(7);

    std::cout << "Top element (highest priority): " << pq.top() << std::endl;
    

    while (!pq.isEmpty()) {
        std::cout << "Removing top element: " << pq.top() << std::endl;
        pq.pop();
    }

    return 0;
}
