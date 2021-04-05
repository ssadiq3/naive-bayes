#include <core/image.h>
#include <istream>
#include <string>

namespace naivebayes {

    std::istream& operator>>(std::istream &is, Image &image) {
        size_t dimension;
        std::string block;
        std::string line;
        while (std::getline(is, line)) {
            if (line.length() == 1) {
                image.class_ = std::stoi(line);
            } else {
                image.dimension_ = line.length();
                block += line;
            }
        }
        image.FillPixelsVector(block);
        return is;
    }

    void Image::FillPixelsVector(std::string block) {
        for (size_t k = 1; k < block.length(); k++) {
            for (size_t i = 0; i < dimension_; i++) {
                for (size_t j = 0; j < dimension_; j++) {
                    if (block.at(k) == '#' || block.at(k) == '+') {
                        image_pixels_[i][j] = 1;
                    } else {
                        image_pixels_[i][j] = 0;
                    }
                }
            }
        }
    }

}
