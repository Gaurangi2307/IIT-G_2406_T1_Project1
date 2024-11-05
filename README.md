Textbook Similarity Detection

This project identifies the 10 most similar pairs of textbooks from a dataset of 64 text files using a simple word frequency analysis. The similarity between textbooks is calculated based on the normalized frequency of the 100 most frequently occurring words, excluding some certain common stop words like 'a','an','and','in','the','of'.

Project Overview
The program reads a set of 64 textbook files in .txt format and performs the following:
1.	Counts frequency of words in each file.
2.	Identifies the top 100 most frequent words after filtering out common stop words.
3.	Normalizes these frequency of words by dividing by the total word count.
4.	Calculates a similarity score between each pair of textbooks using these normalized frequencies.
5.	Outputs the top 10 most similar textbook pairs based on the similarity scores.
   
Features
•	Text Normalization: Converts text to uppercase and removes punctuation for consistency.
•	Stop Word Removal: Excludes common words ("a", "and", "an", "of", "in", "the") from frequency analysis.
•	Top Words Selection: Uses only the top 100 most frequent words in each file.
•	Similarity Matrix: Calculates similarity scores for each pair of textbooks and stores them in a 64x64 matrix.
•	Top Similar Pairs: Outputs the 10 most similar pairs of textbooks.

Dataset
The dataset should consist of 64 .txt files, each representing a textbook. File names should follow the format:
You can download a sample dataset here.

Requirements
•	C++ compiler (e.g., g++)
•	C++11 or newer for unordered_map and to_string functions

File Structure
•	textbook_similarity.cpp: Main program file containing the code for word frequency analysis, similarity calculation, and output.
•	data/: Folder containing the 64 textbook .txt files.

Code Explanation
1.	Data Cleaning: Each word is converted to uppercase and punctuations are removed.
2.	Word Frequency Count: The word_count function reads each file and calculates the frequency of each word.
3.	Top Word Selection: The get_top_words function selects the top 100 most frequent words, normalizing their frequencies by dividing by the total word count.
4.	Similarity Calculation: The calculate_similarity function calculates the similarity index between two files based on the product of their normalized word frequencies.
5.	Similarity Matrix: A 64x64 matrix stores the similarity scores between all pairs of textbooks.
6.	Top Similar Pairs: The top 10 pairs with the highest similarity scores (excluding self-similarity) are output.
   
License
This project is open source and free to use for educational and non-commercial purposes.

Acknowledgments
Special thanks to:
•	The professors for their guidance
•	The open-source community for inspiration

Created by an enthusiastic programmer
Submittion from - ##IITGCS-240611116(Gaurangi Singh Sengar)
