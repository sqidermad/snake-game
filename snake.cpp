// boolean jika input kiri ,kiri true , kanan false//solved
//sort high score masih error //solved
// limited track / bisa di reset, dipindahin jarak terentu ke 0 lagi// solved
//low resp//
//system mode// ubah.
//sebelum main getchar buat apus inputan awal// solved

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


#define A 25  //25
#define B 25
#define C 50 //100
#define UP 0x48
#define RIGHT 0x4D
#define LEFT 0x4B
#define DOWN 0x50
#define ENTER 0xD
#define TRACK 10000

FILE *hig;

struct high{
	char name[100];
	int scr;
};

int dir = 3;
int x = 5,y =5;
int z = 1; 
int snake_length = 5;
int foodcount =1;
int foodx=7,foody = 7;
int score =0;
int flag = -1;
int flagx[TRACK] = {};
int flagy[TRACK] = {};
int cnt = 1;
int count11 = 0;
int cnt20 = 0;

void validasi();
void move (char a[A][B]);
void moveatas (char a[A][B]);
void movebwh (char a[A][B]);
void movekiri (char a[A][B]);
void food(char a[A][B]);
void home();
void menu ();
void loading();
void aftere();
void read();
void write();
void news();
void highscore();
void how();
void credit();
void rest();

void rest(){

	for(int i=0;i<snake_length;++i){
		flagx[i] = flagx[cnt-snake_length+i];
		flagy[i] = flagy[cnt-snake_length+i];
 	}
	cnt = snake_length;

}

void credit(){

	printf("Special Thanks to...\n\n");
	printf("Jesus Christ \n\n");
	printf("\n");
	printf("\n");
	//special thanks to ..
	//
	printf("\n\n\n");

	printf("");
	system("pause");

}

void how(){
	
		printf("\t\t\r        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("\t\t\r        %c        HOW-TO-PLAY         %c\n",186,186);
		printf("\t\t\r        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,189);
		
		printf("\n\n     1.Press the arrow button to move the snake\n       (up,down,left,right).\n\n");
		printf("     2.Don't touch the wall.\n\n");
		printf("     3.Eat the food provided, not your own body.\n\n\n");
		printf("             ---Happy Eating---\n\n");
		
	
}

void highscore(struct high high[100]){
	struct high temp;
	
		printf("\r %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("\r %c         HIGH SCORE         %c\n",186,186);
		printf("\r %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,189);
		
		
			for(int i =0;i<count11;++i){
			printf("       %-10s....%3d\n",high[i].name,high[i].scr);
			
			}
			printf("\n\n");
}

void news(char a[A][B]){
	
	for (int i =0 ;i<A;++i){
	for (int j =0;j<B;++j){
     	a[i][j]= '\0';
     
	}
	//	printf("a");
	}
	snake_length = 5;
		z = 1;
		x = 5;
		y = 5;
		score=0;
		foodcount =1;
		foodx=7;
		foody = 7;
		score =0;
		flag = -1;
		dir =3;
		cnt20 = 0;
		
		for (int i =0;i<TRACK;++i){
		flagx[i] = 0;
		flagy[i] = 0;
	}
        cnt = 1;

}

void aftere(int *fflag){

	static char quitOpsi[2][10] = {("  Yes  "),("  No  ")};
	char ch;

	*fflag = -1;
	quitOpsi[0][0] = '\0';
	quitOpsi[0][7] = '\0';
	quitOpsi[1][0] = '\0';
	quitOpsi[1][7] = '\0';

	for(;;){
	system("cls");
	 printf("\n\n\n");
	printf("\t\t   Are you sure : \n\n");

	for(int i=0; i<2 ;++i){
		printf("\t\t  ");
		for(int j=0;j<10;++j){
			printf("%c",quitOpsi[i][j]);
		}
		puts("");
		puts("");
	}
	printf("\n\n\t   Press enter to select, arrow to move ");


		ch = getch();
		if(ch == UP){
			if (*fflag >0){
				--(*fflag);
			} 
			quitOpsi[*fflag][0] = '-';
			quitOpsi[*fflag][7] = '-';
			quitOpsi[*fflag+1][0] = '\0';
			quitOpsi[*fflag+1][7] = '\0';
		}else if ( ch == DOWN){
			if(*fflag<1){
				++(*fflag);
			}
			quitOpsi[*fflag][0] = '-';
			quitOpsi[*fflag][7] = '-';
			quitOpsi[*fflag-1][0] = '\0';
			quitOpsi[*fflag-1][7] = '\0';
		}

		if(ch == ENTER){
			if (*fflag == 0){
			*fflag = 0;
			return;
			}
			else {
				*fflag = 1;
				return;
			}
		}
	}
}

void read(struct high high[100]){

	count11 = 0;
		hig = fopen("high.txt","r");
	if (hig == NULL){
		printf("data tidak ditemukan");
	}else{
	while(!feof(hig)){
		fscanf(hig,"%[^-]-%d\n",&high[count11].name,&high[count11].scr);
		count11 = count11 +1;
	}
	
	fclose(hig);
}
}

void write(struct high high[100],int count11){
	hig = fopen("high.txt","w");
	
	for(int i =0 ;i<count11;++i){
		fprintf(hig,"%s-%d\n",high[i].name, high[i].scr);
	}
	
	fclose(hig);
}

void loading(){
char snake[5][30] = {("-----------------------------"),
					("  W     W    A    I  T T T"),
					("  W  W  W  A A A  I    T  "),
					("   W   W   A   A  I    T  "),
					("-----------------------------")};
	int countx=1;
	int county=0;
	int key =1;
	int flag =0;
	system("cls");
	
		printf("\n\n\n\n\n");
			for(int j =0;j<5;++j){
		//		printf("\t\t");
			for (int k =0;k<30;++k){
				printf("%2c", snake[j][k]);
			}
			puts("");
	
		}
		Sleep(2000);
	
	
	for (int i =0; i<87;++i){
		
		if ((flag %3 == 0) && (flag>0)){
			county++;
			key++;
			
			} 
			
		if (key % 2 != 0){
		snake[countx][county] = 'o';
		++countx;
		++flag;
		}else if (key % 2 == 0){
			--countx;
			++flag;
			snake[countx][county] = 'o';
			
		}
		Sleep(10);
		system("cls");
		printf("\n\n\n\n\n");
			for(int j =0;j<5;++j){ 
			//	printf("\t\t");
			for (int k =0;k<30;++k){
				printf("%2c", snake[j][k]);
			}
			puts("");
	
		}
	}

	printf("\n\t\t");
	system("pause");

}

void food(char a[A][B]){
	srand(time(NULL));
	int isied =0;
	

	if ( (foodx == x) && (foody == y)){
	++foodcount;
	++snake_length;
	
	++score;
		}		

  	if (foodcount>0){

	do {
	foodx = rand()%(A-5) + 3;
	foody = rand()%(A-5) + 3;
	foodcount =0;
	if ( (foodx == x) && (foody == y) ){
	++isied;
	}
	} while(isied==1);

	}
	}

void validasi(){
	
	if ( x > A -2 || x< 1 || y > B-2 || y<1){
		z = 0;
	}else ++z;
}

void move(char a[A][B]){
	char ch;
	int len =0;
	
for (;;){
	//printf("%d",cnt);
		food(a);
		validasi();
		if (z > 0){

			if(cnt>TRACK-100){
				rest();
			}

		if (kbhit()){
			
				ch = getch();
				if (ch == DOWN ){
					dir = 1;
						return;
				
			
		}else if (ch == UP ){
			dir = 2;
				return;
		}else if(ch == ENTER){
			system("pause");
		}
		
	
		}
		//	printf("m1kanan");

		for (int i=0;i<A ;++i){
		for (int j=0;j<B ;++j){
		
		if ((i==x) && (j==y)) {	
		
			if (a[x][y] == 'o'){
						z=0;
						return;
					}	
			
			for(int k = 0 ; k<=len ;++k){
	 				
				if (k < snake_length-1){		
					a[i][j-k] = 'o';
					}
					
				if (k == len){
					
					flagx[cnt] = x;
					flagy[cnt] = y;
					++cnt;
				}

			if(cnt20 > 3){
				a[flagx[cnt-snake_length]][flagy[cnt-snake_length]] = '\0';	
			}
			
			

				}
			}
			else if (( i == A-1) || (i == 0) || (j == B-1) || (j == 0)){
				a[i][j] = '=';
		} else if ((foodx == i) && (foody == j) ){
			a[foodx][foody] = '+';

			}
		}
	}
		Sleep(C);
		system("cls");
		
		for (int i=0;i<A;++i){
		for(int j=0;j<B;++j){
			printf("%2c",a[i][j]);
		}
		puts("");
	}
		++y;
		++cnt20;
		printf("Score : %d\n",score);
		printf("Press enter to pause\n");
		


}else {
return;

}


if (len < snake_length )++len;
}

}

void movebwh(char a[A][B]){
	char ch;
	int len =0;
	
for (;;){
//	printf("bawah");
 //printf("%d",cnt);
	food(a);

		validasi ();
		if (z > 0){
				
			if(cnt>TRACK-100){
					rest();
					}

			if (kbhit()){
				ch = getch();
				if (ch == LEFT){
					dir = 4;
					return;
			
			}else if (ch == RIGHT ){
				dir = 3;
				return;
				
			}else if(ch == ENTER){
			system("pause");
		}
	
		}
			
		//		printf("m1bwh");
			
		for (int i=0;i<A;++i){
		for(int j=0;j<B;++j){
		if ((i==x) && (j==y)) {
			
				if (a[x][y] == 'o'){
						z=0;
						return;
					}
			
					for(int k = 0 ; k<=len ;++k){
					if (k < snake_length-1){
					a[i-k][j] = 'o';
					}
					
					if (k == len){
					
					flagx[cnt] = x;
					flagy[cnt] = y;
					++cnt;
					}
			
					if(cnt20 >3){
					a[flagx[cnt-snake_length]][flagy[cnt-snake_length]] = '\0';
					}

					

				}
			}
			
		
	else if (( i == A-1) || (i == 0) || (j == B-1) || (j == 0)){
				a[i][j] = '=';
	} else if ((foodx == i) && (foody == j) ){
		a[foodx][foody] = '+';
		}
	}
}

		Sleep(C);
		system("cls");
		
		
			for (int i=0;i<A;++i){
			for(int j=0;j<B;++j){
			printf("%2c",a[i][j]);
		}
		puts("");
	}
	printf("Score : %d\n",score);
	printf("Press enter to pause\n");

++x;
++cnt20;

}else {
return;
}


if (len < snake_length) ++len;
}
	
}

void moveatas(char a[A][B]){ 
	char ch;
	int leng =0;

for (;;){
//	printf("atas");
//	printf("%d",cnt);

		food(a);

		validasi ();
		if (z > 0){

			if(cnt>TRACK-100){
				rest();
			}

			if (kbhit()){
				ch = getch();
				if (ch == LEFT ){
					dir = 4;
					return;
				
			}else if (ch == RIGHT ){
				dir = 3;
				return;
			}else if(ch == ENTER){
			system("pause");
		}
		}
			
		for (int i=0;i<A;++i){
		for(int j=0;j<B;++j){
			
		if ((i == x) && (j == y)) {
			
				if (a[x][y] == 'o'){
						z=0;
						return;
					}
			
				for(int m =0; m<=leng;++m){
				if (m < snake_length-1){
					a[i+m][j] = 'o';
				}
						if (m == leng){
							
						
					flagx[cnt] = x;
					flagy[cnt] = y;
					++cnt;
			}
			
						if(cnt20 >3){
			a[flagx[cnt-snake_length]][flagy[cnt-snake_length]] = '\0';
						}
					
			}

				} else if (( i == A-1) || (i == 0) || (j == B-1) || (j == 0)){
					a[i][j] = '=';
						} else if ((foodx == i) && (foody == j) ){
							a[foodx][foody] = '+';
					} 
				}
			}
			
		Sleep(C);
		system("cls");
	
		for (int i=0;i<A;++i){
		for(int j=0;j<B;++j){
			printf("%2c",a[i][j]);
		}
		puts("");
	}
		printf("Score : %d\n",score);
		printf("Press enter to pause\n");
	
--x;
++cnt20;

}else {
return;
}
if (leng < snake_length )++leng;
}
}

void movekiri(char a[A][B]){ 
	int len =0;
	char ch;
	
for (;;){
//	printf("kiri");
//printf("%d",cnt);	
	food(a);

		validasi ();
		if (z > 0){

			if(cnt>TRACK-100){
				rest();
			}
		
			if (kbhit()){
				ch = getch();
				if (ch == DOWN ){
					dir = 1;
				return;
			}else if (ch == UP ){
				dir = 2;
				return;
	
		}else if(ch == ENTER){
			system("pause");
		}
	}
	
		for (int i=0;i<A;++i){
		for(int j=0;j<B;++j){
			if ((i==x) && (j==y)) {
				
					if (a[x][y] == 'o'){
					z=0;
					return;
					}
	
				for(int k = 0 ; k<=len ;++k){
					if(k<snake_length-1){
					a[i][j+k] = 'o';
				}
					
					if (k == len){
						
				
					flagx[cnt] = x;
					flagy[cnt] = y;
				++cnt; 
			}
			if(cnt20 >3){
			a[flagx[cnt-snake_length]][flagy[cnt-snake_length]] = '\0';
			}

			

			} 
		} else if (( i == A-1) || (i == 0) || (j == B-1) || (j == 0)){
				a[i][j] = '=';} 
				else if ((foodx == i) && (foody == j) ){
		a[foodx][foody] = '+';
				
			}
		}
	}
		Sleep(C);
		system("cls");
		
	
		for (int i=0;i<A;++i){
		for(int j=0;j<B;++j){
			printf("%2c",a[i][j]);
		}
		puts("");
	}
	--y;
	++cnt20;
	printf("Score : %d\n",score);
	printf("Press enter to pause\n");


}else {
return;
}
if(len < snake_length) ++len;
}
}

void menu (struct high high[100]){
	
	char opsi[5][100] = {("  Play"),("  How to play "),("  High score"),("  Credit"),("  Exit")};
	
	char ch = '\0' ;
//	char chr;
	int fflag =-1;
	
flag = -1;
fflag =-1;

 //exit tetap
 // smua jalan di for bawah 
 // shg ga akan dijalanin yg d sini;



printf("\n\n\n");
		
	//	opsi[0][0]= '-';
	//	opsi[0][14] = '-';
		
		for(;;){
			
		system("cls");	
		printf("\n\n\n\n\n");
	for(int k =0; k <5;++k){
		puts("");	
		printf("\t\t    ");
		for (int j =0 ;j<15;++j){
		
		printf("%c", opsi[k][j]);
		
	}
	puts("");
	}
	
	printf("\n\n\t   Press enter to select, arrow to move ");
	
		ch = getch();
		if (ch == DOWN){
			if (flag <4){
			++flag;
		}
			opsi[flag][0] = '-';
			opsi[flag-1][0] = '\0';
			opsi[flag][14] = '-';
			opsi[flag-1][14] = '\0';
			}else if (ch == UP){
				if (flag > 0){
			--flag;
		}
		opsi[flag][0] = '-';
			opsi[flag+1][0] = '\0';
			opsi[flag][14] = '-';
			opsi[flag+1][14] = '\0';
		}
		
		if(ch == ENTER){
		if (flag == 0){
			return;
		}else if (flag ==1){
			system("cls");
			how();
			printf("        ");
			system("pause");
		}else if (flag == 2){
			system("cls");
			highscore(high);
			system("pause");
		}else if (flag == 3 ){
			system("cls");
			credit();
		}else if (flag == 4){
			aftere(&fflag);
			if(fflag == 0){
				return;
			}else {
			flag = -1;
			return;
		}
				
		}
	}
	}
	
					
} 

void home(){
	system("cls");
	flag = -1;
	for (;;){
		
	printf("\r    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("\r    %c >>>>>>>  >>     >>     >>>     >>  >>    >>>>>>  %c \n",186,186);
	printf("\r    %c >>       >>>    >>    >   >    >> >>     >>      %c\n",186,186);
	printf("\r    %c  >>>>>   >> >>  >>   >>>>>>>   >>>>      >>>>>>  %c \n",186,186);
	printf("\r    %c      >>  >>  >> >>   >     >   >>  >>    >>      %c\n",186,186);
	printf("\r    %c >>>>>>>  >>    >>>   >>   >>   >>   >>   >>>>>>  %c \n",186,186);								
	printf("\r    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

	printf("\r    a Homemade project...\n\n\n");
	
	
	Sleep(1000);
	printf("\t\tPress any key to continue");
		Sleep(2000);
		system("cls");
		
if (kbhit()){
	return;
}

}
}

int main(){
	
	struct high high[100];
	char a[A][B]= {};
	int ind =-1;
	int m =0;
	struct high temp;
	struct high tem[100];
	
	read(high);
	
	//system("mode 60,30");
	
do{
	ind =-1;
	m =0;
	
	//sorting h
	for(int i =0;i<count11;++i){
			for(int j =0;j<count11-1;++j){
				if(high[j].scr< high[j+1].scr){
					temp = high[j+1];
					high[j+1] = high[j];
					high[j] = temp;
				}
			}
		}
	//end sorting h
		
	news(a);
	system("cls");
	home();
loading();
	menu(high); 
	system("cls");
		
	if (flag == 0 ){
		
loading();
	do{
		if (dir == 3)move(a);
		else if (dir == 1) movebwh(a);
		else if (dir == 2) moveatas(a);
		else if (dir == 4) movekiri(a);
		
		
}while (z > 0);
		
		//tulis score
		if (count11 >9){
			for(int i =9;i>=0;--i){
				if(score>high[i].scr ){
					ind =i;
				}
			}
			if(ind != -1){
				
			tem[m] = high[ind+1];
			high[ind+1] = high[ind];
			++m;
			
			for(int j =ind;j<9;++j,++m){
			tem[m] = high[j+1];
			high[j+1] = tem[m-1];
			}
			
			high[ind].scr = score;
			
			do{
		printf("\nName [1-8 char]:");
		scanf("%s",high[ind].name); fflush(stdin);
	}while (strlen(high[ind].name)<0 || strlen(high[ind].name)>8);
	
	}else {
		printf("\nyou lose\n");
		system("pause");
	}

	write(high,count11);
	} else {
		
		do{
		printf("\nName [1-8 char]:");
		scanf("%s",high[count11].name); fflush(stdin);
	}while (strlen(high[count11].name)<0 || strlen(high[count11].name)>8);
		high[count11].scr = score;
		++count11;
	write(high,count11);	
	}
	//end tulis score
	
		
	}else if (flag == 4){ 
		write(high,count11);
		return 0;
		
		}else if (flag != -1){
		
		printf("\nyou lose\n");
		system("pause");
	}
	 	
	}while(1);
	
	write(high,count11);
	
	getchar();
	return 0;


}
