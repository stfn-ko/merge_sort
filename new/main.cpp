#include <algorithm>
#include <array>
#include <iostream>

constexpr uint16_t INPUT_SIZE = 5;
constexpr uint16_t OUTPUT_SIZE = INPUT_SIZE * 2;

typedef struct {
  uint16_t distance;
  uint16_t tool_id;
  uint16_t tool_type;
} JobDetails;

bool compare_distance(const JobDetails &job_a, const JobDetails &job_b) {
  return job_a.distance < job_b.distance;
}

std::array<JobDetails, OUTPUT_SIZE>
merge_and_sort(const std::array<uint16_t, INPUT_SIZE> &tool_a,
               const std::array<uint16_t, INPUT_SIZE> &tool_b) {
  std::array<JobDetails, OUTPUT_SIZE> res;

  for (uint16_t i = 0; i < INPUT_SIZE; ++i) {
    if (tool_a.at(i) != 0) {
      //  writes into res[0; 4]
      res.at(i) = {tool_a.at(i), 1, 5};
    }

    if (tool_b.at(i) != 0) {
      //  writes into res[5; 9]
      res.at(i + INPUT_SIZE) = {tool_b.at(i), 2, 6};
    }
  }
  std::sort(res.begin(), res.end(), compare_distance);

  return res;
}

int main() {
  std::array<uint16_t, INPUT_SIZE> tool_a = {10, 50, 15, 0, 80};
  std::array<uint16_t, INPUT_SIZE> tool_b = {40, 30, 10, 70, 0};

  auto jobs = merge_and_sort(tool_a, tool_b);

  for (const auto &job : jobs) {
      printf("%d | %d | %d\n", job.distance, job.tool_id, job.tool_type);
  }

  return 0;
}