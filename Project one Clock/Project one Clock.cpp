#include <iostream>
#include <iomanip>
#include <string>

// Function prototypes
std::string formatTwoDigits(int number);
void printMenu();
int processMenuChoice(int minValue, int maxValue);
void displayTime(int hour, int minute, bool is24HourFormat);
void addTime(int& hour, int& minute, int& second, int hoursToAdd, int minutesToAdd, int secondsToAdd);

// Function to format numbers as two digits
std::string formatTwoDigits(int number) {
    if (number < 10) {
        return "0" + std::to_string(number);
    }
    return std::to_string(number);
}

// Function to print out the menu
void printMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Display 24-hour time" << std::endl;
    std::cout << "2. Display 12-hour time" << std::endl;
    std::cout << "3. Add time" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

// Function to process user input from the menu
int processMenuChoice(int minValue, int maxValue) {
    int choice;
    do {
        std::cout << "Enter your choice (" << minValue << "-" << maxValue << "): ";
        std::cin >> choice;
    } while (choice < minValue || choice > maxValue);

    return choice;
}

// Function to display time in 12-hour or 24-hour format
void displayTime(int hour, int minute, bool is24HourFormat) {
    if (is24HourFormat) {
        std::cout << "24-Hour Format: " << formatTwoDigits(hour) << ":" << formatTwoDigits(minute) << std::endl;
    }
    else {
        std::string period = (hour >= 12) ? "PM" : "AM";
        if (hour > 12) {
            hour -= 12;
        }
        if (hour == 0) {
            hour = 12;
        }
        std::cout << "12-Hour Format: " << formatTwoDigits(hour) << ":" << formatTwoDigits(minute) << " " << period << std::endl;
    }
}

// Function to add time to the clock
void addTime(int& hour, int& minute, int& second, int hoursToAdd, int minutesToAdd, int secondsToAdd) {
    second += secondsToAdd;
    minute += minutesToAdd;
    hour += hoursToAdd;

    if (second >= 60) {
        minute += second / 60;
        second %= 60;
    }
    if (minute >= 60) {
        hour += minute / 60;
        minute %= 60;
    }
    hour %= 24;
}

int main() {
    int hour = 12;
    int minute = 0;
    int second = 0;

    int choice;
    bool is24HourFormat = true;

    do {
        printMenu();
        choice = processMenuChoice(1, 4);

        switch (choice) {
        case 1:
            is24HourFormat = true;
            displayTime(hour, minute, is24HourFormat);
            break;
        case 2:
            is24HourFormat = false;
            displayTime(hour, minute, is24HourFormat);
            break;
        case 3:
            int hoursToAdd, minutesToAdd, secondsToAdd;
            std::cout << "Enter hours to add: ";
            std::cin >> hoursToAdd;
            std::cout << "Enter minutes to add: ";
            std::cin >> minutesToAdd;
            std::cout << "Enter seconds to add: ";
            std::cin >> secondsToAdd;
            addTime(hour, minute, second, hoursToAdd, minutesToAdd, secondsToAdd);
            break;
        case 4:
            std::cout << "Exiting program." << std::endl;
            break;
        }
    } while (choice != 4);

    return 0;
}