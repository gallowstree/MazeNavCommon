#include <iostream>
#include <assert.h>
#include "Stack.h"
#include "HashMap.h"


class Example {
public:
    Example(int val): val(val) {}
    int val;
};

void testStack();
void testHashMap();

int main() {

    testHashMap();

    return 0;
}

void testStack() {
    Stack<Example*> s;

    assert(s.isEmpty());

    auto e1 = Example(666);
    s.push(&e1);
    e1.val = 667;

    std::cout << s.pop()->val << std::endl;
}

void testHashMap() {
    HashMap<Example*> map;

    assert(map.isEmpty());
    auto f = Example(1);
    map.put("first", &f);

    map.put("second", new Example(2));
    map.put("third", new Example(3));

    assert(!map.isEmpty());

    std::cout << map.get("first")->val << std::endl;
    map.put("first", new Example(5));
    std::cout << map.get("first")->val << std::endl;
    std::cout << map.get("second")->val << std::endl;
    std::cout << map.get("third")->val << std::endl;
    //std::cout << map.get("yee")->val << std::endl;

    map.remove("second");
    //std::cout << map.get("second")->val << std::endl;
    std::cout << map.get("third")->val << std::endl;
}