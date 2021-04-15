#include <core/image_classifier.h>

namespace naivebayes {

    int ImageClassifier::EvaluateImage(Model &model, Image image) {
        int class_ = 0;
        //set max to lowest possible value
        double max_prob = -DBL_MAX;
        //iterate through classes, find prior and features for every pixel of this class
        for (int c = 0; c < model.GetNumClasses(); c++) {
            //create temp to compare with max, first part is prior of this class
            double temp_prob = log(model.GetPrior(c));
            for (int row = 0; row < image.GetDimension(); row++) {
                for (int col = 0; col < image.GetDimension(); col++) {
                    //if unshaded, look at unshaded probability, and vice versa
                    if (image.GetPixelValues()[row][col] == ' ') {
                        temp_prob += log(model.GetFeature(row, col, c, 0));
                    } else {
                        temp_prob += log(model.GetFeature(row, col, c, 1));
                    }
                }
            }
            //set class to return if temp>max and set new max
            if (temp_prob > max_prob) {
                class_ = c;
                max_prob = temp_prob;
            }
        }
        //return predicted class
        return class_;
    }
}

