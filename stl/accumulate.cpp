#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> v{1,2,3,4,5,6,7,8};

    int init = 0;
    for(int i=0; i< v.size(); i++) {
        init += v[i];
    }
    std::cout << "Sum: " << init << std::endl;

    int result = 0;
    int current = 0;

    for(int i=0; i< v.size(); i += 2) {
        current = v[i] + v[i+1];
        result += current;
    }

    std::cout << "Result: " << result << std::endl;

    std::cout << "Accumulate: " << std::accumulate(v.begin(), v.end(), 0) << std::endl;
    std::cout << "Accumulate: " << std::accumulate(v.begin(), v.end(), 1, std::multiplies<>()) << std::endl;



    return 0;
}