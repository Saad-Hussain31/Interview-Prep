#include <iostream>
#include <vector>
#include <algorithm>

struct Monster {
    int power;
    int strength;
};


bool monsterCmp(const Monster& a, const Monster& b) {
    int valA = a.power * a.strength;
    int valB = b.power * b.strength;
    return valA < valB;
}

std::ostream& operator<<(std::ostream& os, const Monster& m) {
    return os << "Monster: " << m.power << "," << m.strength;
}

int main() {
    std::vector<Monster> v{{7,2}, {5,7}, {10,11}};
    auto min = std::min_element(v.begin(), v.end(), monsterCmp);
    auto max = std::max_element(v.begin(), v.end(), monsterCmp);

    std::cout << "Minimum element: " << *min << std::endl;
    std::cout << "Maximum element: " << *max << std::endl;
}