#include <algorithm>
#include <iostream>
#include <vector>

typedef struct {
  uint16_t distance;
  uint16_t tool_id;
  uint16_t tool_type;
} JobDetails;

std::vector<JobDetails> merge_and_sort(const std::vector<uint16_t> &tool_a,
                                       const std::vector<uint16_t> &tool_b) {
  std::vector<JobDetails> jobs;
  uint16_t tas = tool_a.size();
  uint16_t tbs = tool_b.size();
  jobs.reserve(tool_a.size() + tool_b.size());

  for (uint16_t i = 0; i < std::max(tbs, tas); ++i) {
    if (i < tas && tool_a[i] != 0) {
      jobs.push_back({tool_a.at(i), 1, 5});
    }
    if (i < tbs && tool_b[i] != 0) {
      jobs.push_back({tool_b.at(i), 2, 6});
    }
  }

  std::sort(jobs.begin(), jobs.end(),
            [](const JobDetails &job_a, const JobDetails &job_b) {
              return job_a.distance < job_b.distance;
            });

  return jobs;
}

int main() {
  std::vector<uint16_t> tool_a = {10, 50, 15, 80};
  std::vector<uint16_t> tool_b = {40, 30, 10, 70, 0, 12, 20, 88};

  auto jobs = merge_and_sort(tool_a, tool_b);

  for (const auto &job : jobs) {
    printf("%d | %d | %d\n", job.distance, job.tool_id, job.tool_type);
  }

  return 0;
}