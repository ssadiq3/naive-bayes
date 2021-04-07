#pragma once

#include "model.h"

namespace naivebayes {

    class ModelLoader {
    public:
        /**
         * Creates model loader file
         * @param path to file for model
         */
        ModelLoader(std::string path);
        /**
         * Writes from file into a model
         * @return model that is generated
         */
        Model WriteToModel();
        /**
         * Writes model to a file
         * @param model which is to be written to file
         */
        void WriteToFile(Model model);

    private:
        std::string path_;
    };
}
