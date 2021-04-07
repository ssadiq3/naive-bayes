#include <core/file.h>
#include <fstream>
#include <sstream>

namespace naivebayes {

    File::File(std::string path) {
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
                    iss >> image;
                    images_.push_back(image);
                    //clear the string when iterating to next image
                    image_string.clear();
                }
                //set dimension, increment count and add the line to the image string
                dimension_ = line.size();
                count++;
                image_string += line;
            }
            //Need to do inside of while loop again since no label after last image string
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

