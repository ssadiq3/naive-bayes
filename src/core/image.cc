#include <core/image.h>
#include <istream>
#include <string>

namespace naivebayes {

    std::istream &operator>>(std::istream &is, Image &image) {
        std::string block;
        std::getline(is, block);
        image.class_ = (int)(block[0] - '0');
        image.pixel_values_ = block;
        image.pixel_values_.erase(0, 1);
        return is;
    }

    int Image::GetClass() {
        return class_;
    }

    std::string Image::GetPixelValues() {
        return pixel_values_;
    }

}
