#include <iostream>
#include <vector>

class QuickUnionUF
{

public:
    QuickUnionUF(size_t n)
        : container_(n)
    {
        for (size_t i = 0; i < n; ++i)
            container_[i] = i;
    }

    void Union(uint64_t first, uint64_t second)
    {
        container_[GetRoot(first)] = GetRoot(second);
    }

    bool Connected(uint64_t first, uint64_t second)
    {
        return GetRoot(first) == GetRoot(second);
    }

private:
    uint64_t GetRoot(uint64_t node)
    {
        while (container_[node] != node)
            node = container_[node];
        return node;
    }

    std::vector<uint64_t> container_;
};

int main()
{
    int amount_of_nodes;
    std::cout << "Enter the amount of nodes: ";
    std::cin >> amount_of_nodes;
    auto data_structure = QuickUnionUF(amount_of_nodes);

    size_t number_of_union_commands;
    std::cout << "Enter the number of union commands and then enter these commands: ";
    std::cin >> number_of_union_commands;
    for (size_t i = 0; i < number_of_union_commands; ++i)
    {
        int first, second;
        std::cin >> first >> second;
        data_structure.Union(first, second);
    }

    size_t number_of_connected_commands;
    std::cout << "Enter the number of connected commands and then enter these commands: ";
    std::cin >> number_of_connected_commands;
    std::cout << std::boolalpha;
    for (size_t i = 0; i < number_of_connected_commands; ++i)
    {
        int first, second;
        std::cin >> first >> second;
        std::cout << data_structure.Connected(first, second) << std::endl;
    }

    return 0;
}