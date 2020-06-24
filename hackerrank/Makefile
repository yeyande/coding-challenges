CXXFLAGS = -Wall -Wextra
CXX = clang++

solution: solution.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

test: solution
	@expected="$(shell cat output.txt)"; \
	got="$(shell export OUTPUT_PATH=/dev/stdout; cat input.txt | ./$^)"; \
	test "$$expected" = "$$got" && \
	echo "Pass!" || (echo "Fail! Expected $$expected, got $$got" && exit 1)
