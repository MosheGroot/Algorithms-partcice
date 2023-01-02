#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdint>

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

void SelectionSort()
{
    for (int first_unsorted = 0; first_unsorted < N - 1; ++first_unsorted)
    {
		int current_min = first_unsorted;
        for (int current_element = first_unsorted; current_element < N; ++current_element)
		{
			if (array[current_element] < array[current_min])
				current_min = current_element;
		}
		std::swap(array[first_unsorted], array[current_min]);
    }
}

int main() {
    FillArray();
    PrintArray();
    
    SelectionSort();
    PrintArray();

    return 0;
}
