#include <core/image.h>
#include <istream>
#include <string>
#include <fstream>
#include <sstream>

namespace naivebayes {

    Image::Image() {}

    Image::Image(std::vector<std::vector<char>> pixels) {
        pixels_ = pixels;
        dimension_ = (int) pixels[0].size();
    }

    std::vector<Image> Image::ProcessImagesFromFile(std::string path) {
        std::vector<Image> images;
        int dimension = 0;
        //Create ifstream to read into image
        std::ifstream input_file(path);
        std::string image_string;
        //count used to stop from creating image from just first label
        int count = 0;
        if (input_file.is_open()) {
            std::string line;
            while (std::getline(input_file, line)) {
                //if size is 1, end of image because we are at label, cannot be first label
                if (line.size() == 1 && count != 0) {
                    //create string stream and push back new image with string of image
                    std::istringstream iss(image_string);
                    Image image;
                    //Set the dimension before creating the image for 2d vector
                    image.dimension_ = dimension;
                    iss >> image;
                    images.push_back(image);
                    //clear the string when iterating to next image
                    image_string.clear();
                }
                //set dimension, increment count and add the line to the image string
                dimension = (int)line.size();
                count++;
                image_string += line;
            }
            //Need to do inside of while loop again since no label after last image string
            std::istringstream iss (image_string);
            Image image;
            image.dimension_ = dimension;
            iss >> image;
            images.push_back(image);
            input_file.close();
        }
        return images;
    }

    std::istream &operator>>(std::istream &is, Image &image) {
        image.pixels_ = std::vector<std::vector<char>>(image.dimension_, std::vector<char>(image.dimension_, ' '));
        //block is image pixels, read as one contiguous line
        std::string block;
        std::getline(is, block);
        //set each image variable from block
        image.class_ = (int)(block[0] - '0');
        int count = 1;
        for (int row = 0; row < image.dimension_; row++) {
            for (int col = 0; col < image.dimension_; col++) {
                image.pixels_[row][col] = block[count];
                count++;
            }
        }
        /*image.pixel_values_ = block;
        image.pixel_values_.erase(0, 1);*/
        return is;
    }

    int Image::GetClass() {
        return class_;
    }

    std::vector<std::vector<char>> Image::GetPixelValues() {
        return pixels_;
    }

    int Image::GetDimension() const {
        return dimension_;
    }

}
