#include <iostream>
#include <cstdlib>
#include <ctime>

static constexpr int N = 3;
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

void InsertionSort()
{
    for (int last_unsorted = 1; last_unsorted < N; ++last_unsorted)
    {
        for (int current_element = last_unsorted;
            array[current_element] < array[current_element - 1];
            --current_element)
        {
            std::swap(array[current_element], array[current_element - 1]);
        }
    }
}

int main() {
    FillArray();
    PrintArray();
    
    InsertionSort();
    PrintArray();

    return 0;
}
