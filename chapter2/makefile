objects = main.o string.o little_endian.o union_intersection.o union_intersection_advance.o swap.o switch.o
vpath %.c source
vpath %.h header
#VPATH = source:header

# 指令后面要有tab键，clean用于在命令行中输入make clean，.o文件自动推到同名的.c文件及cc命令
main : $(objects)
	cc -o main $(objects)
main.o : string.h union_intersection.h union_intersection_advance.h swap.h
#	cc -c source/main.c -I header/
string.o : little_endian.h
little_endian.o :
union_intersection.o :
union_intersection_advance.o :
swap.o : switch.h
switch.o :

.PHONY : clean
clean :
	rm  main $(objects)