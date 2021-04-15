#pragma once

#include "model.h"

namespace naivebayes {

    class ImageClassifier {

    public:
        /**
         * Classifies a given image using a given trained model.
         * @param model trained model to use to classify image
         * @param image to classify
         * @return predicted class of given image
         */
       static int EvaluateImage(Model &model, Image image);

    };

}
