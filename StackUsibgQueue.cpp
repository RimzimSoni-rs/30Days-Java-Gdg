#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:
    // Push element x onto stack
    void push(int x) {
        // Push x to q2
        q2.push(x);
        
        // Push all elements of q1 to q2 to maintain the order
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2
        swap(q1, q2);
    }

    // Removes the element on top of the stack
    void pop() {
        if (!q1.empty()) {
            q1.pop();
        }
    }

    // Get the top element of the stack
    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1; // This should not happen according to problem constraints
    }

    // Returns whether the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    int n;
    cin >> n;
    Stack stack;
    
    while (n--) {
        string operation;
        cin >> operation;
        
        if (operation == "push") {
            int x;
            cin >> x;
            stack.push(x);
        } 
        else if (operation == "pop") {
            stack.pop();
        } 
        else if (operation == "top") {
            cout << stack.top() << endl;
        } 
        else if (operation == "empty") {
            cout << (stack.empty() ? 1 : 0) << endl;
        }
    }
    
    return 0;
}
