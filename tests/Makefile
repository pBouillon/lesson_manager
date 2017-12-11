CXX  	 :=  g++
CXXFLAGS := -g -L/opt/gtest/lib -lgtest -lgtest_main -lpthread
INCS	 := -I../src/it_3/header/ -I/opt/gtest/include
EXEC     := tests
TEST     := users_tests.cpp
OBJ 	 := ../src/it_3/users/admin.o\
			../src/it_3/users/person.o\
			../src/it_3/users/student.o\
			../src/it_3/users/teacher.o

testAll: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCS) -o $(EXEC) $(TEST) $^

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm $(EXEC) *.o

