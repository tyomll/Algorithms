#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string> &strs)
{
    unordered_map<string, vector<string>> anagramMap;

    for (const string &word : strs)
    {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        anagramMap[sortedWord].push_back(word);
    }

    vector<vector<string>> result;
    for (const auto &pair : anagramMap)
    {
        result.push_back(pair.second);
    }

    return result;
}

int main()
{
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> groupedAnagrams = groupAnagrams(words);

    cout << "[" << endl;
    for (const auto &anagrams : groupedAnagrams)
    {
        cout << "  [";
        for (int i = 0; i < anagrams.size(); ++i)
        {
            cout << "\"" << anagrams[i] << "\"";
            if (i < anagrams.size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;

    return 0;
}
