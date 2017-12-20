#include <string>

#include "features.hpp"

int main(int argc, char* argv[]) {
    
    if (argc == 2 && std::string(argv[1]) == "feature-check") {
        features::full_feature_check();
        features::save();
        return 0;
    }

    features::load();

    return 0;

}
