#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// A simplified function to demonstrate left factoring logic on two productions with a common prefix
void leftFactoring(const std::string& nonTerminal, const std::string& prod1, const std::string& prod2) {
    std::cout << "Original Productions for " << nonTerminal << ": " << nonTerminal << " -> " << prod1 << " | " << prod2 << std::endl;

    std::string commonPrefix;
    int minLength = std::min(prod1.length(), prod2.length());

    for (int i = 0; i < minLength; ++i) {
        if (prod1[i] == prod2[i]) {
            commonPrefix += prod1[i];
        } else {
            break;
        }
    }

    if (commonPrefix.empty()) {
        std::cout << "No common prefix to factor." << std::endl;
        return;
    }

    std::string remainder1 = prod1.substr(commonPrefix.length());
    std::string remainder2 = prod2.substr(commonPrefix.length());
    std::string newNonTerminal = nonTerminal + "'";

    // Output transformed productions
    std::cout << "After Left Factoring:" << std::endl;
    std::cout << nonTerminal << " -> " << commonPrefix << newNonTerminal << std::endl;
    std::cout << newNonTerminal << " -> " << (remainder1.empty() ? "ε" : remainder1) << " | " << (remainder2.empty() ? "ε" : remainder2) << std::endl;
}

int main() {
    // Example: A -> aB | aC
    leftFactoring("A", "aB", "aC");
    
    std::cout << std::endl;

    // Example: S -> iEtS | iEtSeS | ... (simplified to two for illustration)
    leftFactoring("S", "iEtS", "iEtSeS");

    return 0;
}
