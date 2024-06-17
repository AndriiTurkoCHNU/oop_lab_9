#include <array>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;


template<typename T, size_t SIZE>
void rotate(array<T, SIZE>& arr, int positions) {
    positions %= SIZE;
    array<T, SIZE> temp = arr;

    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = temp[(i + SIZE - positions) % SIZE];
    }
}

template<typename T>
void insertVectorInVector(vector<T> &v1, vector<T> &v2, int position) {
    v1.insert(v1.begin() + position, v2.begin(), v2.end());
}

template<typename T>
void removeMiddle(deque<T> &deq) {
    size_t size = deq.size();

    if (size % 2 == 0) {
        deq.erase(deq.begin() + size / 2 - 1, deq.begin() + size / 2 + 1);
    } else {
        deq.erase(deq.begin() + size / 2);
    }
}

int main() {
    // task_1
    cout << "Array" << endl;
    array<int, 5> arr = {1, 2, 3, 4, 5};

    rotate(arr, 1);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Array of arrays" << endl;

    array<int, 2> tmp1 = {1, 2};
    array<int, 2> tmp2 = {3, 4};
    array<int, 2> tmp3 = {5, 6};

    array<array<int, 2>, 3> arr2 = {tmp1, tmp2, tmp3};

    rotate(arr2, 4);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // task_2
    cout << "Vector" << endl;

    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {6, 7, 8};

    insertVectorInVector(v1, v2, 2);

    for (int i : v1) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Vector of vectors" << endl;

    vector<vector<int>> vec1 = {{1, 2}, {3, 4}};
    vector<vector<int>> vec2 = {{5, 6}, {7, 8}, {9, 10}};

    insertVectorInVector(vec1, vec2, 1);

    for (const auto &innerVec : vec1) {
        for (const auto &element: innerVec) {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << endl;

    // task_3
    cout << "Deque odd" << endl;

    deque<int> deq = {1, 2, 3, 4, 5};

    removeMiddle(deq);

    for (const auto &element : deq) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Deque even" << endl;

    deque<int> deqE = {1, 2, 3, 4, 5, 6};

    removeMiddle(deqE);

    for (const auto &element : deqE) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Deque of deques" << endl;

    deque<deque<int>> deqDeq = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};

    removeMiddle(deqDeq);

    for (const auto &innerDeq : deqDeq) {
        for (const auto &element : innerDeq) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}