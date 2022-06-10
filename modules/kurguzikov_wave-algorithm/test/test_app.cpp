// Copyright 2022 Oskin G
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING  1
#include <string>
#include <vector>
#include "/Users/usero/Desktop/DevTools/devtools-course-practice/modules/kurguzikov_wave-algorithm/include/wave_algorithm_app.h"
#include "/Users/usero/Desktop/DevTools/devtools-course-practice/3rdparty/gtest/gtest.h"

using ::testing::internal::RE;

class WaveTest : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("WaveAlgorithm_");
        for (std::size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    WaveAlgorithmApplication app_;
    std::string output_;
};

TEST_F(WaveTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("Application started!\n");
}

TEST_F(WaveTest, Is_Checking_Number_Of_Arguments) {
    std::vector<std::string> args = { "3,3", "FREE,WALL,WALL" };

    Act(args);

    Assert("Error: Not enough arguments!\n");
}

TEST_F(WaveTest, Is_Checking_Correct_Of_Dims) {
    std::vector<std::string> args = { "2,2", "FREE,WALL,WALL", "0,0", "1,1" };

    Act(args);

    Assert("Error: Wrong dims of map!\n");
}

TEST_F(WaveTest, Is_Checking_Correct_Of_Keywords) {
    std::vector<std::string> args =
    { "2,2", "FREE,WALL,WALL,smdlk", "0,0", "1,1" };

    Act(args);

    Assert("Error: Wrong keywords of map!\n");
}

TEST_F(WaveTest, AppWorkCorrect_1) {
    std::vector<std::string> args =
    { "3,3", "FREE,WALL,WALL,WALL,FREE,WALL,WALL,WALL,FREE", "0,0", "2,2" };

    Act(args);

    Assert("0,0 1,1 2,2 ");
}

