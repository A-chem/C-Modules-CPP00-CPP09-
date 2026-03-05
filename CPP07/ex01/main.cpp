#include "iter.hpp"

int main()
{
    int arr1[] = {1, 5, 8 ,4};
    float arr2[] = {1.5, 5.88f, 8.6 ,4.8f};
    std::string arr3[] = {"a", "bb", "ccc", "ddd"};
    iter(arr1, 4, print);
    iter(arr2, 4, print);
    iter(arr3, 4, print);
}