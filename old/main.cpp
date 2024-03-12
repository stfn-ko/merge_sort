#include <iostream>

const uint16_t Job_DistRow = 0;
const uint16_t Job_ToolRow = 1;
const uint16_t Job_ToolTypeRow = 2;
const uint16_t Tool1_Type = 5;
const uint16_t Tool2_Type = 6;
const uint16_t Tool_Empty = 0;
const uint16_t array_Size = 5;

uint16_t array_X[10][3] = {0};
uint16_t array_A[5] = {10, 50, 15, 30, 80};
uint16_t array_B[5] = {40, 30, 10, 70, 0};

uint16_t index;
uint16_t PosIndex = 0;
uint16_t array_ID = 0;
uint16_t positionValue = 0;
uint16_t positionIndex = 0;
uint16_t byToolType = 0;
uint16_t JobSize = 0;

bool analyseData = true;

int main() {
  while (analyseData) {
    positionIndex = 0;
    positionValue = 0xFFFF;
    byToolType = Tool_Empty;
    array_ID = 0;

    for (index = 0; index < array_Size; index++) {
      if (array_A[index] != 0) {
        if (array_A[index] < positionValue) {
          positionValue = array_A[index];
          array_ID = 1;
          byToolType = Tool1_Type;
          positionIndex = index;
        }
      }
      if (array_B[index] != 0) {
        if (array_B[index] < positionValue) {
          positionValue = array_B[index];
          array_ID = 2;
          byToolType = Tool2_Type;
          positionIndex = index;
        }
      }
    }

    if (array_ID != 0) {
      array_X[positionIndex][Job_DistRow] = positionValue;
      array_X[positionIndex][Job_ToolRow] = array_ID;
      array_X[positionIndex][Job_ToolTypeRow] = byToolType;

      printf("%d, %d, %d\n", positionValue, array_ID, byToolType);

      switch (array_ID) {
        case 1:
          array_A[positionIndex] = 0;
          break;
        case 2:
          array_B[positionIndex] = 0;
          break;
      }

      PosIndex++;
      JobSize = PosIndex;
    } else {
      analyseData = false;
      JobSize--;
    }
  }
}