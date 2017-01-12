#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
                   flip_pair<A,B>);
    return dst;
}

int main() {

    // open file
    ifstream input("pg10.txt");

    // create vector
    vector<char> my_vector;

    // loop the each char from the file stream
    char c;
    while(input.get(c)) {

        /* QUESTION 1 COMPLETED */
        // push each char to the created vector
        my_vector.push_back(c);
    }

    // close file
    input.close();

    /* QUESTION 2 COMPLETED */
    cout << "Amount of characters: " << my_vector.size() << "\n";

    /* QUESTION 3 COMPLETED */
    cout << "Amount of lines found: " << count(my_vector.begin(), my_vector.end(), '\n') << "\n";

    /* QUESTION 4 COMPLETED */
    cout << "Amount of alphabetic characters found: " << count_if(my_vector.begin(), my_vector.end(), [](char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }) << "\n";

    /* QUESTION 5 COMPLETED */
    for_each(my_vector.begin(), my_vector.end(), [](char &c){ if(c >= 'A' && c <= 'Z') c-= 32; });


    // create map for counted alphabetic chars
    map<char, int> alphaCounted;
    map<char, int> alphaTemp;
    vector<char>alphaSortKey;
    vector<int> alphaSortValue;

    for(char i = 'a'; i <= 'z'; i++) {
        // set in list
        alphaCounted[i] = count(my_vector.begin(), my_vector.end(), i);

        /*QUESTION COMPLETED 6*/
        std::cout << i <<  ":" << alphaCounted[i] << "\n";
    }

    cout << "";
    alphaTemp = alphaCounted;

    while(alphaTemp.size() > 0) {
        char k = 0;
        int v = 0;
        for(auto const elem : alphaTemp) {
            if(elem.second >= v) {
                k = elem.first;
                v = elem.second;
            }
        }
        alphaTemp.erase(alphaTemp.find(k));
        alphaSortKey.push_back(k);
        alphaSortValue.push_back(v);
    }

    /*7 COMPLETED */
    for(int i = 0; i < 26; i++) {
        cout << alphaSortKey[i] << "-" << alphaSortValue[i] << "\n";
    }

    // open file
    ifstream input2("pg10.txt");

    // create map for words count
    map<string, int> words;

    // create string to store input
    string s;

    // set each input to string and set string as key in map. Also increment value of element
    while(input2) {
        input2 >> s;
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); } ), s.end());

        words[s]++; }

    // create tmp map to remove words from
    map<string, int> tmp_words = words;

    // loop amount of words we want
    for(int i = 0; i < 10; i++) {

        // tmp values to store highest values
        int tmp_highest = 0;
        string tmp_highest_string;

        // loop each word
        for(const auto &tmp_word : tmp_words) {

            // word count value higher then temp?
            if(tmp_word.second > tmp_highest){

                // set tmp value to word values
                tmp_highest_string = tmp_word.first;
                tmp_highest = tmp_word.second;

                // remove word from the tmp word map
                tmp_words.erase(tmp_word.first);
            }
        }

        /* QUESTION 8 COMPLETED */
        // print word 
        cout << "'" << tmp_highest_string << "' counted : " << tmp_highest << " times \n";

    }

    return 0;
}