SERVER 		= 	./server/
CLIENT 		= 	./client/
GCLIENT		= 	./Gclient/

S_NAME		=	zappy_server
G_NAME		=	zappy_Gclient
C_NAME 	  	=	zappy_ai

all:		pre-build $(S_NAME) $(C_NAME) $(G_NAME)


pre-build:	
		@echo "Start compilation of $(S_NAME) $(G_NAME) $(C_NAME)"
		@echo "Options :"
		@echo -e "\tCXXFLAGS:\t$(CXXFLAGS)"
		@echo -e "\tCFLAGS:\t$(CFLAFS)"
		@echo -e "\tLDFLAGS:\t$(LDFLAGS)"
		@echo "Start objects compilation."

server:		$(S_NAME)

gclient:	$(G_NAME)

client:		$(C_NAME)

$(S_NAME):
		$(MAKE) -C $(SERVER)
		cp $(SERVER)zappy_server .

$(G_NAME):
		$(MAKE) -C $(GCLIENT)
		cp $(GCLIENT)zappy_Gclient .

$(C_NAME):
		$(MAKE) -C $(CLIENT)
		cp $(CLIENT)zappy_ai .

clean:
		$(MAKE) -C $(CLIENT) clean
		$(MAKE) -C $(GCLIENT) clean
		$(MAKE) -C $(SERVER) clean

fclean: 	clean
		rm -f $(S_NAME) $(G_NAME) $(C_NAME)

re:		fclean all

shlag:		CFLAGS += -Wpedantic -Wshadow -Werror
shlag:		re
