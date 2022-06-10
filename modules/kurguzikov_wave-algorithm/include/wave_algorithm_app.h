// Copyright 2022 Oskin G

#ifndef MODULES_KURGUZIKOV_WAVE_ALGORITHM_INCLUDE_WAVE_ALGORITHM_APP_H_
#define MODULES_KURGUZIKOV_WAVE_ALGORITHM_INCLUDE_WAVE_ALGORITHM_APP_H_

#include <string>

#include "include/kurguzikov_wave_algorithm.h"

class WaveAlgorithmApplication {
 public:
    WaveAlgorithmApplication();
    std::string operator()(int argc, const char** argv);
 private:
    void getHelp(const char* appname, const char* message = "");
    std::string message_;
};

#endif  // MODULES_KURGUZIKOV_WAVE_ALGORITHM_INCLUDE_WAVE_ALGORITHM_APP_H_
