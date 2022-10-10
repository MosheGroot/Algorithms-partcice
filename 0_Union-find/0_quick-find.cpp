#include <iostream>
#include <iomanip>
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
        if (container_[first] == container_[second])
            return;
        auto mergeable_component = container_[first]; // mergeable component
        auto component_to_merge_in = container_[second]; // component to merge in
        for (auto& elem: container_)
        {
            if (elem == mergeable_component)
                elem = container_[component_to_merge_in];
        }
    }

    bool Connected(uint64_t first, uint64_t second)
    {
        return container_[first] == container_[second];
    }

private:
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