
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <vector>
using namespace std;
void print(vector<int> );
void insertionSort(vector<int>);
void selectionSort(vector<int> );
void bubbleSort(vector<int> );
void quickSort(vector<int>& , int , int );
int partition(vector<int>& , int , int );
int main()
{
    setlocale(LC_ALL, "Turkish");

    int choice;
    int n;
    vector<int> array(4);
    cout << "1.Insertion Sort\n";
    cout << "2.Selection Sort\n";
    cout << "3.Bubble Sort\n";
    cout << "4.Quick Sort\n";
    cout << "Sıralama algoritmasını seçin:";
    
    
    cin >> choice;
    
    cout << "---------------------------------------\n";

    for (int i = 0; i < 4; i++) {
        cin>> array[i] ;
    }

    print(array);
    
    switch (choice) {
    case 1:
        insertionSort(array);


        break;
    case 2:
        selectionSort(array);

        break;
    case 3:
        bubbleSort(array);

        break;
    case 4:
        n = array.size();
        quickSort(array,0,n-1);

        break;

    default:
        cout << "Geçersiz seçim!";
    }
}


void print(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        cout << array[i] << "\t";
    }
    cout << endl << endl;

}

void insertionSort(vector<int> array) {
    int n = array.size();

    for (int i = 1; i < n; ++i) {
        int key = array[i];
        int j = i - 1;

        // Key'den büyük olan elemanları bir pozisyon ileri kaydırma
        while ( j>=0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;

        print(array);
       
    }

   
}

void selectionSort(vector<int> array) {
    int n = array.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;  // En küçük elemanın indeksini tutar
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;  // Yeni en küçük eleman bulundu
            }
        }

        // En küçük elemanı ilk elemanla yer değiştir
        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }

        print(array);
    }
}

void bubbleSort(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        print(array);


    }
}

void quickSort(vector<int>& array,  int low, int high) {
    
  
    if (low < high) {

        
        int pi = partition(array, low, high);

        print(array);

        quickSort(array, low, pi - 1);
        print(array);
        quickSort(array, pi + 1, high);
        
    }
}

int partition(vector<int>& array, int low, int high) {

    
    int pivot = array[high];

   
    int i = (low - 1);

    
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

        
            i++;

           
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

   
    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;

   
    return (i + 1);
}


