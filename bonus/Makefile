##
## Makefile for  in /home/belfio_u/rendu/CPE_2014_bsq
## 
## Made by ugo belfiore
## Login   <belfio_u@epitech.net>
## 
## Started on  Mon Dec 15 18:13:01 2014 ugo belfiore
## Last update Sat Jan 17 14:19:51 2015 ugo belfiore
##

SRC     =       main.c			\
		evenement.c		\
		aff_pix_img.c		\
		my_str_to_wordtab_bsq.c \
		aff_bsq.c		\
		aff_bsq_carre.c		\
		bsq_nobrute.c

OBJ     =       $(SRC:.c=.o)

NAME    =       bsq

LIB     =       lib/my/libmy.a

LIBMINI =	lib/minilibx/libmlx.a

CC      =       gcc

CFLAGS  +=      -W -Wall -Wextra

LIB2	=	-L/usr/lib64/X11 -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIB) $(LIBMINI) $(LIB2)

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re: fclean all
