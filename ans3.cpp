#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void countFrequency(const vector<int>& nums) {
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    for (auto& pair : freq) {
        cout << pair.first << " → " << pair.second 
             << (pair.second > 1 ? " times" : " time") << endl;
    }
}

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2}; // example input

    cout << "Frequencies of elements:\n";
    countFrequency(nums);

    return 0;
}
