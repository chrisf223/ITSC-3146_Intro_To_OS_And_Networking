all: Assignment_3_2

clean:
	rm -f *~ *.o Assignment_3_2 Assignment_3_2.zip 
	clear

Assignment_3_2: Assignment_3_2.o Processes.o
	g++ -o $@ $^

.cpp.o:
	g++ -c $(GCC_OPTIONS) -o $@ $(CCFLAGS) $<

#This target prepares a zip file with the student’s submisison
#Note: Only works on MacOS or Linux
submit:
	zip -j Assignment_3_2.zip Assignment_3_2.cpp Processes.cpp Processes.h
