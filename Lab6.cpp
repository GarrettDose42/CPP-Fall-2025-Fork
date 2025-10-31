#include <iostream>
#include <vector>
#include <random>       
#include <stdexcept>    
#include <iomanip>

constexpr double RAND_MATRIX_NUM_MAGNITUDE{1000};
using matrix_type = std::vector<std::vector<double>>;

matrix_type construct_random_matrix(size_t N, size_t M);
matrix_type add_matrices(const matrix_type& a, const matrix_type& b);
void print_matrix(const std::string& title, const matrix_type& m);

int main(void){
    try{
        std::cout << "Rand matrix creation" <<std::endl;
        matrix_type M1{construct_random_matrix(4,4)};
        print_matrix("Matrix 1: ", M1);
        matrix_type M2{construct_random_matrix(4,4)};
        print_matrix("Matrix 2: ", M2);
        matrix_type M3{construct_random_matrix(4,5)};
        print_matrix("Matrix 3: ", M3);

        std::cout << "\ncorrect matrix additon:" <<std::endl;
        matrix_type Msum1{add_matrices(M1, M2)};
        print_matrix("M1+M2:", Msum1);
        Msum1 = add_matrices(Msum1, M2);
        print_matrix("Msum+M2", Msum1);

        std::cout << "\nincorrect Matrix addition:" <<std::endl;
        matrix_type Msum2{add_matrices(M3, M1)};

    }
    catch(const std::domain_error& e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}

matrix_type construct_random_matrix(size_t N, size_t M) {

    std::random_device seed;  //seed
    std::mt19937 rand(seed()); // random num
    std::uniform_real_distribution<double> flt(-RAND_MATRIX_NUM_MAGNITUDE, RAND_MATRIX_NUM_MAGNITUDE); // convert rand to float within range

    matrix_type matrix(N);
    for (size_t i = 0; i < N; ++i) {
        matrix[i].resize(M);
        for (size_t j = 0; j < M; ++j) {
            matrix[i][j] = flt(rand);
        }
    }
    return matrix;
}


matrix_type add_matrices(const matrix_type& a, const matrix_type& b) {
    //get sizes
    size_t rows_a = a.size();
    if (rows_a == 0) { // Handle empty matrix
        return matrix_type();
    }
    size_t cols_a = a[0].size();

    size_t rows_b = b.size();
    if (rows_b == 0) { // Handle empty matrix
        return matrix_type();
    }
    size_t cols_b = b[0].size();

    //check size compatibility
    if (rows_a != rows_b || cols_a != cols_b) {
        throw std::domain_error("Domain error: Matrices have incompatible dimensions for addition.");
    }

   // addition
    matrix_type result(rows_a);
    for (size_t i = 0; i < rows_a; ++i) {
        result[i].resize(cols_a);
        for (size_t j = 0; j < cols_a; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

void print_matrix(const std::string& title, const matrix_type& m) {
    std::cout << title << std::endl;
    if (m.empty()) {
        std::cout << "[ Empty Matrix ]" << std::endl;
        return;
    }

    std::cout << std::fixed << std::setprecision(3);
    for (const auto& row : m) {
        std::cout << "[ ";
        for (double val : row) {
            std::cout << std::setw(9) << val << " ";
        }
        std::cout << "]" << std::endl;
    }
}

