#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
  {
    // Lambda to calculate the gain of adding an extra student
    auto calculateGain = [](int passes, int totalStudents)
    {
      return (double)(passes + 1) / (totalStudents + 1) -
             (double)passes / totalStudents;
    };

    // Max heap to store (-gain, passes, totalStudents)
    priority_queue<pair<double, pair<int, int>>> maxHeap;
    for (const auto &singleClass : classes)
    {
      maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                    {singleClass[0], singleClass[1]}});
    }

    // Distribute extra students
    while (extraStudents--)
    {
      auto topPair = maxHeap.top();
      maxHeap.pop();
      double currentGain = topPair.first;
      int passes = topPair.second.first;
      int totalStudents = topPair.second.second;
      maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                    {passes + 1, totalStudents + 1}});
    }

    // Calculate the final average pass ratio
    double totalPassRatio = 0;
    while (!maxHeap.empty())
    {
      auto topElement = maxHeap.top();
      maxHeap.pop();
      totalPassRatio += (double)topElement.second.first / topElement.second.second;
    }

    return totalPassRatio / classes.size();
  }
};