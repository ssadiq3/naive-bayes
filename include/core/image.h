#pragma once

#include <vector>

namespace naivebayes {

class Image {
public:
    friend std::istream& operator>>(std::istream &is, Image &image);
    void SetDimension(size_t dimension);
    int GetClass();

private:
    int class_;
    static int dimension_;
    std::vector<std::vector<int>> image_pixels_ = std::vector<std::vector<int>>((int)dimension_, std::vector<int>((int)dimension_, 0));
    void FillPixelsVector(std::string block);
    };
}
