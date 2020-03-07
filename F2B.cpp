#include <bits/stdc++.h>
#include <iostream>
#include <chrono> 

using std::cin;
using std::cout;
using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now(); 

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arraySize, target, count;
    cin >> arraySize;

    if (arraySize % 2)
    {
        target = arraySize/2 + 1;
    }
    else
    {
        target = (arraySize-1)/2 + 1;
    }
    
    int array[arraySize];
    for (int i=0; i<arraySize; i++)
    {
        cin >> array[i];
    }

    auto stop = high_resolution_clock::now();
    
    for (int i=0; i<arraySize; i++)
    {   
        count = 0;

        for (int j=0; j<arraySize; j++)
        {
            if (array[j] == array[i])
            {
                count++;
                if (count >= target)
                {
                    //printf("%d\n", array[i]);
                    return 0;
                }
            }
        }
    }
    //cout << "Sem elemento." << "\n";

    auto stopFinal = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stopFinal - start); 
    //cout << "Duration: " << duration.count() << "ms\n";

    cout << duration.count() << " ";

    return 0;
}