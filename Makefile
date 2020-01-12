all:
	@clang libmx/libmx.a src/*.c
lib:
	@make -C ./libmx