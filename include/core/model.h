#pragma once

#include <string>
#include <vector>
#include "file.h"
#include "image.h"

namespace naivebayes {

class Model {
public:
    Model();
    Model(std::string path);
    void CalculatePriors();
    void CalculateFeatures();
    friend std::istream &operator>>(std::istream &is, Model &model);
    friend std::ostream &operator<<(std::ostream &os, Model &model);
    int GetDimension();

private:
    std::vector<Image> images_;
    std::vector<float> priors_;
    std::vector<std::vector<std::vector<std::vector<float>>>> features_;
public:
    const std::vector<float> &GetPriors() const;

    const std::vector<std::vector<std::vector<std::vector<float>>>> &GetFeatures() const;

private:
    int dimension_;
    static constexpr int NUM_CATEGORIES_ = 2;
    static constexpr int NUM_CLASSES_ = 10;
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
