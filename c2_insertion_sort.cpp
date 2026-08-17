#include <string>
#include <iostream>
#include <array>
#include <algorithm> 
using namespace std;

// sort an array of n characters
void insertionSort(int *A, int n)
{
    // insertion loop
    for (int i = 1; i < n; i++)
    {
        char cur = A[i]; // current character to insert
        int j = i - 1;   // start at previous character

        // while A[j] is out of order
        while ((j >= 0) && (A[j] > cur))
        {
            A[j + 1] = A[j]; // move A[j] right
            j--;             // decrement j
        }
        A[j + 1] = cur; // this is the proper place for cur
    }
}

int main(){
    int score[10] = {34, 56, 88, 77, 90, 22 , 10, 88, 95, 12};

    array<int, 10> score2 = {34, 56, 88, 77, 90, 22 , 10, 88, 95, 12};

    cout << "score not sorted : ";
    for (int i = 0; i< 10; i++){
        cout << score[i] << " ";
    }

    insertionSort(score, 10);
 
    cout << "\n" << "score after sorting : ";
    for (int i = 0; i< 10; i++){
        cout << score[i] << " ";
    }

    sort(score2.begin(), score2.end()); 
    cout << "\n" << "Score 2 after sorting : ";
    for (int i = 0; i< score2.size(); i++){
        cout << score2[i] << " ";
    }

}