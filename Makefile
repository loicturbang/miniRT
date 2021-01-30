UTILS = $(addprefix srcs/utils/, get_next_line_utils.c get_next_line.c utils1.c utils2.c utils3.c utils4.c)
PARSING = $(addprefix srcs/parsing/, parsing.c parsing1.c parsing2.c parsing3.c parsing_utils.c)
VECTOR = $(addprefix srcs/vector/, vector_utils1.c vector_utils2.c vector_utils3.c rot.c rot_cy.c)
RAYTRACING_INTERSECT = $(addprefix srcs/raytracing/intersect/, intersect_sp.c intersect_tr.c intersect_pl.c intersect_sq.c intersect_cy.c)
RAYTRACING_COLOR = $(addprefix srcs/raytracing/color/, get_color.c color_utils.c)
RAYTRACING = $(addprefix srcs/raytracing/, ray_tracing1.c ray_tracing2.c)
BMP = $(addprefix srcs/bmp/, save_img.c)
SRCS_PATH = $(addprefix srcs/, window.c main.c)

SRCS	= 	$(PARSING)					\
			$(UTILS)					\
			$(VECTOR)					\
			$(RAYTRACING_INTERSECT) 	\
			$(RAYTRACING_COLOR) 		\
			$(RAYTRACING) 				\
			$(BMP) 						\
			$(SRCS_PATH) 				\

INCL	= 	./includes/


OBJS	= 	${SRCS:.c=.o}

NAME	= 	miniRT

CC		= 	gcc

RM		= 	rm -f

CFLAGS = 	-Wall -Wextra -Werror -I ${INCL}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C mlx
			${CC} -o ${NAME} ${OBJS} -Lmlx -lmlx -lXext -lX11 -lm	

all:		${NAME}

clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all bonus
