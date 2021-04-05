#pragma once

#include <string>
#include <vector>
#include "image.h"

namespace naivebayes {

    class File {
    public:
        File(std::string path);

    private:
        std::vector<naivebayes::Image> images_;
    };
}
