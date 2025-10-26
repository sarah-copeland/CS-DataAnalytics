#include "PurchaseTracker.h"
#include <fstream>
#include <iostream>

bool PurchaseTracker::Initialize(const std::string& inputPath, const std::string& backupPath) {
    bool loaded = LoadDataFromFile(inputPath);
    if (!loaded) {
        std::cerr << "Error: could not open input file: " << inputPath << std::endl;
        return false;
    }
    if (!WriteFrequencyDat(backupPath)) {
        std::cerr << "Error: could not write backup file: " << backupPath << std::endl;
        return false;
    }
    return true;
}

int PurchaseTracker::GetFrequency(const std::string& item) const {
    auto it = freq_.find(item);
    if (it == freq_.end()) return 0;
    return it->second;
}

void PurchaseTracker::PrintAllFrequencies() const {
    for (const auto& kv : freq_) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }
}

void PurchaseTracker::PrintHistogram() const {
    for (const auto& kv : freq_) {
        std::cout << kv.first << " ";
        for (int i = 0; i < kv.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

bool PurchaseTracker::LoadDataFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in.is_open()) {
        return false;
    }
    std::string item;
    while (std::getline(in, item)) {
        // Handle potential CR from Windows line endings
        if (!item.empty() && item.back() == '\r') item.pop_back();
        if (item.empty()) continue;
        ++freq_[item];
    }
    return true;
}

bool PurchaseTracker::WriteFrequencyDat(const std::string& path) const {
    std::ofstream out(path);
    if (!out.is_open()) {
        return false;
    }
    for (const auto& kv : freq_) {
        out << kv.first << " " << kv.second << std::endl;
    }
    return true;
}
