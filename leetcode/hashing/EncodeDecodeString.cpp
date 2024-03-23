#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

string encode(vector<string>& strs) {
    string result{};

    for(int i=0; i<strs.size(); ++i) {
        string str = strs[i];
        result += to_string(str.size()) + "#" + str;
    }
    return result;

}

vector<string> decode(string s) {
    
}

int main() {
    vector<string> input = {"abc", "def", "ghi"};
    
    
    string encoded_str = encode(input);
    assert(encoded_str == "3#abc3#def3#ghi");
    cout << "Encoded string: " << encoded_str << endl;
    
    vector<string> decoded_strs = decode(encoded_str);
    // assert(decoded_strs == input);
    cout << "Decoded strings: ";
    for (const auto& str : decoded_strs) {
        cout << str << " ";
    }
    cout << endl;
    
    cout << "All tests passed!" << endl;
    
    return 0;
}
