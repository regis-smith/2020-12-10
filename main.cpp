#include "min_bucket.h"
#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <string>

int main()
{
  // load the dictionary
  std::ifstream infile("words.txt");
  if (!infile.is_open()) {
    std::cout << "Can not open dictionary.\n";
    throw std::exception();
  }
  std::string word;
  std::vector<std::string> words; // the list of words
  while (infile >> word) words.push_back(word);
  infile.close();
  
  // Insert some random words into a min_bucket
  std::mt19937 e; // Mersenne Twister engine
  std::uniform_int_distribution<int> u(0,words.size());

  // A min_bucket of size 5
  min_bucket<std::string> bukit(5);
  
  // insert 50 random words
  for (int i=0; i<50; i++) {
    std::string x = words[u(e)];
    bukit.insert(x);
    std::cout << x << " was inserted.\n";
  }

  std::cout << "The members of the min_bucket are:\n";
  std::cout << bukit[0] << "\t" << bukit[1] << "\t"
            << bukit[2] << "\t" << bukit[3] << "\t"
            << bukit[4] << "\n";
  
  
}
