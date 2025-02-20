#include <iostream>
#include <string>
#include <sstream>

std::string formatText(const std::string& text, int n) {
    std::istringstream iss(text);
    std::string word, result = "", line = "";

    while (iss >> word) {
        if (line.length() + word.length() + (line.empty() ? 0 : 1) <= n) {
            if (!line.empty()) line += " ";
            line += word;
        }
        else {
            result += line + "\n"; 
            line = word;           
        }
    }
    
    if (!line.empty()) {
        result += line + "\n";
    }

    
    size_t pos = 0;
    while ((pos = result.find(". ", pos)) != std::string::npos) {
        if (pos + 2 < result.length() && result[pos + 2] != '\n') {
            result.insert(pos + 2, "\n\n");  
        }
        pos += 3; 
    }

    return result;
}

int main() {
    int n;
    std::string text, temp;

    std::cout << "Enter the text width (n > 50): ";
    std::cin >> n;
    std::cin.ignore(); 

    if (n <= 50) {
        std::cout << "The width of the text should be larger 50.\n";
        return 0;
    }

    std::cout << "Enter the text (press Ctrl+D or Ctrl+Z to finish typing):\n";
    while (std::getline(std::cin, temp)) {
        text += temp + " ";
    }

    std::string formattedText = formatText(text, n);

    std::cout << "\nFormatted text:\n";
    std::cout << formattedText;

    return 0;
}
