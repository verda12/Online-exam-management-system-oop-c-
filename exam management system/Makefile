CXX      = g++
CXXFLAGS = -std=c++11 -Wall
TARGET   = ExamSystem
SRCDIR   = src
SOURCES  = main.cpp \
           $(SRCDIR)/Question.cpp \
           $(SRCDIR)/Exam.cpp \
           $(SRCDIR)/Student.cpp \
           $(SRCDIR)/GradingEngine.cpp \
           $(SRCDIR)/FileManager.cpp \
           $(SRCDIR)/ExamBank.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)
	@echo "Build successful! Run with: ./$(TARGET)"

clean:
	rm -f $(TARGET) $(TARGET).exe
	rm -rf data/

.PHONY: all clean
