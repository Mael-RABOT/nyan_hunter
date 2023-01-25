##
## EPITECH PROJECT, 2022
## B-CPE-101-LYN-1-1-myls-mael.rabot
## File description:
## Makefile
##

SRC	=	$(wildcard ./*.c)

NAME	=	my_hunter

FLAG = -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(SRC) cpl
	gcc -o $(NAME) $(SRC) -L./lib/ -lmy $(FLAG)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.out

cpl:
	cd lib && make && make clean && cd ..

re: cpl fclean all

run: re
	./my_hunter
