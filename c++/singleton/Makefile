obj=singleton

$(obj):main.o singleton.o
	g++ $< -o $@

%.o:%.cpp
	g++ -c $< -o $@
