CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = main
SRCS = SoPhuc.cpp main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
