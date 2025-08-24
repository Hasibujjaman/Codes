#
# Make the Xinu configuration program
#

COMPILER_ROOT = /opt/homebrew/Cellar/gcc/14.2.0_1/bin/
FLEX_ROOT = /opt/homebrew/Cellar/flex/2.6.4_2/bin
BISON_ROOT = /opt/homebrew/Cellar/bison/3.8.2/bin/

CC	= ${COMPILER_ROOT}gcc-14
LEX	= ${FLEX_ROOT}/flex
YACC	= ${BISON_ROOT}bison -y	# Flag enables yacc-compatible filenames
CFLAGS	= 
LFLAGS	= -L/opt/homebrew/Cellar/flex/2.6.4_2/lib -lfl 


#
# Name of the configuration program
#

CONFIG	= config

all:		conf.h conf.c

${CONFIG}:	lex.yy.c y.tab.c
		$(CC) ${CFLAGS} -o $@ y.tab.c ${LFLAGS}

lex.yy.c:	config.l
		$(LEX) config.l

y.tab.c:	config.y
		@(if test "x$$LOGNAME" = "xxinu"; then			\
		       echo "extern	int	yyleng;";		\
		  else echo "extern	int	yyleng;"; fi) > .yyleng
		$(YACC) config.y
	
clean:
		rm -f config lex.yy.c y.tab.c

conf.h:		config Configuration
		./config Configuration conf.c conf.h

conf.c:		config Configuration
		./config Configuration conf.c conf.h

install:	conf.h conf.c
		cp -p conf.h ../include
		cp -p conf.c ../system
