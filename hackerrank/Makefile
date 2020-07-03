CXXFLAGS = -Wall -Wextra
CXX = clang++

solution: solution.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

test: solution
	@expected="$(shell cat output.txt)"; \
	got="$(shell export OUTPUT_PATH=/dev/stdout; cat input.txt | ./$^)"; \
	test "$$expected" = "$$got" && \
	echo "\e[32mPass!\e[0m" || (echo "\e[31mFail! Expected $$expected, got $$got\e[0m" && exit 1)
