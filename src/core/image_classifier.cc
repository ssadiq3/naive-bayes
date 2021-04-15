#include <core/image_classifier.h>

namespace naivebayes {

    int ImageClassifier::EvaluateImage(Model &model, Image image) {
        int class_ = 0;
        double max_prob = 0;
        for (int c = 0; c < model.GetNumClasses(); c++) {
            double temp_prob = log(model.GetPrior(c));
            for (int row = 0; row < image.GetDimension(); row++) {
                for (int col = 0; col < image.GetDimension(); col++) {
                    if (image.GetPixelValues()[row][col] == ' ') {
                        temp_prob += log(model.GetFeature(row, col, c, 0));
                    } else {
                        temp_prob += log(model.GetFeature(row, col, c, 1));
                    }
                }
            }
            if (temp_prob > max_prob) {
                class_ = c;
                max_prob = temp_prob;
            }
        }
        return class_;
    }
}

