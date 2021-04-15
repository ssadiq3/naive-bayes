#pragma once

#include <string>
#include <vector>
#include "file.h"
#include "image.h"

namespace naivebayes {

class Model {
public:
    /**
     * Default constructor
     */
    Model();
    /**
     * Constructor that constructs based off file
     * @param file file from which model is constructed
     */
    Model(std::vector<Image> images);

    static Model Train(std::vector<Image> images);
    /**
     * Calculates prior probabilities and stores in vector
     */
    void CalculatePriors(std::vector<Image> images);
    /**
     * Calculates feature probabilities and stores in vector
     */
    void CalculateFeatures(std::vector<Image> images);
    /**
     * >> Operator used to build model from file
     * @param is istream containing model string
     * @param model object built from stream
     * @return istream
     */
    friend std::istream &operator>>(std::istream &is, Model &model);
    /**
     * << Operator used to write model to file
     * @param os output stream to write to
     * @param model used for outputting
     * @return output stream
     */
    friend std::ostream &operator<<(std::ostream &os, Model &model);
    int GetDimension();
    const float &GetPrior(int class_) const;
    const float &GetFeature(int row, int col, int class_, int shade) const;
    static const int GetNumClasses();

private:
    std::vector<float> priors_;
    std::vector<std::vector<std::vector<std::vector<float>>>> features_;
    int dimension_;
    static constexpr int NUM_CATEGORIES_ = 2;
    static constexpr int NUM_CLASSES_ = 10;

private:
    static constexpr int K_ = 1;
    std::vector<int> num_each_class;



};

}  // namespace naivebayes

/*
TODO: rename this file. You'll also need to modify CMakeLists.txt.

You can (and should) create more classes and files in include/core (header
 files) and src/core (source files); this project is too big to only have a
 single class.

Make sure to add any files that you create to CMakeLists.txt.

TODO Delete this comment before submitting your code.
*/
