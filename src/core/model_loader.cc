#include <core/model_loader.h>
#include <fstream>

namespace naivebayes {

    ModelLoader::ModelLoader(std::string path) {
        path_ = path;
    }

    Model ModelLoader::WriteToModel() {
        Model model;
        std::ifstream input_file(path_);
        if (input_file.is_open()) {
            input_file >> model;
        }
        return model;
    }

    void ModelLoader::WriteToFile(Model model) {
        std::ofstream output_file(path_);
        if (output_file.is_open()) {
            output_file << model;
        }
    }
}