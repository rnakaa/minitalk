# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:56:25 by rnaka             #+#    #+#              #
#    Updated: 2023/01/18 21:59:26 by rnaka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS1	= server.c \
		  libft.c  

SRCS2	= client.c \
		  libft.c

OBJS1	=	$(SRCS1:.c=.o)
OBJS2	=	$(SRCS2:.c=.o)

CC	= cc

CFLAGS			= -Wall -Wextra -Werror

NAME1	= server
NAME2	= client

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

all:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJS1)
		$(CC) $(CFLAGS) -o $@ $(OBJS1)

$(NAME2):	$(OBJS2)
		$(CC) $(CFLAGS) -o $@ $(OBJS2)

clean:	
		rm -f $(OBJS1) $(OBJS2)

fclean:		clean
		rm -rf $(NAME1) $(NAME2)

re:		fclean all

.PHONY:	all clean fclean re
