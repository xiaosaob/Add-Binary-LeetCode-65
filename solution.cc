// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".

class Solution {
public:
    string addBinary(string a, string b) {
        int aIdx = a.size()-1;
        int bIdx = b.size()-1;
        string res("");
        char c = '0';
        while(aIdx >= 0 && bIdx >= 0) {
            res += addBit(a[aIdx], b[bIdx], c);
            --aIdx;
            --bIdx;
        }
        while(aIdx >= 0) {
            res += addBit(a[aIdx], '0', c);
            --aIdx;
        }
        while(bIdx >= 0) {
            res += addBit('0', b[bIdx], c);
            --bIdx;
        }
        if(c == '1') res += c;
        reverse(res.begin(), res.end());
        return res;
    }
    
    char addBit(char a, char b, char & c) {
        int ai = a-'0';
        int bi = b-'0';
        int ci = c-'0';
        int sum = ai+bi+ci;
        c = '0'+(sum/2);
        return ('0'+sum%2);
    }
};
