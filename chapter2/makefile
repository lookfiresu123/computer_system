objects = main.o string.o little_endian.o

# 指令后面要有tab键，clean用于在命令行中输入make clean
main : $(objects)
	cc -o main $(objects)
main.o : main.c string.h
	cc -c main.c
string.o : string.c little_endian.h
	cc -c string.c
little_endian.o : little_endian.c
	cc -c little_endian.c
	
.PHONY : clean
clean :
	rm  main $(objects)