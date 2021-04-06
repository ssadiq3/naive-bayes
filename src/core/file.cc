#include <core/file.h>
#include <fstream>
#include <sstream>

namespace naivebayes {

    File::File(std::string path) {
        Image image;
        std::ifstream input_file(path);
        std::string image_string;
        int count = 0;
        size_t dimension;
        if (input_file.is_open()) {
            std::string line;
            while (std::getline(input_file, line)) {
                if (line.size() == 1 && count != 0) {
                    std::istringstream iss(image_string);
                    Image image;
                    iss >> image;
                    image.SetDimension(dimension);
                    images_.push_back(image);
                    image_string.clear();
                }
                dimension = line.size();
                count++;
                image_string += line;
            }
            std::istringstream iss (image_string);
            Image image;
            iss >> image;
            image.SetDimension(dimension);
            images_.push_back(image);
            input_file.close();
        }
    }

    std::vector<Image> File::GetImages() {
        return images_;
    }
}

