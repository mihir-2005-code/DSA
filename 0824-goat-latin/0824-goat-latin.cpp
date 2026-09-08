class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word;
        string result = "";
        int index = 1;
        
        while (ss >> word) {
            string newWord;
            
            char firstChar = tolower(word[0]);
            if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') {
                newWord = word + "ma";
            } else {
                newWord = word.substr(1) + word[0] + "ma";
            }
            
            for (int i = 0; i < index; i++) {
                newWord += "a";
            }
            
            if (!result.empty()) result += " ";
            result += newWord;
            
            index++;
        }
        
        return result;
    }
};