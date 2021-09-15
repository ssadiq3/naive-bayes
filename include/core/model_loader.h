#pragma once

#include "model.h"

namespace naivebayes {

    class ModelLoader {
    public:
        /**
         * Creates model loader file
         * @param path to file for model
         */
        ModelLoader();
        /**
         * Writes from file into a model
         * @return model that is generated
         */
        static Model WriteToModel(std::string path);
        /**
         * Writes model to a file
         * @param model which is to be written to file
         */
        static void WriteToFile(Model model, std::string path);

    };
}
