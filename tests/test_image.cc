#include <catch2/catch.hpp>
#include <core/image.h>
#include <core/file.h>

TEST_CASE("Test image pixels for small file") {
    naivebayes::File file =
    naivebayes::File("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\test_file.txt");
    SECTION("Test pixel at index 2 of image 0") {
        REQUIRE(file.GetImages()[0].GetPixelValues()[2] == '#');
    }
    SECTION("Test pixel at index 0 of image 1") {
        REQUIRE(file.GetImages()[1].GetPixelValues()[0] == '#');
    }
    SECTION("Test pixel at index 4 of image 2") {
        REQUIRE(file.GetImages()[2].GetPixelValues()[4] == ' ');
    }

}

TEST_CASE("Test Class for small file") {
    naivebayes::File file = naivebayes::File("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\small_file.txt");
    SECTION("Test first class") {
        REQUIRE(file.GetImages()[0].GetClass() == 5);
    }
    SECTION("Test second class") {
        REQUIRE(file.GetImages()[1].GetClass() == 1);
    }
    SECTION("Test third class") {
        REQUIRE(file.GetImages()[2].GetClass() == 3);
    }
}

