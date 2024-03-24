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
    vector<string> result;
    int i = 0;

    while(i < s.size()) {
        int j = i;
        while(s[j] != '#') {
            j++;
        }
        int length = stoi(s.substr(i, j-i));
        string str = s.substr(j+1, length);
        result.push_back(str);
        i = j+1+length;
    }
    return result;
}

int main() {
    vector<string> input = {"neet", "co#de"};
    
    
    string encoded_str = encode(input);
    assert(encoded_str == "4#neet5#co#de");
    cout << "Encoded string: " << encoded_str << endl;
    
    vector<string> decoded_strs = decode(encoded_str);
    assert(decoded_strs == input);
    cout << "Decoded strings: ";
    for (const auto& str : decoded_strs) {
        cout << str << " ";
    }
    cout << endl;
    
    cout << "All tests passed!" << endl;
    
    return 0;
}
