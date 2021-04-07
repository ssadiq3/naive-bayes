#include <catch2/catch.hpp>
#include <core/model_loader.h>
#include <fstream>

TEST_CASE("Test model loading ") {
    naivebayes::ModelLoader model_file("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\model_file.txt");
    naivebayes::Model model("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\trainingimagesandlabels.txt");
    model.CalculatePriors();
    model.CalculateFeatures();
    SECTION("Check write file") {
        model_file.WriteToFile(model);
        std::string line;
        std::ifstream ifstream("C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\model_file.txt");
        getline(ifstream, line);
        SECTION("Test line length") {
            REQUIRE("28" == line);
        }
        SECTION("Test first prior") {
            getline(ifstream, line);
            REQUIRE("0.0959616" == line);
        }
        SECTION("Check model load") {
            naivebayes::Model model_1 = model_file.WriteToModel();
            SECTION("Test model file prior") {
                REQUIRE(0.0959616 == model_1.GetPriors()[0]);
            }
        }
    }
}

