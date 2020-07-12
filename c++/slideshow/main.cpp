#include <iostream>
#include <opencv2/opencv.hpp>
#include <glob.h> // glob(), globfree()
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>

std::vector<std::string> glob(const std::string& pattern);


int main() {
    auto imagePaths = glob("../images/*.jpg");
    auto cnt = imagePaths.size();
    int idx = 0;

    while (true) {
        auto img = cv::imread(imagePaths[idx++]);
        idx %= cnt;

        if (img.empty()) {
            std::cout << "Image load failed!" << std::endl;
            continue;
        }


        cv::imshow("image", img);

        if (cv::waitKey(1000) == 27)
            break;

    }

    return 0;
}

std::vector<std::string> glob(const std::string& pattern) {
    using namespace std;

    // glob struct resides on the stack
    glob_t glob_result;
    memset(&glob_result, 0, sizeof(glob_result));

    // do the glob operation
    int return_value = glob(pattern.c_str(), GLOB_TILDE, nullptr, &glob_result);
    if (return_value != 0) {
        globfree(&glob_result);
        stringstream ss;
        ss << "glob() failed with return_value " << return_value << endl;
        throw std::runtime_error(ss.str());
    }

    // collect all the filenames into a std::list<std::string>
    vector<string> filenames;
    for (size_t i = 0; i < glob_result.gl_pathc; ++i) {
        filenames.emplace_back(glob_result.gl_pathv[i]);
    }

    // cleanup
    globfree(&glob_result);

    // done
    return filenames;
}