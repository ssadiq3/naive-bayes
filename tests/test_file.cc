#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <core/file.h>

TEST_CASE("Test dimension for small file") {
    naivebayes::File file =
    naivebayes::File("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\small_file.txt");
    SECTION("Test correct dimension") {
        REQUIRE(file.GetDimension() == 7);
    }
}

TEST_CASE("Test dimension for standard file") {
    naivebayes::File file =
    naivebayes::File("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\trainingimagesandlabels.txt");
    SECTION("Test correct dimension") {
        REQUIRE(file.GetDimension() == 28);
    }
}