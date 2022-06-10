// Copyright 2022 Oskin G
#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "include/wave_algorithm_app.h"

WaveAlgorithmApplication::WaveAlgorithmApplication() : message_("") {}

std::vector<std::string>&
split(const std::string& s, char delim, std::vector<std::string>& elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

void WaveAlgorithmApplication::
getHelp(const char* appname, const char* message) {
    message_ = std::string(message) + "Application started!\n" +


        "This is a service which help you to find out\n" +
        "the path on the map from one point to another\n" +
        "Example to start algorithm:\n" +
        "\"$ " + appname +
        " 3,3 FREE,WALL,WALL,WALL,FREE,WALL,WALL,WALL,FREE  0,0 2,2 \n" +
        "Will find path for this map: \n" +
        "FREE,WALL,WALL \n" +
        "WALL,FREE,WALL \n" +
        "WALL,WALL,FREE \n" +
        "From top-left point (0,0) to bot-right point (2,2) \n";
}

std::string WaveAlgorithmApplication::
operator()(int argc, const char** argv) {
    if ((argc == 1))
        getHelp(argv[0]);
    std::string message = std::to_string(argc);
    if (argc < 5) getHelp(argv[0], "Error: Not enough arguments!\n");
    if (argc == 5) {
        char delimiter = ',';
        std::vector<std::string> start_p;
        std::vector<std::string> end_p;
        std::vector<std::string> dims;
        std::string dim_s = argv[1];
        split(dim_s, delimiter, dims);
        int size = std::stoi(dims[0]) * std::stoi(dims[1]);
        std::vector<std::string> map_s_a(size);
        std::string start_s = argv[3];
        split(start_s, delimiter, start_p);
        std::string end_s = argv[4];
        split(end_s, delimiter, end_p);
        std::string map_s = argv[2];
        map_s += "!";
        int i = 0;
        int j = 0;
        int n = std::count(map_s.begin(), map_s.end(), ',');
        if (n != size - 1) {
            getHelp(argv[0], "Error: Wrong dims of map!\n");
            return message_;
        }

        while (map_s[i] != '!') {
            if (map_s[j] == ',') j++;
            if ((map_s[i] == '!') || (map_s[j] == '!')) break;
            while ((map_s[j] != ',') && (map_s[j] != '!')) {
                map_s_a[i] += map_s[j];
                j++;
            }
            i++;
        }

        std::vector<int> map_f(std::stoi(dims[0]) * std::stoi(dims[1]));
        for (int i = 0; i < size; i++) {
            if (map_s_a[i] == "FREE") {
                map_f[i] = -1;
                continue;
            }
            if (map_s_a[i] == "WALL") {
                map_f[i] = -2;
                continue;
            } else {
                getHelp(argv[0], "Error: Wrong keywords of map!\n");
                return message_;
            }
        }
        int d1 = std::stoi(dims[0]);
        int d2 = std::stoi(dims[1]);
        int s1 = std::stoi(start_p[0]);
        int s2 = std::stoi(start_p[1]);
        int e1 = std::stoi(end_p[0]);
        int e2 = std::stoi(end_p[1]);
        std::vector<WaveLib::Point> path;
        WaveLib::Point start(s1, s2);
        WaveLib::Point end(e1, e2);
        WaveLib::WaveAlgorithm algorithm(d1, d2, map_f);
        algorithm.findPath(start, end, &path);
        std::ostringstream oss;
        for (auto& pr : path) {
            oss << pr.first << ',' << pr.second << ' ';
        }
        message_ = oss.str();
    }

    return message_;
}

