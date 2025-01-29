#include <iostream>
#include <string>

std::string ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
std::string teens[] = { "", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen" };
std::string tens[] = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
std::string hundreds[] = { "", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred" };

std::string nTW(int n) {
    if (n == 1000) return "thousand";

    std::string result;

    result += hundreds[n / 100];

    int lastTwoDigits = n % 100;
    if (lastTwoDigits >= 11 && lastTwoDigits <= 19) {
        result += (result.empty() ? "" : " ") + teens[lastTwoDigits - 10];
    }
    else {
        int tensPart = lastTwoDigits / 10;
        int onesPart = lastTwoDigits % 10;

        if (tensPart > 0) {
            result += (result.empty() ? "" : " ") + tens[tensPart];
        }

        if (onesPart > 0) {
            result += (result.empty() ? "" : " ") + ones[onesPart];
        }
    }

    return result;
}

int main() {
    int n;
    std::cout << "Enter a number (n ≤ 1000): ";
    std::cin >> n;

    if (n >= 1 && n <= 1000) {
        std::cout << n << " in words: " << nTW(n) << std::endl;
    }
    else {
        std::cout << "The number must be between 1 and 1000.\n";
    }

    return 0;
}
