#include <iostream>

#include <core/rename_this_file.h>
#include <core/file.h>

// TODO: You may want to change main's signature to take in argc and argv
int main() {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.
  naivebayes::File file = naivebayes::File("..\\trainingimagesandlabels.txt");

  std::cout << "Welcome to " << naivebayes::Placeholder().GetBestClass()
            << std::endl;
  return 0;
}
