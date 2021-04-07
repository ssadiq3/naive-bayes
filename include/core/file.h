#pragma once

#include <string>
#include <vector>
#include "image.h"

namespace naivebayes {

    class File {
    public:
        /**
         * Constructs file with images_ vector filled using >> operator
         * @param path path to file that needs to be generated
         */
        File(std::string path);
        std::vector<Image> GetImages();
        int GetDimension();

    private:
        std::vector<naivebayes::Image> images_;
        int dimension_;
    };
}
