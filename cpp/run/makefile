
MAIN_NAME = test.cpp

OBJ_DIR = /home/nikhil/GITHUB/gitrepo/cpp/objs
EXE_DIR = /home/nikhil/GITHUB/gitrepo/cpp/out
OBJS = $(wildcard $(OBJ_DIR)/*.o)

#
# $^ = dependency list
# $@ = target list
# $< = first dependent
# $? = list of changed dependents
#

#$(OBJ_DIR)/%.o: %.cpp g++ -c -I../inc $? $(OBJ_DIR)/$(patsubst $?, %.o, $(wildcard *.cpp))

.cpp.o:
	g++ -g -c -I../inc $< -o $(OBJ_DIR)/$(subst .cpp,.o,$<)

.cxx.o:
	g++ -g -c -I../inc $< -o $(OBJ_DIR)/$(subst .cpp,.o,$<)

$(EXE_DIR)/exe: $(OBJS) $(MAIN_NAME)
	g++ -g -I../inc -o $@ $^
