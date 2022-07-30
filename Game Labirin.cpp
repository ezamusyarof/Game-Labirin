#include <iostream>
#include <Windows.h>
using namespace std;

string line[7] = {"  +---+---+---+---+---+---+",
                  "O         |               |",
				  "  +---+   +   +---+---+   +",
				  "  |       |   |           |",
				  "  +   +---+   +   +---+---+",
				  "  |           |              ",
				  "  +---+---+---+---+---+---+"};
				  
int curline = 1; //line ke-n
int posisi = 0; //posisi ke-n
int skor = 0; //skor // max:9999

void board();
void utama();

void atas(){
	if(curline>=1&&line[curline-1][posisi]==' '){
		line[curline][posisi]=' ';
		line[curline-1][posisi]='O';
		curline=curline-1;
	}else{
		utama();
	}
	utama();
}

void kiri(){
	if(line[curline][posisi-2]==' '){
		line[curline][posisi]=' ';
		line[curline][posisi-2]='O';
		posisi=posisi-2;
	}
	utama();
}

void kanan(){
	if(line[curline][posisi+2]==' '){
		line[curline][posisi]=' ';
		line[curline][posisi+2]='O';
		posisi=posisi+2;
	}
	utama();	
}

void bawah(){
	if(curline<=5&&line[curline+1][posisi]==' '){
		line[curline][posisi]=' ';
		line[curline+1][posisi]='O';
		curline=curline+1;
	}
	utama();
}

void board(){
	cout << endl;
	cout << "   +-----------------------------+--------------+" << endl;
	cout << "   |   L A B I R I N   G A M E   |  SKOR : " << skor << "	|" << endl;
	cout << "   +-----------------------------+--------------+" << endl;
	cout << "   |                                            |" << endl;
	for(int i=0; i<7; i++){
		switch(i){
			case 1:
				cout << "   | START " << line[i] << "          |" << endl; break;
			case 5:
				cout << "   |       " << line[i] << " FINISH |" << endl; break;
			default:
				cout << "   |       " << line[i] << "          |" << endl;
		}
	}
	cout << "   |                                            |" << endl;
	cout << "   +-----------------------------+--------------+" << endl;
}

void finish(){
	if(line[5][28]=='O'){
		line[5][28]=' ';
		curline=1;
		posisi=0;
		line[curline][posisi]='O';
		cout << endl;
		if(skor>=1000){
			skor=0;
		}else{
			skor = skor+10;
		}
		cout << "         SELAMAT ANDA BERHASIL" << endl;
		Sleep(1000);
		utama();
	}
}

void utama(){
	system("cls");
	board();
	finish();
	
	cout << endl;
	cout << "          ^" << endl;
	cout << "          W             CARA BERMAIN:" << endl;
	cout << "         ---            - Ketik huruf di samping" << endl;
	cout << "    < A |   | D >         untuk mengarahkan" << endl;
	cout << "         ---            - Cari jalan keluar dari" << endl;
	cout << "          S               labirin" << endl;
	cout << "          v" << endl << endl;
	
	string pil;
	cout << "         => "; cin >> pil;
	if(pil=="W"){
		atas();
	}else if(pil=="A"){
		kiri();
	}else if(pil=="D"){
		kanan();
	}else if(pil=="S"){
		bawah();
	}else{
		utama();
	}
}

int main(){
	utama();	
}
