#include <iostream>
#include <utility>

void test(int& value)
{
    std::cout << "lvalue\n";
}

void test(int&& value)
{
    std::cout << "rvalue\n";
}

int main()
{
    // 1. lvalue и rvalue
    int x = 10;   
    
    // x — lvalue
    // 10 — rvalue
    // x + 5 — rvalue


    // 2. Lvalue references

    int& ref = x;

    // ref — lvalue
    // ref и x ссылаются на один объект

    ref = 30;

    // 3. Rvalue references
    int&& rref = 20;

    // rref имеет тип int&&,
    // но выражение rref является lvalue

    rref = 40;
   
    // 4. T&& variable is an lvalue expression

    int& ref2 = x;
    int& ref3 = rref;

    // int&& ref4 = x; // error: x — lvalue
  
    // 5. Overloading by value category
    test(x);    // lvalue
    test(10);   // rvalue
    test(rref); // lvalue

    // 6. std::move
    test(std::move(x));
    test(std::move(rref));

    return 0;
}