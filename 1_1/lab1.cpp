/*#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

void RandomArray(vector<int>& A, vector<int>& B) {
    ofstream fout("Array.bin", ios_base::binary);
    int N;
    cout << "Enter array size: ";
    cin >> N;

    A.resize(2 * N);
    B.resize(2 * N);
    srand(time(NULL));

    for (int i = 0; i < 2 * N; i++) {
        A[i] = rand() % 20 - 10; 
    }
    fout.write((char*)&A[0], A.size() * sizeof(A[0]));
    fout.close();
}

void MainTask(vector<int>& A, vector<int>& B) {
    int N = A.size() / 2;


    for (int i = 0; i < N; i++) {
        B[i] = A[i + N];
    }

    for (int i = N; i < 2 * N; i++) {
        B[i] = A[i - N];
    }
}

int main() {

    vector<int> A;
    vector<int> B;

    RandomArray(A, B);

    cout << "Array A: ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    MainTask(A, B);

    cout << "Array B after main task: ";    
    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}*/

/*16. Знайти номер першого мінімального значення серед додатних елементів,
розташованих правіше першого елемента, рівного нулю.

#include <iostream>
#include <time.h>
using namespace std;

int main() {
    int N;
    cout << "Enter array size: ";
    cin >> N;

    int* A = new int[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 20 - 10;
        cout << A[i] << " ";
    }

    int* ptr = A;
    bool b = false;
    int min = 20;
    for (int i = 0; i < N; i++) {
        if (*ptr == 0) {
            b = true;
            for (int j = i + 1; j < N; j++) {
                if (*ptr > 0 && *ptr < min) {
                    min = *ptr;
                }
                ptr++; // для першого for
            }
            break;
        }
        ptr++; //для наступного 
    }

    if (min == 20) {
        if (b) {
            cout << "\nNo positive elements to the right of the first zero." << endl;
        }
        else {
            cout << "\nNo zero elements found in the array." << endl;
        }
    }
    else {
        cout << "\nThe first minimum positive value to the right of the first zero is: " << min << endl;
    }
    delete[] A;
    return 0;
}*/


#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void RandomArray(vector<int>& A, int N) {
    A.resize(N);
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 21 - 10;
    }
}

void MainTask(vector<int>& A, int N, int& sum, int& last, int& first) {
    last = -1;
    first = -1;
    sum = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    if (first != -1 && last != -1) {
        for (int i = first + 1; i < last; i++) {
            sum += A[i];
        }
    }
}

int main() {
    int N, sum, last, first;
    cout << "Enter array size: ";
    cin >> N;

    if (N > 500) {
        cout << "Invalid array size. Please enter a size <= 500." << endl;
        return -1;
    }

    vector<int> A;

    RandomArray(A, N);

    cout << "Array A: ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    MainTask(A, N, sum, last, first);

    if (first != -1 && last != -1) {
        cout << "First negative element index: " << first << endl;
        cout << "Last negative element index: " << last << endl;
        cout << "Sum of elements between first and last negative elements: " << sum << endl;
    }
    else {
        cout << "No negative elements found in the array." << endl;
    }

    return 0;
}
