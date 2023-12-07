#include "jjuggumi.h"
#include "canvas.h"
#include "keyin.h"
#include <stdio.h>

void map_init_jul(int n_row, int n_col) {
	
	for (int i = 0; i < ROW_MAX; i++) {
		for (int j = 0; j < COL_MAX; j++) {
			back_buf[i][j] = front_buf[i][j] = ' ';
		}
	}

	N_ROW = n_row;
	N_COL = n_col;
	for (int i = 0; i < N_ROW; i++) {
		
		back_buf[i][0] = back_buf[i][N_COL - 1] = '#';
		

		for (int j = 1; j < N_COL - 1; j++) {
			if (j == 14) {
				back_buf[i][j] = ' ';
			}
			else if (i == 0 || i == N_ROW - 1) {
				back_buf[i][j] = '#';
			}
			else {
				back_buf[i][j] = ' ';
			}
		}
		
	}

}
double total_str() {
	double total = 0.0;
	for (int i = 0; i < n_player; i++) {
		if (i % 2 == 0) {
			total -= player[i].str;
		}
		else {
			total += player[i].str;
		}
		
	}
	return total;
}
void juldarigi() {
	
	
	map_init_jul(3, 30);
	display();
	double t_str = total_str();
	while (1) {
		
		gotoxy(5, 0);
		printf("str:   %.1lf", t_str);
		key_t key = get_key();
		if (key == K_QUIT) {
			break;
		}
		else if (key == K_JULRT) {
			t_str += 1.0;
			gotoxy(5, 0);
			printf("str:   %.1lf", t_str);
			
			
		}
		else if (key == K_JULLT) {
			t_str -= 1.0;
			gotoxy(5, 0);
			printf("str:   %.1lf", t_str);
			
			
		}
		if (tick >= 300) {
			t_str = total_str();
			tick = 0;
		}
		
	}
	
	

}

