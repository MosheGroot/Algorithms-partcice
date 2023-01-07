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

class QuickSort
{
private:
    static void Shuffle(int *array, int N)
    {
        for (int current_index = 0; current_index < N; ++current_index)
        {
            int index_to_swap_with = std::rand() % (current_index + 1);
            std::swap(array[current_index], array[index_to_swap_with]);
        }
    }

    static std::pair<int, int> PartitionIn3Way(int* array, int l, int r)
    {
        int pivot = array[l];

        int lt = l, gt = r;
        int i = l;
        while (i <= gt)
        {
            if (array[i] < pivot)
                std::swap(array[i++], array[lt++]);
            else if (array[i] > pivot)
                std::swap(array[i++], array[gt--]);
            else
                ++i;
        }

        return {lt, gt};
    }

    static void QuickSortImpl(int* array, int l, int r)
    {
        if (r <= l)
            return;

        auto pivot_indexes = PartitionIn3Way(array, l, r);
        QuickSortImpl(array, l, pivot_indexes.first - 1);
        QuickSortImpl(array, pivot_indexes.second + 1, r);
    }

public:
    static void Sort(int* array, int size)
    {
        Shuffle(array, N); // for performance guarantees
        QuickSortImpl(array, 0, size - 1);
    }
};

int main() {
    FillArray();
    PrintArray();

    QuickSort::Sort(array, N);
    PrintArray();

    return 0;
}
