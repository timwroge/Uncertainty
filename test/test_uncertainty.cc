#include <uncertainty/uncertainty.hh>
using namespace uncertainty;

int main(void) {
    Measurement A = {3, 4};
    Measurement B = {1, 4};
    auto C = A + B;
    auto D = A * B;

    std::cout << "A: "<< A << std::endl;
    std::cout << "C: "<< C << std::endl;
    std::cout << "D: "<< D << std::endl;
    std::cout << "A * 2: "<< A*2  << std::endl;
    std::cout << "2 * A : "<< 2 * A  << std::endl;
}
