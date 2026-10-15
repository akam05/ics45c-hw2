#ifndef WORD_COUNT_HPP
#define WORD_COUNT_HPP

#include <iosfwd>
#include <map>
#include <set>
#include <string>

using namespace std;

// lowercases str in place
void to_lowercase(string& str);

// reads the stop words from the stream, lowercased
set<string> load_stopwords(istream& stopwords);

// counts the words of the document, lowercased, skipping the stop words
map<string, int> count_words(istream& document, const set<string>& stopwords);

// writes "<word> <count>" per line, in ascending order by word
void output_word_counts(const map<string, int>& word_counts, ostream& output);

#endif  // End of the include guard.
