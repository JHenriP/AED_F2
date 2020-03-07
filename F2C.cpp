#include <bits/stdc++.h>
#include <iostream>
#include <chrono> 

using std::cin;
using std::cout;
using namespace std::chrono; 

void bin(int bitCount[], int number, int aux)
{   
    if (number > 1)
    {
        bin(bitCount, number>>1, aux+1);
    }

    
    if (number&1 == 1)
    {
        bitCount[aux] = bitCount[aux] + 1; 
    }
    
    //cout << (number&1) << "\n";
}

int main()
{   
    auto start = high_resolution_clock::now(); 

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arraySize, target, result, count, maxBits;
    cin >> arraySize;

    if (arraySize % 2)
    {
        target = arraySize/2 + 1;
    }
    else
    {
        target = (arraySize-1)/2 + 1;
    }
    
    //Init array de elementos
    int array[arraySize];
    for (int i=0; i<arraySize; i++)
    {
        cin >> array[i];
    }

    //Init contador de bits
    maxBits = 8; //-> Maior número 255 
    int bitCount[8];
    for (int i=0; i<maxBits; i++)
    {
        bitCount[i] = 0;
    }

    auto stop = high_resolution_clock::now();

    //Itera sobre todos os elemtos, somando os valors binários
    for (int i=0; i<arraySize; i++)
    {   
        bin(bitCount, array[i], 0);
        //cout << "\n";
    }

    result = 0;
    for (int i=0; i<maxBits; i++)
    {
        //cout << bitCount[i] << " ";
        if (bitCount[i] >= target)
        {
            result += pow(2, i);
            //cout << i << "\n";
        }
    }

    count = 0;
    for (int i=0; i<arraySize; i++)
    {
        if (array[i] == result)
        {
            count++;
        }
        
        if (count >= target)
        {
            cout << result << "\n";
            return 0;
        }
    }

    //cout << "Sem elemento.\n";

    //cout << "\n";

    //cout << "Result: " << result << "\n";

    auto stopFinal = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stopFinal - start); 
    //cout << "Duration: " << duration.count() << "ms\n";

    cout << duration.count() << " ";
    return 0;
}
