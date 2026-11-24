// classify.cpp — part of boot-optimizer-ai.

#include "bootoptimizerai/classify.h"

#include <cstdio>

namespace bootoptimizerai {

Classify::Classify(const std::string& config_path)
    : config_path_(config_path) {}

void Classify::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Classify::run() {
    if (verbose_) std::fprintf(stderr, "[boot-optimizer-ai] classify: run\n");
    // core logic lives here
    return true;
}

}  // namespace bootoptimizerai
