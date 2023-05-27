#include "Runner.hpp"

int main () {

    try {
        Runner::run();

    } catch (std::exception& e) {
        
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
