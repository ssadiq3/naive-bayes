#include <core/image.h>
#include <istream>
#include <string>

namespace naivebayes {

    std::istream &operator>>(std::istream &is, Image &image) {
        std::string block;
        std::getline(is, block);
        image.class_ = (int)(block[0] - '0');
        image.FillPixelsVector(block);
        return is;
    }

    void Image::FillPixelsVector(std::string block) {
        int k = -1;
        auto vector = std::vector<std::vector<int>>(28, std::vector<int>(28, 0));
        for (int i = 0; i < 28; i++) {
            for (int j = 0; j < 28; j++) {
                k++;
                if (block.at(k) == '#' || block.at(k) == '+') {
                    vector[i][j] = 1;
                } else {
                    vector[i][j] = 0;
                }
            }
        }
        image_pixels_ = vector;
    }

    void Image::SetDimension(size_t dimension) {
        dimension_ = dimension;
    }

    int Image::GetClass() {
        return class_;
    }

}
