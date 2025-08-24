CXX = c++
CXXFLAGS = -std=gnu++14 -arch arm64 -mmacosx-version-min=14.1
LDFLAGS = -lpthread /usr/local/lib/libgtest_main.a /usr/local/lib/libgtest.a
SRC = $(f).cpp
OUT = $(f)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)