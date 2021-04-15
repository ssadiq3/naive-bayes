#include <iostream>

#include <core/model.h>
#include <core/file.h>
#include <core/model_loader.h>

// TODO: You may want to change main's signature to take in argc and argv
int main() {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.
  std::vector<naivebayes::Image> images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\image-files\\trainingimagesandlabels.txt");
  naivebayes::Model model = naivebayes::Model::Train(images);

  /*naivebayes::File file = naivebayes::File("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\trainingimagesandlabels.txt");
  naivebayes::Model model = naivebayes::Model(file);
  model.CalculatePriors();
  model.CalculateFeatures();*/
  naivebayes::ModelLoader model_processor = naivebayes::ModelLoader("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\model_file.txt");
  model_processor.WriteToFile(model);
  naivebayes::Model loaded_model = model_processor.WriteToModel();
  return 0;
}
