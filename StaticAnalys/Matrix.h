#pragma once
#include <iostream>
#include <exception> 

class Matrix {
public:

    Matrix() = default;

    Matrix(size_t size) : _size(size) {
        _data = new int* [size];
        for (size_t i = 0; i < size; ++i) {
            _data[i] = new int[size];
        }
    }
    Matrix(Matrix& matrix) {
        _size = matrix._size;
        _data = new int* [_size];
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = new int[_size];
            for (size_t j = 0; j < _size; j++)
                _data[i][j] = matrix._data[i][j];
        }
    }

    ~Matrix() {
        for (size_t i = 0; i < _size; ++i) {
            delete[] _data[i];
        }
        delete[] _data;
    }

    void fillRand() {
        for (size_t i = 0; i < _size; ++i) {
            for (size_t j = 0; j < _size; ++j)
                _data[i][j] = rand() % 10;
        }
    }

    void setData(int** data) {
        for (size_t i = 0; i < _size; ++i) {
            for (size_t j = 0; j < _size; ++j)
                _data[i][j] = data[i][j];
        }
    }

    int** getData() {
        return _data;
    }

    size_t getSize() {
        return _size;
    }


    void show() {
        for (size_t i = 0; i < _size; ++i) {
            for (size_t j = 0; j < _size; ++j) {
                std::cout << _data[i][j] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }


    Matrix& operator+(Matrix& matrix) {
        if (matrix._size != _size)
            throw std::exception("Incorrect size!");

        Matrix* temp = new Matrix(_size);
        for (size_t i = 0; i < _size; ++i) {
            for (size_t j = 0; j < _size; ++j) {
                temp->_data[i][j] = _data[i][j] + matrix._data[i][j];
            }
        }
        return *temp;
    }

    Matrix& operator-(Matrix& matrix) {
        if (matrix._size != _size)
            throw std::exception("Incorrect size!");

        Matrix* temp = new Matrix(_size);
        for (size_t i = 0; i < _size; ++i) {
            for (size_t j = 0; j < _size; ++j) {
                temp->_data[i][j] = _data[i][j] - matrix._data[i][j];
            }
        }
        return *temp;
    }


private:
    size_t _size = 0;
    int** _data = nullptr;

};
