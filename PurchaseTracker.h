#ifndef PURCHASE_TRACKER_H
#define PURCHASE_TRACKER_H

#include <string>
#include <map>

// PurchaseTracker encapsulates reading an input file of items (one per line),
// counting frequencies, and writing a backup file frequency.dat.
// Public interface is minimal and focused on required assignment features.
class PurchaseTracker {
public:
    // Initialize loads from inputPath and writes backupPath (frequency.dat).
    // Returns true on success, false on failure.
    bool Initialize(const std::string& inputPath, const std::string& backupPath);

    // Returns the frequency for a specific item. If not present, returns 0.
    int GetFrequency(const std::string& item) const;

    // Prints each item and count as "Item count" (sorted by item).
    void PrintAllFrequencies() const;

    // Prints a histogram: "Item *****" with asterisks equal to the count.
    void PrintHistogram() const;

private:
    std::map<std::string, int> freq_; // private: internal storage, sorted keys

    // Internal helpers
    bool LoadDataFromFile(const std::string& path);
    bool WriteFrequencyDat(const std::string& path) const;
};

#endif // PURCHASE_TRACKER_H
