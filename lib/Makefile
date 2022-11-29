##
## EPITECH PROJECT, 2022
## B-CPE-110-LYN-1-1-BSQ-mael.rabot
## File description:
## Makefile
##

SRC	=	$(wildcard ./*.c)

OBJ	=	$(SRC:.c=.o)

LIB	=	libmy.a

all:	$(LIB)

$(LIB):	$(OBJ)
	ar rc $(LIB) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIB)
	rm -f *.out

re: fclean all
