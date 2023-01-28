#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

static constexpr int N = 5;
static int* array = new int[N];

void FillArray()
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < N; ++i)
        array[i] = std::rand() % 10;
}

void PrintArray()
{
    for (int i = 0; i < N; ++i)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
}

class HeapSort
{
    static void MaxHeapSwim(int *array, int size, int index)
    {
        static auto get_parent = [](int index) -> int {
            return (index - 1) / 2;
        };

        int parent = get_parent(index);
        while (index > 0 && array[parent] < array[index])
        {
            std::swap(array[parent], array[index]);
            index = parent;
            parent = get_parent(index);
        }
    }

    static void MaxHeapSink(int *array, int size, int index)
    {
        static auto get_children = [](int index) -> std::pair<int, int> {
            return { index * 2 + 1, index * 2 + 2 };
        };

        auto children = get_children(index);
        while (children.first < size)
        {
            int max_child;
            if (children.second >= size || array[children.first] >= array[children.second])
                max_child = children.first;
            else
                max_child = children.second;
            if (array[max_child] < array[index])
                break;
            std::swap(array[max_child], array[index]);
            index = max_child;
            children = get_children(index);
        }
    }

    static void BuildMaxHeap(int *array, int size)
    {
        // building max heap using bottom-up method
        for (int i = size / 2; i >= 0; --i)
            MaxHeapSink(array, size, i);
    }

    static void ConvertMaxHeapToSortedArray(int *array, int size)
    {
        // move max to the end of the array
        // and try to support max heap structure
        // with other `size - 1` elements
        for (int i = size - 1; i > 0; --i)
        {
            std::swap(array[0], array[i]);
            MaxHeapSink(array, --size, 0);
        }
    }

public:
    static void Sort(int* array, int size)
    {
        BuildMaxHeap(array, size);
        ConvertMaxHeapToSortedArray(array, size);
    }
};

int main() {
    FillArray();
    PrintArray();

    HeapSort::Sort(array, N);
    PrintArray();

    return 0;
}
