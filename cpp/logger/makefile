
OBJS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
OBJ_DIR = /home/nikhil/GITHUB/gitrepo/cpp/objs

#
# $^ = dependency list
# $@ = target list
# $< = first dependent
# $? = list of changed dependents
#

#$(OBJ_DIR)/%.o: %.cpp g++ -c -I../inc $? $(OBJ_DIR)/$(patsubst $?, %.o, $(wildcard *.cpp))

.cpp.o:
	g++ -c -I../inc $< -o $(OBJ_DIR)/$(subst .cpp,.o,$<)

.cxx.o:
	g++ -c -I../inc $< -o $(OBJ_DIR)/$(subst .cxx,.o,$<)

$(OBJ_DIR)/exe: $(OBJ_DIR)/$(OBJS)
	$(info not creating executables)
