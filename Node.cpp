#include <iostream>
#include <stdexcept>

// Node class representing each node in the stack
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// Stack class implementing stack functionality
template <typename T>
class Stack {
private:
    Node<T>* top; // Top of the stack
    int size;     // Size of the stack

public:
    Stack() : top(nullptr), size(0) {}

    // Destructor to free allocated memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Method to add an element to the stack
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top; // Link new node to the previous top
        top = newNode;       // Update the top to the new node
        size++;
        std::cout << value << " pushed to the stack." << std::endl;
    }

    // Method to remove and return the top element from the stack
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty. Cannot pop.");
        }
        Node<T>* temp = top;
        T data = top->data;
        top = top->next; // Update top to the next node
        delete temp;     // Free memory
        size--;
        std::cout << data << " popped from the stack." << std::endl;
        return data;
    }

    // Method to return the top element without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty. Cannot peek.");
        }
        return top->data; // Return the top element
    }

    // Method to check if the stack is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Method to get the size of the stack
    int getSize() const {
        return size;
    }

    // Method to display the stack
    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node<T>* current = top;
        std::cout << "Stack: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Main function to test the stack implementation
int main() {
    Stack<int> stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the stack
    stack.display();

    // Peek at the top element
    std::cout << "Top element is: " << stack.peek() << std::endl;

    // Pop elements from the stack
    stack.pop();
    stack.pop();

    // Display the stack
    stack.display();

    // Check stack size
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    return 0;
}
