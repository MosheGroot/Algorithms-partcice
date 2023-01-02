#include <iostream>
#include <cstdlib>
#include <ctime>

static constexpr int N = 15;
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

void ShellSort()
{
    int h = 1;
    while (h < N / 3)
        h = h * 3 + 1; // 3x + 1 sequence: 1, 4, 13, 40, 121, ...
    
    while (h >= 1)
    {
        for (int last_unsorted = h; last_unsorted < N; ++last_unsorted)
        {
            for (int current_element = last_unsorted;
                current_element >= h && array[current_element] < array[current_element - h];
                current_element -= h)
            {
                std::swap(array[current_element], array[current_element - h]);
            }
        }

        h /= 3; // take smaller gap
    }
}

int main() {
    FillArray();
    PrintArray();
    
    ShellSort();
    PrintArray();

    return 0;
}
