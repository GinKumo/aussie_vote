CXX        := g++-4.8
CXXFLAGS   += -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f AussieVote
	rm -f AussieVote.tmp
	rm -f TestAussieVote
	rm -f TestAussieVote.tmp

config:
	git config -l

scrub:
	make  clean
	rm -f  AussieVote.log
	rm -rf collatz-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: AussieVote.tmp TestAussieVote.tmp

AussieVote: AussieVote.h AussieVote.c++ RunAussieVote.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) AussieVote.c++ RunAussieVote.c++ -o AussieVote

AussieVote.tmp: AussieVote
	./AussieVote < AussieVote.in > AussieVote.tmp
	diff AussieVote.tmp AussieVote.out

TestAussieVote: AussieVote.h AussieVote.c++ TestAussieVote.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) AussieVote.c++ TestAussieVote.c++ -o TestAussieVote $(LDFLAGS)

TestAussieVote.tmp: TestAussieVote
	$(VALGRIND) ./TestAussieVote                                       >  TestAussieVote.tmp 2>&1
	$(GCOV) -b AussieVote.c++     | grep -A 5 "File 'AussieVote.c++'"     >> TestAussieVote.tmp
	$(GCOV) -b TestAussieVote.c++ | grep -A 5 "File 'TestAussieVote.c++'" >> TestAussieVote.tmp
	cat TestAussieVote.tmp
