#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Define commonly occurring words to exclude
const unordered_set<string> ignore_words = {"A", "AND", "AN", "OF", "IN", "THE"};
const int words = 100;
const int N = 64;

// Function to convert a string to uppercase
string change_case(const string& str) {
    string result = str;
    for (char& ch : result) {
        ch = toupper(ch);
    }
    return result;
}

// Function to parse words from a file and count word frequency
unordered_map<string, int> word_frequency(const string& filename) {
    ifstream file(filename);
    unordered_map<string, int> word_count;
    string word;
    int total_words = 0;

    while (file >> word) {
        // Convert to uppercase and keep only alphanumeric characters
        word = change_case(word);
        word.erase(remove_if(word.begin(), word.end(), [](char ch) {
            return !isalnum(ch);
        }), word.end());

        // Skip if it's a ignore word or empty
        if (word.empty() || ignore_words.find(word) != ignore_words.end()) {
            continue;
        }

        word_count[word]++;
        total_words++;
    }

    // Normalize word frequencies
    for (auto& pair : word_count) {
        pair.second = static_cast<double>(pair.second) / total_words;
    }

    return word_count;
}

// Function to get top N frequent words from the word frequency map
vector<pair<string, double>> get_top_words(const unordered_map<string, double>& word_count, int top_n) {
    vector<pair<string, double>> words(word_count.begin(), word_count.end());
    sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    if (words.size() > top_n) {
        words.resize(top_n);
    }

    return words;
}

// Function to calculate similarity index between two frequency maps
double calculate_similarity(const unordered_map<string, double>& freq1, const unordered_map<string, double>& freq2) {
    double similarity = 0.0;
    for (const auto& [word, freq] : freq1) {
        if (freq2.find(word) != freq2.end()) {
            similarity += freq * freq2.at(word);
        }
    }
    return similarity;
}

// Main function
int main() {
    vector<unordered_map<string, double>> frequencies(N);

    // Load and process each textbook
    for (int i = 0; i < N; i++) {
        string filename = "C:\Users\Admin\Downloads" + to_string(i + 1) + ".txt"; 
        unordered_map<string, int> word_freq = word_frequency(filename);
        frequencies[i] = get_top_words(word_freq, words);
    }

    // Create similarity matrix
    double similarity_matrix[N][N] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            similarity_matrix[i][j] = calculate_similarity(frequencies[i], frequencies[j]);
            similarity_matrix[j][i] = similarity_matrix[i][j];
        }
    }

    // Identify top 10 similar pairs
    vector<pair<double, pair<int, int>>> similarity_pairs;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            similarity_pairs.push_back({similarity_matrix[i][j], {i, j}});
        }
    }

    sort(similarity_pairs.rbegin(), similarity_pairs.rend()); 

    cout << "Top 10 similar pairs of textbooks:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Textbook " << similarity_pairs[i].second.first + 1
             << " and Textbook " << similarity_pairs[i].second.second + 1
             << " with similarity index: " << fixed << setprecision(4) << similarity_pairs[i].first << endl;
    }

    return 0;
}
