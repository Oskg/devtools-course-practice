// Copyright 2022 Oskin G



#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "/Users/usero/Desktop/DevTools/devtools-course-practice/modules/kurguzikov_wave-algorithm/include/wave_algorithm_app.h"

int main(int argc, const char** argv) {
    WaveAlgorithmApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
