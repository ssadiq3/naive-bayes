#include <core/model.h>
#include <sstream>

namespace naivebayes {

    Model::Model() {}

    Model::Model(std::string path) {
        File file_(path);
        images_ = file_.GetImages();
        dimension_ = file_.GetDimension();
        num_each_class = std::vector<int>(NUM_CLASSES_, 0);
        for (int i = 0; i < NUM_CLASSES_; i++) {
            for (Image image : images_) {
                if (image.GetClass() == i) {
                    num_each_class[i]++;
                }
            }
        }
    }

    void Model::CalculatePriors() {
        for (int i = 0; i < NUM_CLASSES_; i++) {
            int class_sum = 0;
            for (size_t j = 0; j < images_.size(); j++) {
                if (images_[j].GetClass() == i) {
                    class_sum++;
                }
            }
            priors_.push_back((float)((K_ + class_sum)/(float)((K_ * NUM_CATEGORIES_) + images_.size())));
        }
        return;
    }

    void Model::CalculateFeatures() {
        int unshaded_sum = 0;
        int shaded_sum = 0;
        features_ = std::vector<std::vector<std::vector<std::vector<float>>>>(dimension_, std::vector<std::vector<std::vector<float>>>(dimension_, std::vector<std::vector<float>>(NUM_CLASSES_, std::vector<float>(NUM_CATEGORIES_, 0))));
        int pixel_count = -1;
        for (int i = 0; i < dimension_; i++) {
            for (int j = 0; j < dimension_; j++) {
                ++pixel_count;
                for (int c = 0; c < NUM_CLASSES_; c++) {
                    for (Image image : images_) {
                        if (image.GetClass() == c) {
                            if (image.GetPixelValues()[pixel_count] == ' ') {
                                unshaded_sum++;
                            } else if (image.GetPixelValues()[pixel_count] == '+' || image.GetPixelValues()[pixel_count] == '#') {
                                shaded_sum++;
                            }
                        }
                    }
                    features_[i][j][c][0] = (float)(K_ + unshaded_sum)/(float) ((K_ * NUM_CATEGORIES_) + num_each_class[c]);
                    features_[i][j][c][1] = (float)(K_ + shaded_sum)/(float) ((K_ * NUM_CATEGORIES_) + num_each_class[c]);
                    unshaded_sum = 0;
                    shaded_sum = 0;
                }
            }
        }
    }

    std::ostream &operator<<(std::ostream &os, Model &model) {
        os << model.dimension_ << std::endl;

        for (size_t i = 0; i < model.priors_.size(); i++) {
            os << model.priors_[i] << std::endl;
        }

        for (int i = 0; i < model.dimension_; i++) {
            for (int j = 0; j < model.dimension_; j++) {
                for (int c = 0; c < model.NUM_CLASSES_; c++) {
                    for (int s = 0; s < model.NUM_CATEGORIES_; s++) {
                        os << model.features_[i][j][c][s] << std::endl;
                    }
                }
            }
        }
        return os;
    }

    std::istream &operator>>(std::istream &is, Model &model) {
        std::string dim_line;
        std::getline(is, dim_line);
        model.dimension_ = std::stoi(dim_line);

        model.priors_.resize(model.NUM_CLASSES_);
        for (int i = 0; i < model.NUM_CLASSES_; i++) {
            std::string line;
            std::getline(is, line);
            model.priors_[i] = std::stof(line);
        }

        model.features_ = std::vector<std::vector<std::vector<std::vector<float>>>>(model.dimension_, std::vector<std::vector<std::vector<float>>>(model.dimension_, std::vector<std::vector<float>>(model.NUM_CLASSES_, std::vector<float>(model.NUM_CATEGORIES_, 0))));
        for (int i = 0; i < model.dimension_; i++) {
            for (int j = 0; j < model.dimension_; j++) {
                for (int c = 0; c < model.NUM_CLASSES_; c++) {
                    for (int s = 0; s < model.NUM_CATEGORIES_; s++) {
                        std::string line;
                        std::getline(is, line);
                        model.features_[i][j][c][s] = std::stof(line);
                    }
                }
            }
        }
        return is;
    }

    int Model::GetDimension() {
        return dimension_;
    }

    const std::vector<float> &Model::GetPriors() const {
        return priors_;
    }

    const std::vector<std::vector<std::vector<std::vector<float>>>> &Model::GetFeatures() const {
        return features_;
    }


    //iterate through classes, find num of certain class, find feature at 0,0 for every image in that class, count 0s,
    //1s = num class - num 0s, divide num 0s by num class-add to [i][j][class][0],
    //divide num 1s by num class-add to [i][j][class][1]

}  // namespace naivebayes