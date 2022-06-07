CC = gcc
target = app
outfile = ./build/
src = ./
functions = ./function/
temp = ./tmp/
lib = -ljson-c -lcurl
# CFLAGS = -I $(src)include -L $(src)include -libtar
# wildcard 滿足條件的全部展開 patsubst 為 a -> b
src1 = $(wildcard ./function/*.c)
src2 = $(wildcard ./*.c)
# src3 = $(wildcard ./extend/*.c)
obj1 = $(patsubst %.c,%.o,$(src1))
obj2 = $(patsubst %.c,%.o,$(src2))
# obj3 = $(patsubst %.c,%.o,$(src3))


# 在build內產生app
$(target):$(obj1) $(obj2) 
	$(CC) $(CFLAGS) $(lib) $(src)include/libtar.a $^ -o $(outfile)$@ 
# gcc $(obj1) $(obj2) -o $(target)

# 編譯主目錄下所有.c成.o
%.o:%.c
	$(CC) -I ./include -c $< -o $@
# 編譯function下所有.c成.o
$(functions)%.o:$(functions)%.c
	$(CC) $(lib) -c $< -o $@

# .PHONY 為定義Makefile中的指令
.PHONY:run,clean 
# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

run:
	@./$(outfile)$(target) $(RUN_ARGS)
clean:
	@-rm -f $(outfile)$(target) $(obj1) $(obj2) $(obj3)