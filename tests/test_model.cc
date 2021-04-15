#include <catch2/catch.hpp>

#include <core/model.h>

TEST_CASE("Test 28 small model data") {
    std::vector<naivebayes::Image> images  = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\image-files\\small_28_file.txt");
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

TEST_CASE("Test 2x2 small model data") {
    std::vector<naivebayes::Image> images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\image-files\\2x2_file.txt");
    naivebayes::Model model = naivebayes::Model::Train(images);
    SECTION("Test dimension from file") {
        REQUIRE(model.GetDimension() == 2);
    }
    SECTION("Test priors") {
        SECTION("Test prior 0") {
            REQUIRE(Approx(model.GetPrior(0)).epsilon(0.1) == 0.2);
        }
        SECTION("Test prior 1") {
            REQUIRE(Approx(model.GetPrior(1)).epsilon(0.1) == 0.4);
        }
        SECTION("Test prior 2") {
            REQUIRE(Approx(model.GetPrior(1)).epsilon(0.1) == 0.4);
        }
        SECTION("Test prior 3") {
            REQUIRE(Approx(model.GetPrior(2)).epsilon(0.1) == 0.4);
        }
    }
    SECTION("Test feature probabilities") {
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,0,1,0)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,0,1,1)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,0,2,0)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,0,2,1)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,0,3,0)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,0,3,1)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,1,1,0)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,1,1,1)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,1,2,0)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,1,2,1)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,1,3,0)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(0,1,3,1)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,0,1,0)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,0,1,1)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,0,2,0)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,0,2,1)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,0,3,0)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,0,3,1)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,1,1,0)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,1,1,1)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,1,2,0)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,1,2,1)).epsilon(0.1) == 0.667f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,1,3,0)).epsilon(0.1) == 0.333f);
        }
        SECTION("Test feature probability") {
            REQUIRE(Approx(model.GetFeature(1,1,3,1)).epsilon(0.1) == 0.667f);
        }
    }
}
