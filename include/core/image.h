#pragma once

#include <vector>

namespace naivebayes {

class Image {
public:
    Image();
    Image(std::vector<std::vector<char>> pixels);
    static std::vector<Image> ProcessImagesFromFile(std::string path);
    /**
     * >> Operator used by file to construct image from string stream
     * @param is input stream
     * @param image image to be constructed
     * @return input stream
     */
    friend std::istream& operator>>(std::istream &is, Image &image);
    int GetClass();
    std::vector<std::vector<char>> GetPixelValues();
    int GetDimension() const;

private:
    int class_;
    int dimension_;
    std::vector<std::vector<char>> pixels_;

    //std::vector<std::vector<int>> image_pixels_ = std::vector<std::vector<int>>((int)dimension_, std::vector<int>((int)dimension_, 0));
    //void FillPixelsVector(std::string block);
    };
}
