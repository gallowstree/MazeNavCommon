#include <iostream>
#include <assert.h>
#include "Stack.h"


class Example {
public:
    int val;
};

int main() {

    Stack<Example*> s;

    assert(s.isEmpty());

    auto e1 = Example();
    e1.val = 666;
    s.push(&e1);
    e1.val = 667;

    std::cout << s.pop()->val << std::endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}