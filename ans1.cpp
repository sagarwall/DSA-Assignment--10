#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;  // duplicate found
        }
        seen.insert(num);
    }

    return false;  // no duplicates
}

int main() {
    vector<int> nums = {1, 2, 3, 1};  // example input

    if (containsDuplicate(nums))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
