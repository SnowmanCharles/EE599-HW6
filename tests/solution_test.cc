#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(HelloWorldShould, ReturnHelloWorld) {
  Solution solution;
  std::string actual = solution.PrintHelloWorld();
  std::string expected = "**** Hello World ****";
  EXPECT_EQ(expected, actual);
}

TEST(CheckMazeTestSuccess, CheckMazeTestSuccess) {
    Solution solution;
    vector<vector<int>> maze{
        {1, 1, 0, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };
    vector<int> start{0,0}, end{4,4};
    EXPECT_EQ(solution.checkMaze(maze, start, end), true);
}

TEST(CheckMazeTestFail, CheckMazeTestFail) {
    Solution solution;
    vector<vector<int>> maze{
        {1,1,0,0,0},
        {1,1,1,1,1},
        {0,1,0,0,1},
        {1,0,0,0,0},
        {1,1,1,1,1}
    };
    vector<int> start{1,2}, end{4,4};
    EXPECT_EQ(solution.checkMaze(maze, start, end), false);
}

TEST(PartitionTest, PartitionTest) {
    Solution solution;
    vector<int> vec{9,1,2,8,7,3,6,4,5};
    solution.partition(vec, 8);
    vector<int> expect{1, 2, 3, 4, 5, 9, 6, 8, 7};
    for (int i = 0; i < expect.size(); i++) {
      EXPECT_EQ(vec[i], expect[i]);
    }
}