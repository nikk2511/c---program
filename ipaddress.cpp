#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool isValidOctet(const std::string& octet) {
    // Check if the octet is empty or has leading zeros (except for "0")
    if (octet.empty() || (octet.size() > 1 && octet[0] == '0')) return false;

    // Check if the octet contains only digits
    for (char ch : octet) {
        if (!isdigit(ch)) return false;
    }

    // Convert the octet to an integer and check if it's in the range [0, 255]
    int value = std::stoi(octet);
    return value >= 0 && value <= 255;
}

bool isValidIPv4(const std::string& ip) {
    std::stringstream ss(ip);
    std::string octet;
    std::vector<std::string> octets;
    
    // Split the string by '.'
    while (std::getline(ss, octet, '.')) {
        octets.push_back(octet);
    }
    
    // Check if we have exactly 4 octets
    if (octets.size() != 4) return false;

    // Validate each octet
    for (const std::string& octet : octets) {
        if (!isValidOctet(octet)) return false;
    }

    return true;
}

int main() {
    std::string ip;
    std::cout << "Enter an IPv4 address: ";
    std::cin >> ip;

    if (isValidIPv4(ip)) {
        std::cout << ip << " is a valid IPv4 address." << std::endl;
    } else {
        std::cout << ip << " is not a valid IPv4 address." << std::endl;
    }

    return 0;
}
