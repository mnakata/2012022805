all: a.out

test: test0

test-all: test0 test1 test2 test3

test0: .a0.txt
	diff examples/a0.txt .a0.txt

test1: .a1.txt
	diff examples/a1.txt .a1.txt

test2: .a2.txt
	diff examples/a2.txt .a2.txt

test3: .a3.txt
	diff examples/a3.txt .a3.txt

.a0.txt: a.out examples/q0.txt
	time ./$< < examples/q0.txt | tee $@

.a1.txt: a.out examples/q1.txt
	time ./$< < examples/q1.txt | tee $@

.a2.txt: a.out examples/q2.txt
	time ./$< < examples/q2.txt | tee $@

.a3.txt: a.out examples/q3.txt
	time ./$< < examples/q3.txt | tee $@

a.out: main.cc
	$(CXX) -o $@ $<

main.cc: main1.cc
	ln -s -f $< $@

clean:
	$(RM) *~

distclean: clean
	$(RM) main.cc
	$(RM) a.out
	$(RM) .a*.txt
