#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> topKFrequent1(vector<int> &nums, int k) {
  unordered_map<int, int> m;
  for (int num : nums) {
    m[num]++;
  }

  /*
  This loop iterates over each key-value pair in the m map. It then adds the key
  (which is the number) to the bucket corresponding to its frequency. For
  example, if the frequency of the number 5 is 3, it will be added to
  buckets[3].*/
  vector<vector<int>> buckets(nums.size() + 1);
  for (const auto &entry : m) {
    buckets[entry.second].push_back(
        entry.first); // buckets k 3rd idx per 5 ajaega
  }

  vector<int> result;
  for (int i = nums.size(); i >= 0; i--) {
    if (result.size() >= k) {
      break;
    }
    if (!buckets[i].empty()) {
      result.insert(result.end(), buckets[i].begin(), buckets[i].end());
    }
  }

  return result;
}


vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> umap;

    for(auto e : nums) {
        umap[e]++;
    }

    vector<vector<int>> v;
    for(auto kv : umap) {
        v[kv.second].push_back(kv.first);
    }

    vector<int> result;
    
}

int main() {

  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  vector<int> expected = {1, 2};
  vector<int> result = topKFrequent(nums, k);
  assert(result == expected);

  // Additional test cases
  nums = {4, 1, -1, 2, -1, 2, 3};
  k = 3;
  expected = {-1, 2, 3};
  result = topKFrequent(nums, k);
  // assert(result == expected);

  nums = {5, 5, 5, 5, 5, 5, 5};
  k = 1;
  expected = {5};
  result = topKFrequent(nums, k);
  assert(result == expected);

  cout << "All tests passed!" << endl;
  return 0;
}
