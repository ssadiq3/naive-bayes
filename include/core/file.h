#pragma once

#include <string>
#include <vector>
#include "image.h"

namespace naivebayes {

    class File {
    public:
        File(std::string path);
        std::vector<Image> GetImages();
        int GetDimension();

    private:
        std::vector<naivebayes::Image> images_;
        int dimension_;
    };
}
