#include <catch2/catch.hpp>

#include <core/model.h>

TEST_CASE("Test model data") {
    naivebayes::Model model = naivebayes::Model("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\trainingimagesandlabels.txt");
    SECTION("Test dimension from file") {
        REQUIRE(model.GetDimension() == 28);
    }
    SECTION("Test prior") {
        REQUIRE(Approx(model.GetPriors()[0]).epsilon(0.1) == 1);
    }
    SECTION("Test pixel in first image") {
        REQUIRE(Approx(model.GetFeatures()[0][0][0][0]).epsilon(0.1) == 1);
    }
}
