#!/bin/bash

COMPILER="$(realpath "$(dirname "$0")./k0")"
TEST_DIR="$(realpath "$(dirname "$0")/k0")"
KOTLIN_TEST_DIR="$(realpath "$(dirname "$0")/kotlin")"
ERROR_TEST_DIR="$(realpath "$(dirname "$0")/errors")"
OUTPUT_FILE="$(realpath "$(dirname "$0")/output.log")"

> "$OUTPUT_FILE"

if [[ ! -d "$TEST_DIR" ]]; then
    echo "Error: Test directory '$TEST_DIR' does not exist!" | tee -a "$OUTPUT_FILE"
    exit 1
fi
if [[ ! -d "$KOTLIN_TEST_DIR" ]]; then
    echo "Error: Test directory '$KOTLIN_TEST_DIR' does not exist!" | tee -a "$OUTPUT_FILE"
    exit 1
fi
if [[ ! -d "$ERROR_TEST_DIR" ]]; then
    echo "Error: Test directory '$ERROR_TEST_DIR' does not exist!" | tee -a "$OUTPUT_FILE"
    exit 1
fi
# Run compiler on each test file
for TEST_FILE in $TEST_DIR/*.kt; do
    if [[ -f "$TEST_FILE" ]]; then
        echo "Running test: $TEST_FILE" | tee -a "$OUTPUT_FILE"
        "$COMPILER" "$TEST_FILE" >> "$OUTPUT_FILE" 2>&1
        echo "----------------------------------" | tee -a "$OUTPUT_FILE"
    fi
done
for TEST_FILE in $KOTLIN_TEST_DIR/*.kt; do
    if [[ -f "$TEST_FILE" ]]; then
        echo "Running test: $TEST_FILE" | tee -a "$OUTPUT_FILE"
        "$COMPILER" "$TEST_FILE" >> "$OUTPUT_FILE" 2>&1
        echo "----------------------------------" | tee -a "$OUTPUT_FILE"
    fi
done
for TEST_FILE in $ERROR_TEST_DIR/*.kt; do
    if [[ -f "$TEST_FILE" ]]; then
        echo "Running test: $TEST_FILE" | tee -a "$OUTPUT_FILE"
        "$COMPILER" "$TEST_FILE" >> "$OUTPUT_FILE" 2>&1
        echo "----------------------------------" | tee -a "$OUTPUT_FILE"
    fi
done
echo "all tests completed. Output saved in $OUTPUT_FILE"
