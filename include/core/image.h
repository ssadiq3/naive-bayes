#pragma once

#include <vector>

namespace naivebayes {

class Image {
public:
    Image();
    /**
     * An image constructor that constructs using a 2d vector of pixels-used for the sketchpad
     * @param pixels 2d vector of pixels
     */
    Image(std::vector<std::vector<char>> pixels);
    /**
     * Static method that processes images from a file into a vector of image objects
     * @param path to the file
     * @return vector of image objects in file
     */
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
    };
}
