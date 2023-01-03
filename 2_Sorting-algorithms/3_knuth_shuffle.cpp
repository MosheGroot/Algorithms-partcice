#include <iostream>
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

void KnuthShuffle()
{
    for (int current_index = 0; current_index < N; ++current_index)
    {
        int index_to_swap_with = std::rand() % (current_index + 1);
        std::swap(array[current_index], array[index_to_swap_with]);
    }
}

int main() {
    FillArray();
    PrintArray();

    KnuthShuffle();
    PrintArray();

    return 0;
}
