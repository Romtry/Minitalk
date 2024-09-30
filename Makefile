# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 13:22:24 by rothiery          #+#    #+#              #
#    Updated: 2024/09/30 16:50:11 by rothiery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT=		client
SERVER=		server

SRC_C= 		src/client.c			\
SRCS_S=		src/server.c			\
SRC_UTILS=	src/utils/mini_utils.c	\

OFILESSRV= 	${SRCS_S.c=.o} ${SRC_UTILS:.c=.o}
OFILESC= 	${SRC_C.c=.o} ${SRC_UTILS:.c=.o}

CC= 	cc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g3 -I includes

RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m

ORANGE = \033[38;5;216m
DARKBLUE = \033[38;5;21m
RED = \033[38;5;130m
DARK_RED = \033[38;5;88m
GREEN = \033[38;5;85m

NBR_TOT_FICHIER=5

FICH_COUNT = 0
NBR_COMPILER = ${shell expr 100 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
BAR =  ${shell expr 23 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
REST = ${shell expr 23 - ${BAR}}

all:		${SERVER} ${CLIENT}

${SERVER}:	${OFILESSRV}
			@${CC} ${CFLAGS} ${OFILESSRV} -o ${SERVER}
			@echo "\n\n${GREEN} [✓] - ${_GREEN}server${GREEN} Successfully Compiled!${RESET}"

${CLIENT}:	${OFILESC}
			@${CC} ${CFLAGS} ${OFILESC} -o ${CLIENT}
			@echo "\n\n${GREEN} [✓] - ${_GREEN}client${GREEN} Successfully Compiled!${RESET}"

%.o:%.c
	@${eval FICH_COUNT = ${shell expr ${FICH_COUNT} + 1}}
	@${CC} ${CFLAGS} -c -I . $< -o $@
	@file_name=$(notdir $<) && \
	echo " ${GRAS}${RED}-> COMPILING${RESET}${GRAS}${GREEN}${RESET}" && \
	printf " ${RED}${GRAS}[${GREEN}%-.${BAR}s${DARK_RED}%-.${REST}s${RED}] [%d/%d (%d%%)] ${GREEN}%s  ✓                         ${DEF_COLOR}" "-----------------------" "-----------------------" ${FICH_COUNT} ${NBR_TOT_FICHIER} ${NBR_COMPILER} $${file_name} && \
	echo "${UP}${UP}${UP}" && \
	echo ""

clean:
	@rm -rf *.o
	@echo "${ORANGE}${GRAS}\tNETTOYAGE${RESET}"
	@echo "${RED}${ITALIQUE} -files successfully removed${RESET}"

fclean:	clean
	@rm -f ${NAME}
	@${RM} ${NAME}
	@echo "${RED}${ITALIQUE} -${NAME} is removed${RESET}"

re:	fclean all

.PHONY:		all server client clean fclean re