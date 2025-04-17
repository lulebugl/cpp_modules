#!/bin/bash

PROGRAM="./baby-sed"
TEST_DIR="test_sed_tmp"
mkdir -p $TEST_DIR

echo "Creating large test file..."

dd if=/dev/urandom bs=1M count=10 2>/dev/null | base64 > "$TEST_DIR/large_file.txt" #bs=1 = 10mb

echo "File created. Size: $(du -h "$TEST_DIR/large_file.txt" | cut -f1)"

cp "$TEST_DIR/large_file.txt" "$TEST_DIR/expected_large.txt"
if [[ "$(uname)" == "Darwin" ]]; then
    sed -i '' 's/Ar/Xp/g' "$TEST_DIR/expected_large.txt"
else
    sed -i 's/Ar/Xp/g' "$TEST_DIR/expected_large.txt"
fi

echo "Running program..."
time $PROGRAM "$TEST_DIR/large_file.txt" "Ar" "Xp"

echo "Checking results..."
diff "$TEST_DIR/large_file.txt.replace" "$TEST_DIR/expected_large.txt" | head -n 10 > "$TEST_DIR/diff.txt"
if [ $? -eq 0 ]; then
    echo "SUCCESS: Output file matches expected result"
else
    echo "FAILURE: Output does not match expected result"
    
    ORIG_COUNT=$(grep -o "Ar" "$TEST_DIR/large_file.txt" | wc -l)
    REPLACED_COUNT=$(grep -o "Xp" "$TEST_DIR/large_file.txt.replace" | wc -l)
    EXPECTED_COUNT=$(grep -o "Xp" "$TEST_DIR/expected_large.txt" | wc -l)
    
    echo "Original 'Ar' count: $ORIG_COUNT"
    echo "Your output 'Xp' count: $REPLACED_COUNT"
    echo "Expected 'Xp' count: $EXPECTED_COUNT"

fi

echo "Cleaning up..."
rm -rf $TEST_DIR
echo "Test completed."