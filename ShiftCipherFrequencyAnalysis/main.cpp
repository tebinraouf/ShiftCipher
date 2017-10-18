//
//  main.cpp
//  ShiftCipherFrequencyAnalysis
//
//  Created by Tebin on 9/13/17.
//  Copyright © 2017 Tebin. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;


//Helper Functions
string GetAlphabetByNumber(int number) {
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<int, char> dictionary;
    for (int i=0; i<alpha.size(); i++) {
        dictionary[i] = alpha[i];
    }
    return &dictionary[number];
}
int GetAlphabetNumberByLetter(char letter) {
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<char, int> dictionary;
    for (int i=0; i<alpha.size(); i++) {
        dictionary[alpha[i]] = i;
    }
    return dictionary[letter];
}
void DisplayFrequency(map<char,int> frequency) {
    cout << "Frequency Analysis:\n";
    for (map<char,int>::iterator it=frequency.begin(); it != frequency.end(); it++) {
        cout << it->first << ": " << it->second << '\n';
    }
    cout << '\n';
}
map<char,int> GetFrequencyAnalysis(string cipherText){
    map<char,int> frequency;
    
    for (int i=0; i<cipherText.size(); i++) {
        
        char c = cipherText[i];
        
        if (frequency.count(c) == 0) {
            frequency[c] = 1;
        } else {
            int currentValue = frequency[c];
            frequency[c] = currentValue + 1;
        }
    }
    return frequency;
}
string Decrypt(string cipherText, int key) {
    string result = "";
    for (int i = 0; i < cipherText.size(); i++) {
        char c = cipherText[i];
        int charNumber = GetAlphabetNumberByLetter(c);
        int plainTextNumber = (charNumber + (26 - key)) % 26;
        result += GetAlphabetByNumber(plainTextNumber);
    }
    return result;
}
string Encrypt(string plainText, int key) {
    string result = "";
    
    for (int i = 0; i<plainText.size(); i++) {
        char p = plainText[i];
        int pNumber = GetAlphabetNumberByLetter(p);
        int cipherNumber = (pNumber + key) % 26;
        result += GetAlphabetByNumber(cipherNumber);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    
    string cipher = "KWSVVSYXKSBOKRKBNRKDKXNKNBEXUKBOKDKLKBGROXDROIQODDROSBLOOBCDROIXYDSMOKPVISXOKMRWEQDROWSVVSYXKSBOZYVSDOVIKCUCDROLKBDOXNOBPYBKXYDROBLOOBDROXZBYMOONCDYCSZSDDRORKBNRKDCZSVVCYEDTECDOXYEQRDYQODBSNYPDROPVIKXNAEKPPCDROBOCDSDCXYGDRONBEXUCDEBXROCDSMUCRSCRKXNSXDYDROLOOBQBKLCDROPVILIDROGSXQCKXNCRYEDCCZSDSDYEDCZSDSDYEDBOKNOBCNSQOCDPOLBEKBIDGYDRYECKXNDOX";

    map<char,int> frequency = GetFrequencyAnalysis(cipher);

    DisplayFrequency(frequency);

    //The key is found by trial and error.
    int key = 10;
    string plainText = Decrypt(cipher, key);
    string cipherText = Encrypt(plainText, key);

    
    //Plain Text
    cout << "Plain Text: \n" + plainText + "\n\n";
    
    
    //Cipher Text
    cout << "Cipher Text: \n" + cipherText + "\n\n";;
    
    /*
     
     Result
     
     Frequency Analysis:
     A: 1
     B: 25
     C: 24
     D: 43
     E: 13
     G: 4
     I: 8
     K: 27
     L: 8
     M: 4
     N: 14
     O: 41
     P: 8
     Q: 7
     R: 26
     S: 24
     T: 1
     U: 4
     V: 11
     W: 3
     X: 21
     Y: 19
     Z: 6
     
     Plain Text:
     AMILLIONAIREAHARDHATANDADRUNKAREATABARWHENTHEYGETTHEIRBEERSTHEYNOTICEAFLYINEACHMUGTHEMILLIONAIREPOLITELYASKSTHEBARTENDERFORANOTHERBEERTHENPROCEEDSTOSIPITTHEHARDHATSPILLSOUTJUSTENOUGHTOGETRIDOFTHEFLYANDQUAFFSTHERESTITSNOWTHEDRUNKSTURNHESTICKSHISHANDINTOTHEBEERGRABSTHEFLYBYTHEWINGSANDSHOUTSSPITITOUTSPITITOUTREADERSDIGESTFEBRUARYTWOTHOUSANDTEN
     
     Cipher Text:
     KWSVVSYXKSBOKRKBNRKDKXEXUCDEBXROCDSMUNKNBEXUKBOKDKLKBGROXDROIQODDROSBLOOBCDROIXYDSMOKPVISXOKMRWEQDROWSVVSYXKSBOZYVSDOVIKCUCDROLKBDOXNOBPYBKXYDROBLOOBDROXZBYMOONCDYCSZSDDRORKBNRKDCZSVVCYEDTECDOXYEQRDYQODBSNYPDROPVIKXNAEKPPCDROBOCDSDCXYGDRONBEXUCDEBXROCDSMUCRSCRKXNSXDYDROLOOBQBKLCDROPVILIDROGSXQCKXNCRYEDCCZSDSDYEDCZSDSDYEDBOKNOBCNSQOCDPOLBEKBIDGYDRYECKXNDOX
     
     
     
     */
    
    
    return 0;
}

