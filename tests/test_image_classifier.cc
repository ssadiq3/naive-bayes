#include <catch2/catch.hpp>
#include <core/image.h>
#include <core/image_classifier.h>
#include <core/model_loader.h>

TEST_CASE("Test classifying accuracy") {
    std::vector<naivebayes::Image> test_images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\image-files\\testimagesandlabels.txt");
    naivebayes::Model model = naivebayes::ModelLoader::WriteToModel("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\model-files\\model_file.txt");
    int correct_count = 0;
    for (size_t i = 0; i < 50; ++i) {
        int class_guess = naivebayes::ImageClassifier::EvaluateImage(model, test_images[i]);
        if (class_guess == test_images[i].GetClass()) {
            correct_count++;
        }
    }
    float percentage = (float) correct_count/50;
    REQUIRE(percentage > 0.7);
}

