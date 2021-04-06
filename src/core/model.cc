#include <core/model.h>

namespace naivebayes {

    Model::Model() {
        images_ = file.GetImages();
    }

    void Model::CalculatePriors() {
        for (int i = 0; i < 10; i++) {
            int class_sum = 0;
            for (int j = 0; j < images_.size(); j++) {
                if (images_[j].GetClass() == i) {
                    class_sum++;
                }
            }
            priors_.push_back((float)class_sum/images_.size());
        }
    }

}  // namespace naivebayes