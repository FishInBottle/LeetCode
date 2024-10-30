#include <iostream>
#include <array>

using namespace std;

/*
* Fabonacci by Dynamic Programming
*/
std::array<uint32_t, 100> fabVal;

uint32_t fab(uint32_t num)
{
    if (1 >= num)
    {
        fabVal[num] = num;
    }
    else
    {
        if (-1 == fabVal[num])
        {
            fabVal[num] = fab(num - 1) + fab(num - 2);
        }
    }

    return fabVal[num];
}

int main()
{
    int32_t num;

    fabVal.fill(0xFFFFFFFF);

    while (true)
    {
        cout << "Input value for fabonacci sequence" << endl;
        cin >> num;
        if (99 < num || 0 > num)
        {
            cout << "OOR" << endl;
            break;
        }
        cout << fab((uint32_t)num) << endl;
    }
    
    return 1;
}
