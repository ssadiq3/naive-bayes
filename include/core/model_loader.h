#pragma once

#include "model.h"

namespace naivebayes {

    class ModelLoader {
    public:
        ModelLoader(std::string path);
        Model WriteToModel();
        void WriteToFile(Model model);

    private:
        std::string path_;
    };
}
