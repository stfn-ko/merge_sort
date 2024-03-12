# Plockmatic Interview [Algorithm](/sorting_alg_polckmatic/old/main.cpp)

## Algorithm's purpose
This algorithm takes in two equally sized arrays and produces an incrementally sorted 2D array. For an input of:

``` C++
    uint16_t array_A[5] = {10, 50, 15, 30, 80};
    uint16_t array_B[5] = {40, 30, 10, 70, 0};
```

The algorithm will output:

|Position Value|Array Id|Tool Type|
|--------------|--------|---------|
|10            |1       |5        |
|10            |2       |6        |
|15            |1       |5        |
|30            |2       |6        |
|30            |1       |5        |
|40            |2       |6        |
|50            |1       |5        |
|70            |2       |6        |
|80            |1       |5        |

</br>

> :warning: This algorithm skips null values

## Time complexity

The time complexity in this case is indeed `O(1)`, because `array_Size` is fixed at `5`. As long as the input arrays are no smaller than 5 (to avoid out-of-bounds errors), the loops will always iterate exactly `5` times.

If this algorithm was to take in arrays of any size, the time complexity would grow to O(n<sup>2</sup>). 

## Notes about the code

One of the main drawbacks of the code is that the `printf()` fucntion only shows the current state of array_X at the time it's called. Since the loop continues, it populates subsequent rows with new minimum values, overwriting previous entries. 

In order to improve this code I would advise to:
- 
- Split the code up into smaller functions to promote code modularity as well as make it more readable.
- Remove the unnecessary `switch` statement to improve code readability as well as (potentially) squeeze out some perofrmance out of the code. 
- Restrain from using the `std` namespace, besides being a bad practice, there's no actual reason for using it in this particular example.
- The code formatting strictly depends on the conventions used by the company, however, I would personally prefer to read it in `Clang/LLVM` formats.
- Global variables aren't necessarily a bad thing, but I would also try to circumvent using those unless it is absolutely necessary.
- Add the `return` statement to the end of `main`. 
- The code is inconsistent in naming convention using a mix of `snake_case`, `CamelCase`, `camel_Snake_Case`, `Title_Case` and `UpperCamelCase`. Basically, every naming convention there is that C++ syntax allows. <sup>[[1]](https://en.wikipedia.org/wiki/Naming_convention_(programming))</sup>

---

# Alternative solutions

## [Solution 1](/sorting_alg_polckmatic/new/main.cpp)

### Description
This function merges and sorts job details from two input arrays (`tool_a` and `tool_b`). It iterates through both arrays and creates `JobDetails` entries for non-zero distances. The function assigns a unique `tool_id` and a fixed `tool_type` to each job.

After creating the initial entries, the function uses `std::sort` with a custom comparison function `compare_distance` <sup>[[2]](#compare_distance)</sup> to sort the `JobDetails` array in ascending order based on the `distance` field.

### Notes:

This function assumes the input arrays (`tool_a` and `tool_b`) have the same size defined by `INPUT_SIZE`.
The function uses fixed values for tool IDs and types. These values can be modified based on specific requirements.

### Documentation

###### Function Signature
```C++
merge_and_sort(const std::array<uint16_t, INPUT_SIZE> &tool_a, 
               const std::array<uint16_t, INPUT_SIZE> &tool_b)
``` 

###### Header Files

- `<algorithm>` → Provides the `std::sort` algorithms
- `<array>` → Provides functionality for working with fixed-size arrays
- `<iostream>` → Provides input/output functionality (used in main for printing)

###### Constant Expressions
- `INPUT_SIZE` → `constexpr` set to the size of the input arrays (`tool_a` & `tool_b`)
- `OUTPUT_SIZE` → `constexpr` set to twice the size of `INPUT_SIZE` to store the merged and sorted result

###### Type Definitions

- `JobDetails` → `struct` representing a job with the following fields:
    - `distance` → The distance associated with the job ( `uint16_t` )
    - `tool_id` → The ID of the array associated with the job ( `uint16_t` )
    - `tool_type` → The type of the tool associated with the job ( `uint16_t` )

###### Function Parameters

- `tool_a` → A constant reference to a `std::array<uint16_t, INPUT_SIZE>` containing distances for tool A.
- `tool_b` → A constant reference to a `std::array<uint16_t, INPUT_SIZE>` containing distances for tool B.

###### Return Value

- `std::array<JobDetails, OUTPUT_SIZE>` → contains the merged and sorted job details. Jobs are sorted by `distance` in ascending order.

### Complexity

Time complexity of the `merge_and_sort` function is `O(nlogn)` because of the sorting operation using `std::sort`, where `n` is the size of the `OUTPUT_SIZE` array. The space complexity is `O(n)` because we are creating an array of size `OUTPUT_SIZE` to store the merged and sorted job details. <sup>[[3]](https://www.bigocalc.com/)</sup>

---

## [Solution 2](/sorting_alg_polckmatic/new/main_vec.cpp)

This function merges and sorts job details from two input vectors (`tool_a` and `tool_b`). It iterates through both vectors and creates `JobDetails` entries for non-zero distances. The function assigns a unique `tool_id` and a fixed `tool_type` to each job.

After creating the initial entries, the function uses `std::sort` with a `lambda function` <sup>[[4]](#compare_distance)</sup> to sort the `JobDetails` vector in ascending order based on the `distance` field.

### Notes:

This function does not care if the input vectors (`tool_a` and `tool_b`) have the same size.
The function uses fixed values for tool IDs and types. These values can be modified based on specific requirements.

### Documentation

###### Function Signature
```C++
merge_and_sort(const std::vector<uint16_t> &tool_a, const std::vector<uint16_t> &tool_b)
``` 

###### Header Files

- `<algorithm>` → Provides the `std::sort` algorithms
- `<vector>` → Provides functionality for working with dynamically-sized vectors
- `<iostream>` → Provides input/output functionality (used in main for printing)

###### Type Definitions

- `JobDetails` → `struct` representing a job with the following fields:
    - `distance` → The distance associated with the job ( `uint16_t` )
    - `tool_id` → The ID of the array associated with the job ( `uint16_t` )
    - `tool_type` → The type of the tool associated with the job ( `uint16_t` )

###### Function Parameters

- `tool_a` → A constant reference to a `std::vector<uint16_t>` containing distances for tool A.
- `tool_b` → A constant reference to a `std::vector<uint16_t>` containing distances for tool B.

###### Return Value

- `std::vector<JobDetails>` → contains the merged and sorted job details. Jobs are sorted by `distance` in ascending order.

### Complexity

The time complexity of this function is `O(n log n)`, where n is the total number of elements in both input vectors `tool_a` and `tool_b`. This is because the function first iterates through the elements of both input vectors to create the `jobs` vector, which has a time complexity of `O(n)`. Then, it sorts the `jobs` vector using `std::sort`, which has a time complexity of `O(n log n)` in the worst case scenario.

The space complexity of this function is `O(n)`, where `n` is the total number of elements in both input vectors `tool_a` and `tool_b`. This is because the function creates a new vector jobs to store the merged and sorted job details, which can potentially contain all the elements from both input vectors. <sup>[[5]](https://www.bigocalc.com/)</sup>

### References

###### compare_distance
``` C++
bool compare_distance(const JobDetails &job_a, const JobDetails &job_b) {
  return job_a.distance < job_b.distance;
}
```