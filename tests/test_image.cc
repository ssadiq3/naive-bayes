#include <catch2/catch.hpp>
#include <core/image.h>

TEST_CASE("Test every pixel value and class for 2x2 file") {
    std::vector<naivebayes::Image> images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\image-files\\2x2_file.txt");

    SECTION("Test dimension") {
        REQUIRE(images[0].GetDimension() == 2);
    }
    SECTION("Test classes") {
        SECTION("Test first class") {
            REQUIRE(images[0].GetClass() == 1);
        }
        SECTION("Test second class") {
            REQUIRE(images[1].GetClass() == 2);
        }
        SECTION("Test third class") {
            REQUIRE(images[2].GetClass() == 3);
        }
    }

    SECTION("Test pixels") {
        SECTION("Test pixel at index 0,0 of image 0") {
            REQUIRE(images[0].GetPixelValues()[0][0] == '#');
        }
        SECTION("Test pixel at index 0,1 of image 0") {
            REQUIRE(images[0].GetPixelValues()[0][1] == '#');
        }
        SECTION("Test pixel at index 1,0 of image 0") {
            REQUIRE(images[0].GetPixelValues()[1][0] == ' ');
        }
        SECTION("Test pixel at index 1,1 of image 0") {
            REQUIRE(images[0].GetPixelValues()[1][1] == '+');
        }
        SECTION("Test pixel at index 0,0 of image 1") {
            REQUIRE(images[1].GetPixelValues()[0][0] == '#');
        }
        SECTION("Test pixel at index 0,1 of image 1") {
            REQUIRE(images[1].GetPixelValues()[0][1] == ' ');
        }
        SECTION("Test pixel at index 1,0 of image 1") {
            REQUIRE(images[1].GetPixelValues()[1][0] == ' ');
        }
        SECTION("Test pixel at index 1,1 of image 1") {
            REQUIRE(images[1].GetPixelValues()[1][1] == '+');
        }
        SECTION("Test pixel at index 0,0 of image 2") {
            REQUIRE(images[2].GetPixelValues()[0][0] == ' ');
        }
        SECTION("Test pixel at index 0,1 of image 2") {
            REQUIRE(images[2].GetPixelValues()[0][1] == '#');
        }
        SECTION("Test pixel at index 1,0 of image 2") {
            REQUIRE(images[2].GetPixelValues()[1][0] == '#');
        }
        SECTION("Test pixel at index 1, of image 2") {
            REQUIRE(images[2].GetPixelValues()[1][1] == '#');
        }
    }
}

