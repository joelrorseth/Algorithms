//
//  Implement Magic Dictionary
//  https://leetcode.com/problems/implement-magic-dictionary/
//
//  Given a list of dictionary words, determine which words from an
//  input set of words is contained in the dictionary when a single
//  character is modified. Eg. If "hello" is in dict, "hellr" yeilds
//  true. Furthermore, "hello" is an exact match, thus returns false.
//
//  Joel Rorseth
//  January 31, 2018
//

#include <iostream>
#include <vector>
#include <unordered_set>


class MagicDictionary {

    private:
        std::unordered_set<std::string> dict;

    public:
        /** Initialize your data structure here. */
        MagicDictionary() {
        }

        /** Build a dictionary through a list of words */
        void buildDict(std::vector<std::string> words) {
            for (const auto & word: words)
                dict.insert(word);
        }

        /** Returns if there is any word in the trie that equals 
         * to the given word after modifying exactly one character */
        bool search(std::string word) {

            for (int l = 0; l < word.size(); ++l) {
                const auto current_letter = word[l];

                // Swap every letter into this position, check for match
                for (int i = 0; i < 26; ++i) {
                    word[l] = 'a' + i;

                    // Must skip original letter, exact matches return false
                    if (word[l] == current_letter) continue;

                    if (dict.find(word) != dict.end())
                        return true;
                }

                word[l] = current_letter;
            }

            return false;
        }
};



// Demonstration
int main(void) {

    std::vector<std::string> list{ "hello", "apple", "search"};

    MagicDictionary dictionary;
    dictionary.buildDict(list);

    std::cout << "Dictionary: hello, apple, search\n";
    std::cout << "hello: " << dictionary.search("hello") << '\n';
    std::cout << "hellr: " << dictionary.search("hellr") << '\n';
    std::cout << "helrr: " << dictionary.search("helrr") << '\n';
    std::cout << std::endl;
}
