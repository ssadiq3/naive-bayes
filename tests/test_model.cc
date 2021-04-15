#include <catch2/catch.hpp>

#include <core/model.h>

TEST_CASE("Test 28 small model data") {
    std::vector<naivebayes::Image> images  = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\small_28_file.txt");
    naivebayes::Model model = naivebayes::Model::Train(images);
    SECTION("Test dimension from file") {
        REQUIRE(model.GetDimension() == 28);
    }
    SECTION("Test prior") {
        REQUIRE(Approx(model.GetPrior(0)).epsilon(0.1) == 0.33);
    }
    SECTION("Test pixel in first image") {
        REQUIRE(Approx(model.GetFeature(0, 0, 0, 0)).epsilon(0.1) == 0.667f);
    }
}

TEST_CASE("Test 7 small model data") {
    std::vector<naivebayes::Image> images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\small_file.txt");
    naivebayes::Model model = naivebayes::Model::Train(images);
    SECTION("Test dimension from file") {
        REQUIRE(model.GetDimension() == 7);
    }
    SECTION("Test prior") {
        REQUIRE(Approx(model.GetPrior(0)).epsilon(0.1) == 0.33);
    }
    SECTION("Test pixel in first image") {
        REQUIRE(Approx(model.GetFeature(0,0,0,0)).epsilon(0.1) == 0.667f);
    }
}
