#include <iostream>
#include <vector>
#include <algorithm>

// return index of first `a[i] == value` or index of element to insert before
ssize_t BinarySearch_LowerBound(std::vector<int> container, int value)
{
    ssize_t l = 0;
    ssize_t r = container.size() - 1;

    while (l != r)
    {
        ssize_t mid = l + (r - l) / 2;
        if (value <= container[mid])
            r = mid;
        else
            l = mid + 1;
    }
    if ((l == container.size() - 1) && (container[l] < value))
        ++l;
    return l;
}

// return index of first `a[i] > value` or index of element to insert before
ssize_t BinarySearch_UpperBound(std::vector<int> container, int value)
{
    ssize_t l = 0;
    ssize_t r = container.size() - 1;

    while (l != r)
    {
        ssize_t mid = l + (r - l) / 2;
        if (value < container[mid])
            r = mid;
        else
            l = mid + 1;
    }
    if ((l == container.size() - 1) && (container[l] <= value))
        ++l;
    return l;
}

int main()
{
    size_t amount_of_elements;
    std::cout << "Enter the amount of elements: "; std::cin >> amount_of_elements;
    std::vector<int> container(amount_of_elements);

    std::cout << "Enter these elements:" << std::endl;
    for (auto& elem: container)
        std::cin >> elem;
    
    std::sort(container.begin(), container.end());
    std::cout << "\nYour's sorted array:\n";
    for (const auto& elem: container)
        std::cout << elem << ' ';
    
    int value_to_find;
    std::cout << "\n\nEnter a value to check: "; std::cin >> value_to_find;
    std::cout << "The lower bound index of this value is: " << BinarySearch_LowerBound(container, value_to_find) << std::endl;
    std::cout << "The upper bound index of this value is: " << BinarySearch_UpperBound(container, value_to_find) << std::endl;
    
    return 0;
}