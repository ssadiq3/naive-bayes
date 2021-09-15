#include <core/model_loader.h>
#include <fstream>

namespace naivebayes {

    ModelLoader::ModelLoader() {}

    Model ModelLoader::WriteToModel(std::string path) {
        Model model;
        std::ifstream input_file(path);
        //Uses operator >> to write from file into the model
        if (input_file.is_open()) {
            input_file >> model;
        }
        return model;
    }

    void ModelLoader::WriteToFile(Model model, std::string path) {
        std::ofstream output_file(path);
        //Uses overload operator << to write model into a file
        if (output_file.is_open()) {
            output_file << model;
        }
    }
}