#include <catch2/catch.hpp>
#include <core/image.h>

TEST_CASE("Test image pixels for small file") {
    std::vector<naivebayes::Image> images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\test_file.txt");
    SECTION("Test pixel at index 2 of image 0") {
        REQUIRE(images[0].GetPixelValues()[0][2] == '#');
    }
    SECTION("Test pixel at index 0 of image 1") {
        REQUIRE(images[0].GetPixelValues()[0][0] == '#');
    }
    SECTION("Test pixel at index 4 of image 2") {
        REQUIRE(images[2].GetPixelValues()[0][4] == ' ');
    }

}

TEST_CASE("Test Class for small file") {
    std::vector<naivebayes::Image> images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\small_file.txt");
    SECTION("Test first class") {
        REQUIRE(images[0].GetClass() == 5);
    }
    SECTION("Test second class") {
        REQUIRE(images[1].GetClass() == 1);
    }
    SECTION("Test third class") {
        REQUIRE(images[2].GetClass() == 3);
    }
}

