#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <random>

using namespace std;
//https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/


void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

void SelectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n ; ++i) {
        for (int j = i; j < n ; ++j) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void printArray(std::vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    sleep(3);
    cout << endl;
}

double getResultFromAlg(vector<int>& arr,int option) {
    time_t start, end;
    double time_taken;
    switch(option) {
        case 1:
            time(&start);
            ios_base::sync_with_stdio(false);
            insertionSort(arr);
            time(&end);
            time_taken = double(end - start);
            return time_taken;
            break;
        case 2: 
            time(&start);
            ios_base::sync_with_stdio(false);
            SelectionSort(arr);
            time(&end);
            time_taken = double(end - start);
            return time_taken;
            break;
        case 3:
            time(&start);
            ios_base::sync_with_stdio(false);
            bubbleSort(arr);
            time(&end);
            time_taken = double(end - start);
            return time_taken;
            break;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    
    if (argc < 1) {
        cout << "Usage: program <amount>\n";
        return 1;
    }
    srand(time(nullptr));
    int amount = 50000 + (rand() % (52300 - 50000 + 1));(50000, 52300);
    

    int optionAlg = 0;

    cout << "Carreras de algoritmos " << endl;
    cout << "1. Acendente." << endl;
    cout << "2. Descendente." << endl;
    cout << "Opcion elegida: " << endl;
    cin >> optionAlg;


    srand(time(nullptr));
    vector<int> arr;
    vector<int> arrCanByDuplicate;
    vector<int> arrSorted;
    vector<int> arrReverse;
    bool insert;
    bool exists = false;
    int random_value;

    cout << "Generando set de datos: " << endl;

    for (int i = 0; i < amount ; ++i) {
        arrSorted.push_back(i+1);
        arrReverse.push_back(amount-i);
        if ( i == 0 ) {
            random_value = 1 + rand() % (amount);
            arr.push_back(random_value);
        }
        else {
            // insert = false;
            // while (insert != true){
            //     exists = false;
            random_value = 1 + rand() % (amount);
            //     for (int j = 0 ; j < i ; j++ ) {
            //         if (random_value == arr[j]) {
            //             exists = true;
            //             break;
            //         }
            //     }
            //     if (exists == false) {
            arr.push_back(random_value);
            //         insert = true;
            //     }
            // }
        }
    }
    for (int i = 0; i < amount ; ++i) {
        random_value = 1 + rand() % (amount);
        arrCanByDuplicate.push_back(random_value);
    }
    //printArray(arrSorted);
    cout << amount  << " elementos en cada modo fueron generados." << endl;

    unordered_map<string, double> results;
    
    vector<int> arr1,arr2;
    arr1.assign(arrReverse.begin(), arrReverse.end());
    arr2.assign(arrReverse.begin(), arrReverse.end());


    cout << "Carrera por el Tablero: Modo Inversamente ordenado comenzo" << endl;

    results["InsertionSort"] = getResultFromAlg(arrReverse,1);
    results["SeleciontSort"] = getResultFromAlg(arr1,2);
    results["BubbleSort"] = getResultFromAlg(arr2,3);

    cout << endl << endl;


    

    //cout << "Carrera por el Tablero: Modo Inversamente ordenado " << endl;
    int id = 1;
    double Winning = 100;
    string titleWinnige = "";
    for (const auto& pair : results) {
        const string& key = pair.first;
        double value = pair.second;
        cout << id << ". " << key << ", " << fixed << value << setprecision(5) << endl;
        id++;
        if (value < Winning) {
            Winning = value;
            titleWinnige = key;
        }

    }
    cout << endl << endl;
    std::cout << "El ganador es:"  << titleWinnige << std::fixed << std::setprecision(5) << "con un tiempo de " << Winning << " segundos\n";
    //cout << "El ganador es:" << titleWinnige << " con un tiempo de " << Winning << " segundos" << endl;
    cout << endl << endl;

    return 0;
}
