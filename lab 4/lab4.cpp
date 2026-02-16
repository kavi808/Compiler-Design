#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Function to eliminate immediate left recursion for a specific pattern (A -> Aα | β)
void eliminateLeftRecursion(const std::string& nonTerminal, const std::vector<std::string>& productions) {
    std::string alpha, beta;
    std::vector<std::string> alphas, betas;

    // Assuming the input productions are in the form: [Aα1, Aα2, ..., β1, β2, ...]
    for (const std::string& prod : productions) {
        if (prod.rfind(nonTerminal, 0) == 0) { // Check if production starts with the non-terminal
            alphas.push_back(prod.substr(nonTerminal.length()));
        } else {
            betas.push_back(prod);
        }
    }

    if (alphas.empty()) {
        std::cout << "No direct left recursion found for non-terminal " << nonTerminal << std::endl;
        return;
    }

    // Output transformed productions
    std::cout << "Original Productions for " << nonTerminal << ": ";
    for (size_t i = 0; i < productions.size(); ++i) {
        std::cout << nonTerminal << " -> " << productions[i] << (i == productions.size() - 1 ? "" : " | ");
    }
    std::cout << std::endl;

    std::cout << "Transformed Productions:" << std::endl;
    // A -> β1A' | β2A' | ...
    for (const std::string& b : betas) {
        std::cout << nonTerminal << " -> " << b << nonTerminal << "'" << std::endl;
    }
    // A' -> α1A' | α2A' | ... | ε
    std::cout << nonTerminal << "' -> ";
    for (size_t i = 0; i < alphas.size(); ++i) {
        std::cout << alphas[i] << nonTerminal << "'" << (i == alphas.size() - 1 ? " | ε" : " | ");
    }
    std::cout << std::endl;
}

int main() {
    // Example: E -> E + T | T (A -> Aα | β)
    // Non-terminal 'E', productions {"E+T", "T"}, but we need just the RHS for processing
    std::vector<std::string> eProductions = {"+T", "T"}; // We extract only the RHS
    eliminateLeftRecursion("E", {"+T", "T"}); // Pass the full RHS parts and the non-terminal for logic
    
    std::cout << std::endl;

    // Example: T -> T * F | F (A -> Aα | β)
    std::vector<std::string> tProductions = {"*F", "F"};
    eliminateLeftRecursion("T", {"*F", "F"});

    return 0;
}
