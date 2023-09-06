#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

bool serch(std::vector<int>& vector, int numb) {
    for (int i{}; i < vector.size(); ++i) {
        if (vector[i] == numb) {
            return true;
        }
    }
    return false;
}

void bfs(int** matrix, int i, int size, std::vector<int>& result, std::queue<int>& queue) {
    if (!queue.empty()) {
        queue.pop();
    }
    for (int j{}; j < size; ++j) {
        if (matrix[i][j] != 0) {
            if (!serch(result, j)) {
                result.push_back(j);
            }
            matrix[i][j] = 0;
            matrix[j][i] = 0;
            queue.push(j);
        }
    }
}

int main() {
    std::fstream f_in("input.txt");
        int size{};
        if (f_in.is_open()) {
            f_in >> size;
            int** matrix = new int* [size];
            for (int i{}; i < size; ++i) {
                matrix[i] = new int[size];
            }
            for (int i{}; i < size; ++i) {
                for (int j{}; j < size; ++j) {
                    f_in >> matrix[i][j];
                }
            }

            int start{};
            std::cout << "Enter first vertex: ";
            std::cin >> start;
            std::vector<int> result{ start - 1};
            std::queue<int> queue;
            bfs(matrix, start - 1, size, result, queue);
            while (!queue.empty()) {
                bfs(matrix, queue.front(), size, result, queue);
            }
            for (auto i : result) {
                std::cout << i + 1 << " ";
            }
            for (int i{}; i < size; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    f_in.close();
}