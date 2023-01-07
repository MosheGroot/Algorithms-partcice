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

class MergeSort
{
private:
    static void MergeParts(int *array, int* aux, int l, int mid, int r)
    {
        for (int i = l; i <= r; ++i)
            aux[i] = array[i];

        int i = l;          // part [i; mid]
        int j = mid + 1;    // part [mid + 1; r]
        for (int k = l; k <= r; ++k)
        {
            if (i > mid)
                array[k] = aux[j++];
            else if (j > r)
                array[k] = aux[i++];
            else if (aux[i] <= aux[j])
                array[k] = aux[i++];
            else
                array[k] = aux[j++];
        }
    }

    static void MergeSortImpl(int* array, int* aux, int l, int r)
    {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        MergeSortImpl(array, aux, l, mid);
        MergeSortImpl(array, aux, mid + 1, r);
        MergeParts(array, aux, l, mid, r);
    }

public:
    static void Sort(int* array, int size)
    {
        auto auxiliary_array = new int[N];
        MergeSortImpl(array, auxiliary_array, 0, N - 1);
        delete[] auxiliary_array;
    }
};

int main() {
    FillArray();
    PrintArray();

    MergeSort::Sort(array, N);
    PrintArray();

    return 0;
}
