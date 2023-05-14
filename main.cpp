#include "Commands.hpp"

int main () {

    std::cout << "Welcome to XML Parser app! To continue, please enter a command or type \"help\" for more information." << std::endl;

    Commands shell;

    std::string command;
    std::string nextCommand, next;

        std::cout << ">";
        getline(std::cin, command);
        
        shell.process(command);

        std::cout << ">";
        getline(std::cin, nextCommand);

        shell.process(nextCommand);

        std::cout << ">";
        getline(std::cin, next);

        shell.process(next);

    return 0;
}