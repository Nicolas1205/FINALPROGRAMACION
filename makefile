SOURCES := $(wildcard ./src/*.cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))
DEPENDS := $(patsubst %.cpp, %.d, $(SOURCES))

WARNING := -Wall -Wextra

.PHONY: all clean 

all: app

clean:
	$(RM) $(OBJECTS) $(DEPENDS) app

app: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

-include $(DEPENDS)

%.o: %.cpp MakeFile
	${CXX} $(WARNING) $(CXXFLAGS) -MMD -MP -c $< -o $@
