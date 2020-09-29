#pragma once

#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>

template <class T>
class Matrix {
    private:
        std::vector<std::vector<T>> data;

        bool isRowIndexInRange(const int&);

    public:
        Matrix() {};
        ~Matrix() {};

        void insertRow(const std::vector<T>&);
        void eraseRow(const int&);

        void addRowToRowWithCoeff(const int&, const int&, const T&);
        void multiplyRowToCoeff(const int&, const T&);

        void readFromFile(const std::string&);
        void printToFile(const std::string&);
        void print();
};

template <class T>
bool Matrix<T>::isRowIndexInRange(const int& index) {
    return index >= 0 && index < this->data.size();
};

template <class T>
void Matrix<T>::insertRow(const std::vector<T>& row) {
    this->data.push_back(row);
}

template <class T>
void Matrix<T>::eraseRow(const int& index) {
    this->data.erase(this->data.begin() + index);
}

template <class T>
void Matrix<T>::addRowToRowWithCoeff(const int& srcIndex, const int& dstIndex, const T& coeff) {
    if (!isRowIndexInRange(srcIndex) || !isRowIndexInRange(dstIndex) || srcIndex == dstIndex) {
        return;
    }

    int j = 0;
    for (auto srcElement : this->data[srcIndex]) {
        this->data[dstIndex][j] = this->data[dstIndex][j] + srcElement * coeff;
        j++;
    }
};

template <class T>
void Matrix<T>::multiplyRowToCoeff(const int& index, const T& coeff) {
    if (!isRowIndexInRange(index)) {
        return;
    }

    int j = 0;
    for (auto element : this->data[index]) {
        this->data[index][j] = element * coeff;
        j++;
    }
};

template <class T>
void Matrix<T>::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line, num;

    int j = 0;
    while (!file.eof()) {
        std::getline(file, line);
        std::vector<T> row;
        num = "";
        for (auto ch : line) {
            if (std::isdigit(ch) || ch == '-') {
                num += ch;
            } else {
                row.push_back(T(std::stoi(num)));
                num = "";
            }
        }
        if (num != "") {
            row.push_back(T(std::stoi(num)));
        }
        this->insertRow(row);
        j++;
    }

    file.close();
}

template <class T>
void Matrix<T>::printToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);

    int j = 0;
    for (auto row : this->data) {
        for (auto element : this->data[j]) {
            file << element << " ";
        }
        file << std::endl;
        j++;
    }

    file.close();
};

template <class T>
void Matrix<T>::print() {
    if (this->data.empty()) {
        std::cout << "Matrix is empty." << std::endl;
        return;
    }

    for (auto row : this->data) {
        for (auto element : row) {
            std::cout << std::setw(5) << element << " ";
        }
        std::cout << std::endl;
    }
}
