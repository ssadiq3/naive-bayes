#pragma once

#include <vector>

namespace naivebayes {

class Image {
public:
    friend std::istream& operator>>(std::istream &is, Image &image);
    void FillPixelsVector(std::string block);

private:
    int class_;
    size_t dimension_;
    std::vector<std::vector<int>> image_pixels_ = std::vector<std::vector<int>>(dimension_, std::vector<int>(dimension_, 0));
    };
}
