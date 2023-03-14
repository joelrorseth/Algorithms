//
// Expression Add Operators
//
// Given a digit in the form of a string, containing only digits 0-9, and a
// target value, determine all possibilities to add + - or * in between the
// digits, so that the formed expression will evaluate to the target.
//
// Joel Rorseth
//

#include <iostream>
#include <vector>

using namespace std;


void _find(string num, int target, int pos, long cur_total, string cur_str, 
        long prev, vector<string> & combos) {

    // When all digits have been combined in some way, check for match
    if (pos >= num.size() && cur_total == target) {
        combos.push_back(cur_str);
        return;
    }

    for (int i=pos, count=1; i < num.size(); ++i, ++count) {

        // Avoid 001, 0002 etc.
        if (i != pos && num[pos] == '0')
            break;

        // Extract increasing length digits from substr eg. 1, 10, 101, 1012 etc...
        auto val = stol(num.substr(pos,count));
        string valstr = to_string(val);

        // If first num in combo, start off with number only, else attempt each operation & recurse
        if (pos == 0) {
            _find(num, target, i+1, val, cur_str+valstr, val, combos);
        } else {
            _find(num, target, i+1, cur_total+val, cur_str+'+'+valstr, val, combos);
            _find(num, target, i+1, cur_total-val, cur_str+'-'+valstr, -1*val, combos);
            _find(num, target, i+1, cur_total-prev+prev*val, cur_str+'*'+valstr, prev*val, combos);
        }
    }
}

// Entry point for recursive solution
vector<string> addOperators(string num, int target) {
    vector<string> combos;

    if (num.size() == 0)
        return combos;

    _find(num, target, 0, 0, "", 0, combos);
    return combos;
}





// Driver
int main() {

    cout << "Given num = 105, target = 5, valid expressions:\n";
    for (auto & combo: addOperators("105", 5))
        cout << combo << endl;
}
