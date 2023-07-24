#include <iostream>
#include <thread>
#include <functional>

void calculateArr(int begin, int end, int arr[], int& summArr)
{
    for (int y = begin; y < end; y++)
    {
        summArr += arr[y];
    }
}

int main()
{
    int summArr = 0;
    const int sizeArr = 20;
    int arr[sizeArr];
    for (int i = 0; i < sizeArr; i++)
    {
        arr[i] = i + 1;
    }

    std::thread t1(calculateArr, 0, 5, arr, std::ref(summArr));
    std::thread t2(calculateArr, 5, 10, arr, std::ref(summArr));
    std::thread t3(calculateArr, 10, 15, arr, std::ref(summArr));
    std::thread t4(calculateArr, 15, 20, arr, std::ref(summArr));
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "Summ = " << summArr << std::endl;
    return 0;
}