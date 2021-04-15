#include <catch2/catch.hpp>
#include <core/image.h>

TEST_CASE("Test classifying accuracy") {
    std::vector<naivebayes::Image> test_images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\image-files\\testimagesandlabels.txt");

}

