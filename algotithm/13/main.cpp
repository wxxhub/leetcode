#include <iostream>
#include <map>

using namespace std;
//
//class Solution {
//public:
//    Solution() {
//        Unit1["I"]    = 1;
//        Unit1["II"]   = 2;
//        Unit1["III"]  = 3;
//        Unit1["IV"]   = 4;
//        Unit1["V"]    = 5;
//        Unit1["VI"]   = 6;
//        Unit1["VII"]  = 7;
//        Unit1["VIII"] = 8;
//        Unit1["IX"]   = 9;
//
//        Unit2["X"]    = 10;
//        Unit2["XX"]   = 20;
//        Unit2["XXX"]  = 30;
//        Unit2["XL"]   = 40;
//        Unit2["L"]    = 50;
//        Unit2["LX"]   = 60;
//        Unit2["LXX"]  = 70;
//        Unit2["LXXX"] = 80;
//        Unit2["XC"]   = 90;
//
//        Unit3["C"]    = 100;
//        Unit3["CC"]   = 200;
//        Unit3["CCC"]  = 300;
//        Unit3["CD"]   = 400;
//        Unit3["D"]    = 500;
//        Unit3["DC"]   = 600;
//        Unit3["DCC"]  = 700;
//        Unit3["DCCC"] = 800;
//        Unit3["CM"]   = 900;
//
//        Unit4["M"]    = 1000;
//        Unit4["MM"]   = 2000;
//        Unit4["MMM"]  = 3000;
//    }
//    int romanToInt(string s) {
//        int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//
//        int index = 0;
//        string temp = "";
//        while (index < s.size()) {
//            temp += s[index];
//            if (Unit4.find(temp) != Unit4.end()) {
//                b4 = Unit4[temp];
//                ++index;
//            } else {
//                break;
//            }
//        }
//
//        temp = "";
//        while (index < s.size()) {
//            temp += s[index];
//            if (Unit3.find(temp) != Unit3.end()) {
//                b3 = Unit3[temp];
//                ++index;
//            } else {
//                break;
//            }
//        }
//
//        temp = "";
//        while (index < s.size()) {
//            temp += s[index];
//            if (Unit2.find(temp) != Unit2.end()) {
//                b2 = Unit2[temp];
//                ++index;
//            } else {
//                break;
//            }
//        }
//
//        temp = "";
//        while (index < s.size()) {
//            temp += s[index];
//            if (Unit1.find(temp) != Unit1.end()) {
//                b1 = Unit1[temp];
//                ++index;
//            } else {
//                break;
//            }
//        }
//
//        return b1 + b2 + b3 + b4;
//    }
//
//private:
//    map<string, int> Unit1;
//    map<string, int> Unit2;
//    map<string, int> Unit3;
//    map<string, int> Unit4;
//};

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };

        int ans = 0;
        int len = s.size();
        for(int i = 0; i < len-1; i++){
            if(table[s[i]] >= table[s[i+1]]){
                //左边>=右边时，等于加上他的原值
                ans += table[s[i]];
            }else{
                //左边<右边时，相当于加上他的负值
                ans = ans -table[s[i]];
            }
        }
        ans += table[s[len-1]];
        return ans;
    }
};

int main() {
    Solution solution;

    string input;
    cin >> input;

    cout << solution.romanToInt(input) << endl;
    return 0;
}