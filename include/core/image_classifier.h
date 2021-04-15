#pragma once

#include "model.h"
#include "file.h"

namespace naivebayes {

    class ImageClassifier {

    public:
       static int EvaluateImage(Model &model, Image image);

    };

}
