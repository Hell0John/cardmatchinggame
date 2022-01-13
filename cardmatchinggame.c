#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int check,i,j,l,m,n,o,holder1,zero,cards[8][8],memory[3][17],randval1,randval2,scrPlayer,scrCPU,winCon,draw;
	int prow1,pcolumn1,prow2,pcolumn2,rtrn,controller,control9,memborder,count5,check2,guessPlayer,control3,guessComputer,control8;
	char difficulty,star[8][8],menu1,menu2,menu3='R',menu8;
while(menu3=='R'){
	check=0;
	control3=0;
	zero=0;
	scrPlayer=0;
	guessPlayer=0;
	guessComputer=0;
	scrCPU=0;
	draw=0;
	control9=0;
	menu1='N';
	menu8='R';
	system("cls");
	while(menu1!='S'){
printf("                                  Welcome to the Card Matching game!\n\n\n                                 To learn how to play please enter H\n\n\n                                 ");
printf("To start the game please enter S\n\n\n                                 Input:");
do{
	menu1=getchar();
}while(menu1 !='H'&& menu1 !='S');
system("cls");
if(menu1=='H'){
	printf("                                       How to Play\n\n\n                              *You start the game by choosing a difficulty.");
	printf("\n\n                              *You are playing against a Computer with a certain amount of memory.\n\n                              ");
	printf("*Your goal is to match the cards with the same numbers on them.\n\n                              *You start the game by picking 2 cards.\n\n                              ");
	printf("*To pick a card choose your coordinates then enter them to the Input like this: 1,2\n\n                              *If you guess wrong your turn ends and Computer remembers the cards you chose.\n\n                              ");
	printf("*If computer doesn't remember 2 matching cards it picks a random card as his first card.\n\n                              *If Computer has the matching card in its memory it chooses that one as a second card.\n\n                              ");
	printf("*If computer doesn't have the matching card in its memory. It chooses a random card as its second card.\n\n                              *If Computer's cards doesn't match its your turn again.\n\n                              *To win the game one of the players have to reach points equilevant to: number of cards/2 + 1");
	printf("\n\n\n                                To return to the Main Menu please enter B\n                                Input:");
    do{
	    menu2=getchar();
    }while(menu2 !='B');
    system("cls");
}}
	do{
	printf("Enter the difficulty(E[Easy],N[Normal],H[Hard]:");
	difficulty=getchar();
	difficulty=getchar();
	if(difficulty == 'N' || difficulty == 'H' || difficulty == 'E'){
		system("cls");
		if(difficulty=='E'){		
		    printf("Your difficulty has been set to Easy\n",difficulty);
		}
		if(difficulty=='N'){		
		    printf("Your difficulty has been set to Normal\n",difficulty);
		}
		if(difficulty=='H'){		
		    printf("Your difficulty has been set to Hard\n",difficulty);
		}		
		check=1;
		}else{
		system("cls");
		printf("Error! Please Enter the difficulty again!\n");
	}
}while(check == 0);
if(difficulty == 'E'){
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			j=j+1;
			zero=zero+1;
			cards[i][j-1]=zero;
			cards[i][j]=zero;
		}
	}
	zero=5;
	memborder=1;
}
if(difficulty=='N'){
	for(i=0;i<6;i++){
		for(j=0;j<5;j++){
			j=j+1;
			zero=zero+1;
			cards[i][j-1]=zero;
			cards[i][j]=zero;
		}
	}
	zero=7;
	memborder=5;
}
if(difficulty=='H'){
	for(i=0;i<8;i++){
		for(j=0;j<7;j++){
			j=j+1;
			zero=zero+1;
			cards[i][j-1]=zero;
			cards[i][j]=zero;
		}
	}
	zero=9;
	memborder=15;
}
zero=zero-1;
for(i=0;i<zero;i++){
	for(j=0;j<zero;j++){
		star[i][j]='*';
	}
}
//memorynin tüm elemanlarýný 0 yapma
for(i=0;i<3;i++){
	for(j=0;j<17;j++){
		memory[i][j]=0;
	}
}
cards[0][0]=1;
//SHUFFLE
srand( time(0) );
for(check=0;check<2;check++){// iki kere karistirdim.
for(i=0;i<zero;i++){
	for(j=0;j<zero;j++){
		randval1=rand() % (zero); 
        randval2=rand() % (zero);
        check2=cards[i][j];
        cards[i][j]=cards[randval1][randval2];
        cards[randval1][randval2]=check2;
	}
}}
printf("Cards are successfully shuffled!\n");
//SHUFFLE

//gameplay
winCon=(zero*zero)/4;
winCon=++winCon;
while(scrPlayer!= winCon && scrCPU!= winCon && draw==0&&menu8=='R'){
	rtrn=0;
	while(rtrn==0 && draw==0&&scrPlayer!= winCon){  //Oyuncunun sýrasý *****************************************************************
	zero=++zero;
printf("     ");
for(i=1;i<zero;i++){
	printf("| [%d] ",i);
}
printf("|");
zero=--zero;
for(i=0;i<zero;i++){
	printf("\n [%d] ",i+1);
	for(j=0;j<zero;j++){
		if(cards[i][j]<=9){
			printf("|  %d  ",cards[i][j]);
		}
		else{
			printf("| %d  ",cards[i][j]);
		}
	}
	printf("|");
}
					//STAR
		zero=++zero;
		printf("\n\n     ");
for(i=1;i<zero;i++){
	printf("| [%d] ",i);
}
printf("|");
zero=--zero;
for(i=0;i<zero;i++){
	printf("\n [%d] ",i+1);
	for(j=0;j<zero;j++){
		printf("|  %c  ",star[i][j]);
	}
	printf("|");
} 
//STAR
    printf("\nPlayer's Turn. Please choose your first card:");
    controller=0;
    while(controller==0){
    scanf("%d, %d", &prow1,&pcolumn1);
    if(star[prow1-1][pcolumn1-1]=='-'){
    	printf("Sorry :( That card has been already opened. Please pick a new card:");
    }
    else{
    	controller=1;
	}
	}
    printf("First card's value:%d",cards[prow1-1][pcolumn1-1]);
    printf("\nPlease choose your second card:");
    controller=0;
    while(controller==0){
    scanf("%d, %d", &prow2,&pcolumn2);
    if(star[prow2-1][pcolumn2-1]=='-' || (prow1-1==prow2-1 && pcolumn1-1==pcolumn2-1)){
    	printf("Sorry :( That card has been already opened. Please pick a new card:");
    }
    else{
    	controller=1;
	}
	}
    printf("Second cards value:%d",cards[prow2-1][pcolumn2-1]);
	if(cards[prow1-1][pcolumn1-1]==cards[prow2-1][pcolumn2-1]){
		j=0;
        while(j!=memborder+1 && memory[2][j]!=0){ //Hafýzada bilinen kartlar varsa onlarý çýkaran bölüm
	if(memory[2][j]==cards[prow1-1][pcolumn1-1]){
		for(i=0;i<3;i++){
		count5=j;
		while(count5!=memborder+1){
			memory[i][count5]=memory[i][count5+1];
			count5=++count5;
		}}
		j=--j;
	}
	j=++j;
}  
		scrPlayer=++scrPlayer;
		guessPlayer=++guessPlayer;
		printf("\nCongrats! You got a matching pair! Your current score:%d\n\n",scrPlayer);
		star[prow2-1][pcolumn2-1]='-';
		star[prow1-1][pcolumn1-1]='-';
		if(scrPlayer==winCon-1 && scrCPU==winCon-1){ //oyuncunun sýrasýnda beraberlik oluþursa oyunu bitirme
    	     draw=1;
	}
          
		}
    else{
    	guessPlayer=++guessPlayer;
		count5=0;
while(memory[2][count5]!=0 && count5!=memborder+1){
	count5=count5+1;
}
if(count5==memborder+1){
	for(i=0;i<3;i++){
		for(j=0;j<memborder;j++){
			memory[i][j]=memory[i][j+1];
		}
	}
	memory[0][memborder]=prow1;
	memory[1][memborder]=pcolumn1;
	memory[2][memborder]=cards[prow1-1][pcolumn1-1];
}else{
	memory[0][count5]=prow1;
	memory[1][count5]=pcolumn1;
	memory[2][count5]=cards[prow1-1][pcolumn1-1];
}
count5=0;
while(memory[2][count5]!=0 && count5!=memborder+1){
	count5=count5+1;
}
if(count5==memborder+1){
	for(i=0;i<3;i++){
		for(j=0;j<memborder;j++){
			memory[i][j]=memory[i][j+1];
		}
	}
	memory[0][memborder]=prow2;
	memory[1][memborder]=pcolumn2;
	memory[2][memborder]=cards[prow2-1][pcolumn2-1];
}else{
	memory[0][count5]=prow2;
	memory[1][count5]=pcolumn2;
	memory[2][count5]=cards[prow2-1][pcolumn2-1];
}
		rtrn=1;
		}}
//***************************************************************************************************************************
        rtrn=0;	//Bilgisayarýn sýrasý//Bilgisayarýn sýrasý
        system("cls");
		printf("Sorry:( Your cards didn't match. Your second card was: %d,%d: %d\n",++prow2,++pcolumn2,cards[--prow2][--pcolumn2]);
				//STAR
		zero=++zero;
		printf("\n\n     ");
for(i=1;i<zero;i++){
	printf("| [%d] ",i);
}
printf("|");
zero=--zero;
for(i=0;i<zero;i++){
	printf("\n [%d] ",i+1);
	for(j=0;j<zero;j++){
		printf("|  %c  ",star[i][j]);
	}
	printf("|");
} 
//STAR
control3=0;
while(draw==0 &&  scrPlayer!= winCon && scrCPU != winCon &&control3==0){ // hafýzada çoktan 2 tane eþlenmiþ kart varsa direk onlarý bilir ve hafýzadan çýkarýr.
	i=-1;
		do{  // hafýzada çoktan 2 tane eþlenmiþ kart varsa direk onlarý bilir ve hafýzadan çýkarýr.
			i=++i;
			check=i+1;
			control8=0;
			while(memory[2][check]!=0 && control8!=1&&check!=memborder+1){
				if(memory[2][i]==memory[2][check] && (memory[0][i]!= memory[0][check] || memory[1][i]!=memory[1][check])){
					star[--memory[0][i]][--memory[1][i]]='-';
					star[--memory[0][check]][--memory[1][check]]='-';
				    control8=1;
				    scrCPU=++scrCPU;
				    guessComputer=++guessComputer;
				    		if(scrPlayer==winCon-1 && scrCPU==winCon-1){ //BÝLGÝSAYARIN sýrasýnda beraberlik oluþursa oyunu bitirme
    	     draw=1;
    	 }
					printf("\nComputer's Turn. Computer has a matching pair in its memory!\nComputer's first card: %d,%d : %d\n",++memory[0][i],++memory[1][i],memory[2][i]);
				    printf("Computer's second card: %d,%d : %d\nComputer got a matching pair!. Computer's current score: %d",++memory[0][check],++memory[1][check],memory[2][check],scrCPU);
				    //star
					zero=++zero;
					printf("\n\n     "); 
for(n=1;n<zero;n++){
	printf("| [%d] ",n);
}
printf("|");
zero=--zero;
for(n=0;n<zero;n++){
	printf("\n [%d] ",n+1);
	for(o=0;o<zero;o++){
		printf("|  %c  ",star[n][o]);
	}
	printf("|");
} //star
				    check2=i; //problem burda
				    holder1=memory[2][i];
				    while(memory[2][check2]!=0&&draw==0 && scrCPU != winCon&&check2!=memborder+1){
				    	if(memory[2][check2]==holder1){
				    		for(l=0;l<3;l++){
				    			for(m=check2;m<memborder+1;m++){
				    				memory[l][m]=memory[l][m+1];
								}
							}
							check2=--check2;
						}
						check2=++check2;
					}
				    i=--i;
				}else{
					check=++check;
				}
	}
		}while(memory[2][i+1]!=0&&draw==0 && scrCPU != winCon&&i+1!=memborder);
		control3=1;
}

		while(draw==0 && rtrn==0&& scrPlayer!= winCon && scrCPU != winCon){ //Bilgisayarýn sýrasý		
	    do{     //bilgisayarýn ilk girdisini random alýr.
		    prow1=rand() %zero;
		    pcolumn1=rand() %zero;
		    controller=0;
		    if(star[prow1][pcolumn1]=='*'){
		    	controller=1;
			}		    
		}while(controller==0);
		printf("\n\nComputer's Turn. Computer's first card: %d,%d : %d\n",prow1+1,pcolumn1+1,cards[prow1][pcolumn1]);
		i=0;
		control9=0;
		while(memory[2][i]!=0&&i!=memborder+1&&control9!=1){
		    if(cards[prow1][pcolumn1]==memory[2][i]&&(prow1+1!=memory[0][i]||pcolumn1+1!=memory[1][i])){
		    	control9=1;
		    	scrCPU=++scrCPU;
				guessComputer=++guessComputer;
		    	printf("Computer has the matching card in its memory! Computer's second card: %d,%d: %d\nComputer's current score: %d",memory[0][i],memory[1][i],memory[2][i],scrCPU);
		    		star[prow1][pcolumn1]='-';
					star[memory[0][i]-1][memory[1][i]-1]='-';
//star
					zero=++zero;
					printf("\n\n     "); 
for(n=1;n<zero;n++){
	printf("| [%d] ",n);
}
printf("|");
zero=--zero;
for(n=0;n<zero;n++){
	printf("\n [%d] ",n+1);
	for(o=0;o<zero;o++){
		printf("|  %c  ",star[n][o]);
	}
	printf("|");
} //star
				    		if(scrPlayer==winCon-1 && scrCPU==winCon-1){ //BÝLGÝSAYARIN sýrasýnda beraberlik oluþursa oyunu bitirme
    	     draw=1;
    	 }
				    check2=i;
				    holder1=memory[2][i];
				    while(memory[2][check2]!=0&&draw==0 && scrCPU != winCon&&check2!=memborder+1){
				    	if(memory[2][check2]==holder1){
				    		for(l=0;l<3;l++){
				    			for(m=check2;m<memborder+1;m++){
				    				memory[l][m]=memory[l][m+1];
								}
							}
							check2=--check2;
						}
						check2=++check2;
					}
				}
			i=++i;	//*******************************************************************
		}
		if(control9==0){
	    do{     //bilgisayarýn ikinci girdisini random alýr.
		    prow2=rand() %zero;
		    pcolumn2=rand() %zero;
		    controller=0;
		    if(star[prow2][pcolumn2]=='*'&&(prow1!=prow2||pcolumn1!=pcolumn2)){
		    	controller=1;
			}		    
		}while(controller==0);
		guessComputer=++guessComputer;
		if(cards[prow1][pcolumn1]==cards[prow2][pcolumn2]){
			scrCPU=++scrCPU;
							    		if(scrPlayer==winCon-1 && scrCPU==winCon-1){ //BÝLGÝSAYARIN sýrasýnda beraberlik oluþursa oyunu bitirme
    	     draw=1;
    	 }
		    printf("Computer's second card: %d,%d: %d\nComputer got a matching pair! Computer's current score: %d\n",prow2+1,pcolumn2+1,cards[prow2][pcolumn2],scrCPU);
		    star[prow1][pcolumn1]='-';
		    star[prow2][pcolumn2]='-';
		    //star
					zero=++zero;
					printf("\n\n     "); 
for(n=1;n<zero;n++){
	printf("| [%d] ",n);
}
printf("|");
zero=--zero;
for(n=0;n<zero;n++){
	printf("\n [%d] ",n+1);
	for(o=0;o<zero;o++){
		printf("|  %c  ",star[n][o]);
	}
	printf("|");
} //star
		    for(j=0;j<=memborder;j++){
		    	if(memory[0][j]==prow1&&memory[1][j]==pcolumn1){
		    		for(l=0;l<3;l++){
		    			for(m=j;m<=memborder;m++){
		    				memory[l][m]=memory[l][m+1];
						}
					}
				}
			}
		}else{
			printf("Computer's second card: %d,%d: %d\nComputer failed to find a matching pair! It's your turn now.\nPlease enter 'R' to start the next round.",prow2+1,pcolumn2+1,cards[prow2][pcolumn2]);
					count5=0;
while(memory[2][count5]!=0 && count5!=memborder+1){
	count5=count5+1;
}
if(count5==memborder+1){
	for(i=0;i<3;i++){
		for(j=0;j<memborder;j++){
			memory[i][j]=memory[i][j+1];
		}
	}
	memory[0][memborder]=prow1+1;
	memory[1][memborder]=pcolumn1+1;
	memory[2][memborder]=cards[prow1][pcolumn1];
}else{
	memory[0][count5]=prow1+1;
	memory[1][count5]=pcolumn1+1;
	memory[2][count5]=cards[prow1][pcolumn1];
}
count5=0;
while(memory[2][count5]!=0 && count5!=memborder+1){
	count5=count5+1;
}
if(count5==memborder+1){
	for(i=0;i<3;i++){
		for(j=0;j<memborder;j++){
			memory[i][j]=memory[i][j+1];
		}
	}
	memory[0][memborder]=prow2+1;
	memory[1][memborder]=pcolumn2+1;
	memory[2][memborder]=cards[prow2][pcolumn2];
}else{
	memory[0][count5]=prow2+1;
	memory[1][count5]=pcolumn2+1;
	memory[2][count5]=cards[prow2][pcolumn2];
}
rtrn=1;
			do{
	menu8=getchar();
}while(menu8!='R');
system("cls");
		}}}}			
//bilgisayarýn sýrasý bitiþ
system("cls");
if(draw==1){
	printf("It's a draw!");
}
if(scrPlayer== winCon){
	printf("Congrats! You won! It took you %d guesses to win!",guessPlayer);
}
if(scrCPU== winCon){
	printf("You lost :( Computer won. Computer won with %d guesses.",guessComputer);
}
printf("\nTo Play again please enter 'R', To End the game please enter 'E'\nInput:");
do{
	menu3=getchar();
}while(menu3!='E' && menu3!='R');
}
	return 0;	
}
