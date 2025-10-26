// Author: Sarah Copeland
// Course: CS210 Project Three
// Project: Corner Grocer item frequency tracker
// Notes: Uses a class with public and private sections, map for counts, and creates frequency.dat

#ifndef PURCHASE_TRACKER_H
#define PURCHASE_TRACKER_H

#include <string>
#include <map>

class PurchaseTracker {
public:
    bool Initialize(const std::string& inputPath, const std::string& backupPath);
    int GetFrequency(const std::string& item) const;
    void PrintAllFrequencies() const;
    void PrintHistogram() const;

private:
    std::map<std::string, int> freq_;
    bool LoadDataFromFile(const std::string& path);
    bool WriteFrequencyDat(const std::string& path) const;
};

#endif // PURCHASE_TRACKER_H
