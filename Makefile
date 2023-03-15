first_lab:
	gcc -Wall -Werror -Wextra 1-st\ lub/source.c 1-st\ lub/dynamic_stack.c -o first_lab -lm
second_lab:
	gcc -Wall -Werror -Wextra 2-nd\ lab/main.c 2-nd\ lab/menu.c 2-nd\ lab/static_queue.c -o second_lab -lm
third_lab:
	gcc -Wall -Werror -Wextra 3-rd_lab/main.c 3-rd_lab/dynamic_queue.c 3-rd_lab/menu.c -lncurses -o third_lab -lm
fourth_lab:
	gcc -Wall -Werror -Wextra 4-th_lab/main.c 4-th_lab/menu.c 4-th_lab/linked_list.c -o fourth_lab -lm
fifth_lab:
	gcc -Wall -Werror -Wextra 5-th_lab/main.c 5-th_lab/menu.c 5-th_lab/linked_point_list.c -o fifth_lab -lm
clean:
	rm -rf first_lab
	rm -rf second_lab
	rm -rf third_lab
	rm -rf fourth_lab
	rm -rf fifth_lab
