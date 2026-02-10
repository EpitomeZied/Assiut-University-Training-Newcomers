// main.cpp

#include <iostream>
#include <vector>
#include <stdexcept>

// Type alias for a 2D vector to represent a matrix, improving readability.
using Matrix = std::vector<std::vector<int>>;

/**
 * @brief Sets up fast I/O for C++.
 * Disables synchronization with C-style I/O and unties cin from cout.
 */
void setup_fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

/**
 * @brief Reads a matrix of given dimensions from standard input.
 * @param rows The number of rows in the matrix.
 * @param cols The number of columns in the matrix.
 * @return The populated matrix.
 */
Matrix read_matrix(int rows, int cols) {
    Matrix mat(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> mat[i][j];
        }
    }
    return mat;
}

/**
 * @brief Prints the elements of a matrix to the console.
 * @param mat The matrix to be printed.
 */
void print_matrix(const Matrix& mat) {
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[0].size(); ++j) {
            std::cout << mat[i][j] << (j == mat[0].size() - 1 ? "" : " ");
        }
        std::cout << '\n';
    }
}

/**
 * @brief Multiplies two matrices.
 * @param matrixA The first matrix (left operand).
 * @param matrixB The second matrix (right operand).
 * @return The resulting product matrix.
 * @throws std::invalid_argument if the matrices cannot be multiplied.
 */
Matrix multiply_matrices(const Matrix& matrixA, const Matrix& matrixB) {
    if (matrixA.empty() || matrixB.empty()) {
        throw std::invalid_argument("Input matrices cannot be empty.");
    }

    size_t rowsA = matrixA.size();
    size_t colsA = matrixA[0].size();
    size_t rowsB = matrixB.size();
    size_t colsB = matrixB[0].size();

    // Check for compatibility: columns of A must equal rows of B.
    if (colsA != rowsB) {
        throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
    }

    // Initialize the result matrix with zeros.
    Matrix result(rowsA, std::vector<int>(colsB, 0));

    for (size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsB; ++j) {
            for (size_t k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}

int main() {
    setup_fast_io();

    try {
        int rowsA, colsA, rowsB, colsB;

        // Read dimensions and data for the first matrix
        std::cin >> rowsA >> colsA;
        Matrix matrixA = read_matrix(rowsA, colsA);

        // Read dimensions and data for the second matrix
        std::cin >> rowsB >> colsB;
        Matrix matrixB = read_matrix(rowsB, colsB);

        // Calculate and print the result
        Matrix result_matrix = multiply_matrices(matrixA, matrixB);
        print_matrix(result_matrix);

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Indicate failure
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1; // Indicate failure
    }

    return 0; // Indicate success
}