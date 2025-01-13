#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

// Linear Search
pair<bool, int> linearSearch(const vector<int>& records, int key) {
    int comparisons = 0;
    for (size_t i = 0; i < records.size(); ++i) {
        comparisons++;
        if (records[i] == key)
            return {true, comparisons};
    }
    return {false, comparisons};
}

// Weighted Search
pair<bool, int> weightedSearch(vector<int> records, vector<double> probabilities, int key) {
    int comparisons = 0;
    vector<pair<double, int>> weightedRecords;
    for (size_t i = 0; i < records.size(); ++i) {
        weightedRecords.push_back({probabilities[i], records[i]});
    }
    sort(weightedRecords.rbegin(), weightedRecords.rend());
    for (const auto& record : weightedRecords) {
        comparisons++;
        if (record.second == key)
            return {true, comparisons};
    }
    return {false, comparisons};
}

// Binary Search
pair<bool, int> binarySearch(const vector<int>& records, int key) {
    int comparisons = 0;
    int low = 0, high = records.size() - 1;
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;
        if (records[mid] == key)
            return {true, comparisons};
        else if (records[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return {false, comparisons};
}

// Generate Random Integers
vector<int> generateRandomIntegers(int n) {
    vector<int> records(n);
    for (int i = 0; i < n; ++i)
        records[i] = rand() % 1000000 + 1;
    return records;
}

// Generate Random Probabilities
vector<double> generateRandomProbabilities(int n) {
    vector<double> probabilities(n);
    double total = 0.0;
    for (int i = 0; i < n; ++i) {
        probabilities[i] = static_cast<double>(rand()) / RAND_MAX;
        total += probabilities[i];
    }
    for (int i = 0; i < n; ++i)
        probabilities[i] /= total;
    return probabilities;
}

// Main Function
int main() {
    srand(time(0)); // Seed for random number generation
    vector<int> ns = {10, 100, 1000, 10000, 100000};
    vector<double> linearTimesPresent, linearTimesAbsent;
    vector<double> weightedTimesPresent, weightedTimesAbsent;
    vector<double> binaryTimesPresent, binaryTimesAbsent;

    for (int n : ns) {
        vector<int> records = generateRandomIntegers(n);
        vector<double> probabilities = generateRandomProbabilities(n);
        vector<int> sortedRecords = records;
        sort(sortedRecords.begin(), sortedRecords.end());
        int keyPresent = records[rand() % n];
        int keyAbsent = 1000001;

        // Linear Search
        auto start = chrono::high_resolution_clock::now();
        linearSearch(records, keyPresent);
        auto end = chrono::high_resolution_clock::now();
        linearTimesPresent.push_back(chrono::duration<double>(end - start).count());

        start = chrono::high_resolution_clock::now();
        linearSearch(records, keyAbsent);
        end = chrono::high_resolution_clock::now();
        linearTimesAbsent.push_back(chrono::duration<double>(end - start).count());

        // Weighted Search
        start = chrono::high_resolution_clock::now();
        weightedSearch(records, probabilities, keyPresent);
        end = chrono::high_resolution_clock::now();
        weightedTimesPresent.push_back(chrono::duration<double>(end - start).count());

        start = chrono::high_resolution_clock::now();
        weightedSearch(records, probabilities, keyAbsent);
        end = chrono::high_resolution_clock::now();
        weightedTimesAbsent.push_back(chrono::duration<double>(end - start).count());

        // Binary Search
        start = chrono::high_resolution_clock::now();
        binarySearch(sortedRecords, keyPresent);
        end = chrono::high_resolution_clock::now();
        binaryTimesPresent.push_back(chrono::duration<double>(end - start).count());

        start = chrono::high_resolution_clock::now();
        binarySearch(sortedRecords, keyAbsent);
        end = chrono::high_resolution_clock::now();
        binaryTimesAbsent.push_back(chrono::duration<double>(end - start).count());
    }

    // Display Results
    cout << "n\tLinear (Present)\tLinear (Absent)\tWeighted (Present)\tWeighted (Absent)\tBinary (Present)\tBinary (Absent)\n";
    for (size_t i = 0; i < ns.size(); ++i) {
        cout << ns[i] << "\t" 
             << linearTimesPresent[i] << "\t\t" 
             << linearTimesAbsent[i] << "\t\t" 
             << weightedTimesPresent[i] << "\t\t" 
             << weightedTimesAbsent[i] << "\t\t" 
             << binaryTimesPresent[i] << "\t\t" 
             << binaryTimesAbsent[i] << "\n";
    }

    return 0;
}
