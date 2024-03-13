#include <array>
#include <iostream>

constexpr uint8_t INPUT_SIZE = 5;
constexpr uint8_t TOOL1_TYPE = 5;
constexpr uint8_t TOOL2_TYPE = 6;

typedef struct {
  uint8_t array_id = 0;
  uint8_t tool_type = 0;
  uint16_t distance = UINT16_MAX;
} Job;

using DistArr = std::array<uint16_t, INPUT_SIZE>;

// foo
// Note: Modifies the pos_idx
Job closestJob(const DistArr &a, const DistArr &b, uint8_t &pos_idx) {
  Job job;

  for (uint8_t i = 0; i < INPUT_SIZE; ++i) {
    if (a[i] != 0 && a[i] < job.distance) {
      pos_idx = i;
      job.array_id = 1;
      job.tool_type = TOOL1_TYPE;
      job.distance = a[i];
    }
    if (b[i] != 0 && b[i] < job.distance) {
      pos_idx = i;
      job.array_id = 2;
      job.tool_type = TOOL2_TYPE;
      job.distance = b[i];
    }
  }

  return job;
}

int main() {
  uint8_t pos_idx = 0;
  DistArr arr_a = {10, 50, 15, 30, 80};
  DistArr arr_b = {40, 30, 10, 70, 0};

  while (true) {
    Job job = closestJob(arr_a, arr_b, pos_idx);

    if (job.array_id != 0) {
      printf("%d, %d, %d\n", job.distance, job.array_id, job.tool_type);
      (job.array_id == 1) ? arr_a[pos_idx] = 0 : arr_b[pos_idx] = 0;
    } else {
      break;
    }
  }
}

