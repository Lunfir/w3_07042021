#include <iostream>

struct StackElement
{
    int value;
    StackElement* prev;
};

struct Stack
{
    void push(int value) {
        StackElement* element = (StackElement*)malloc(sizeof(StackElement));

        if (element == NULL) {
            printf("Push element warning\n");
            return;
        }

        element->value = value;
        element->prev = this->current;

        current = element;
    }

    int pop() {
        if (current == NULL) {
            printf("Pop NULL element\n");
            return 0;
        }

        int out = this->current->value;
        StackElement* tmp = this->current;

        this->current = this->current->prev;

        free(tmp);

        return out;
    }

    StackElement* current;    
};


int main(int argc, char const *argv[])
{
    Stack stack;

    stack.push(-7);
    stack.push(42);
    stack.push(53);

    printf("%d\n", stack.pop());
    printf("%d\n", stack.pop());
    printf("%d\n", stack.pop());
    printf("%d\n", stack.pop());

    return 0;
}