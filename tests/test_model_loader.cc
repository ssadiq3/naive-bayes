#include <catch2/catch.hpp>
#include <core/model_loader.h>
#include <fstream>

TEST_CASE("Test 2x2 model loading and saving") {
    std::vector<naivebayes::Image> images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\image-files\\2x2_file.txt");
    naivebayes::Model model = naivebayes::Model::Train(images);
    SECTION("Check write file") {
        naivebayes::ModelLoader::WriteToFile(model, "C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\model-files\\small_model_file.txt");
        std::string line;
        std::ifstream ifstream("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\model-files\\small_model_file.txt");
        getline(ifstream, line);
        SECTION("Test line length") {
            REQUIRE("2" == line);
        }
        SECTION("Test first prior") {
            getline(ifstream, line);
            REQUIRE("0.2" == line);
        }
        SECTION("Test loaded model data") {
            naivebayes::Model model_1 = naivebayes::ModelLoader::WriteToModel("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\model-files\\small_model_file.txt");
            SECTION("Test prior") {
                REQUIRE(0.2f == model_1.GetPrior(0));
            }
            SECTION("Test prior") {
                REQUIRE(0.4f == model_1.GetPrior(1));
            }
            SECTION("Test prior") {
                REQUIRE(0.4f == model_1.GetPrior(2));
            }
            SECTION("Test prior") {
                REQUIRE(0.4f == model_1.GetPrior(3));
            }
        }
    }
}
TEST_CASE("Test 5x5 model loading") {
    std::vector<naivebayes::Image> images = naivebayes::Image::ProcessImagesFromFile("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\small_file.txt");
    naivebayes::Model model = naivebayes::Model::Train(images);
    SECTION("Check write file") {
        naivebayes::ModelLoader::WriteToFile(model, "C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\small_7_model_file.txt");
        std::string line;
        std::ifstream ifstream("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\small_file.txt");
        getline(ifstream, line);
        SECTION("Test line length") {
            REQUIRE("5" == line);
        }
        SECTION("Test first prior") {
            getline(ifstream, line);
            REQUIRE("0.0959616" == line);
        }
        SECTION("Check model load") {
            naivebayes::Model model_1 = naivebayes::ModelLoader::WriteToModel("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\small_7_model_file.txt");
            SECTION("Test model file prior") {
                REQUIRE(0.33f == model_1.GetPrior(5));
            }
        }
    }
}

