#include <iostream>

#include <core/model.h>
#include <core/file.h>

// TODO: You may want to change main's signature to take in argc and argv
int main() {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.
  naivebayes::File file = naivebayes::File("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\trainingimagesandlabels.txt");

  std::cout << "Welcome to " << naivebayes::Placeholder().GetBestClass()
            << std::endl;
  return 0;
}
