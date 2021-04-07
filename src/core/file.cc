#include <core/file.h>
#include <fstream>
#include <sstream>

namespace naivebayes {

    File::File(std::string path) {
        std::ifstream input_file(path);
        std::string image_string;
        int count = 0;
        if (input_file.is_open()) {
            std::string line;
            while (std::getline(input_file, line)) {
                if (line.size() == 1 && count != 0) {
                    std::istringstream iss(image_string);
                    Image image;
                    iss >> image;
                    images_.push_back(image);
                    image_string.clear();
                }
                dimension_ = line.size();
                count++;
                image_string += line;
            }
            std::istringstream iss (image_string);
            Image image;
            iss >> image;
            images_.push_back(image);
            input_file.close();
        }
    }

    std::vector<Image> File::GetImages() {
        return images_;
    }

    int File::GetDimension() {
        return dimension_;
    }
}

