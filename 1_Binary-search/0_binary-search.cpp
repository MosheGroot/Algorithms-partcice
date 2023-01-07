#include <iostream>
#include <vector>
#include <algorithm>

ssize_t BinarySearch(std::vector<int> container, int value)
{
    ssize_t l = 0;
    ssize_t r = container.size() - 1;

    while (l <= r)
    {
        ssize_t mid = l + (r - l) / 2;
        if (value < container[mid])
            r = mid - 1;
        else if (value > container[mid])
            l = mid + 1;
        else
            return mid;
    }
    return -1;
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
    std::cout << "\n\nEnter a value to find: "; std::cin >> value_to_find;
    std::cout << "Index of this value is: " << BinarySearch(container, value_to_find) << std::endl;

    return 0;
}