// Author: Sarah Copeland
// Course: CS210 Project Three
// Project: Corner Grocer item frequency tracker
// Notes: Uses a class with public and private sections, map for counts, and creates frequency.dat

#include <iostream>
#include <limits>
#include <string>
#include "PurchaseTracker.h"

static void ClearStdin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static int ReadMenuChoice() {
    std::cout << "\nCorner Grocer Item Tracker\n";
    std::cout << "1. Look up a specific item frequency\n";
    std::cout << "2. Print all item frequencies\n";
    std::cout << "3. Print histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option (1-4): ";
    int choice;
    if (!(std::cin >> choice)) {
        ClearStdin();
        return -1;
    }
    ClearStdin();
    return choice;
}

int main() {
    const std::string kInputFile = "CS210_Project_Three_Input_File.txt";
    const std::string kBackupFile = "frequency.dat";

    PurchaseTracker tracker;
    if (!tracker.Initialize(kInputFile, kBackupFile)) {
        std::cerr << "Failed to initialize. Make sure the input file is next to the executable." << std::endl;
        return 1;
    }

    while (true) {
        int choice = ReadMenuChoice();
        if (choice == -1) {
            std::cout << "Invalid input. Please enter a number from 1 to 4.\n";
            continue;
        }
        if (choice == 1) {
            std::cout << "Enter item name to look up: ";
            std::string query;
            std::getline(std::cin, query);
            int count = tracker.GetFrequency(query);
            std::cout << query << " " << count << std::endl;
        } else if (choice == 2) {
            tracker.PrintAllFrequencies();
        } else if (choice == 3) {
            tracker.PrintHistogram();
        } else if (choice == 4) {
            std::cout << "Goodbye.\n";
            break;
        } else {
            std::cout << "Please choose a valid option 1-4.\n";
        }
    }

    return 0;
}
