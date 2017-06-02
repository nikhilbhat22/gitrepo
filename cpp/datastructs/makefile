
OBJS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
$(info objs= $(OBJS))

OBJ_DIR = /home/nikhil/GITHUB/gitrepo/cpp/libs
$(info $(OBJ_DIR))

$(OBJ_DIR)/%.o: %.cpp
		g++ -c -I../inc $^ 

exe: $(OBJ_DIR)/*.o
		g++ -o $@ $^

