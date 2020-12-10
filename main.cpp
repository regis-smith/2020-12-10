#include "min_bucket.h"
#include <iostream>
#include <random>

int main()
{
  std::mt19937 e; // Mersenne Twister engine
  std::uniform_int_distribution<int> u(1,100);

  // A min_bucket of size 5
  min_bucket<int> bukit(5);
  
  // insert 50 random ints
  for (int i=0; i<50; i++) {
    int x = u(e);
    bukit.insert(x);
    std::cout << x << " was inserted.\n";
  }

  // The bucket should have 1, 4, 10, 11, and 12
  std::cout << "The members of the min_bucket are:\n";
  std::cout << bukit[0] << "\t" << bukit[1] << "\t"
            << bukit[2] << "\t" << bukit[3] << "\t"
            << bukit[4] << "\n";
  
  
}
