CXX = g++
CXXFLAGS = -O3 -DLOCAL -std=c++20 -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow -Wno-unused-result -Wno-sign-conversion
TARGET = main
SRC = main.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -rf $(TARGET)