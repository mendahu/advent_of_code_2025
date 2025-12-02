# Default compiler and flags
CXX := "clang++"
CXXFLAGS := "-std=c++17 -Wall -g"

# Build solution for a specific day
# Usage: just build 01 a
build DAY PART:
    {{CXX}} {{CXXFLAGS}} solutions/{{DAY}}/{{PART}}.cpp -o solutions/{{DAY}}/{{PART}}

# Run with test input
# Usage: just test 01 a
test DAY PART:
    just build {{DAY}} {{PART}}
    ./solutions/{{DAY}}/{{PART}} < inputs/{{DAY}}/test.txt

# Run with actual data
# Usage: just run 01 b
run DAY PART:
    just build {{DAY}} {{PART}}
    ./solutions/{{DAY}}/{{PART}} < inputs/{{DAY}}/data.txt

# Clean all compiled binaries
clean:
    find solutions -type f ! -name "*.cpp" ! -name "*.h" -delete