#pragma once

#include <string>
#include <vector>
#include "image.h"

namespace naivebayes {

    class File {
    public:
        File(std::string path);
        std::vector<Image> GetImages();

    private:
        std::vector<naivebayes::Image> images_;
    };
}
