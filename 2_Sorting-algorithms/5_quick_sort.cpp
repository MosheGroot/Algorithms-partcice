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

    static int Partition(int* array, int l, int r)
    {
        int pivot = array[l];
        int pivot_index = l;

        int i = l + 1;
        int j = r;
        while (true)
        {
            // Search for element that is larger than the pivot
            // to move it to the right part
            while (array[i] <= pivot && i < r)
                ++i;

            // Search for element that is lesser than the pivot
            // to move it to the left part
            while (pivot <= array[j] && j > l)
                --j;

            if (i >= j)
                break;

            std::swap(array[i], array[j]);
        }

        // The array[r] element now is the  leftmost
        // element that is lesser than the pivot,
        // so we can swap these elements,
        // and the pivot element will occur exactly
        // between the parts lesser and larger than the pivot element.
        std::swap(array[pivot_index], array[j]);
        return j; // return pivot's index
    }

    static void QuickSortImpl(int* array, int l, int r)
    {
        if (r <= l)
            return;

        int pivot = Partition(array, l, r);
        QuickSortImpl(array, l, pivot - 1);
        QuickSortImpl(array, pivot + 1, r);
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
