#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(std::string s) {
    // Remove non-alphanumeric characters and convert to lowercase
    std::string cleanString;
    for (char c : s) {
        if (std::isalnum(c)) {
            cleanString += std::tolower(c);
        }
    }
    
    // Check if the cleaned string is a palindrome
    int left = 0;
    int right = cleanString.length() - 1;
    while (left < right) {
        if (cleanString[left] != cleanString[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;
    
    if (isPalindrome(input)) {
        std::cout << "It's a palindrome!" << std::endl;
    } else {
        std::cout << "It's not a palindrome." << std::endl;
    }
    
    return 0;
}
