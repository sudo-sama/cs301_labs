/*
 * Write a program which tries to swap values by:
 * 1: Value (in not possible though)
 * 2: Reference (Possible)
 * 3: Pointers (Tricky but possible)
*/

#include <iostream>

using namespace std;

template <typename T>
void swapping_by_value(T x, T y){
    T temp{x};
    x = y;
    y = temp;
}

template <typename T>
void swapping_by_reference(T& x, T& y){
    T temp{x};
    x = y;
    y = temp;
}

template <typename T>
void swapping_by_pointer(T* x, T* y){
    T temp{*x};
    *x = *y;
    *y = temp;
}

int main(){
    int x{5};
    int y{10};

    std::cout << "===== Function Call By Value =====\n";
    std::cout << "***Before Swapping***\n";
    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';
    swapping_by_value<int>(x, y);
    std::cout << "***After Swapping***\n";
    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';

    std::cout << "===== Function Call By Reference =====\n";
    std::cout << "***Before Swapping***\n";
    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';
    swapping_by_reference<int>(x, y);
    std::cout << "***After Swapping***\n";
    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';

    std::cout << "===== Function Call By Pointer =====\n";
    std::cout << "***Before Swapping***\n";
    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';
    swapping_by_pointer<int>(&x, &y);
    std::cout << "***After Swapping***\n";
    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';

    return 0;
}
