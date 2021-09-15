#include <iostream>

#include <core/model.h>
#include <core/model_loader.h>
#include <core/image_classifier.h>

// TODO: You may want to change main's signature to take in argc and argv
int main() {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.
  std::vector<naivebayes::Image> images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\image-files\\trainingimagesandlabels.txt");
  //naivebayes::Model model = naivebayes::Model::Train(images);
  naivebayes::Model model = naivebayes::ModelLoader::WriteToModel("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\model-files\\model_file.txt");
  std::vector<naivebayes::Image> test_images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\image-files\\testimagesandlabels.txt");
  int class_guess = naivebayes::ImageClassifier::EvaluateImage(model, test_images[4]);
  //naivebayes::ModelLoader::WriteToFile(model, "C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\model_file.txt");
  return 0;
}
