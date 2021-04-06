#include <string>
#include <vector>
#include "file.h"
#include "image.h"

namespace naivebayes {

class Model {
public:
    Model();
    void CalculatePriors();

private:
    std::vector<Image> images_;
    const std::string path_ = "C:\\Users\\User\\Cinder\\cinder_0.9.2_vc2015_\\cinder_0.9.2_vc2015\\my-projects\\Naive Bayes\\trainingimagesandlabels.txt";
    File file = File(path_);
    std::vector<float> priors_;
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
