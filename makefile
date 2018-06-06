#Makefile for Kyle Garland
#This makefile was created with the help of the rooker lecture under the makefile module
#and also from the TA's makefile example.
#References were also pulled from https://www.gnu.org/software/make/manual/make.pdf
#and also from ftp://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_2.html
#This is the makefile for Lab1 - created on 4/8/2018

#changes made
#executable file
EXEC = Proj4

#Zip file
ZIP = ${EXEC}_Garland_Kyle

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

#Valgrind commands for debugging and memory leaks
VALG = --leak-check=full
VALG += --tool=memcheck
VALG += --show-leak-kinds=all
VALG += --track-origins=yes

#source files
SRCS = main.cpp
SRCS += Vampire.cpp
SRCS += BlueMen.cpp
SRCS += Medusa.cpp
SRCS += HarryPotter.cpp
SRCS += Barbarian.cpp
SRCS += Fight.cpp
SRCS += Character.cpp
SRCS += CharacterList.cpp
SRCS += Util.cpp

#header files
HEADERS = Util.hpp
HEADERS += Vampire.hpp
HEADERS += Medusa.hpp
HEADERS += BlueMen.hpp
HEADERS += Barbarian.hpp
HEADERS += Fight.hpp
HEADERS += Character.hpp
HEADERS += CharacterList.hpp
HEADERS += HarryPotter.hpp

#objects
OBJS = $(SRCS:.cpp=.o)

#target: dependencies
#     rule to build

${EXEC}: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o $@

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

debug:
	valgrind $(VALG) ./$(EXEC)

#zip file
zip:
	zip -D $(ZIP) Proj4_Garland_Kyle *.cpp *.hpp *.pdf *makefile

#clean
clean:
	rm ${OBJS} ${EXEC}

